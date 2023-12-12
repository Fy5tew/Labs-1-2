const DAY_LABELS = ['пн', 'вт', 'ср', 'чт', 'пт', 'сб', 'вс'];
const MONTHS_NAMES = ['Январь', 'Февраль', 'Март', 'Апрель', 'Май', 'Июнь', 'Июль', 'Август', 'Сентябрь', 'Октябрь', 'Ноябрь', 'Декабрь'];


const monthDecrease = (date) => {
    const newDate = new Date(date);
    newDate.setMonth(date.getMonth() - 1);
    return newDate;
}

const monthIncrease = (date) => {
    const newDate = new Date(date);
    newDate.setMonth(date.getMonth() + 1);
    return newDate;
}


function CalendarHead({currentDate, onCurrentDateUpdate}) {
    return (
        <div className="calendar__head">
            <MonthSelect 
                currentDate={currentDate} 
                onCurrentDateUpdate={onCurrentDateUpdate} 
            />
            <DayLabels />
        </div>
    );
}


function MonthSelect({currentDate, onCurrentDateUpdate}) {
    return (
        <div className="calendar__month-select">
            <p className="calendar__month-name">
                {MONTHS_NAMES[currentDate.getMonth()]} {currentDate.getFullYear()}
            </p>
            <div className="calendar__month-change-wrapper">
                <button 
                    className="calendar__month-change-button"
                    onClick={() => onCurrentDateUpdate(monthDecrease(currentDate))}
                >
                    &lt;
                </button>
                <button 
                    className="calendar__month-change-button"
                    onClick={() => onCurrentDateUpdate(monthIncrease(currentDate))}
                >
                    &gt;
                </button>
            </div>
        </div>
    );
}


function DayLabels() {
    return (
        <div className="calendar__day-labels">
            {DAY_LABELS.map((label, i) => <DayLabel key={i} text={label} />)}
        </div>
    );
}


function DayLabel({text}) {
    return (
        <div className="calendar__day-label">
            {text}
        </div>
    );
}


export default CalendarHead;
