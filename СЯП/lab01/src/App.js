import HelloWorld from './components/HelloWorld/HelloWorld';
import StocksTable from './components/StocksTable/StocksTable';
import ChessBoard from './components/ChessBoard/ChessBoard';
import Separator from './components/Separator/Separator';

import stocks from './stocks.data.js';

import './App.css';


function App() {
  return (
    <div className="App">
      <h1>Лабораторная работа №1</h1>
      <Separator />
      <h1>Задание №1</h1>
      <HelloWorld />
      <Separator />
      <h1>Задание №2</h1>
      <StocksTable data={stocks} />
      <Separator />
      <h1>Задание №3</h1>
      <ChessBoard />
    </div>
  );
}


export default App;
