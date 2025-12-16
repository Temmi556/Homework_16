#include "functions.h"
#include <time.h> // для rand()

// === Классная работа 11 ===
float funct_1(float x){
    return x*x - pow(cos(2*PI*x),2);
}

int task_1(){
    float cr = 0.0; // Среднее значение
    float c = 0.0;  // сумма элементов массива
    float A[10];    // начальный массив
    float B[10];    // изменённый массив
    float temp;     // переменная для ввода значений в массив 

    for(int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }

    printf("|ИНДЕКС|ИСХОДНОЕ ЗНАЧЕНИЕ|НОВОЕ ЗНАЧЕНИЕ|\n");
    for (int i = 0; i < N; i++){
        B[i] = A[i] * 2.0; // Удвоенный результат
        c += B[i];
        printf("   %d         %.2f          %.2f\n", i, A[i], B[i]);
    }
    cr = c / N;
    printf("%.2f / %.1f = %.2f\n", c, N, cr);
    return 0;
}

int task_2(){
    float cr_2 = 0.0;
    float cr_1 = 0.0;
    float C[100];
    float x = 1.0;

    for (int i = 0; i < 100; i++){
        C[i] = funct_1(x);
        cr_1 += C[i];
        x += 0.02;
    }
    cr_2 = cr_1;
    cr_1 /= 100.0;

    printf("\nМассив C: сумма положительных чисел = %.2f, кол-во положительных 100, отрицательных 0, среднее значение = %.2f\n", cr_2, cr_1);
    return 0;
}

// === ДЗ к 11 ===
void count_words_and_letters(void) {
    setlocale(LC_ALL, "");
    
    wint_t c;
    int letters = 0;
    int words = 0;
    int in_word = 0;

    wprintf(L"Введите строку:\n");

    while ((c = getwchar()) != L'\n') {
        if (c != L' ' && c != L'\t') {
            letters++;
            if (!in_word) {
                words++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }

    if (words > 0)
        wprintf(L"Средняя длина слова = %.2f\n", (float)letters / words);
    else
        wprintf(L"Слова отсутствуют\n");
}

// === Лабы 14, 16 и ДЗ к ним ===
double f(double x){
    return x * x * x + 3 * x - 3;
}

double* full_elements(double *ptr_array, int n){
    double x = 2.0;
    for (int i = 0; i < n; ++i){
        ptr_array[i] = f(x);
        x += 0.01;
    }
    return ptr_array;
}

int put_elements(double *ptr_array, int n){
    printf("Элементы массива:\n");
    for (int i = 0; i < n; ++i){
        printf("%0.1lf\n", ptr_array[i]);
    }
    return 0;
}

double* calc_elements(double *ptr_array, int n){
    for (int i = 0; i < n; ++i){
        ptr_array[i] = ptr_array[i] * 2.0;
    }
    return ptr_array;
}

double sum_elements(double *ptr_array, int begin, int end){
    double sum = 0.0;
    for (int i = begin; i <= end; ++i){
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double *ptr_array, int n, double element){
    for (int i = 0; i < n; ++i){
        if (fabs(ptr_array[i] - element) < 0.1){
            return i;
        }
    }
    return -1;
}

double max_begin_end(double *ptr_array, int begin, int end){
    double max = ptr_array[begin];
    for (int i = begin; i <= end; ++i){
        if (ptr_array[i] > max){
            max = ptr_array[i];
        }
    }
    return max;
}

// === ДЗ к 16 (по фото) ===
void generate_and_merge_arrays(void) {
    srand(time(NULL)); // инициализация генератора случайных чисел

    int n = 5 + rand() % 11; // от 5 до 15
    int m = 5 + rand() % 11;
    int l = 5 + rand() % 11;

    double *a = malloc(n * sizeof(double));
    double *b = malloc(m * sizeof(double));
    double *c = malloc(l * sizeof(double));

    // Генерация случайных чисел от 10 до 50
    for (int i = 0; i < n; i++) a[i] = 10.0 + (rand() % 41); // [10, 50]
    for (int i = 0; i < m; i++) b[i] = 10.0 + (rand() % 41);
    for (int i = 0; i < l; i++) c[i] = 10.0 + (rand() % 41);

    int d_size = n + m + l;
    double *d = malloc(d_size * sizeof(double));

    // Чередование: d1=a0, d2=b0, d3=c0, d4=a1, d5=b1, d6=c1...
    int idx_a = 0, idx_b = 0, idx_c = 0;
    for (int i = 0; i < d_size; i++) {
        if (i % 3 == 0 && idx_a < n) {
            d[i] = a[idx_a++];
        } else if (i % 3 == 1 && idx_b < m) {
            d[i] = b[idx_b++];
        } else if (i % 3 == 2 && idx_c < l) {
            d[i] = c[idx_c++];
        } else {
            // Если один из массивов закончился — продолжаем по другим
            if (idx_a < n) d[i] = a[idx_a++];
            else if (idx_b < m) d[i] = b[idx_b++];
            else if (idx_c < l) d[i] = c[idx_c++];
        }
    }

    // Вывод массивов
    printf("\n=== Массив A (%d элементов):\n", n);
    for (int i = 0; i < n; i++) printf("%.1lf ", a[i]);
    printf("\n");

    printf("\n=== Массив B (%d элементов):\n", m);
    for (int i = 0; i < m; i++) printf("%.1lf ", b[i]);
    printf("\n");

    printf("\n=== Массив C (%d элементов):\n", l);
    for (int i = 0; i < l; i++) printf("%.1lf ", c[i]);
    printf("\n");

    printf("\n=== Массив D (чередование A, B, C, всего %d элементов):\n", d_size);
    for (int i = 0; i < d_size; i++) printf("%.1lf ", d[i]);
    printf("\n");

    free(a);
    free(b);
    free(c);
    free(d);
}