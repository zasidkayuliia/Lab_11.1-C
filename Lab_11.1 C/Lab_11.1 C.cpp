#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <direct.h> // Для _getcwd

// Функція для підрахунку пар сусідніх букв "aa", "bb" або "cc" в рядку
int countNeighboringPairs(const char* line) {
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if ((line[i] == 'a' && line[i + 1] == 'a') ||
            (line[i] == 'b' && line[i + 1] == 'b') ||
            (line[i] == 'c' && line[i + 1] == 'c')) {
            count++;
        }
    }
    return count;
}

// Функція для підрахунку пар у всьому файлі
int countPairsInFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Не вдалося відкрити файл.\n");
        return -1; // Повертаємо -1, якщо файл не вдалося відкрити
    }

    int totalCount = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        totalCount += countNeighboringPairs(line); // Додаємо кількість пар у поточному рядку
    }

    fclose(file);
    return totalCount;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* filename = "C:\\Users\\Dara\\Desktop\\t.txt";


    int pairCount = countPairsInFile(filename);
    if (pairCount == -1) {
        return 1; // Помилка відкриття файлу, завершуємо програму
    }

    if (pairCount > 0) {
        printf("У файлі знайдено %d пар(и) сусідніх букв \"aa\", \"bb\" або \"cc\".\n", pairCount);
    }
    else {
        printf("У файлі не знайдено пари сусідніх букв \"aa\", \"bb\" або \"cc\".\n");
    }

    return 0;
}



