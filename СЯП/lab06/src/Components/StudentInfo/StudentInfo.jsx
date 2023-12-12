import { useSelector, useDispatch } from 'react-redux';
import { actions } from '../../features/studentInfo/studentInfoSlice';

import './StudentInfo.css';


const PHONE_PATTERN = '^\\+?\\d{9,20}$';

const PHONE_SYMBOL_REGEXP = /^\+|\d$/;

const TEXT_SYMBOL_REGEXP = /^[A-z]|[А-я]$/


const clearArray = (array, elementRegexp) => array.filter(element => elementRegexp.test(element)); 

const clearString = (string, elementRegexp) => clearArray(Array.from(string), elementRegexp).join('');

const clearPhoneNumber = (phoneNumber) => clearString(phoneNumber, PHONE_SYMBOL_REGEXP);

const clearText = (text) => clearString(text, TEXT_SYMBOL_REGEXP);


function StudentInfo() {
    const dispatch = useDispatch();

    return (
        <div className="student-info">
            <div className="student-info__content">
                <h3
                    className="student-info__header"
                >
                    Заполение информации о студенте
                </h3>
                <Input
                    id="student-info__input-last-name"
                    placeholder="Фамилия"
                    value={useSelector(actions.getLastName)}
                    setValue={(lastName) => dispatch(actions.setLastName(clearText(lastName)))}
                />
                <Input
                    id="student-info__input-first-name"
                    placeholder="Имя"
                    value={useSelector(actions.getFirstName)}
                    setValue={(firstName) => dispatch(actions.setFirstName(clearText(firstName)))}
                />
                <Input
                    id="student-info__input-surname"
                    placeholder="Отчество"
                    value={useSelector(actions.getSurname)}
                    setValue={(surname) => dispatch(actions.setSurname(clearText(surname)))}
                />
                <Input
                    id="student-info__input-date-of-birth"
                    type="date"
                    label="Дата рождения:"
                    value={useSelector(actions.getDateOfBirth)}
                    setValue={(dateOfBirth) => dispatch(actions.setDateOfBirth(dateOfBirth))}
                />
                <Input
                    id="student-info__input-admission-year"
                    type="number"
                    label="Год поступления:"
                    min={new Date().getFullYear() - 70}
                    max={new Date().getFullYear()}
                    value={useSelector(actions.getAdmissionYear)}
                    setValue={(admissionYear) => dispatch(actions.setAdmissionYear(admissionYear))}
                />
                <Input
                    id="student-info__input-faculty"
                    label="Факультет:"
                    value={useSelector(actions.getFaculty)}
                    setValue={(faculty) => dispatch(actions.setFaculty(clearText(faculty)))}
                />
                <Input
                    id="student-info__input-group"
                    type="number"
                    label="Группа"
                    min={1}
                    max={20}
                    value={useSelector(actions.getGroup)}
                    setValue={(group) => dispatch(actions.setGroup(group))}
                />
                <Input
                    id="student-info__input-speciality"
                    label="Специальность:"
                    value={useSelector(actions.getSpeciality)}
                    setValue={(speciality) => dispatch(actions.setSpeciality(clearText(speciality)))}
                />
                <Input
                    id="student-info__input-email"
                    type="email"
                    placeholder="Email"
                    value={useSelector(actions.getEmail)}
                    setValue={(email) => dispatch(actions.setEmail(email))}
                />
                <Input
                    id="student-info__input-phone-number"
                    type="tel"
                    placeholder="Номер телефона"
                    pattern={PHONE_PATTERN}
                    value={useSelector(actions.getPhoneNumber)}
                    setValue={(phoneNumber) => dispatch(actions.setPhoneNumber(clearPhoneNumber(phoneNumber)))}
                />
            </div>
        </div>
    );
}


function Input({id, value, setValue, label='', placeholder='', type='text', pattern=null, min=null, max=null}) {
    return (
        <div className="input">
            <label 
                className="input__label"
                htmlFor={id}
                style={{
                    display: label? 'block' : 'none',
                }}
            >
                {label}
            </label>
            <input
                className="input__field"
                id={id}
                type={type}
                placeholder={placeholder}
                min={min}
                max={max}
                pattern={pattern}
                required
                value={value}
                onChange={(event) => setValue(event.target.value)}
            />
        </div>
    );
}


export default StudentInfo;
