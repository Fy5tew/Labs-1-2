import { VIEW_MODE, SORT_TYPE, toggleSortType } from '#utils/filters';

import styles from './Catalog.module.css';


const SortOption = ({ name, property, selectedType, onPropertyChange, onTypeChange }) => {
    const handleClick = () => {
        if (!selectedType) {
            onPropertyChange(property);
            onTypeChange(SORT_TYPE.ASCENDING);
        }
        else {
            onTypeChange(toggleSortType(selectedType));
        }
    }

    return (
        <p className={styles.option}>
            <span onClick={handleClick} data-selected={selectedType !== null}>{name}</span>
            {selectedType !== null && <span>{selectedType === SORT_TYPE.ASCENDING ? '↑' : '↓'}</span>}
        </p>
    );
}


const ViewModeOption = ({ selectedViewMode, onChange }) => {
    const setViewMode = (viewMode) => () => onChange(viewMode);

    return (
        <>
            <p 
                className={styles.option} 
                onClick={setViewMode(VIEW_MODE.SEPARATE_NEW)} 
                data-selected={selectedViewMode === VIEW_MODE.SEPARATE_NEW}
            >
                Сначала новые
            </p>
            <p 
                className={styles.option} 
                onClick={setViewMode(VIEW_MODE.ALL_PRODUCTS)} 
                data-selected={selectedViewMode === VIEW_MODE.ALL_PRODUCTS}
            >
                Все товары
            </p>
        </>
    );
}


export const CatalogHead = ({ 
    sortableProperties, 
    sortProperty, 
    sortType, 
    viewMode,
    onSortTypeChange, 
    onSortPropertyChange, 
    onViewModeChange 
}) => {
    return (
        <div className={styles.head}>
            <div className={styles.optionGroup}>
                <p className={styles.optionLabel}>Сортировать по:</p>
                {sortableProperties.map(entry => 
                    <SortOption
                        key={entry.property}
                        name={entry.name}
                        property={entry.property}
                        selectedType={entry.property === sortProperty ? sortType : null}
                        onPropertyChange={onSortPropertyChange}
                        onTypeChange={onSortTypeChange}
                    />
                )}
            </div>
            <div className={styles.optionGroup}>
                <p className={styles.optionLabel    }>Режим отображения:</p>
                <ViewModeOption
                    selectedViewMode={viewMode}
                    onChange={onViewModeChange}
                />
            </div>
        </div>
    );
}
