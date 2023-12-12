#include <iostream>
#include <ctime>

using namespace std;

// Класс для хранения элемента хеш-таблицы
class HashEntry {
public:
    int key;
    int value;

    HashEntry(int key, int value) : key(key), value(value) {}
};

// Класс хеш-таблицы
class HashTable {
private:
    HashEntry** table;
    int* collisions;
    int tableSize;

    // Универсальная хеш-функция
    int hash(int key, int a, int b) {
        return ((a * key + b) % tableSize);
    }

public:
    HashTable(int size) : tableSize(size) {
        table = new HashEntry * [size];
        collisions = new int[size];

        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
            collisions[i] = 0;
        }
    }

    ~HashTable() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
        delete[] table;
        delete[] collisions;
    }

    // Вставка элемента в хеш-таблицу
    void insert(int key, int value, int a, int b) {
        int index = hash(key, a, b);
        int collision = 0;

        while (table[index] != nullptr) {
            if (collision >= tableSize) {
                cout << "OverflowError: Hash-table is overflowing." << endl;
                return;
            }

            collision++;
            index = (hash(key, a, b) + collision) % tableSize;
        }

        table[index] = new HashEntry(key, value);
        collisions[index] = collision;
    }

    // Удаление элемента из хеш-таблицы по ключу
    void remove(int key, int a, int b) {
        int index = hash(key, a, b);
        int collision = 0;

        while (table[index] != nullptr) {
            if (table[index]->key == key) {
                delete table[index];
                table[index] = nullptr;
                collisions[index] = 0;
            }

            collision++;
            index = (hash(key, a, b) + collision) % tableSize;
        }

        cout << "Удаление успешно завершено!" << endl;
    }

    // Поиск элемента в хеш-таблице по ключу
    void search(int key, int a, int b) {
        int index = hash(key, a, b);
        int collision = 0;

        while ((table[index] != nullptr) and (collision < tableSize)) {
            if (table[index]->key == key) {
                cout << "Ключ: " << key << ", Значение: " << table[index]->value << ", Коллизия: " << collisions[index] << endl;
            }
            collision++;
            index = (hash(key, a, b) + collision) % tableSize;
        }
    }

    // Вывод статистики о коллизиях
    void printCollisionStats() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i] != nullptr) {
                cout << "Ключ: " << table[i]->key << ", Значение: " << table[i]->value << ", Коллизии: " << collisions[i] << endl;
            }
        }
    }
};

int main() {
    setlocale(0, "");
    srand(time(0));

    int tableSize = 16, choices, key, value;
    HashTable hashTable(tableSize);

    int a = rand() % (tableSize - 1) + 1;
    int b = rand() % (tableSize - 1) + 1;

    do {
        cout << "\nМеню:" << endl;
        cout << "1 - Вывод коллизий хеш-таблицы;" << endl;
        cout << "2 - Добавление элемента хеш-таблицы;" << endl;
        cout << "3 - Удаление элемента хеш-таблицы;" << endl;
        cout << "4 - Поиск элемента хеш-таблицы;" << endl;
        cout << "0 - Выход из программы." << endl;

        cout << "Введите значение: "; cin >> choices;

        system("cls");
        switch (choices) {
        case 1: {
            hashTable.printCollisionStats();
            break;
        }
        case 2: {
            cout << "Введите ключ и значение: "; cin >> key >> value;
            hashTable.insert(key, value, a, b);
            break;
        }
        case 3: {
            cout << "Введите ключ: "; cin >> key;
            hashTable.remove(key, a, b);
            break;
        }
        case 4: {
            cout << "Введите ключ: "; cin >> key;
            hashTable.search(key, a, b);
            break;
        }
        default:
            cout << "Вы ввели некорректное значение. Повторите попытку";
            break;
        }

    } while (choices != 0);

    return 0;
}