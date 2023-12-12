import { clsx } from "@utils/clsx";

import { Comments } from "@components/Comments";

import { avatars } from "../../avatars";

import styles from "./App.module.css";


export const App = (props) => {
    return (
        <div className={clsx("container", "p-5", styles.App)}>
            <h1 className="mb-5">Лабораторная работа №8</h1>
            <Comments avatars={avatars} />
        </div>
    );
}
