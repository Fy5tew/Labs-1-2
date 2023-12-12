import { createSlice } from "@reduxjs/toolkit";


const formatDate = (date) => `${date.toLocaleDateString()} ${date.toLocaleTimeString()}`;
const getFormattedDate = () => formatDate(new Date());


export const commentsSlice = createSlice({
    name: "comments",
    initialState: [],
    reducers: {
        addComment: (state, action) => {
            state.push({
                ...action.payload,
                editedDate: null,
                addedDate: getFormattedDate(),
            });
        },
        editComment: (state, action) => {
            const { commentId, newText } = action.payload;
            state[commentId].text = newText;
            state[commentId].editedDate = getFormattedDate();
        },
        deleteComment: (state, action) => {
            const { commentId } = action.payload;
            state.splice(commentId, 1);
        },
    },
});


export const actions = {
    ...commentsSlice.actions,
    getComments: (state) => state.comments,
};


export default commentsSlice.reducer;
