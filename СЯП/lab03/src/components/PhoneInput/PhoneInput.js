import React from 'react';
import countries from './countriesInfo.js';
import './PhoneInput.css';


const PHONE_SYMBOLS = ['+', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];


function getCountryId(number) {
    return countries.find(country => country.phone.checkRegexp.test(number))?.id || 0;
}


function getCountry(countryId) {
    return countries.find(country => country.id == countryId);
}


function getRawPhone(string) {
    return Array.from(string).filter(symbol => PHONE_SYMBOLS.includes(symbol)).join('');
}


function formatPhone(rawPhone) {
    const countryId = getCountryId(rawPhone);
    const country = getCountry(countryId);
    const parsed = country.phone.parseRegexp.exec(rawPhone);
    if (!parsed) {
        return rawPhone;
    }
    const {code, part1, part2, part3} = parsed.groups;
    const formattedPhone = country.phone.mask
        .replace('<code>', code)
        .replace('<part1>', part1)
        .replace('<part2>', part2)
        .replace('<part3>', part3);
    return normalizeFormattedPhone(formattedPhone, rawPhone);
}


function normalizeFormattedPhone(formattedPhone, rawPhone) {
    let length = 0;
    let phoneSymbolsCount = 0;
    for (let i = 0; i < formattedPhone.length; i++) {
        if (PHONE_SYMBOLS.includes(formattedPhone[i])) {
            phoneSymbolsCount++;
        }
        length++;
        if (phoneSymbolsCount == rawPhone.length) {
            break;
        }
    }
    return formattedPhone.slice(0, length);
}


class PhoneInput extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            country: getCountry(0),
            operator: null,
            rawPhone: '+',
            formattedPhone: '+',
            userEdit: false,
        }
        this.inputPhone = this.inputPhone.bind(this);
    }

    inputPhone(event) {
        this.setState((prevState) => {
            const rawPhone = event.target.value.length == 0 ? '+' : getRawPhone(event.target.value);
            const countryId = getCountryId(rawPhone);
            const country = getCountry(countryId);

            const formattedPhone = formatPhone(rawPhone);

            const userEdit = (
                                (rawPhone.length > 1 && rawPhone.length < prevState.rawPhone.length)
                                || (prevState.userEdit && rawPhone.at(-1) == prevState.rawPhone.at(-1))
                            );

            if (rawPhone.length > country.phone.rawLength) {
                return {
                    ...prevState,
                    userEdit: false,
                };
            }
            return {
                country,
                rawPhone,
                formattedPhone,
                userEdit,
                operator: prevState.operator,
            }
        });
    }

    changeCountry(countryId) {
        this.setState(prevState => {
            const country = getCountry(countryId);
            const rawPhone = country.phone.placeholder + prevState.rawPhone.slice(prevState.country.phone.placeholder.length, prevState.rawPhone.length);
            const formattedPhone = formatPhone(rawPhone);

            return {
                country,
                rawPhone: getRawPhone(formattedPhone),
                formattedPhone,
                userEdit: false,
            }
        });
    }

    changeOperator(operatorName) {
        this.setState(prevState => {
            return {
                ...prevState,
                operator: operatorName,
            }
        })
    }

    render() {
        return (
            <div className="phone-input">
                <div className="phone-input__wrapper">
                    <PhoneInputArea 
                        value={!this.state.userEdit ? this.state.formattedPhone : undefined}
                        maxLength={!this.state.userEdit ? this.state.country.phone.formatedLength : 30}
                        inputHandler={this.inputPhone}
                    />
                </div>
                <div className="phone-input__wrapper">
                    <PhoneCountryFlag icon={this.state.country.icon} />
                    <PhoneCountrySelect 
                        countries={countries} 
                        selectedId={this.state.country.id}
                        inputHandler={(event) => this.changeCountry(event.target.value)}
                    />
                </div>
                <div className="phone-input__wrapper">
                    <PhoneOperatorRadio 
                        selectedCountry={this.state.country}
                        inputHandler={(event) => this.changeOperator(event.target.value)}
                    />
                </div>
            </div>
        );
    }
}


function PhoneCountryFlag({icon}) {
    return (
        <img 
            className="phone-input__img" 
            src={icon} 
        />
    );
}


function PhoneCountrySelect({countries, selectedId, inputHandler}) {
    return (
        <select className="phone-input__country-select" value={selectedId} onInput={inputHandler}>
            {
                countries.map(
                    country => <PhoneCountrySelectOption key={country.id} country={country} />
                )
            }
        </select>
    );
}


function PhoneCountrySelectOption({country}) {
    return (
        <option value={country.id}>
            {country.name} ({country.phone.placeholder})
        </option>
    );
}


class PhoneInputArea extends React.Component {
    validateInput(event) {
        if (!PHONE_SYMBOLS.includes(event.key) || event.key == '+') {
            event.preventDefault();
        } 
    }

    render() {
        return (
            <input 
                className="phone-input__input-area"
                type="tel" 
                value={this.props.value} 
                maxLength={this.props.maxLength}
                onInput={this.props.inputHandler}
                onKeyPress={this.validateInput}
            />
        );
    }
}


function PhoneOperatorRadio({selectedCountry, inputHandler}) {
    if (!selectedCountry.operators.length) {
        return (
            <div className="phone-input__operator-radio">
                <p>Нет доступных операторов</p>
            </div>
        );
    }
    return (
        <div className="phone-input__operator-radio">
            {selectedCountry.operators.map((operator) => <PhoneOperatorRadioButton 
                                                                key={operator} 
                                                                operatorName={operator} 
                                                                inputHandler={inputHandler}
                                                                />)}
        </div>
    );
}


function PhoneOperatorRadioButton({operatorName, inputHandler}) {
    return (
        <label className="phone-input__operator-radio-label">
            <input
                className="phone-input__operator-radio-button"
                type="radio"
                name="operator"
                value={operatorName}
                onInput={inputHandler}
            />
            {operatorName}
        </label>
    );
}


export default PhoneInput;
