import { createSlice } from '@reduxjs/toolkit';


export const studentInfoSlice = createSlice({
    name: 'studentInfo',
    initialState: {
        lastName: '',
        firstName: '',
        surname: '',
        dateOfBirth: '',
        admissionYear: (new Date()).getFullYear(),
        faculty: '',
        group: 0,
        speciality: '',
        email: '',
        phoneNumber: '',
    },
    reducers: {
        setLastName: (state, action) => {
            state.lastName = action.payload;
        },
        setFirstName: (state, action) => {
            state.firstName = action.payload; 
        },
        setSurname: (state, action) => {
            state.surname = action.payload;
        },
        setDateOfBirth: (state, action) => {
            state.dateOfBirth = action.payload;
        },
        setAdmissionYear: (state, action) => {
            state.admissionYear = +action.payload;
        },
        setFaculty: (state, action) => {
            state.faculty = action.payload;
        },
        setGroup: (state, action) => {
            state.group = +action.payload;
        },
        setSpeciality: (state, action) => {
            state.speciality = action.payload;
        },
        setEmail: (state, action) => {
            state.email = action.payload;
        },
        setPhoneNumber: (state, action) => {
            state.phoneNumber = action.payload;
        },
    },
});


export const actions = {
    ...studentInfoSlice.actions,
    getLastName: (state) => state.studentInfo.lastName,
    getFirstName: (state) => state.studentInfo.firstName,
    getSurname: (state) => state.studentInfo.surname,
    getDateOfBirth: (state) => state.studentInfo.dateOfBirth,
    getAdmissionYear: (state) => state.studentInfo.admissionYear,
    getFaculty: (state) => state.studentInfo.faculty,
    getGroup: (state) => state.studentInfo.group,
    getSpeciality: (state) => state.studentInfo.speciality,
    getEmail: (state) => state.studentInfo.email,
    getPhoneNumber: (state) => state.studentInfo.phoneNumber,
};


export default studentInfoSlice.reducer;
