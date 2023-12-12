import { createSlice } from "@reduxjs/toolkit";
import { products } from "./products.data";


export const productsSlice = createSlice({
    name: "products",
    initialState: products,
    reducers: {

    },
});


export const actions = {
    ...productsSlice.actions,
    getProducts: (state) => state.products,
};


export const productsReducer = productsSlice.reducer;
