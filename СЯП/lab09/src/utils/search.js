export const SEARCH_TYPE = Object.freeze({
    MATCH: Symbol('match'),
    PARTIAL: Symbol('partial'),
});


export const search = (products, query, searchType) => {
    if (!query) {
        return [...products];
    }
    query = query.trim();
    switch (searchType) {
    case SEARCH_TYPE.MATCH:
        return products.filter(product => product.title.value === query);
    case SEARCH_TYPE.PARTIAL:
        return products.filter(product => product.title.value.toLowerCase().includes(query.toLowerCase()));    
    default:
        return [...products];
    }
}
