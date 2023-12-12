import { Product } from "#components/Product";

import styles from "./ProductList.module.css";


export const ProductList = ({ products }) => {
    return (
        <div className={styles.productList}>
            {products.map((product) => <Product 
                                            key={product.title.value}
                                            title={product.title.value}
                                            price={product.price.value}
                                            discount={product.discount.value}
                                            description={product.description.value}
                                            count={product.count.value}
                                            isNew={product.isNew.value}
                                            imageSrc={product.imageSrc.value}
                                        />
            )}

        </div>
    );
}
