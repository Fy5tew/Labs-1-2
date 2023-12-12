import { configureStore } from '@reduxjs/toolkit';
import schedulerReducer from '../features/scheduler/schedulerSlice';


export const store = configureStore({
  reducer: {
    scheduler: schedulerReducer,
  },
});


export const unsubscribe = store.subscribe(() => console.log("STORE UPDATE", store.getState()));
