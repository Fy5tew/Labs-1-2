import { clsx } from "@utils/clsx";

import styles from "./CommentInfo.module.css";


export const CommentInfo = ({username, email, editedDate, onClose}) => {
    return (
        <div className={clsx("position-relative", "p-3", "rounded-5", "border", "border-secondary", "bg-secondary-subtle")}>
            <h5 className={clsx("text-secondary")}>Дополнительная информация</h5>
            <p>Автор: {username}</p>
            <p>Email: {email}</p>
            {editedDate !== null
                ? <p>Дата изменения: {editedDate}</p>
                : <p>Сообщение не редактировалось</p>
            }
            <button className={clsx("btn", "btn-outline-danger", "position-absolute", "top-0", "end-0", "m-3")} onClick={onClose} >
                ❌
            </button>
        </div>
    );
}
