import { useState } from "react";

import { useSelector, useDispatch } from "react-redux";
import { actions } from "@store/comments/comments.slice";

import { clsx } from "@utils/clsx";

import { Comment } from "@components/Comment";
import { CommentAdd } from "@components/CommentAdd";

import style from "./Comments.module.css";


export const Comments = ({ avatars }) => {
    const dispatch = useDispatch();
    const comments = useSelector(actions.getComments);

    const handleCommentAdd = (comment) => {
        dispatch(actions.addComment(comment));
    }

    const handleCommentEdit = (commentId, newText) => {
        dispatch(actions.editComment({commentId, newText}));
    }

    const handleCommentDelete = (commentId) => {
        dispatch(actions.deleteComment({commentId}));
    }

    return (
        <div className={clsx("d-flex", "flex-column", "gap-4")}>
            <CommentAdd avatars={avatars} onAdd={handleCommentAdd} />
            {
                comments.map(({username, avatar, email, text, secretWord, addedDate, editedDate}, i) => 
                    <Comment key={secretWord} 
                                username={username}
                                avatar={avatar}
                                email={email}
                                text={text}
                                secretWord={secretWord}
                                addedDate={addedDate}
                                editedDate={editedDate}
                                onEdit={newText => handleCommentEdit(i, newText)}
                                onDelete={() => handleCommentDelete(i)}
                    />
                )
            }
        </div>
    );
}
