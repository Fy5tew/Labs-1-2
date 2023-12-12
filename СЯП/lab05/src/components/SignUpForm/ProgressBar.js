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


export default ProgressBar;
