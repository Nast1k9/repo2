#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10
#define MAX_POWER 10
#define HIGHT_TRUNC 3
#define NUM_LINES 10
#define WIN_THRESHOLD 6 // 60% от MAX_LENGTH

struct Line {
    int length;
    int power;
    int cut; // 0 - обычная, 1 - отрезана
};

struct Line lines[NUM_LINES];
int resources = 100; // Ресурсы игрока

void initGame() {
    for (int i = 0; i < NUM_LINES; i++) {
        lines[i].length = 5;
        lines[i].power = 8;
        lines[i].cut = 0;
    }
}

void printGameField() {
    printf("\n--- Жизненная сила (цвет): Синий(0-3), Зеленый(4-7), Красный(8+) --- Ресурсы: %d ---\n", resources);
    for (int i = 0; i < NUM_LINES; i++) {
        int empty_pos = MAX_LENGTH - lines[i].length;
        for (int p = 0; p < empty_pos; p++) printf(" ");

        for (int p = 0; p < lines[i].length; p++) {
            if (lines[i].cut) printf("-");
            else if (lines[i].power < 4) printf("\033[0;34m*\033[0m"); // Синий
            else if (lines[i].power < 8) printf("\033[0;32m*\033[0m"); // Зеленый
            else printf("\033[0;31m*\033[0m"); // Красный
        }
        printf("[%d]", i);
        for (int p = 0; p < lines[i].length; p++) {
            if (lines[i].cut) printf("-");
            else if (lines[i].power < 4) printf("\033[0;34m*\033[0m");
            else if (lines[i].power < 8) printf("\033[0;32m*\033[0m");
            else printf("\033[0;31m*\033[0m");
        }
        printf("\n");
    }
}

void doAutoStep() {
    if (rand() % 3 == 0) {
        int nline = rand() % NUM_LINES;
        if (!lines[nline].cut) lines[nline].power -= 2;
    }
    for (int i = 0; i < NUM_LINES; i++) {
        if (!lines[i].cut && lines[i].power < 5) lines[i].length--;
        if (lines[i].length < 0) lines[i].length = 0;
    }
}

int checkGameState() {
    int win = 1;
    for (int i = 0; i < NUM_LINES; i++) {
        if (lines[i].length == 0) return -1; // Проигрыш
        if (lines[i].length < WIN_THRESHOLD) win = 0;
    }
    return win ? 1 : 0; // 1 - Победа
}

int main() {
    srand(time(NULL));
    initGame();
    char command, line;

    while (1) {
        printGameField();
        int state = checkGameState();
        if (state == 1) { printf("ПОБЕДА! Дерево выросло!\n"); break; }
        if (state == -1) { printf("ПОРАЖЕНИЕ! Ветка отмерла.\n"); break; }

        printf("Команды: [T]reat(10), [F]eed(5), [C]ut, [E]xit. Пример: T0\n");
        scanf(" %c%c", &command, &line);
        while (getchar() != '\n');
        if (command == 'E') break;

        int nline = line - '0';
        if (nline >= 0 && nline < NUM_LINES) {
            switch (command) {
                case 'T': if (resources >= 10) { lines[nline].power = MAX_POWER; resources -= 10; lines[nline].cut = 0; } break;
                case 'F': if (resources >= 5 && !lines[nline].cut && lines[nline].length < MAX_LENGTH) { lines[nline].length++; resources -= 5; } break;
                case 'C': lines[nline].cut = 1; lines[nline].length = 1; lines[nline].power = 8; break;
            }
        }
        doAutoStep();
    }
    return 0;
}