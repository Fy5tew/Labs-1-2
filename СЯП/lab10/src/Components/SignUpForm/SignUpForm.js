import React from 'react';

import Input from './Input';
import RadioInput from './RadioInput';
import DateInput from './DateInput';
import PhoneInput from './PhoneInput/PhoneInput';
import SignUpEmailInput from './SignUpEmailInput';
import SignUpPasswordInput from './SignUpPasswordInput';

import './SignUpForm.css';


const Sex = Object.freeze({
    MALE: Symbol('male'),
    FEMALE: Symbol('female'),
    UNDEFINED: Symbol('undefined'),
});


function getSexString(sex) {
    switch (sex) {
    case Sex.MALE: return "Мужской";
    case Sex.FEMALE: return "Женский";
    default: return "Неизвестно";
    }
}


class SignUpForm extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            lastName: '',
            firstName: '',
            surname: '',
            sex: Sex.UNDEFINED,
            birthDate: null,
            phoneInfo: {
                phone: '',
                country: '',
                operator: '',
            },
            email: '',
            isEmailValid: false,
            password: '',
            isPasswordValid: false,
        };

        this.setLastName = this.setLastName.bind(this);
        this.setFirstName = this.setFirstName.bind(this);
        this.setSurname = this.setSurname.bind(this);
        this.setSex = this.setSex.bind(this);
        this.setBirthDate = this.setBirthDate.bind(this);
        this.setPhone = this.setPhone.bind(this);
        this.setEmail = this.setEmail.bind(this);
        this.setIsEmailValid = this.setIsEmailValid.bind(this);
        this.setPassword = this.setPassword.bind(this);
        this.setIsPasswordValid = this.setIsPasswordValid.bind(this);
        this.sendData = this.sendData.bind(this);
    }

    setLastName(lastName) {
        this.setState({lastName});
    }

    setFirstName(firstName) {
        this.setState({firstName});
    }

    setSurname(surname) {
        this.setState({surname});
    }

    setSex(sex) {
        this.setState({sex});
    }

    setBirthDate(birthDate) {
        this.setState({birthDate});
    }

    setPhone(phone) {
        this.setState({phoneInfo: {...phone}});
    }

    setEmail(email) {
        this.setState({email});
    }

    setIsEmailValid(isEmailValid) {
        this.setState({isEmailValid});
    }

    setPassword(password) {
        this.setState({password});
    }

    setIsPasswordValid(isPasswordValid) {
        this.setState({isPasswordValid});
    }

    formatPhone() {
        const phone = this.state.phoneInfo.phone || 'Неизвестно';
        const country = this.state.phoneInfo.country || 'Неизвестно';
        const operator = this.state.phoneInfo.operator || 'Неизвестно';
        return `${phone} (${operator}, ${country})`;
    }

    sendData(event) {
        event.preventDefault();
        console.log("Отправка формы");
        console.log({
            lastName: this.state.lastName,
            firstName: this.state.firstName,
            surname: this.state.surname,
            sex: this.state.sex,
            birthDate: this.state.birthDate,
            phoneInfo: {
                phone: this.state.phoneInfo.phone,
                country: this.state.phoneInfo.country,
                operator: this.state.phoneInfo.operator,
            },
            email: this.state.email,
            password: this.state.password,
        });
    }

    render() {
        return (
            <div className="sign-up-form__wrapper">
                <form className="sign-up-form" onSubmit={this.sendData}>
                    <h3 className="sign-up-form__header">
                        Регистрация
                    </h3>
                    <Input 
                        id="input-last-name"
                        label="Фамилия:" 
                        value={this.state.lastName} 
                        setValue={this.setLastName}
                    />
                    <Input
                        id="input-first-name"
                        label="Имя:"
                        value={this.state.firstName}
                        setValue={this.setFirstName}
                    />
                    <Input
                        id="input-surname"
                        label="Отчество:"
                        value={this.state.surname}
                        setValue={this.setSurname}
                    />
                    <RadioInput 
                        id="input-sex"
                        label="Пол:"
                        values={[
                            {
                                data: Sex.MALE,
                                title: 'Мужской',
                            },
                            {
                                data: Sex.FEMALE,
                                title: 'Женский',
                            },
                        ]}
                        settedValue={this.state.sex}
                        setValue={this.setSex}
                    />
                    <DateInput
                        id="input-birth-date"
                        label="Дата рождения:"
                        value={this.state.birthDate}
                        setValue={this.setBirthDate}
                        startYear={1930}
                        endYear={2010}
                    />
                    <PhoneInput
                        setValue={this.setPhone}
                    />
                    <SignUpEmailInput
                        id="input-email"
                        label="Email:"
                        setValue={this.setEmail}
                        setValid={this.setIsEmailValid}
                    />
                    <SignUpPasswordInput
                        setValue={this.setPassword}
                        setValid={this.setIsPasswordValid}
                    />
                    <Input 
                        id="submit"
                        type="submit"
                        value="Отправить"
                        disabled={!(this.state.isEmailValid && this.state.isPasswordValid)}
                    />
                </form>
            </div>
        );
    }
}


export default SignUpForm;
