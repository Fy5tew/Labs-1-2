import PropTypes from 'prop-types';


function ProgressBar({value, maxValue=100, label=''}) {
    return (
        <div className="sign-up-form__progress-bar-wrapper">
            <label>{label}</label>
            <progress
                className="sign-up-form__progress-bar"
                value={value}
                max={maxValue}
            />
        </div>
    );
}


ProgressBar.propTypes = {
    value: PropTypes.number.isRequired,
    maxValue: PropTypes.number,
    label: PropTypes.string,
}


export default ProgressBar;
