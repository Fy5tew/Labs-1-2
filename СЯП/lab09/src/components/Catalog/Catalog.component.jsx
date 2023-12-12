import { useState, useEffect, useMemo } from 'react';

import { CatalogHead } from './CatalogHead.component';
import { CatalogBody } from './CatalogBody.component';

import { VIEW_MODE, SORT_TYPE } from '#utils/filters';
import { getSortableProperties, sortByProperty } from '#utils/filters';

import styles from './Catalog.module.css';


const CatalogEmpty = (props) => {
    return (
        <div>
            <h2>Список товаров пуст</h2>
        </div>
    );
}


const CatalogItems = ({ products: productsData }) => {  
    const sortableProperties = useMemo(() => getSortableProperties(productsData[0]), [productsData]);

    const [ products, setProducts ] = useState(productsData);
    const [ sortProperty, setSortProperty ] = useState(sortableProperties[0].property);
    const [ sortType, setSortType ] = useState(SORT_TYPE.ASCENDING);
    const [ viewMode, setViewMode ] = useState(VIEW_MODE.SEPARATE_NEW);

    useEffect(() => {
        setProducts(sortByProperty(productsData, sortProperty, sortType));
    }, [productsData, sortProperty, sortType]);

    return (
        <div>
            <CatalogHead 
                sortableProperties={sortableProperties}
                sortProperty={sortProperty}
                sortType={sortType}
                viewMode={viewMode}
                onSortPropertyChange={setSortProperty}
                onSortTypeChange={setSortType}
                onViewModeChange={setViewMode}
            />
            <CatalogBody 
                products={products}
                viewMode={viewMode}
            />
        </div>
    );
}


export const Catalog = ({ products }) => {
    if (!products || !products.length) {
        return <CatalogEmpty />;
    }
    return <CatalogItems products={products} />
}
