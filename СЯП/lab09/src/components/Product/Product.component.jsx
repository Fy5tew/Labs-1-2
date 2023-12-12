import { getDiscountPrice, formatPrice } from "#utils/price";

import styles from "./Product.module.css";


export const Product = ({ title, price, discount, description, count, isNew, imageSrc }) => {
    const discountPrice = getDiscountPrice(price, discount);

    return (
        <div className={styles.card}>
            <div className={styles.cardPart}>
                <div className={styles.indicatorsWrapper}>
                    {isNew && <p className={styles.newIndicator}>Новинка!</p>}
                    {discount !== 0 && <p className={styles.discountIndicator}> -{discount}%</p>}
                </div>
                <div className={styles.imageWrapper}>
                    <img className={styles.image} src={imageSrc} alt={title} />
                </div>
            </div>
            <div className={styles.cardPart}>
                <h3 className={styles.title}>{title}</h3>
                <p className={styles.priceWrapper}>
                    <span className={styles.priceCurrent}>{formatPrice(discountPrice)} BYN</span>
                    {discountPrice !== price && <span className={styles.pricePrevious}>{formatPrice(price)} BYN</span>}
                </p>
                <p className={[styles.inStock, count === 0 && styles.inStockNone].join(' ')}>
                    {count !== 0
                        ? `В наличии ${count} шт.`
                        : 'Нет в наличии'
                    }
                </p>
                <p className={styles.description}>
                    {description}
                </p>
            </div>
        </div>
    );
}
