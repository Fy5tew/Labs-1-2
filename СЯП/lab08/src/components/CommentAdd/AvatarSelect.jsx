import { clsx } from "@utils/clsx";


const AvatarSelectOption = ({avatar}) => {
    const emoji = avatar.sex === "both" ? "⚥" : avatar.sex === "male" ? "♂️" : "♀️";
    const text = `${emoji} ${avatar.name}`;

    return (
        <option value={avatar.src}>{text}</option>
    );
}


export const AvatarSelect = ({avatars, selected, onSelect}) => {
    const handleChange = (event) => onSelect(event.target.value);
    
    const renderedAvatars = Object.keys(avatars).map(key => <AvatarSelectOption key={key} avatar={avatars[key]} />)

    return (
        <select className={clsx("form-control")} value={selected} onChange={handleChange}>
            {renderedAvatars}
        </select>
    );
}
