#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Вывод массива
void printArray(const vector<int> &arr)
{
     for (int x : arr)
          cout << x << " ";
     cout << "\n";
}

// Красивый вывод кучи как дерева
void printHeapTree(const vector<int> &arr, int n)
{
     int levels = log2(n) + 1;
     int index = 0;

     cout << "\nHeap as tree:\n";

     for (int i = 0; i < levels; i++)
     {
          int level_nodes = pow(2, i);
          int spaces = pow(2, levels - i);

          // отступ слева
          for (int s = 0; s < spaces / 2; s++)
               cout << " ";

          for (int j = 0; j < level_nodes && index < n; j++, index++)
          {
               cout << arr[index];

               // расстояние между узлами
               for (int s = 0; s < spaces; s++)
                    cout << " ";
          }
          cout << "\n\n";
     }
}

// heapify с визуализацией
void heapify(vector<int> &arr, int n, int i)
{
     int largest = i;
     int left = 2 * i + 1;
     int right = 2 * i + 2;

     if (left < n && arr[left] > arr[largest])
          largest = left;

     if (right < n && arr[right] > arr[largest])
          largest = right;

     if (largest != i)
     {
          swap(arr[i], arr[largest]);

          cout << "\nSwap elements: " << arr[largest] << " <-> " << arr[i] << "\n";
          printArray(arr);
          printHeapTree(arr, n);

          heapify(arr, n, largest);
     }
}

// HeapSort
void heapSort(vector<int> &arr)
{
     int n = arr.size();

     cout << "Original array:\n";
     printArray(arr);
     printHeapTree(arr, n);

     // Построение кучи
     cout << "\n=== BUILD MAX HEAP ===\n";
     for (int i = n / 2 - 1; i >= 0; i--)
     {
          heapify(arr, n, i);

          cout << "\nAfter heapify at index " << i << ":\n";
          printArray(arr);
          printHeapTree(arr, n);
     }

     // Сортировка
     cout << "\n=== SORTING ===\n";
     for (int i = n - 1; i > 0; i--)
     {
          swap(arr[0], arr[i]);

          cout << "\nMove max to end (swap root with index " << i << "):\n";
          printArray(arr);
          printHeapTree(arr, i);

          heapify(arr, i, 0);
     }
}

int main()
{
     vector<int> arr = {31, 32, 34, 13, 28, 20, 28, 36, 30, 20};

     heapSort(arr);

     cout << "\nSorted array:\n";
     printArray(arr);

     return 0;
}