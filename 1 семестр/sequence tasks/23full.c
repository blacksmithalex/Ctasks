#include <stdio.h>

int maxSumOfIncreasingSegment(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Ошибка открытия файла.\n");
        return -1;
    }

    int curr, prev;
    int maxSum = 0;        
    int currSum = 0;        
    int firstElement = 1;  

    while (fscanf(file, "%d", &curr) == 1) {
        if (firstElement) {
            currSum = curr;
            prev = curr;
            firstElement = 0;
        } else {
            if (curr > prev) {
                currSum += curr;
            } else {
                if (currSum > maxSum) {
                    maxSum = currSum;
                }
                currSum = curr;
            }
            prev = curr;
        }
    }

    if (currSum > maxSum) {
        maxSum = currSum;
    }

    fclose(file);

    if (firstElement) {
        return 0;
    }

    return maxSum;
}

int main() {
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        printf("Ошибка открытия файла для вывода.\n");
        return 1;
    }

    int result = maxSumOfIncreasingSegment(inputFile);

    if (result == -1) {
        fprintf(out, "Ошибка обработки файла.\n");
    } else {
        fprintf(out, "Наибольшая сумма возрастающего участка: %d\n", result);
    }

    fclose(out);
    return 0;
}
