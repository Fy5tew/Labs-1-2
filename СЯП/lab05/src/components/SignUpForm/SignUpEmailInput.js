import React from 'react';
import Input from './Input';


const EMAIL_REGEXP = /^([a-z0-9_-]+\.)*[a-z0-9_-]+@[a-z0-9_-]+(\.[a-z0-9_-]+)*\.[a-z]{2,6}$/;


const isValidEmail = (email) => EMAIL_REGEXP.test(email);


class SignUpEmailInput extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            email: '',
        };
        this.setEmail = this.setEmail.bind(this);
    }

    setEmail(email) {
        this.setState({
            email,
        });
        this.props.setValue(email);
        this.props.setValid(isValidEmail(email));
    }

    render() {
        return (
            <div className="sign-up-form__email-input">
                <Input
                    id={this.props.id}
                    label={this.props.label}
                    value={this.state.email}
                    setValue={this.setEmail}
                />
            </div>
        );
    }
}


export default SignUpEmailInput;
