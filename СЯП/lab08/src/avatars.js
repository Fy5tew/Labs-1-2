import guestAvatar from './assets/avatars/guest.png';
import hackerAvatar from './assets/avatars/hacker.png';
import teenAvatar from './assets/avatars/teen.png';
import boyAvatar from './assets/avatars/boy.png';
import girlAvatar from './assets/avatars/girl.png';
import manAvatar from './assets/avatars/man.png';
import womanAvatar from './assets/avatars/woman.png';


export const avatars = {
    guest: {
        name: 'Гость',
        sex: 'both',
        src: guestAvatar,
    },
    hacker: {
        name: 'Хакер',
        sex: 'male',
        src: hackerAvatar,
    },
    teen: {
        name: 'Подросток',
        sex: 'female',
        src: teenAvatar,
    },
    boy: {
        name: 'Парень',
        sex: 'male',
        src: boyAvatar,
    },
    girl: {
        name: 'Девушка',
        sex: 'female',
        src: girlAvatar,
    },
    man: {
        name: 'Мужчина',
        sex: 'male',
        src: manAvatar,
    },
    wooman: {
        name: 'Женщина',
        sex: 'female',
        src: womanAvatar,
    },
}
