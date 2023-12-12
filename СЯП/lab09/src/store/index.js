import { configureStore } from '@reduxjs/toolkit';
import { productsReducer } from './products/products.slice';


export const store = configureStore({
  reducer: {
    products: productsReducer,
  },
});


export const unsubscribe = store.subscribe(() => console.log("STORE UPDATE", store.getState()));
