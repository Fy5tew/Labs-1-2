import { useState, useEffect } from 'react';
import { useSelector } from 'react-redux';

import { actions } from '#store/products';

import { Search } from '#components/Search';
import { Catalog } from '#components/Catalog';

import { search, SEARCH_TYPE } from '#utils/search';

import styles from './App.module.css';


export const App = (props) => {
    const productsData = useSelector(actions.getProducts);

    const [ products, setProducts ] = useState(productsData);
    const [ searchOptions, setSearchOptions ] = useState({query: '', type: SEARCH_TYPE.PARTIAL});

    useEffect(() => {
        setProducts(search(productsData, searchOptions.query, searchOptions.type));
    }, [searchOptions, productsData]);

    return (
        <div className={styles.container}>
            <h1 className={styles.header}>Лабораторная работа №9</h1>
            <Search 
                options={searchOptions}
                onOptionsChange={setSearchOptions}
            />
            <Catalog 
                products={products} 
            />
        </div>
    );
}
