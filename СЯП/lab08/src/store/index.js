import { configureStore } from '@reduxjs/toolkit';
import commentsReducer from '@store/comments/comments.slice';


export const store = configureStore({
  reducer: {
    comments: commentsReducer,
  },
});


export const unsubscribe = store.subscribe(() => console.log("STORE UPDATE", store.getState()));
