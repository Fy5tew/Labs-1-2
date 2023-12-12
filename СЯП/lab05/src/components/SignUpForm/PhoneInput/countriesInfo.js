import belarusIcon from './assets/icons/belarus.png';
import russiaIcon from './assets/icons/russia.png';
import ukraineIcon from './assets/icons/ukraine.png';
import polandIcon from './assets/icons/poland.png';
import lithuaniaIcon from './assets/icons/lithuania.png';
import latviaIcon from './assets/icons/latvia.png';
import defaultIcon from './assets/icons/default.png';


const countries = [
    {
        id: 0,
        name: 'Другое',
        icon: defaultIcon,
        phone: {
            rawLength: 16,
            formatedLength: 16,
            placeholder: '+',
            mask: '+<part1>',
            checkRegexp: /\-/,
            parseRegexp: /^\+*(?<part1>\d{0,15})/,
        },
        operators: [],
    },
    {
        id: 1,
        name: 'Беларусь',
        icon: belarusIcon,
        phone: {
            rawLength: 13,
            formatedLength: 19,
            placeholder: '+375',
            mask: '+375 (<code>) <part1>-<part2>-<part3>',
            checkRegexp: /^\+*375/,
            parseRegexp: /^\+*375(?<code>\d{0,2})(?<part1>\d{0,3})(?<part2>\d{0,2})(?<part3>\d{0,2})/,
        },
        operators: [
            'МТС',
            'A1',
            'life:)',
        ],
    },
    {
        id: 2,
        name: 'Россия',
        icon: russiaIcon,
        phone: {
            rawLength: 12,
            formatedLength: 18,
            placeholder: '+7',
            mask: '+7 (<code>) <part1>-<part2>-<part3>',
            checkRegexp: /^\+*7/,
            parseRegexp: /^\+*7(?<code>\d{0,3})(?<part1>\d{0,3})(?<part2>\d{0,2})(?<part3>\d{0,2})/,
        },
        operators: [
            'Билайн', 
            'Мегафон',
            'МТС', 
            'Tele2',
        ],
    },
    {
        id: 3,
        name: 'Украина',
        icon: ukraineIcon,
        phone: {
            rawLength: 13,
            formatedLength: 19,
            placeholder: '+380',
            mask: '+380 (<code>) <part1>-<part2>-<part3>',
            checkRegexp: /^\+*380/,
            parseRegexp: /^\+*380(?<code>\d{0,2})(?<part1>\d{0,3})(?<part2>\d{0,2})(?<part3>\d{0,2})/,
        },
        operators: [
            'Lifecell',
            'Vodafone',
            'Київстар',
        ],
    },
    {
        id: 4,
        name: 'Польша',
        icon: polandIcon,
        phone: {
            rawLength: 12,
            formatedLength: 15,
            placeholder: '+48',
            mask: '+48 <part1>-<part2>-<part3>',
            checkRegexp: /^\+*48/,
            parseRegexp: /^\+*48(?<code>\d{0})(?<part1>\d{0,3})(?<part2>\d{0,3})(?<part3>\d{0,3})/,
        },
        operators: [
            'Orange', 
            'Play', 
            'Plus', 
            'T-mobile',
        ],
    },
    {
        id: 5,
        name: 'Литва',
        icon: lithuaniaIcon,
        phone: {
            rawLength: 13,
            formatedLength: 19,
            placeholder: '+370',
            mask: '+370 (<code>) <part1>-<part2>-<part3>',
            checkRegexp: /^\+*370/,
            parseRegexp: /^\+*370(?<code>\d{0,2})(?<part1>\d{0,3})(?<part2>\d{0,2})(?<part3>\d{0,2})/,
        },
        operators: [
            'Telia', 
            'Bite', 
            'Tele2',
        ],
    },
    {
        id: 6,
        name: 'Латвия',
        icon: latviaIcon,
        phone: {
            rawLength: 12,
            formatedLength: 14,
            placeholder: '+371',
            mask: '+371 <part1>-<part2>',
            checkRegexp: /^\+*371/,
            parseRegexp: /^\+*371(?<code>\d{0})(?<part1>\d{0,4})(?<part2>\d{0,4})(?<part3>\d{0})/,
        },
        operators: [
            'LMT', 
            'Tele2', 
            'Bite',
        ],
    },
]


export default countries;
