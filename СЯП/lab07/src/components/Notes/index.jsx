import { useState } from 'react';

import './style.css';


const Notes = ({notes, onInput, onEdit, onDelete, onClear}) => {
    return (
        <div className="notes">
            <NotesInput
                inputNote={onInput}
            />
            <NotesList
                notes={notes}
                editNote={onEdit}
                deleteNote={onDelete}
                clearNotes={onClear}
            />
        </div>
    );
}


const NotesInput = ({inputNote}) => {
    const [title, setTitle] = useState('');
    const [text, setText] = useState('');

    const clearForm = () => {
        setTitle('');
        setText('');
    }

    const inputHandler = (event) => {
        event.preventDefault();
        inputNote({
            title: title,
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
                        disabled={!(title && text)}
                    />
                    <input
                        className="notes__input-controlls-button"
                        type="reset"
                        value="Сбросить"
                        disabled={!title && !text}
                    />
                </div>
            </form>
        </div>
    );
}


const NotesList = ({notes, editNote, deleteNote, clearNotes}) => {
    const renderedNotes = notes.map((note, id) => <Note key={id}
                                                title={note.title} 
                                                text={note.text} 
                                                overflow={id > 6}
                                                onEdit={(newNote) => editNote(id, newNote)}
                                                onDelete={() => deleteNote(id)}
                                            />
    );

    if (!notes.length) {
        renderedNotes.push(<h4 key="no-notes" className="notes__list-alert">Вы пока не создали ни одной заметки</h4>);
    }
    if (notes.length > 0) {
        renderedNotes.unshift(
            <div key="controlls" className="notes__list-controlls">
                <button
                    className="notes__list-controlls-button"
                    onClick={() => clearNotes()}
                >
                    Удалить все заметки
                </button>
            </div>
        );
    }

    return (
        <div className="notes__list">
            <div className="notes__list-content">
                {renderedNotes}
            </div>
        </div>
    );
}


const Note = ({title, text, onEdit, onDelete}) => {
    const [isEdit, setEdit] = useState(false)

    const handleEditStart = () => {
        setEdit(true);
    }

    const handleEditSubmit = (newNote) => {
        onEdit(newNote);
        setEdit(false);
    }

    const handleDelete = () => {
        onDelete();
    }

    if (isEdit) {
        return (
            <NoteEdit 
                title={title}
                text={text}
                onEditSubmit={handleEditSubmit}
            />
        );
    }

    return (
        <NoteView
            title={title}
            text={text}
            onEdit={handleEditStart}
            onDelete={handleDelete}
        />
    );
}


const NoteView = ({title, text, onEdit, onDelete}) => {
    return (
        <div className={'notes__note notes__note-view'}>
            <p className="notes__note-field note-title">
                {title}
            </p>
            <p className="notes__note-field note-text">
                {text}
            </p>
            <button 
                className="notes__note-control-button"
                onClick={onDelete}
            >
            🗙
            </button>
            <button 
                className="notes__note-control-button"
                onClick={onEdit}
            >
            ✎
            </button>
        </div>
    );
}


const NoteEdit = ({title, text, onEditSubmit}) => {
    const [titleInput, setTitleInput] = useState(title);
    const [textInput, setTextInput] = useState(text);

    const handleTitleInput = (event) => setTitleInput(event.target.value);
    const handleTextInput = (event) => setTextInput(event.target.value);

    return (
        <div className={'notes__note notes__note-edit'}>
            <textarea 
                className="notes__note-field note-title" 
                value={titleInput}
                onInput={handleTitleInput}
            ></textarea>
            <textarea 
                className="notes__note-field note-text"
                value={textInput}
                onInput={handleTextInput}
            ></textarea>
            <button 
                className="notes__note-control-button"
                onClick={() => onEditSubmit({title: titleInput, text: textInput})}
            >
            ✓
            </button>
        </div>
    );
}


export default Notes;
