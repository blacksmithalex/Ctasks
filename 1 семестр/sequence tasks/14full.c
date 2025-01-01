#include <stdio.h>
#define MAX_INT 10000 

int countMinValues(const char *filename, int *minValue) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Ошибка открытия файла.\n");
        return -1;
    }

    int curr;
    int minCount = 0;
    *minValue = MAX_INT;  
    int isEmpty = 1;     

    while (fscanf(file, "%d", &curr) == 1) {
        isEmpty = 0; 

        if (curr < *minValue) {
            *minValue = curr;
            minCount = 1; 
        } else if (curr == *minValue) {
            minCount++;  
        }
    }

    fclose(file);

    if (isEmpty) {
        return -1; 
    }

    return minCount;  
}

int main() {
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        printf("Ошибка открытия файла для вывода.\n");
        return 1;
    }

    int minValue;
    int result = countMinValues(inputFile, &minValue);


    if (result == -1) {
        fprintf(out, "Ошибка: файл пустой или не удалось обработать данные.\n");
    } else {
        fprintf(out, "Минимальное значение: %d\n", minValue);
        fprintf(out, "Количество минимальных значений: %d\n", result);
    }

    fclose(out);
    return 0;
}