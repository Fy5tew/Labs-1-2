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
                cout << "�����: " << current->address << ", �������: " << current->surname << endl;
                flag = true;
            }
            current = current->next;
        }
        if (flag == false)
            cout << "������� �� ������!";
    }

    void printAllRecords()
    {
        for (int i = 0; i < size; i++)
        {
            EmailRecord* current = table[i];
            while (current != nullptr)
            {
                cout << "�����: " << current->address << ", �������: " << current->surname << ", ���: " << current->year << " | ";
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
                cout << "������ �������!";
                return;
            }

            previous = current;
            current = current->next;
        }

        cout << "������ �� �������!";
    }
};

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;

    cout << "������� ������ �������: "; cin >> size;

    HashTable emailTable(size);

    int choice;
    int year;
    clock_t t1, t2;
    string surname, address;

    do
    {
        system("cls");

        cout << "0 - �����" << endl;
        cout << "1 - ����� ���-�������" << endl;
        cout << "2 - �������� �������" << endl;
        cout << "3 - ������� �������" << endl;
        cout << "4 - ����� ��������" << endl;
        cout << endl;

        cout << "�����: "; cin >> choice;

        system("cls");

        switch (choice)
        {
        case 0:
            return;
        case 1:
            emailTable.printAllRecords();
            break;
        case 2:
            cout << "������� ���: "; cin >> year;
            cout << "������� �������: "; cin >> surname;
            cin.ignore();
            cout << "������� �����: "; getline(cin, address);
            emailTable.addRecord(address, surname, year);
            break;
        case 3:
            cout << "������� ���: "; cin >> year;
            emailTable.deleteRecord(year);
            break;
        case 4:
            cout << "������� ���: "; cin >> year;
            t1 = clock();
            emailTable.searchRecords(year);
            t2 = clock();
            cout << endl << "������ ������: " << t2 - t1 << endl;
            break;
        }

        cout << endl << endl;
        system("pause");
    } while (choice != 0);
}
