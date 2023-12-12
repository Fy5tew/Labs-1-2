import { useState } from "react";

import { clsx } from "@utils/clsx";

import { CommentInfo } from "@components/CommentInfo";
import { CommentEdit } from "@components/CommentEdit";
import { CommentDelete } from "@components/CommentDelete";

import styles from "./Comment.module.css";


const OPENED_STATE = Object.freeze({
    NONE: Symbol("none"),
    INFO: Symbol("info"),
    EDIT: Symbol("edit"),
    DELETE: Symbol("delete"),
});


export const Comment = ({
    username,
    avatar,
    email,
    text,
    secretWord,
    addedDate,
    editedDate,
    onEdit,
    onDelete,
}) => {
    const [opened, setOpened] = useState(OPENED_STATE.NONE);

    const isInfo = opened === OPENED_STATE.INFO;
    const isEdit = opened === OPENED_STATE.EDIT;
    const isDelete = opened === OPENED_STATE.DELETE;

    const toggle = (open_state) => () => setOpened(prev => prev !== open_state ? open_state : OPENED_STATE.NONE);
    const close = () => setOpened(OPENED_STATE.NONE);

    return (
        <div>
            <div className={clsx("d-flex", "flex-column", "gap-2", "p-4", "bg-secondary-subtle", "rounded-5", "border", "border-secondary")}>
                <div className={clsx("d-flex", "align-items-center", "gap-2")}>
                    <div className={styles.imageWrapper}>
                        <img className={styles.image} src={avatar} alt={avatar.name} />
                    </div>
                    <p className={clsx("mb-0", "text-info-emphasis")}>
                        {username}
                    </p>
                    <p className={clsx("mb-0", "text-info-emphasis")}>
                        {addedDate}
                    </p>
                </div>
                <div>
                    <p className={clsx("text-start", "mb-0", "text-secondary-emphasis")}>
                        {text}
                    </p>
                </div>
                <div className={clsx("d-flex", "gap-1", "justify-content-end")}>
                    <button className={clsx("btn", isInfo? "btn-info" : "btn-outline-info")} onClick={toggle(OPENED_STATE.INFO)} >
                        ℹ️
                    </button>
                    <button className={clsx("btn", isEdit? "btn-warning" : "btn-outline-warning")} onClick={toggle(OPENED_STATE.EDIT)} >
                        ✏️
                    </button>
                    <button className={clsx("btn", isDelete? "btn-danger" : "btn-outline-danger")} onClick={toggle(OPENED_STATE.DELETE)} >
                        🗑️
                    </button>
                </div>
            </div>
            {isInfo && <CommentInfo username={username} email={email} editedDate={editedDate} onClose={close} />}
            {isEdit && <CommentEdit text={text} onEdit={onEdit} onClose={close} />}
            {isDelete && <CommentDelete secretWord={secretWord} onDelete={onDelete} onClose={close} />}
        </div>
    );
}
