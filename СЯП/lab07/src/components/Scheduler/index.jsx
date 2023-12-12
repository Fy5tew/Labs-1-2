import React, { useState } from "react";
import { useSelector, useDispatch } from "react-redux";
import { actions } from "../../features/scheduler/schedulerSlice";
import Calendar from "../Calendar";
import Notes from "../Notes";
import "./index.css";


const Scheduler = () => {
    const [selectedDate, setSelectedDate] = useState(null);
    
    const dispatch = useDispatch();

    const daysWithNotes = useSelector(actions.getNonEmptyKeys());
    const notes = useSelector(actions.getNotes(selectedDate && selectedDate.toLocaleDateString()));

    const handleNoteInput = (note) => {
        dispatch(actions.createNote({
            key: selectedDate.toLocaleDateString(),
            note: note,
        }));
    }

    const handleNoteEdit = (noteId, newNote) => {
        dispatch(actions.updateNote({
            key: selectedDate.toLocaleDateString(),
            noteId: noteId,
            newNote: newNote,
        }));
    }

    const handleNoteDeletion = (noteId) => {
        dispatch(actions.deleteNote({
            key: selectedDate.toLocaleDateString(),
            noteId: noteId,
        }));
    }

    const handleNotesClear = () => {
        dispatch(actions.clearNotes({
            key: selectedDate.toLocaleDateString(),
        }));
    }

    return (
        <div className="scheduler">
            <Calendar 
                selectedDate={selectedDate}
                setSelectedDate={setSelectedDate}
                daysWithNotes={daysWithNotes}
            />
            {
                selectedDate !== null
                &&
                <>
                    <h3>Заметки на {selectedDate.toLocaleDateString()}</h3>
                    <Notes 
                        notes={notes}
                        onInput={handleNoteInput}
                        onEdit={handleNoteEdit}
                        onDelete={handleNoteDeletion}
                        onClear={handleNotesClear}
                    />
                </>
            }
        </div>
    );
}


export default Scheduler;
