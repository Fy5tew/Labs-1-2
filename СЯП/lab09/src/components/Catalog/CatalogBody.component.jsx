import { useState } from 'react';

import { ProductList } from '#components/ProductList';

import { VIEW_MODE } from '#utils/filters';
import { getNewProducts, getOldProducts } from '#utils/filters';

import styles from './Catalog.module.css';


const CatalogBodyAllProducts = ({ products }) => {
    return (
        <>
            <h2>Все товары</h2>
            {products.length !== 0
                ? <ProductList products={products} />
                : <p>Список товаров пуст</p>
            }
        </>
    );
}


const CatalogBodySeparateNew = ({ products }) => {
    const newProducts = getNewProducts(products);
    const oldProducts = getOldProducts(products);

    return (
        <>
            <h2>Новые товары</h2>
            {newProducts.length !== 0 
                ? <ProductList products={newProducts} />
                : <p>Список новинок пуст</p>
            }
            <h2>Остальные товары</h2>
            {oldProducts.length !== 0
                ? <ProductList products={oldProducts} />
                : <p>Список товаров пуст</p>
            }
        </>
    );
}


export const CatalogBody = ({ products, viewMode }) => {
    switch (viewMode) {
        case VIEW_MODE.ALL_PRODUCTS:
            return <CatalogBodyAllProducts products={products} />
        case VIEW_MODE.SEPARATE_NEW:
            return <CatalogBodySeparateNew products={products} />
        default:
            return <CatalogBodySeparateNew products={products} />
    }
}
