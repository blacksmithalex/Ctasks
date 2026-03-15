#include <iostream>
#include <vector>
using namespace std;

// Функция для вывода массива
void printArray(const vector<int> &arr, int left, int right, const string &message = "")
{
     if (!message.empty())
     {
          cout << message << ": ";
     }
     cout << "[";
     for (int i = left; i <= right; i++)
     {
          cout << arr[i];
          if (i < right)
               cout << ", ";
     }
     cout << "]" << endl;
}

// Функция для обмена элементов
void swap(int &a, int &b)
{
     int temp = a;
     a = b;
     b = temp;
}

// Модифицированная функция быстрой сортировки для порядка НЕВОЗРАСТАНИЯ
void quickSortDesc(vector<int> &arr, int left, int right, int depth = 0)
{
     // Базовый случай: если подмассив пуст или содержит один элемент
     if (left >= right)
     {
          return;
     }

     // Вывод отступа для наглядности рекурсии
     string indent(depth * 2, ' ');

     // Выбор опорного элемента (середина)
     int mid = left + (right - left) / 2;
     int pivot = arr[mid];

     cout << indent << "Сортируем подмассив: ";
     printArray(arr, left, right);
     cout << indent << "Опорный элемент (индекс " << mid << "): " << pivot << endl;

     // Указатели для прохода по массиву
     int i = left;
     int j = right;

     // Разделение массива для сортировки по НЕВОЗРАСТАНИЮ
     while (i <= j)
     {
          // Двигаем i вправо, пока не найдем элемент МЕНЬШЕ опорного
          // (для невозрастания большие элементы должны быть слева)
          while (arr[i] > pivot)
          {
               i++;
          }

          // Двигаем j влево, пока не найдем элемент БОЛЬШЕ опорного
          // (для невозрастания меньшие элементы должны быть справа)
          while (arr[j] < pivot)
          {
               j--;
          }

          // Если указатели не пересеклись, меняем элементы местами
          if (i <= j)
          {
               cout << indent << "  Меняем " << arr[i] << " (индекс " << i << ") и "
                    << arr[j] << " (индекс " << j << ")" << endl;
               swap(arr[i], arr[j]);
               i++;
               j--;

               cout << indent << "  Промежуточный результат: ";
               printArray(arr, left, right);
          }
     }

     cout << indent << "Разделение завершено. i = " << i << ", j = " << j << endl;
     cout << indent << "Левая часть (бо'льшие элементы): ";
     printArray(arr, left, j);
     cout << indent << "Правая часть (меньшие элементы): ";
     printArray(arr, i, right);
     cout << endl;

     // Рекурсивно сортируем левую и правую части
     if (left < j)
     {
          quickSortDesc(arr, left, j, depth + 1);
     }
     if (i < right)
     {
          quickSortDesc(arr, i, right, depth + 1);
     }
}

// Перегрузка для удобства вызова
void quickSortDesc(vector<int> &arr)
{
     quickSortDesc(arr, 0, arr.size() - 1, 0);
}

int main()
{
     // Исходный массив
     vector<int> arr = {39, 31, 27, 13, 17, 18, 14, 20, 31, 17};

     cout << "Исходный массив: ";
     printArray(arr, 0, arr.size() - 1);
     cout << "Сортировка в порядке НЕВОЗРАСТАНИЯ (по убыванию)" << endl;
     cout << string(50, '=') << endl;

     // Вызываем сортировку
     quickSortDesc(arr);

     cout << string(50, '=') << endl;
     cout << "Отсортированный массив (невозрастание): ";
     printArray(arr, 0, arr.size() - 1);

     return 0;
}