#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Вывод массива
void printArray(const vector<int> &arr, string label = "")
{
     if (!label.empty())
          cout << label;
     for (int x : arr)
          cout << x << " ";
     cout << "\n";
}

// Вывод count массива
void printCountArray(const vector<int> &count)
{
     cout << "Final count array (value : frequency):\n";
     for (int i = 0; i < count.size(); i++)
     {
          if (count[i] > 0)
          {
               cout << i << " : " << count[i] << "\n";
          }
     }
}

// Counting Sort
void countingSort(vector<int> &arr)
{
     int n = arr.size();

     cout << "Original array:\n";
     printArray(arr);

     // максимум
     int maxVal = *max_element(arr.begin(), arr.end());

     // count массив
     vector<int> count(maxVal + 1, 0);

     // подсчёт
     for (int i = 0; i < n; i++)
     {
          count[arr[i]]++;
     }

     // вывод только финального count
     cout << "\n=== FINAL COUNT ARRAY ===\n";
     printCountArray(count);

     // восстановление отсортированного массива
     vector<int> output;
     for (int i = 0; i <= maxVal; i++)
     {
          while (count[i] > 0)
          {
               output.push_back(i);
               count[i]--;
          }
     }

     arr = output;
}

int main()
{
     vector<int> arr = {4, 4, 5, 4, 8, 4, 6, 3, 5, 2, 8, 1, 3, 5, 2};

     countingSort(arr);

     cout << "\nSorted array:\n";
     printArray(arr);

     return 0;
}