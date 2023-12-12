import { getDiscountPrice } from "./price";


export const VIEW_MODE = Object.freeze({
    ALL_PRODUCTS: Symbol("ALL_PRODUCTS"),
    SEPARATE_NEW: Symbol("SEPARATE_NEW"),
});


export const SORT_TYPE = Object.freeze({
    ASCENDING: Symbol("ASCENDING"),
    DESCENDING: Symbol("DESCENDING"),
});


export const toggleViewMode = (viewMode) =>
    viewMode === VIEW_MODE.ALL_PRODUCTS ? VIEW_MODE.SEPARATE_NEW : VIEW_MODE.ALL_PRODUCTS;


export const toggleSortType = (sortType) =>
    sortType === SORT_TYPE.ASCENDING ? SORT_TYPE.DESCENDING : SORT_TYPE.ASCENDING;


export const getSortableProperties = (product) => 
    Object.entries(product).filter(entry => entry[1].isFilterable).map(entry => ({
        property: entry[0],
        name: entry[1].name,
    }));


export const getNewProducts = (products) => products.filter(product => product.isNew.value);


export const getOldProducts = (products) => products.filter(product => !product.isNew.value);


export const getValue = (product, property) => {
    if (property === 'price') {
        return getDiscountPrice(product[property].value, product.discount.value);
    }
    return product[property].value;
}


export const sortByPropertyAscending = (products, property) => 
    [...products].sort((a, b) => getValue(a, property) > getValue(b, property) ? 1 : -1);


export const sortByPropertyDescending = (products, property) => 
    [...products].sort((a, b) => getValue(a, property) > getValue(b, property) ? -1 : 1);


export const sortByNew = (products) => {
    return sortByPropertyDescending(products, 'isNew');
} 


export const sortByProperty = (products, property, sortType) => {
    let sortedProducts;
    switch (sortType) {
        case SORT_TYPE.ASCENDING:
            sortedProducts = sortByPropertyAscending(products, property);
            break;
        case SORT_TYPE.DESCENDING:
            sortedProducts = sortByPropertyDescending(products, property);
            break;
        default:
            sortedProducts = [...products]; 
            break;
    }
    return sortByNew(sortedProducts);
}
