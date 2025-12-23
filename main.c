#include "functions.h"

int main() {
    printf("=== Классная работа 11 ===\n");
    task_2(); 
    printf("\n=== ДЗ к 11 (подсчёт слов и букв) ===\n");
    count_words_and_letters();

    printf("\n=== Лаба 14/16 (массивы и функции) ====\n");
    double *ptr_array;
    int size;
    int begin, end;

    printf("Введите размер массива > ");
    scanf("%d", &size);

    ptr_array = (double *)malloc((size_t)size * sizeof(double));

    full_elements(ptr_array, size);
    calc_elements(ptr_array, size);
    put_elements(ptr_array, size);

    printf("Введите начальный и конечный индексы для суммы > ");
    scanf("%d %d", &begin, &end);
    double sum = sum_elements(ptr_array, begin, end);
    printf("Сумма элементов с индекса %d по индекс %d равна: %.1lf\n", begin, end, sum);

    printf("Введите элемент для поиска > ");
    double a;
    scanf("%lf", &a);
    int poi = find_element(ptr_array, size, a);
    if (poi != -1){
        printf("Элемент %.1lf найден на индексе %d\n", a, poi+1);
    } else {
        printf("Элемент %.1lf не найден в массиве\n", a);
    }

    printf("Введите начальный и конечный индексы для поиска максимального элемента > ");
    scanf("%d %d", &begin, &end);
    double max = max_begin_end(ptr_array, begin, end);
    printf("Максимальный элемент с индекса %d по индекс %d равен: %.1lf\n", begin, end, max);

    free(ptr_array);

    printf("\n=== ДЗ к 16 (генерация и чередование массивов) ===\n");
    generate_and_merge_arrays();

    return 0;
}