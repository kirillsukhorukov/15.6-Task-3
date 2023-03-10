#include <iostream>
#include <vector>

using namespace std;

// Функция для преобразования в двоичную кучу поддерева с корневым узлом i,
// где i - индекс в векторе vec, а n - размер кучи

void heapify(vector <int> &vec, const int n, const int i)
{
    // Инициализируем наибольший элемент как корень
    int largest = i;
    // Определяем индексы дочерних элементов
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Если левый дочерний элемент больше корня, то присваеваем наибольшему элементу индекс левого дочернего элемента
    if (left < n && vec[left] > vec[largest])
        largest = left;

    // Если правый дочерний элемент больше, чем самый большой на данный момент,
    // то присваеваем наибольшему элементу индекс правого дочернего элемента
    if (right < n && vec[right] > vec[largest])
        largest = right;

    // Если индекс самого большого элемента изменился
    if (largest != i)
    {
        // Переставляем самый большой элемент в корень
        swap(vec[i], vec[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(vec, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(vector <int> &vec, const int n)
{
    // Построение кучи (перегруппировка вектора)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vec, n, i);

    // Один за другим извлекаем максимальные элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(vec[0], vec[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(vec, i, 0);
    }
}
//Процедура сортировки и вывода числа с требуемым индексом
void sort_and_output(vector <int>& vec, const int& index)
{
    //Проверка что индекс выводимого числа не больше размера вектора
    if(index>vec.size())
    {
        cerr << "There is no element in the array with that index!" << endl;
        return;
    }
    heapSort(vec, vec.size());
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