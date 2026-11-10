#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
char map[SIZE][SIZE];
int px = 0, py = 0; // Позиция игрока
int health = 10;
int gold = 0;

void initGame() {
    // Заполняем карту пустотой
    for(int i=0; i<SIZE; i++) for(int j=0; j<SIZE; j++) map[i][j] = '.';
    
    // Расставляем объекты
    map[SIZE-1][SIZE-1] = 'E'; // Выход
    map[5][5] = 'X'; map[2][8] = 'X'; map[7][3] = 'X'; // Ловушки
    map[1][1] = 'G'; map[8][2] = 'G'; map[4][7] = 'G'; // Золото
}

void printMap() {
    printf("\nЗдоровье: %d | Золото: %d\n", health, gold);
    printf("-------------------------------\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            // Игрок всегда виден
            if(i == py && j == px) printf(" P ");
            // Туман войны: показываем клетку только если рядом с игроком
            else if(abs(i-py) <= 1 && abs(j-px) <= 1) printf(" %c ", map[i][j]);
            else printf(" ? ");
        }
        printf("\n");
    }
    printf("-------------------------------\n");
}

int main() {
    srand(time(NULL));
    initGame();
    char move;
    
    printf("Добро пожаловать в Подземелье! Найдите выход 'E'.\n");
    
    while(health > 0) {
        printMap();
        printf("WASD для движения (E для выхода): ");
        scanf(" %c", &move);
        
        if(move == 'e' || move == 'E') break;

        int nx = px, ny = py;
        if(move == 'w' || move == 'W') ny--; 
        else if(move == 's' || move == 'S') ny++;
        else if(move == 'a' || move == 'A') nx--; 
        else if(move == 'd' || move == 'D') nx++;
        else {
            printf("Неверная команда!\n");
            continue;
        }
        
        // Проверка границ поля
        if(nx>=0 && nx<SIZE && ny>=0 && ny<SIZE) {
            px = nx; py = ny;
            
            // Логика событий
            if(map[py][px] == 'X') { 
                health -= 3; 
                printf("!!! БАБАХ! Ловушка! -3 HP !!!\n"); 
            }
            else if(map[py][px] == 'G') { 
                gold += 10; 
                map[py][px] = '.'; 
                printf("!!! Нашел золото! +10 Gold !!!\n"); 
            }
            else if(map[py][px] == 'E') { 
                printf("\nПОБЕДА! Вы выбрались! Золото: %d\n", gold); 
                return 0; 
            }
        } else {
            printf("Там стена!\n");
        }
    }
    
    printf("\nGAME OVER. Вы погибли в подземелье.\n");
    return 0;
}
