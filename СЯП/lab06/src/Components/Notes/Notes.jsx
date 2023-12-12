import { useState } from 'react';
import { useSelector, useDispatch } from 'react-redux';

import { actions } from '../../features/notes/notesSlice';

import './Notes.css';


function Notes() {
    const dispatch = useDispatch();

    const notes = useSelector(actions.getNotes);

    return (
        <div className="notes">
            <NotesInput
                inputNote={(note) => dispatch(actions.addNote(note))}
            />
            <NotesList
                notes={notes}
                deleteNote={(id) => dispatch(actions.deleteNoteById(id))}
            />
        </div>
    );
}


function NotesInput({inputNote}) {
    const [title, setTitle] = useState('');
    const [date, setDate] = useState('');
    const [text, setText] = useState('');

    const clearForm = () => {
        setTitle('');
        setDate('');
        setText('');
    }

    const inputHandler = (event) => {
        event.preventDefault();
        inputNote({
            title: title,
            date: date,
            text: text,
        });
        clearForm();
    }

    return (
        <div className="notes__input">
            <form 
                className="notes__input-form"
                onSubmit={inputHandler}
                onReset={clearForm} 
            >
                <input
                    className="notes__input-field"
                    type="text"
                    placeholder="Заголовок"
                    required
                    value={title}
                    onChange={(event) => setTitle(event.target.value)}
                />
                <input
                    className="notes__input-field"
                    type="date"
                    required
                    value={date}
                    onChange={(event) => setDate(event.target.value)}
                />
                <textarea 
                    className="notes__input-area"
                    required
                    value={text}
                    onChange={(event) => setText(event.target.value)}
                />
                <div className="notes__input-controlls">
                    <input
                        className="notes__input-controlls-button"
                        type="submit"
                        value="Добавить заметку"
                        disabled={!(title && date && text)}
                    />
                    <input
                        className="notes__input-controlls-button"
                        type="reset"
                        value="Сбросить"
                        disabled={!title && !date && !text}
                    />
                </div>
            </form>
        </div>
    );
}


function NotesList({notes, deleteNote}) {
    const renderedNotes = notes.map((note, id) => <Note key={id}
                                                title={note.title} 
                                                date={note.date} 
                                                text={note.text} 
                                                overflow={id > 6}
                                                onDelete={() => deleteNote(id)} 
                                            />
    );

    if (!notes.length) {
        renderedNotes.push(<h4 key="no-notes" className="notes__list-alert">Вы пока не создали ни одной заметки</h4>);
    }
    if (notes.length > 3) {
        renderedNotes.unshift(
            <div key="controlls" className="notes__list-controlls">
                <button
                    className="notes__list-controlls-button"
                    onClick={() => deleteNote(0)}
                >
                    Удалить первую заметку
                </button>
                <button
                    className="notes__list-controlls-button"
                    onClick={() => deleteNote(notes.length - 1)}
                >
                    Удалить последнюю заметку
                </button>
            </div>
        );
    }
    if (notes.length > 7) {
        renderedNotes.splice(8, 0, <h4 key="to-many-notes" className="notes__list-alert">У вас слишком много заметок</h4>);
    }

    return (
        <div className="notes__list">
            <div className="notes__list-content">
                {renderedNotes}
            </div>
        </div>
    );
}


function Note({title, date, text, onDelete, overflow=false}) {
    return (
        <div className={['notes__note', overflow? 'overflow' : ''].join(' ')}>
            <p className="notes__note-field note-title">
                {title}
            </p>
            <p className="notes__note-field note-date">
                {date}
            </p>
            <p className="notes__note-field note-text">
                {text}
            </p>
            <button 
                className="notes__note-delete-button"
                onClick={onDelete}
            >
            X
            </button>
        </div>
    );
}


export default Notes;
