function Input({id, value, setValue=()=>{}, type='text', label='', placeholder='', name='', disabled=false,}) {
    return (
        <div className="sign-up-form__input">
            <label htmlFor={id}>{label}</label>
            <input 
                id={id}
                name={name}
                type={type}
                placeholder={placeholder}
                value={value}
                onInput={event => setValue(type != 'radio' ? event.target.value : value)}
                disabled={disabled}
             />
        </div>
    );
}


export default Input;
