import { useState } from "react";

import { clsx } from "@utils/clsx";
import { useInput } from "@utils/useInput";

import { AvatarSelect } from "./AvatarSelect";

import styles from "./CommentAdd.module.css";


export const CommentAdd = ({avatars, onAdd}) => {
    const username = useInput("");
    const email = useInput("");
    const text = useInput("");
    const secretWord = useInput("");
    const [avatarSrc, setAvatarSrc] = useState(avatars.guest.src);


    const handleAvatarSelect = (avatarSelection) => setAvatarSrc(avatarSelection);

    const handleSubmit = () => {
        onAdd({
            username: username.value,
            email: email.value,
            text: text.value,
            secretWord: secretWord.value,
            avatar: avatarSrc,
        });
        username.clear();
        email.clear();
        text.clear();
        secretWord.clear();
        setAvatarSrc(avatars.guest.src);
    }

    const canSubmit = username.value && email.value && text.value && secretWord.value && avatarSrc;

    return (
        <div className={clsx("d-flex", "flex-column", "gap-2", "p-4", "bg-secondary-subtle", "rounded-5", "border", "border-secondary")}>
            <h4 className={clsx("text-secondary")}>Добавление комментария</h4>
            <div className={clsx("d-flex", "align-items-center", "gap-2")}>
                <p className={clsx("mb-0")}>Аватарка: </p>
                <div className={clsx(styles.imageWrapper)}>
                    <img className={clsx(styles.image)} src={avatarSrc} alt="" />
                </div>
                <AvatarSelect avatars={avatars} selected={avatarSrc} onSelect={handleAvatarSelect} />
            </div>
            <input className={clsx("form-control")} placeholder="Никнейм" {...username.bind} />
            <input className={clsx("form-control")} type="email" placeholder="Email" {...email.bind} />
            <input className={clsx("form-control")} placeholder="Секретное слово" {...secretWord.bind} />
            <textarea className={clsx(styles.textarea, "form-control")} placeholder="Текст комментария" {...text.bind} />
            <button className={clsx("btn", "btn-primary")} onClick={handleSubmit} disabled={!canSubmit}>Опубликовать</button>
        </div>
    );
}
