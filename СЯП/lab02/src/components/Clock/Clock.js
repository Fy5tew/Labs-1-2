import React from 'react';
import './Clock.css';


class Time {
    constructor({date, timezone=null, isHour12=false}) {
        this.date = date || new Date();
        this.isHour12 = isHour12;
        this.timezone = this.parseTimezone(timezone);
        this.initFormatter();
    }

    initFormatter() {
        this.formatter = Intl.DateTimeFormat('default', {
            hour: '2-digit',
            minute: '2-digit',
            second: '2-digit',
            hour12: this.isHour12,
        })
    }

    parseTimezone(timezone) {
        if (!timezone) {
            return null;
        }
        const parsed = /^(?<sign>[\+\-])(?<hours>\d*):(?<minutes>\d*)/.exec(timezone);
        if (!parsed) {
            return null;
        }
        const {sign, hours, minutes} = parsed.groups;
        return {
            sign,
            hours: +hours,
            minutes: +minutes,
            value: (+hours * 60 * 60 * 1000) + (+minutes * 60 * 1000),
            calc(milliseconds) {
                return this.sign == '+'
                    ? milliseconds + this.value
                    : milliseconds - this.value;
            },
        }
    }

    getTimezoneDate() {
        const UTCDate = new Date(this.date.getTime() + this.date.getTimezoneOffset() * 60000);
        if (!this.timezone) {
            return UTCDate;
        }
        const timezoneDate = new Date(this.timezone.calc(UTCDate.getTime()));
        return timezoneDate;
    }

    format() {
        const date = (!this.timezone) ? this.date : this.getTimezoneDate();
        return this.formatter.format(date);
    }
}


class Clock extends React.Component {
    constructor(props) {
        super(props);
        this.state = {date: new Date()};
    }

    tick() {
        this.setState({
            date: new Date()
        });
    }

    formatTime() {
        const time = new Time({
            date: this.state.date,
            timezone: this.props.timezone,
            isHour12: (this.props.format == '12'),
        });
        const [hours, minutes, rest] = time.format().split(':');
        const [seconds, info] = rest.split(' ');
        return (
            <>
                <span className="clock__hours">{hours}</span>
                <span className="clock__dots">:</span>
                <span className="clock__minutes">{minutes}</span>
                <span className="clock__dots">:</span>
                <span className="clock__seconds">{seconds}</span>
                <span className="clock__info">{info}</span>
            </>
        );
    }

    componentDidMount() {
        this.timerId = setInterval(
            () => this.tick(), 
            1000
        );
    }

    componentWillUnmount() {
        clearInterval(this.timerId);
    }

    render() {
        return (
            <div className="clock">
                {this.formatTime()}
            </div>
        );
    }
}


export default Clock;
