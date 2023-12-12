import React, { useState } from 'react';

import CalendarHead from './head.jsx';
import CalendarBody from './body.jsx';

import './index.css';


const Calendar = ({selectedDate, setSelectedDate, daysWithNotes}) => {
    const [currentDate, setCurrentDate] = useState(new Date());
    const [partialSelectedDate, setPartialSelectedDate] = useState(selectedDate);

    return (
        <div className="calendar-wrapper">
            <div className="calendar">
                <CalendarHead
                    currentDate={currentDate}
                    onCurrentDateUpdate={setCurrentDate}
                />
                <CalendarBody 
                    currentDate={currentDate}
                    selectedDate={partialSelectedDate}
                    isFullSelected={selectedDate && partialSelectedDate.toLocaleDateString() === selectedDate.toLocaleDateString()}
                    daysWithNotes={daysWithNotes}
                    onPartialSelectDate={setPartialSelectedDate}
                    onFullSelectDate={setSelectedDate}
                />
            </div>
        </div>
    );
}


export default Calendar;
