import { createSlice } from "@reduxjs/toolkit";


const schedulerSlice = createSlice({
    name: "scheduler",
    initialState: {},
    reducers: {
        createNote: (state, action) => {
            const { key, note } = action.payload; 

            if (!state[key]) {
                state[key] = [];
            }

            state[key].push(note);
        },
        updateNote: (state, action) => {
            const { key, noteId, newNote } = action.payload;

            if (!state[key] || !state[key].length) {
                return;
            }

            state[key][noteId] = newNote;
        },
        deleteNote: (state, action) => {
            const { key, noteId } = action.payload;

            if (!state[key] || !state[key].length) {
                return;
            }
            
            state[key].splice(noteId, 1);
        },
        clearNotes: (state, action) => {
            const { key } = action.payload;

            state[key] = [];
        },
        clearAllNotes: (state) => {
            for (const key of Object.keys(state)) {
                state[key] = [];
            }
        }
    }
})


export const actions = {
    ...schedulerSlice.actions,
    getNonEmptyKeys: () => state => Object.keys(state.scheduler).filter((key) => state.scheduler[key].length),
    getNotes: (key) => (state) => state.scheduler[key] || [],
};


export default schedulerSlice.reducer;
