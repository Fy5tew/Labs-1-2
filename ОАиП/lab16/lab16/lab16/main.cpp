#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class EmailRecord
{
public:
    string address;
    string surname;
    int year;
    EmailRecord* next;

    EmailRecord(string addr, string sname, int yr)
    {
        address = addr;
        surname = sname;
        year = yr;
    }
};

class HashTable
{
private:
    int size;
    EmailRecord** table;

public:
    HashTable(int tableSize)
    {
        size = tableSize;
        table = new EmailRecord * [size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void addRecord(string address, string surname, int year)
    {
        int hashValue = hashFunction(year);
        EmailRecord* newRecord = new EmailRecord(address, surname, year);

        if (table[hashValue] == nullptr)
            table[hashValue] = newRecord;
        else
        {
            EmailRecord* current = table[hashValue];
            while (current->next != nullptr)
                current = current->next;
            current->next = newRecord;
        }
    }

    void searchRecords(int year)
    {
        bool flag = false;
        int hashValue = hashFunction(year);
        EmailRecord* current = table[hashValue];

        while (current != nullptr)
        {
            if (current->year == year)
            {
                cout << "Адрес: " << current->address << ", фамилия: " << current->surname << endl;
                flag = true;
            }
            current = current->next;
        }
        if (flag == false)
            cout << "Элемент не найден!";
    }

    void printAllRecords()
    {
        for (int i = 0; i < size; i++)
        {
            EmailRecord* current = table[i];
            while (current != nullptr)
            {
                cout << "Адрес: " << current->address << ", фамилия: " << current->surname << ", год: " << current->year << " | ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void deleteRecord(int year)
    {
        int hashValue = hashFunction(year);
        EmailRecord* current = table[hashValue];
        EmailRecord* previous = nullptr;

        while (current != nullptr)
        {
            if (current->year == year)
            {
                if (previous == nullptr)
                    table[hashValue] = current->next;
                else
                    previous->next = current->next;
                delete current;
                cout << "Запись удалена!";
                return;
            }

            previous = current;
            current = current->next;
        }

        cout << "Запись не найдена!";
    }
};

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;

    cout << "Введите размер таблицы: "; cin >> size;

    HashTable emailTable(size);

    int choice;
    int year;
    clock_t t1, t2;
    string surname, address;

    do
    {
        system("cls");

        cout << "0 - Выход" << endl;
        cout << "1 - Вывод хеш-таблицы" << endl;
        cout << "2 - Добавить элемент" << endl;
        cout << "3 - Удалить элемент" << endl;
        cout << "4 - Поиск элемента" << endl;
        cout << endl;

        cout << "Пункт: "; cin >> choice;

        system("cls");

        switch (choice)
        {
        case 0:
            return;
        case 1:
            emailTable.printAllRecords();
            break;
        case 2:
            cout << "Введите год: "; cin >> year;
            cout << "Введите фамилию: "; cin >> surname;
            cin.ignore();
            cout << "Введите адрес: "; getline(cin, address);
            emailTable.addRecord(address, surname, year);
            break;
        case 3:
            cout << "Введите год: "; cin >> year;
            emailTable.deleteRecord(year);
            break;
        case 4:
            cout << "Введите год: "; cin >> year;
            t1 = clock();
            emailTable.searchRecords(year);
            t2 = clock();
            cout << endl << "Прошло тактов: " << t2 - t1 << endl;
            break;
        }

        cout << endl << endl;
        system("pause");
    } while (choice != 0);
}
