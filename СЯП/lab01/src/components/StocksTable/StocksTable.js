import './StocksTable.css';


function StocksTable(props) {
    return (
        <div className="stocks-table-wrapper">
            <table className="stocks-table">
                <StocksTableHead />
                <StocksTableBody data={props.data} />
            </table>
        </div>
    );
}


function StocksTableHead() {
    return (
        <thead>
            <tr>
                <th>Акция</th>
                <th>Компания</th>
                <th>Стоимость</th>
                <th>Изменение</th>
                <th>Валюта</th>
            </tr>
        </thead>
    );
}


function StocksTableBody(props) {
    return (
        <tbody>
            {props.data.map((stock, i) => <StocksTableRow key={i} stock={stock} />)}
        </tbody>
    );
}


function StocksTableRow(props) {
    const {stock_name: stockName, company_name: companyName, price, change, currency} = props.stock;
    const priceChangeColor = {"+": "green", "-": "red"}[change[0]];

    return (
        <tr>
            <td>{stockName}</td>
            <td>{companyName}</td>
            <td>{price}</td>
            <td className={priceChangeColor}>{change}</td>
            <td>{currency}</td>
        </tr>
    );
}


export default StocksTable;
