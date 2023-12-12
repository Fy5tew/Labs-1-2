import React from 'react';

import CalendarHead from './CalendarHead.js';
import CalendarBody from './CalendarBody.js';

import './Calendar.css';


class Calendar extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            currentDate: new Date(),
            selectedDate: null,
        };
        this.setCurrentDate = this.setCurrentDate.bind(this);
        this.setSelectedDate = this.setSelectedDate.bind(this);
    }

    setCurrentDate(date) {
        this.setState({
            currentDate: date,
        });
    }

    setSelectedDate(date) {
        this.setState({
            selectedDate: date
        });
    }

    render() {
        return (
            <div className="calendar-wrapper">
                <div className="calendar">
                    <CalendarHead
                        currentDate={this.state.currentDate}
                        onCurrentDateUpdate={this.setCurrentDate}
                     />
                    <CalendarBody 
                        currentDate={this.state.currentDate}
                        selectedDate={this.state.selectedDate}
                        onSelectedDateUpdate={this.setSelectedDate}
                    />
                </div>
            </div>
        );
    }
}


export default Calendar;
