#include <iostream>
#include <fstream>
#include "array.h"

using namespace std;

void print_array(ostream &out, Array *arr)
{
    size_t size = array_size(arr);
    for (size_t i = 0; i < size; i++){
        if (i > 0) out << " ";
        out << array_get(arr, i);
    }
    out << endl;
}

Array *array_create_and_read(ifstream &input)
{
    int n;
    input >> n;
    Array *arr = array_create(n);

    for (int i = 0; i < n; ++i)
    {
        int x;
        input >> x;
        array_set(arr, i, x);
    }

    return arr;
}

void task1(Array *arr, ifstream &input, ofstream &output)
{
    int k1, k2;
    input >> k1 >> k2;

    size_t size = array_size(arr);

    if (k1 < 0 || k1 >= (int)size || k2 < 0 || k2 >= (int)size) {
        cout << "Ошибка: индексы k1/k2 выходят за пределы массива" << endl;
        output << "Ошибка: индексы k1/k2 выходят за пределы массива" << endl;
        return;
    }

    print_array(cout, arr);

    print_array(output, arr);

    int elem_k1 = array_get(arr, k1);
    int elem_k2 = array_get(arr, k2);

    for (size_t i = 0; i < size; i++){
        int current = array_get(arr, i);
        if (current > 0){
            array_set(arr, i, current - elem_k1);
        } else {
            array_set(arr, i, current - elem_k2);
        }
    }

    print_array(cout, arr);

    print_array(output, arr);
}

void task2(Array *arr, ifstream &input, ofstream &output)
{
    int direction, steps;
    input >> direction >> steps;
    
    size_t size = array_size(arr);
    
    print_array(cout, arr);
    
    print_array(output, arr);
    
    Data* temp = new Data[size];
    
    if (direction == 0) {
        for (size_t i = 0; i < size; i++) {
            if ((int)i + steps < (int)size) {
                temp[i] = array_get(arr, i + steps);
            } else {
                temp[i] = 0;
            }
        }
    } else if (direction == 1) {
        for (size_t i = 0; i < size; i++) {
            if ((int)i - steps >= 0) {
                temp[i] = array_get(arr, i - steps);
            } else {
                temp[i] = 0;
            }
        }
    } else {
        delete[] temp;
        return;
    }
    
    for (size_t i = 0; i < size; i++) {
        array_set(arr, i, temp[i]);
    }
    delete[] temp;
    
    print_array(cout, arr);
    
    print_array(output, arr);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        cout << "Использование: " << argv[0] << " <входной_файл> [выходной_файл]" << endl;
        return 1;
    }
    
    ifstream input(argv[1]);
    if (!input.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    
    ofstream output;
    if (argc >= 3) {
        output.open(argv[2]);
    } else {
        output.open("output.txt");
    }
    
    if (!output.is_open()) {
        cout << "Ошибка создания выходного файла" << endl;
        input.close();
        return 1;
    }
    
    Array *arr = array_create_and_read(input);
    task1(arr, input, output);
    array_delete(arr);
    
    arr = array_create_and_read(input);
    task2(arr, input, output);
    array_delete(arr);
    
    input.close();
    output.close();
    return 0;
}
