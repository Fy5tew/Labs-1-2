import PropTypes from 'prop-types';
import Input from './Input';


function RadioInput({id, values, settedValue, setValue, label=''}) {
    return (
        <div className="sign-up-form__radio-input">
            <label htmlFor={id}>{label}</label>
            {
                values.map(value => <Input 
                                        key={value.data.toString()} 
                                        type="radio" 
                                        id={value.data.toString()} 
                                        name={id}
                                        label={value.title} 
                                        value={value.data} 
                                        setValue={setValue} 
                                    />)
            }
        </div>
    )
}


RadioInput.propTypes = {
    id: PropTypes.string.isRequired,
    values: PropTypes.arrayOf(PropTypes.object).isRequired,
    settedValue: PropTypes.oneOfType([PropTypes.string, PropTypes.symbol]).isRequired,
    setValue: PropTypes.func.isRequired,
    label: PropTypes.string,
};


export default RadioInput;
