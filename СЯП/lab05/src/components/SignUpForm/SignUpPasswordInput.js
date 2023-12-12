import React from 'react';

import Input from './Input';
import ProgressBar from './ProgressBar';


const getPasswordSecurity = (password) => {
    let strength = 25;

    if (password.length >= 8) {
        strength += 25;
    }
    if (password.match(/([a-zA-Z])/) && password.match(/([0-9])/)) {
        strength += 25;
    }
    if (password.match(/([!,%&@#$^*?_~])/)) {
        strength += 25;
    }

    return strength;
}



class SignUpPasswordInput extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            password: '',
            passwordRepeat: '',
            isValid: false,
            passwordSecurity: 0,
        }
        this.setPassword = this.setPassword.bind(this);
        this.setPasswordRepeat = this.setPasswordRepeat.bind(this);
    }

    setValid() {
        const isValid = this.state.password && this.state.password === this.state.passwordRepeat;
        this.props.setValid(isValid);
        this.setState({isValid});
        if (isValid) {
            this.props.setValue(this.state.password);
            this.setState({passwordSecurity: getPasswordSecurity(this.state.password)});
        }
    }

    setPassword(password) {
        this.setState({password}, this.setValid);
    }

    setPasswordRepeat(passwordRepeat) {
        this.setState({passwordRepeat}, this.setValid);
    }

    render() {
        return (
            <div className="sign-up-form__password-input">
                <Input 
                    id="input-password"
                    type="password"
                    label="Пароль:"
                    value={this.state.password}
                    setValue={this.setPassword}
                />
                <Input
                    id="input-password-repeat"
                    type="password"
                    label="Повторите пароль:"
                    value={this.state.passwordRepeat}
                    setValue={this.setPasswordRepeat}
                />
                {
                    this.state.isValid ?
                        <ProgressBar
                            label="Надежность пароля:"
                            value={this.state.passwordSecurity}
                            maxValue={100}
                        />
                    : 
                        <p>Введенные пароли не совпадают</p>
                }
            </div>
        );
    }
}


export default SignUpPasswordInput;
