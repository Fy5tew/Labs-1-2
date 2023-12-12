import Clock from './components/Clock/Clock';
import JobMenu from './components/JobMenu/JobMenu';
import Separator from './components/Separator/Separator';

import jobs from './jobs.data.js';

import './App.css';


function App() {
  return (
    <div className="App">
      <h1>Лабораторная работа №2</h1>
      <Separator />
      <h1>Задание №1</h1>
      <JobMenu jobs={jobs} />
      <Separator />
      <h1>Задание №2</h1>
      <Clock />
      <Clock format="24" />
      <Clock format="12" />
      <Clock timezone="+00:00" />
      <Clock timezone="+5:30" />
      <Clock format="12" timezone="+5:30" />
      <Clock timezone="-5:30" />
      <Clock format="12" timezone="-5:30" />
    </div>
  );
}


export default App;
