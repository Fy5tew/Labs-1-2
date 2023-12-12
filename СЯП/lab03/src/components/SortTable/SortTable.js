import React from 'react';

import './SortTable.css';


const LABELS = ['№', 'Name', 'Price', 'In Stock'];
const ASCENDING_ARROW = '↑';
const DESCENDING_ARROW = '↓';


const SortType = Object.freeze({
   DEFAULT: Symbol('default'),
   NAME_ASCENDING: Symbol('name_ascending'),
   NAME_DESCENDING: Symbol('name_descending'),
   PRICE_ASCENDING: Symbol('price_ascending'),
   PRICE_DESCENDING: Symbol('price_descending'),
   IN_STOCK_ASCENDING: Symbol('in_stock_ascending'),
   IN_STOCK_DESCENDING: Symbol('in_stock_descending'),
})


function asc_or_desc(selectedSortType, ascSortType, descSortType) {
    return selectedSortType === ascSortType ? descSortType : ascSortType; 
}


function sortByType(data, sortType) {
    switch (sortType) {
    case SortType.NAME_ASCENDING:
        return data.sort((lhs, rhs) => lhs.name > rhs.name ? 1 : -1);
    case SortType.NAME_DESCENDING:
        return data.sort((lhs, rhs) => lhs.name < rhs.name ? 1 : -1);
    case SortType.PRICE_ASCENDING:
        return data.sort((lhs, rhs) => lhs.price > rhs.price ? 1 : -1);
    case SortType.PRICE_DESCENDING:
        return data.sort((lhs, rhs) => lhs.price < rhs.price ? 1 : -1);
    case SortType.IN_STOCK_ASCENDING:
        return data.sort((lhs, rhs) => lhs.inStock > rhs.inStock ? 1 : -1);
    case SortType.IN_STOCK_DESCENDING:
        return data.sort((lhs, rhs) => lhs.inStock < rhs.inStock ? 1 : -1);
    default:
        return data;
    }
}


class SortTable extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            sortType: SortType.DEFAULT,
            sortedData: [...this.props.data],
        };
        this.changeSortType = this.changeSortType.bind(this);
    }

    changeSortType(sortType) {
        this.setState((prevState, props) => {
            const sortedData = sortByType([...props.data], sortType);
            return {
                sortType: sortType,
                sortedData: sortedData,
            };
        });
    }

    render() {
        return (
            <div className="sort-table-wrapper">
                <table className="sort-table">
                    <SortTableHead 
                        selectedSortType={this.state.sortType}
                        onSortTypeChange={this.changeSortType}
                    />
                    <SortTableBody data={this.state.sortedData} />
                </table>
            </div>
        );
    }
}


function SortTableHead({selectedSortType, onSortTypeChange}) {
    let [no_label, name_label, price_label, in_stock_label] = LABELS;
    let name_arrow, price_arrow, in_stock_arrow;
    switch (selectedSortType) {
    case SortType.NAME_ASCENDING:
        name_arrow = ASCENDING_ARROW;
        break;
    case SortType.NAME_DESCENDING:
        name_arrow = DESCENDING_ARROW;
        break;
    case SortType.PRICE_ASCENDING:
        price_arrow = ASCENDING_ARROW;
        break;
    case SortType.PRICE_DESCENDING:
        price_arrow = DESCENDING_ARROW;
        break;
    case SortType.IN_STOCK_ASCENDING:
        in_stock_arrow = ASCENDING_ARROW;
        break;
    case SortType.IN_STOCK_DESCENDING:
        in_stock_arrow = DESCENDING_ARROW;
        break;
    }
    return (
        <thead className="sort-table__head">
            <tr className="sort-table__row">
                <th className="sort-table__title" onClick={() => onSortTypeChange(SortType.DEFAULT)}>
                    {no_label}
                </th>
                <th className="sort-table__title" 
                    onClick={() => onSortTypeChange(asc_or_desc(selectedSortType, SortType.NAME_ASCENDING, SortType.NAME_DESCENDING))}
                >
                    {name_label}
                    <span className="sort-table__arrow">{name_arrow}</span>
                </th>
                <th className="sort-table__title" onClick={() => onSortTypeChange(asc_or_desc(selectedSortType, SortType.PRICE_ASCENDING, SortType.PRICE_DESCENDING))}>
                    {price_label}
                    <span className="sort-table__arrow">{price_arrow}</span>
                </th>
                <th className="sort-table__title" onClick={() => onSortTypeChange(asc_or_desc(selectedSortType, SortType.IN_STOCK_ASCENDING, SortType.IN_STOCK_DESCENDING))}>
                    {in_stock_label}
                    <span className="sort-table__arrow">{in_stock_arrow}</span>
                </th>
            </tr>
        </thead>
    );
}


function SortTableBody({data}) {
    return (
        <tbody className="sort-table__body">
            {data.map((product, i) => <SortTableRow key={product.name} rowNumber={i+1} product={product} />)}
        </tbody>
    );
}


function SortTableRow({rowNumber, product}) {
    const classes = ['sort-table__row'];
    if (product.inStock == 0) {
        classes.push('red');
    }
    else if (product.inStock < 3) {
        classes.push('yellow');
    }
    return (
        <tr className={classes.join(' ')}>
            <td className="sort-table__data">
                {rowNumber}
            </td>
            <td className="sort-table__data">
                {
                    product.name
                        .split(' ')
                        .map(word => word[0].toUpperCase() + word.slice(1))
                        .join(' ')
                }
            </td>
            <td className="sort-table__data">
                ${product.price}
            </td>
            <td className="sort-table__data">
                {product.inStock}
            </td>
        </tr>
    );
}


export default SortTable;
