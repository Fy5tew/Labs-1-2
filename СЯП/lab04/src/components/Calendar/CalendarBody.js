const getFirstDayOfMonthDate = (date) => {
    const newDate = new Date(date);
    newDate.setDate(1);
    return newDate; 
}

const addDay = (date) => {
    const newDate = new Date(date);
    newDate.setDate(date.getDate() + 1);
    return newDate;
}

const removeDay = (date) => {
    const newDate = new Date(date);
    newDate.setDate(date.getDate() - 1);
    return newDate;
}

const getAllMonthDaysDates = (date) => {
    const monthDays = [];
    const firstDayDate = getFirstDayOfMonthDate(date);
    let currentDay = firstDayDate;
    while (currentDay.getMonth() === firstDayDate.getMonth()) {
        monthDays.push(currentDay);
        currentDay = addDay(currentDay);
    }
    return monthDays;
}

const appendOtherMonthsDays = (monthDays) => {
    const _monthDays = [...monthDays];
    while (_monthDays[0].getDay() !== 1) {
        _monthDays.unshift(removeDay(_monthDays[0]));
    }
    while (_monthDays.at(-1).getDay() !== 0) {
        _monthDays.push(addDay(_monthDays.at(-1)));
    }
    return _monthDays;
}


function CalendarBody({currentDate, selectedDate, onSelectedDateUpdate}) {
    const monthDays = getAllMonthDaysDates(currentDate);
    const allDays = appendOtherMonthsDays(monthDays);
    return (
        <div className="calendar__body">
            {
                allDays.map(date => <DayCell key={`${date.getDate()}.${date.getMonth()}.${date.getFullYear()}`} 
                                        date={new Date(date)} 
                                        selected={selectedDate ? date.toLocaleDateString() === selectedDate.toLocaleDateString() : false} 
                                        disabled={date.getMonth() !== currentDate.getMonth()}
                                        current={date.toLocaleDateString() === new Date().toLocaleDateString()}
                                        onSelect={onSelectedDateUpdate}
                                    />)
            }
        </div>
    );
}


function DayCell({date, selected, disabled, current, onSelect}) {
    if (disabled) {
        return (
            <div className="calendar__day-cell disabled">
                {date.getDate()}
            </div>
        );
    }
    const classes = ['calendar__day-cell'];
    if (selected) {
        classes.push('selected');
    } 
    if (current) {
        classes.push('current');
    }
    return (
        <div className={classes.join(' ')} onClick={() => onSelect(date)}>
            {date.getDate()}
        </div>
    );
}


export default CalendarBody;
