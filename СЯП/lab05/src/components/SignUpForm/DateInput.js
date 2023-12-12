import React from 'react';

import SelectInput from './SelectInput';


const ZERO_YEAR = '0';
const ZERO_MONTH = '0';
const ZERO_DAY = '0';
const DEFAULT_START_YEAR = 1900;


function getYears(startYear, endYear) {
    if (!startYear) {
        startYear = DEFAULT_START_YEAR;
    }
    if (!endYear) {
        endYear = new Date().getFullYear();
    }
    endYear += 1;
    return Array.from({length: endYear - startYear}, (_, i) => (startYear + i).toString());
}


function getMonths() {
    return (Array.from({length: 12}, (_, i) => (1 + i).toString())
            .map(v => v.length == 1 ? `0${v}` : v));
}


function getDays(year, month) {
    return (Array.from({length: new Date(year, month, 0).getDate()}, (_, i) => (1 + i).toString())
            .map(v => v.length == 1 ? `0${v}` : v));
}


class DateInput extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            year: ZERO_YEAR, 
            month: ZERO_MONTH,
            day: ZERO_DAY,
        }

        this.setYear = this.setYear.bind(this);
        this.setMonth = this.setMonth.bind(this);
        this.setDay = this.setDay.bind(this);
        this.setValue = this.setValue.bind(this);
    }

    setYear(year) {
        this.setState({year}, this.setValue);
    }

    setMonth(month) {
        this.setState({month}, this.setValue);
    }

    setDay(day) {
        this.setState({day}, this.setValue);
    }

    setValue() {
        const {year, month, day} = this.state;
        if (!(year === ZERO_YEAR || month === ZERO_MONTH || day === ZERO_DAY)) {
            this.props.setValue(new Date(+year, +month - 1, +day))
        }
    }

    render() {
        return (
            <div className="sign-up-form__date-input">
                <label>{this.props.label}</label>
                <div>
                    <SelectInput 
                        placeholder="Год"
                        values={getYears(this.props.startYear, this.props.endYear)} 
                        selectedValue={this.state.year} 
                        setValue={this.setYear} 
                    />
                    <SelectInput
                        placeholder="Месяц"
                        values={getMonths()}
                        selectedValue={this.state.month}
                        setValue={this.setMonth}
                        disabled={this.state.year === ZERO_YEAR}
                    />
                    <SelectInput
                        placeholder="День"
                        values={getDays(+this.state.year, +this.state.month)}
                        selectedValue={this.state.day}
                        setValue={this.setDay}
                        disabled={this.year === ZERO_YEAR || this.state.month === ZERO_MONTH}
                    />
                </div>
            </div>
        );
    }
}


export default DateInput;
