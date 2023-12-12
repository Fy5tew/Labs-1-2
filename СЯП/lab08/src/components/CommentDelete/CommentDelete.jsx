import { useState } from "react";

import { clsx } from "@utils/clsx";

import styles from "./CommentDelete.module.css";


export const CommentDelete = ({secretWord, onDelete, onClose}) => {
    const [inputWord, setInputWord] = useState("");
    const [isWarning, setWarning] = useState(false);

    const handleInput = (event) => {
        setInputWord(event.target.value);
        setWarning(false);
    }
    const handleSubmit = () => {
        if (inputWord === secretWord) {
            onClose();
            onDelete();
        }
        else {
            setWarning(true);
        }
    }

    return (
        <div className={clsx("position-relative", "d-flex", "flex-column", "gap-3", "p-3", "rounded-5", "border", "border-secondary", "bg-secondary-subtle")}>
            <h5 className={clsx("text-secondary")}>Удаление комментария</h5>
            <input className={clsx("form-control")} value={inputWord} placeholder="Введите секретное слово" onChange={handleInput} />
            {isWarning && <p className={clsx("mb-0", "alert", "alert-danger")}>Вы ввели неверное секретное слово</p>}
            <button className={clsx("btn", "btn-danger")} onClick={handleSubmit} >
                Удалить
            </button>
            <button className={clsx("btn", "btn-outline-danger", "position-absolute", "top-0", "end-0", "m-3")} onClick={onClose} >
                ❌
            </button>
        </div>
    );
}
