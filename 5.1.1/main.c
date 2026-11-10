#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void examples_integers() {
    printf("--- Integers Example ---\n");
    unsigned long long l = 1;
    int i = 0;
    while (i < 30) { // Ограничим, чтобы не ждать вечно
        printf("<%llu (%d)>\n", l, i);
        l *= 2;
        i += 1;
    }
}

void examples_factorial_char() {
    printf("\n--- Factorial char Example ---\n");
    int n = 1;
    char fact = 1, prevFact = 1;
    while (n < 11) {
        fact = 1;
        int i = 1;
        do {
            fact = fact * i;
            i = i + 1;
        } while (i <= n);
        printf("<%hhi (%d!) %d>\n", fact, n, (int)(fact / prevFact));
        prevFact = fact;
        n += 1;
    }
}

void examples_factorial_int() {
    printf("\n--- Factorial int Example ---\n");
    int n = 1;
    int fact = 1, prevFact = 1;
    while (n < 20) {
        fact = 1;
        int i = 1;
        do {
            fact = fact * i;
            i = i + 1;
        } while (i <= n);
        printf("<%i (%d!) %d>\n", fact, n, (fact / prevFact));
        prevFact = fact;
        n += 1;
    }
}

void examples_floating_point() {
    printf("\n--- Floating Point Example ---\n");
    double f = 1.23456789012345678901234567890;
    int i = 0;
    while (i < 10) {
        printf("<%60.30f (%d)>\n", f, i);
        f *= 10;
        i += 1;
    }
    printf("sizeof: f = %zu, i = %zu\n", sizeof(f), sizeof(i));
}

void examples_pointer_1() {
    printf("\n--- Pointer Example 1 ---\n");
    int a;
    int* pa;
    a = 10;
    pa = &a;
    printf("val: a=%d *pa=%d pa=%p\n", a, *pa, (void*)pa);
    printf("ptr: &a=%p &pa=%p\n", (void*)&a, (void*)&pa);
    printf("sizeof: %zu %zu\n", sizeof(a), sizeof(pa));
    *pa = 30;
    printf("val: a=%d *pa=%d pa=%p\n", a, *pa, (void*)pa);
}

void f(int* ps, int a, int b) {
    *ps = a + b;
}

void examples_pointer_2() {
    printf("\n--- Pointer Example 2 ---\n");
    int i1, i2, i3;
    i1 = 10; i2 = 20; i3 = 30;
    printf("i1=%d i2=%d i3=%d\n", i1, i2, i3);
    f(&i1, i2, i3);
    printf("i1=%d i2=%d i3=%d\n", i1, i2, i3);
}

void examples_arrays() {
    printf("\n--- Arrays Example 1 ---\n");
    int a[4];
    a[0] = 1; a[1] = 10; a[2] = 100; a[3] = 1000;
    printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
    int b[5] = {2, 20, 200, 2000, 20000};
    printf("%d %d %d %d %d\n", b[0], b[1], b[2], b[3], b[4]);
}

struct date { int d, m, y; };

void examples_structs() {
    printf("\n--- Struct Example ---\n");
    struct date d1;
    d1.d = 11; d1.m = 3; d1.y = 2022;
    struct date d2 = { 31, 12, 2021 };
    printf("(%02d.%02d.%d)\n", d1.d, d1.m, d1.y);
    printf("(%02d.%02d.%d)\n", d2.d, d2.m, d2.y);
}

int main() {
    int choice;
    printf("Выберите функцию для запуска (1-9):\n");
    printf("1. Целые числа\n2. Факториал (char)\n3. Факториал (int)\n4. Вещественные числа\n5. Указатель 1\n6. Указатель 2\n7. Массивы\n8. Структуры\n9. Все примеры\n");
    if (scanf("%d", &choice) != 1) return 1;

    printf("main() start!\n");
    
    switch(choice) {
        case 1: examples_integers(); break;
        case 2: examples_factorial_char(); break;
        case 3: examples_factorial_int(); break;
        case 4: examples_floating_point(); break;
        case 5: examples_pointer_1(); break;
        case 6: examples_pointer_2(); break;
        case 7: examples_arrays(); break;
        case 8: examples_structs(); break;
        case 9:
            examples_integers();
            examples_factorial_char();
            examples_factorial_int();
            examples_floating_point();
            examples_pointer_1();
            examples_pointer_2();
            examples_arrays();
            examples_structs();
            break;
        default: printf("Invalid choice!\n");
    }
    
    printf("main() finish!\n");
    return 0;
}
