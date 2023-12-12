function SelectInput({values, selectedValue, setValue, placeholder='', disabled=false}) {
    if (!values.includes(selectedValue)) {
        selectedValue = placeholder;
    }
    return (
        <select 
            className="sign-up-form__select-input" 
            value={selectedValue}
            onInput={event => setValue(event.target.value)}
            disabled={disabled}
        >
            <option disabled>{placeholder}</option>
            {values.map(value => <option key={value} id={value} value={value}>{value}</option>)}
        </select>
    );
}


export default SelectInput;
