const phoneProviders = [
    {
        name: 'A1 (Velcom)',
        regexp: /^(\+375|80)(29(1|3|6|9)|44)/,
    },
    {
        name: 'МТС',
        regexp: /^(\+375|80)(29(2|5|7|8)|33)/,
    },
    {
        name: 'life:)',
        regexp: /^(\+375|80)25/,
    },
    {
        name: 'Белтелеком (городской)',
        regexp: /^(\+375|80)17/,
    },
];


export default phoneProviders;
