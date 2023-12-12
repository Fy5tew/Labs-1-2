import PhoneInput from './components/PhoneInput/PhoneInput';
import SortTable from './components/SortTable/SortTable';

import products from './products.data.js'

import './App.css';


function App() {
  return (
    <div className="App">
      <h1>Лабораторная работа №3</h1>
      <h2>Задание №1</h2>
      <PhoneInput />
      <h2>Задание №2</h2>
      <SortTable data={products} />
    </div>
  );
}


export default App;
