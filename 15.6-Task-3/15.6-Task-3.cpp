#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Процедура сортировки и вывода числа с требуемым индексом
void sort_and_output(vector <int>& vec, const int& index)
{
    //Проверка что индекс выводимого числа не больше размера вектора
    if(index>vec.size())
    {
        cerr << "There is no element in the array with that index!" << endl;
        return;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
    cout << endl << index << " element=" << vec[index - 1] << endl;
    return;
}

int main() {
    //Ввод первого числа и запись его в массив vec
    cout << "Please, enter the number: ";
    int number;
    cin >> number;
    vector <int> vec(1);
    vec[0] = number;
    //Инициализация номера элемента массива, который должен быть выведен при запросе
    int index = 5;
    //Цикл запроса следующих чисел и обработки массива
    while (number != -2)
    {
        cout << "Please, enter the number:  ";
        cin >> number;
        if (number == -1) sort_and_output(vec, index);
        else vec.push_back(number);
    }
    return 0;
}