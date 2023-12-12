import { useState } from "react";

import { clsx } from "@utils/clsx";

import styles from "./CommentEdit.module.css";


export const CommentEdit = ({text, onEdit, onClose}) => {
    const [editedText, setEditedText] = useState(text);

    const handleInput = (event) => setEditedText(event.target.value);
    const handleSubmit = () => {
        onClose();
        if (editedText !== text) {
            onEdit(editedText);
        }
    };

    return (
        <div className={clsx("position-relative", "d-flex", "flex-column", "gap-3", "p-3", "rounded-5", "border", "border-secondary", "bg-secondary-subtle")}>
            <h5 className={clsx("text-secondary")}>Редактирование комментария</h5>
            <textarea className={clsx(styles.textInput, "form-control")} value={editedText} onChange={handleInput} />
            <button className={clsx("btn", "btn-success")} onClick={handleSubmit} >
                Сохранить
            </button>
            <button className={clsx("btn", "btn-outline-danger", "position-absolute", "top-0", "end-0", "m-3")} onClick={onClose} >
                ❌
            </button>
        </div>
    );
}
