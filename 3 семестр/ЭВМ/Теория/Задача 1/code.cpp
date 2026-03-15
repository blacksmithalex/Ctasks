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

// Основная функция быстрой сортировки
void quickSort(vector<int> &arr, int left, int right)
{
     // Базовый случай: если подмассив пуст или содержит один элемент
     if (left >= right)
     {
          return;
     }

     // Выбор опорного элемента (середина)
     int mid = left + (right - left) / 2; // (left + right) / 2
     int pivot = arr[mid];

     cout << "\nСортируем подмассив: ";
     printArray(arr, left, right);
     cout << "Опорный элемент (индекс " << mid << "): " << pivot << endl;

     // Указатели для прохода по массиву
     int i = left;
     int j = right;

     // Разделение массива
     while (i <= j)
     {
          // Двигаем i вправо, пока не найдем элемент >= pivot
          while (arr[i] < pivot)
          {
               i++;
          }

          // Двигаем j влево, пока не найдем элемент <= pivot
          while (arr[j] > pivot)
          {
               j--;
          }

          // Если указатели не пересеклись, меняем элементы местами
          if (i <= j)
          {
               cout << "  Меняем " << arr[i] << " (индекс " << i << ") и "
                    << arr[j] << " (индекс " << j << ")" << endl;
               swap(arr[i], arr[j]);
               i++;
               j--;

               cout << "  Промежуточный результат: ";
               printArray(arr, left, right);
          }
     }

     cout << "Разделение завершено. i = " << i << ", j = " << j << endl;
     cout << "Левая часть: ";
     printArray(arr, left, j);
     cout << "Правая часть: ";
     printArray(arr, i, right);

     // Рекурсивно сортируем левую и правую части
     if (left < j)
     {
          quickSort(arr, left, j);
     }
     if (i < right)
     {
          quickSort(arr, i, right);
     }
}

// Перегрузка для удобства вызова
void quickSort(vector<int> &arr)
{
     quickSort(arr, 0, arr.size() - 1);
}

int main()
{
     // Исходный массив
     vector<int> arr = {31, 21, 24, 29, 29, 31, 11, 27, 24, 27};

     cout << "Исходный массив: ";
     printArray(arr, 0, arr.size() - 1);

     // Вызываем сортировку
     quickSort(arr);

     cout << "\nОтсортированный массив: ";
     printArray(arr, 0, arr.size() - 1);

     return 0;
}