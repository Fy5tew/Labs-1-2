import { createSlice } from '@reduxjs/toolkit';


export const notesSlice = createSlice({
    name: 'notes',
    initialState: {
        notes: [],
    },
    reducers: {
        addNote: (state, action) => {
            state.notes.push(action.payload);
        },
        deleteNoteById: (state, action) => {
            state.notes.splice(action.payload, 1);
        },
    },
});


export const actions = {
    ...notesSlice.actions,
    getNotes: (state) => state.notes.notes,
    getNoteById: (state, id) => state.notes.notes[id],
};


export default notesSlice.reducer;
