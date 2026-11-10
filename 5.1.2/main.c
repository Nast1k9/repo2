#include <stdio.h>
#include <limits.h>
#include <float.h>

// Перечисления (4)
typedef enum { LOW, MEDIUM, HIGH } Priority;

// Структуры (3)
struct DataPacket {
    unsigned char id;
    int payload;
};

// Объединения (7)
union Data {
    int i;
    float f;
};

// Битовые поля (6)
struct Flags {
    unsigned int active : 1;
    unsigned int mode : 3;
};

// Указатели на функции (5.1)
void greet() { printf("Hello!\n"); }

void test_types() {
    printf("--- 1. Standard Types & Overflow ---\n");
    signed char sc = SCHAR_MAX;
    printf("char: %d, sizeof: %zu. Overflow: %d\n", sc, sizeof(sc), ++sc);

    unsigned int ui = UINT_MAX;
    printf("unsigned int: %u, sizeof: %zu. Overflow: %u\n", ui, sizeof(ui), ui + 1);

    double d = 1.23;
    int i = (int)d; // Явное
    float f = i;    // Неявное
    printf("Double: %f -> Int: %d -> Float: %f\n", d, i, f);
}

void test_arrays() {
    printf("\n--- 2. Arrays ---\n");
    int arr[3] = {10, 20, 30};
    printf("Arr[0]: %d, sizeof(arr): %zu\n", arr[0], sizeof(arr));
}

void test_pointers() {
    printf("\n--- 5. Pointers ---\n");
    int x = 100;
    int *ptr = &x;
    void (*func_ptr)() = greet;
    printf("Ptr points to: %d, sizeof(ptr): %zu\n", *ptr, sizeof(ptr));
    func_ptr();
}

int main() {
    printf("Select option (1: Types, 2: Arrays, 3: Pointers):\n");
    int ch;
    scanf("%d", &ch);

    if (ch == 1) test_types();
    else if (ch == 2) test_arrays();
    else if (ch == 3) test_pointers();
    
    return 0;
}
