#include <iostream>
#include <string>

using namespace std;

struct Pair
{
    string key;
    int value;
};

// структура хеш-таблицы
struct HashTable
{
private:
    Pair* table; // Массив пар ключ-значение
    int size; // Размер массива
    int count; // Количество элементов в хеш-таблице

    // Хеш-функция
    int Hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            hash += key[i];
            //cout << "key[i] = " << key[i] << endl;
            //cout << "hash = " << hash << endl;
        }
        return hash % size;
    }

public:
    HashTable(int size)
    {
        this->size = size;
        table = new Pair[size];
        count = 0;
    }

    ~HashTable()
    {
        delete[] table;
    }

    //добавление элемента в хеш-таблицу
    void put(string key, int value)
    {
        if (count == size)
        {
            cout << "Хеш-таблица заполнена" << endl;
            return;
        }
        int index = Hash(key);
        while (table[index].key != "" && table[index].key != key)
        {
            index = (index + 1) % size;
        }
        if (table[index].key == "")
        {
            count++;
        }
        table[index] = { key, value };
    }

    //поиск элемента в хеш-таблице по ключу
    int Get(string key) {
        int index = Hash(key);
        int startIndex = index;
        while (table[index].key != "" && table[index].key != key) {
            index = (index + 1) % size;
            if (index == startIndex) {
                return 0;
            }
        }
        if (table[index].key == "")
        {
            // элемент не найден
            return 0;
        }
        return table[index].value;
    }
};

int main() {

    HashTable hashTable(4);

    hashTable.put("fox", 33);
    hashTable.put("dog", 11);
    hashTable.put("pig", 22);
    hashTable.put("cat", 44);

    cout << hashTable.Get("fox") << endl;
    cout << hashTable.Get("dog") << endl;
    cout << hashTable.Get("pig") << endl;
    cout << hashTable.Get("cat") << endl;
    cout << hashTable.Get("owl") << endl;
    cout << hashTable.Get("fox") << endl;
    cout << hashTable.Get("owl") << endl;
    cout << hashTable.Get("fox") << endl;

    return 0;
}
