import PropTypes from 'prop-types';


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


SelectInput.propTypes = {
    values: PropTypes.arrayOf(PropTypes.string).isRequired,
    selectedValue: PropTypes.string.isRequired,
    setValue: PropTypes.func.isRequired,
    placeholder: PropTypes.string,
    disabled: PropTypes.bool,
}


export default SelectInput;
