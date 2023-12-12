import StudentInfo from './Components/StudentInfo/StudentInfo';
import StudentInfoHandler from './Components/StudentInfoHandler/StudentInfoHandler';
import Notes from './Components/Notes/Notes';

import './App.css';


function App() {
  return (
    <div className="App">
      <h1>Лабораторная работа №6</h1>
      <h2>Задание №1</h2>
      <StudentInfo />
      <StudentInfoHandler />
      <h2>Задание №2</h2>
      <Notes />
    </div>
  );
}


export default App;
