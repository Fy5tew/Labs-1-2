import { useSelector } from 'react-redux';
import { actions } from '../../features/studentInfo/studentInfoSlice';

import phoneProviders from './phoneProviders.js';

import './StudentInfoHandler.css';


const VALIDATE_EMAIL_REGEXP = /^([a-z0-9_-]+\.)*[a-z0-9_-]+@(?<provider>[a-z0-9_-]+(\.[a-z0-9_-]+)*\.[a-z]{2,6})$/;

const VALIDATE_PHONE_REGEXP = /^\+?\d{9,20}$/;


const validateEmail = (email) => VALIDATE_EMAIL_REGEXP.test(email);

const validatePhoneNumber = (phoneNumber) => VALIDATE_PHONE_REGEXP.test(phoneNumber);

const getEmailProvider = (email) => email.match(VALIDATE_EMAIL_REGEXP).groups.provider;

const getPhoneProvider = (phoneNumber) => phoneProviders.find(provider => provider.regexp.test(phoneNumber))?.name || 'Неизвестно';


function StudentInfoHandler() {
    const lastName = useSelector(actions.getLastName);
    const firstName = useSelector(actions.getFirstName);
    const surname = useSelector(actions.getSurname);
    const dateOfBirth = useSelector(actions.getDateOfBirth);
    const admissionYear = useSelector(actions.getAdmissionYear);
    const faculty = useSelector(actions.getFaculty);
    const group = useSelector(actions.getGroup);
    const speciality = useSelector(actions.getSpeciality);
    const email = useSelector(actions.getEmail);
    const phoneNumber = useSelector(actions.getPhoneNumber);

    if (!(
        lastName && firstName && surname 
        && dateOfBirth && admissionYear
        && faculty && group &&speciality
        && email && phoneNumber
        && validateEmail(email) && validatePhoneNumber(phoneNumber)
    )) {
        return (
            <div className="student-info-handler">
                <h3 className="student-info-handler__header">
                    Вывод информации о студенте
                </h3>
                <p>
                    Введите информацию о студенте в нужном формате
                </p>
            </div>
        );
    }
    
    const currentDate = new Date();

    const age = currentDate.getFullYear() - new Date(dateOfBirth).getFullYear();
    let course = currentDate.getFullYear() - admissionYear + 1;
    course = course > 4 ? 'Окончил университет' : course;
    const emailProvider = getEmailProvider(email);
    const phoneProvider = getPhoneProvider(phoneNumber);

    function alertInfo() {
        alert(
`Информация о студенте:
ФИО: ${lastName} ${firstName} ${surname}
Возраст: ${age} лет
Факультет, курс, группа: ${faculty}, ${course}, ${group}
Специальность: ${speciality} 
Электронная почта: ${email} (Провайдер - ${emailProvider}) 
Номер телефона: ${phoneNumber} (Провайдер - ${phoneProvider})`);
    }

    return (
        <div className="student-info-handler">
            <div className="student-info-handler__head">
                <h3 className="student-info-handler__header">
                    Вывод информации о студенте
                </h3>
                <button onClick={alertInfo} >
                    Показать в окне
                </button>
            </div>
            <table className="student-info-handler__content">
                <tbody>
                    <Row
                        title="ФИО"
                        value={`${lastName} ${firstName} ${surname}`}
                    />
                    <Row
                        title="Текущий возраст студента"
                        value={`${age} лет`}
                    />
                    <Row
                        title="Факультет, курс, группа"
                        value={`${faculty}, ${course}, ${group}`}
                    />
                    <Row
                        title="Специальность"
                        value={speciality}
                    />
                    <Row
                        title="Электронная почта"
                        value={email}
                    />
                    <Row
                        title="Оператор услуг электронной почты"
                        value={emailProvider}
                    />
                    <Row
                        title="Номер телефона"
                        value={phoneNumber}
                    />
                    <Row
                        title="Оператор услуг мобильной связи"
                        value={phoneProvider}
                    />
                </tbody>
            </table>
        </div>
    );
}


function Row({title, value}) {
    return (
        <tr className="student-info-handler__row">
            <th className="student-info-handler__title">
                {title}
            </th>
            <td className="student-info-handler__data">
                {value}
            </td>
        </tr>
    );
}


export default StudentInfoHandler;
