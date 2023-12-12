import { configureStore } from '@reduxjs/toolkit';

import studentInfoReducer from '../features/studentInfo/studentInfoSlice';
import notesReducer from '../features/notes/notesSlice';


export const store = configureStore({
  reducer: {
    studentInfo: studentInfoReducer,
    notes: notesReducer,
  },
});


store.subscribe(() => console.log("STATE HAS BEEN CHANGED", store.getState()));

console.log("INITIAL STATE", store.getState());
