export const roundPrice = (price) => Math.round(price * 100) / 100;


export const getDiscountValue = (price, discount) => roundPrice(price * discount / 100);


export const getDiscountPrice = (price, discount) => roundPrice(price - getDiscountValue(price, discount));


export const formatPrice = (price) => new Intl.NumberFormat('ru-Ru').format(price);
