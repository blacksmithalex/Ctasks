#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 41

int countA(const char *word)
{
    int count = 0;
    while (*word)
    {
        if (toupper(*word) == 'A')
        {
            count++;
        }
        word++;
    }
    return count;
}

int main()
{
    char str[MAX_LENGTH];
    char currentWord[MAX_LENGTH];
    char maxWord[MAX_LENGTH] = "";

    printf("Введите строку (макс. 40 символов, заканчивается точкой):\n");
    fgets(str, MAX_LENGTH, stdin);

    // Удаляем точку в конце если есть
    char *dot = strchr(str, '.');
    if (dot)
        *dot = '\0';

    printf("Исходная строка: %s\n", str);

    int maxCount = -1;
    int wordNumber = -1;
    int currentWordNumber = 0;

    int i = 0;
    int wordStart = -1;

    // Парсинг строки
    while (str[i] != '\0')
    {
        // Пропускаем пробелы
        while (str[i] == ' ')
        {
            i++;
        }

        // Начало слова
        if (str[i] != ' ' && str[i] != '\0')
        {
            wordStart = i;
            currentWordNumber++;

            // Копируем слово
            int j = 0;
            while (str[i] != ' ' && str[i] != '\0')
            {
                currentWord[j++] = str[i++];
            }
            currentWord[j] = '\0';

            // Считаем буквы 'A'
            int aCount = countA(currentWord);

            // Проверяем на максимум
            if (aCount > maxCount)
            {
                maxCount = aCount;
                wordNumber = currentWordNumber;
                strcpy(maxWord, currentWord);
            }
        }
    }

    // Вывод результата
    if (maxCount > 0)
    {
        printf("Слово с максимальным количеством букв 'A': %s\n", maxWord);
        printf("Номер слова: %d\n", wordNumber);
        printf("Количество букв 'A': %d\n", maxCount);
    }
    else
    {
        printf("Слово с буквами 'A' не найдено.\n");
    }

    return 0;
}