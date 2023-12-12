import { useState } from "react";


export const useInput = (initialState) => {
    const [value, setValue] = useState(initialState);

    const handleChange = (event) => setValue(event.target.value);
    const clear = () => setValue("");

    return {
        value,
        setValue,
        clear,
        bind: {
            value,
            onChange: handleChange,
        },
    };
}
