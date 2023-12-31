﻿#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    const int size = 10;
    int array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Открывается  файл на запись в бинарном режиме (если файл не существует - он будет создан, если файл существует - 
    // он будет усечен до нулевой длины).
    ofstream out("Array.txt", ios::binary | ios::trunc | ios::out);

    // В файл сохраняется размерность массива.
    out.write((char*)&size, sizeof(size));
    
    // В файл сохраняется массив.
    out.write((char*)array1, sizeof(array1));

    // Закрытие файлового потока.
    out.close();
	
    // Открывается файл на чтение в бинарном режиме (при этом файл должен существовать).
    ifstream in("Array.txt", ios::binary | ios::in);

    int count = 0;

    // Считывание размера массива в переменную.
    in.read((char*)&count, sizeof(count));

    // Выделение памяти под массив данных.
    int* array2 = new int[count];

    // Считывание массива из файла.
    in.read((char*)array2, sizeof(int) * count);

    // Закрытие файлового потока.
    in.close();

    for (int i = 0; i < count; ++i)
    {
        // Вывод на экран считанного массива.
        cout << array2[i] << '\t';
    }

    delete [] array2;

    return 0;
}