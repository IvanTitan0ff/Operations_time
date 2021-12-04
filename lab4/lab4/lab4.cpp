#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

long double sumArray(long double* arr, unsigned int size) {
    long double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

long double subArray(long double* arr, unsigned int size) {
    long double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum -= arr[i];
    }
    return sum;
}

long double prodArray(long double* arr, unsigned int size) {
    long double product = arr[0];
    for (int i = 1; i < size; ++i) {
        product *= arr[i];
    }
    return product;
}

long double quotArray(long double* arr, unsigned int size) {
    long double quotient = arr[0];
    for (int i = 1; i < size; ++i) {
        quotient /= arr[i];
    }
    return quotient;
}


void measureFuncTime(long double func(long double*, unsigned int), long double* arr, unsigned int size) {
    auto start = std::chrono::steady_clock::now();

    std::cout << std::fixed << func(arr, size) << "\n";

    auto end = std::chrono::steady_clock::now();
    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << deltaTime.count() << " milliseconds\n";
    return;
}

int main()
{
    unsigned int size;
    long double leftLim, rightLim;

    std::cin >> size >> leftLim >> rightLim;
    long double* arr = new long double[size];
    
    std::ofstream fout("array.txt");

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < size; ++i) {
        arr[i] = leftLim + (double)(static_cast<float> (rand() / static_cast <float> (RAND_MAX / (rightLim - leftLim))));
    }
    auto end = std::chrono::steady_clock::now();
    
    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Array generation time: " << deltaTime.count() << "\n";

    std::cout << "Sum = ";
    measureFuncTime(sumArray, arr, size);
    std::cout << "Substraction = ";
    measureFuncTime(subArray, arr, size);
    std::cout << "Product = ";
    measureFuncTime(prodArray, arr, size);
    std::cout << "Quotient = ";
    measureFuncTime(quotArray, arr, size);

    delete[] arr;
}


/*
    Массив из N элементов (сгенерировать [a,b])

    Выбранный тип (целая или дробь)

    Вывести время работы алгоритма по выполнению арифм. операций со всеми эл массива:
    Сумма 
    Разность
    Произведение
    Частное
*/

/*
    + Вся документация по ГОСТам
    + Тестирование
    + Рефакторинг
    + Профилирование
*/