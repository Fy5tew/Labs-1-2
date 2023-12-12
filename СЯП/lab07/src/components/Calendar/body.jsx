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


function CalendarBody({currentDate, selectedDate, isFullSelected, daysWithNotes, onPartialSelectDate, onFullSelectDate}) {
    const monthDays = getAllMonthDaysDates(currentDate);
    const allDays = appendOtherMonthsDays(monthDays);

    const isPartialSelectedDate = (date) => selectedDate ? date.toLocaleDateString() === selectedDate.toLocaleDateString() : false;
    const isFullSelectedDate = (date) => isPartialSelectedDate(date) && isFullSelected;

    return (
        <div className="calendar__body">
            {
                allDays.map(date => <DayCell key={`${date.getDate()}.${date.getMonth()}.${date.getFullYear()}`} 
                                        date={new Date(date)} 
                                        isPartialSelected={isPartialSelectedDate(date)} 
                                        isFullSelected={isFullSelectedDate(date)}
                                        disabled={date.getMonth() !== currentDate.getMonth()}
                                        current={date.toLocaleDateString() === new Date().toLocaleDateString()}
                                        hasNotes={daysWithNotes.includes(date.toLocaleDateString())}
                                        onPartialSelect={onPartialSelectDate}
                                        onFullSelect={onFullSelectDate}
                                    />)
            }
        </div>
    );
}


function DayCell({date, isPartialSelected, isFullSelected, disabled, current, hasNotes, onPartialSelect, onFullSelect}) {
    if (disabled) {
        return (
            <div className="calendar__day-cell disabled">
                {date.getDate()}
            </div>
        );
    }

    const handleClick = () => {
        if (isPartialSelected && !isFullSelected) {
            onFullSelect(date);
        }
        else if (!isPartialSelected) {
            onPartialSelect(date);
            onFullSelect(null);
        }
    }

    const classes = ['calendar__day-cell'];
    if (isFullSelected) {
        classes.push('full-selected');
    }
    if (isPartialSelected) {
        classes.push('partial-selected');
    }
    if (current) {
        classes.push('current');
    }
    if (hasNotes) {
        classes.push('has-notes');
    }
    return (
        <div className={classes.join(' ')} onClick={handleClick}>
            {date.getDate()}
        </div>
    );
}


export default CalendarBody;
