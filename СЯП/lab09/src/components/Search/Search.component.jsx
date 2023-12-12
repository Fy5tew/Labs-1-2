import { SEARCH_TYPE } from '#utils/search';

import styles from './Search.module.css';


export const Search = ({ options, onOptionsChange }) => {
    const handleInput = (event) => onOptionsChange(prev => ({...prev, query: event.target.value}));
    const handleSwitch = (event) => {
        const newType = {
            'match': SEARCH_TYPE.MATCH,
            'partial': SEARCH_TYPE.PARTIAL,
        }[event.target.value] || SEARCH_TYPE.PARTIAL;
        onOptionsChange(prev => ({...prev, type: newType}));
    }

    return (
        <div className={styles.search}>
            <h2 className={styles.header}>Поиск товаров: </h2>
            <input
                className={styles.searchBar}
                placeholder='Введите текст для поиска'
                value={options.query}
                onInput={handleInput}
            />
            <label>
                <input
                    type='radio'
                    name='type'
                    value='partial'
                    checked={options.type === SEARCH_TYPE.PARTIAL}
                    onChange={handleSwitch}
                />
                Частичное совпадение
            </label>
            <label>
                <input
                    type='radio'
                    name='type'
                    value='match'
                    checked={options.type === SEARCH_TYPE.MATCH}
                    onChange={handleSwitch}
                />
                Полное совпадение
            </label>
        </div>
    );
}
