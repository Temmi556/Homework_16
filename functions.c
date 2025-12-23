#include "functions.h"
#include <time.h> 

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
        B[i] = A[i] * 2.0; 
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
// Количество элементов массива, расположенных между первым и последним нулевыми элементами
void count_between_zeros(void) {
    int n;
    printf("Введите размер массива > ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Поиск первого нулевого элемента
    int first_zero = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            first_zero = i;
            break;
        }
    }

    // Поиск последнего нулевого элемента
    int last_zero = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            last_zero = i;
            break;
        }
    }

    // Вывод массива
    printf("Массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Подсчёт элементов между нулями
    if (first_zero == -1 || last_zero == -1) {
        printf("В массиве нет нулевых элементов\n");
    } else if (first_zero == last_zero) {
        printf("В массиве только один нулевой элемент (индекс %d)\n", first_zero);
        printf("Количество элементов между нулями: 0\n");
    } else {
        int count = last_zero - first_zero - 1;
        printf("Первый ноль на индексе %d, последний на индексе %d\n", first_zero, last_zero);
        printf("Количество элементов между нулями: %d\n", count);
    }

    free(arr);
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


void generate_and_merge_arrays(void) {
    srand(time(NULL)); // инициализация генератора случайных чисел

    int n = 10 + rand() % 41; // от 10 до 50
    int m = 10 + rand() % 41;
    int l = 10 + rand() % 41;

    double *a = malloc(n * sizeof(double));
    double *b = malloc(m * sizeof(double));
    double *c = malloc(l * sizeof(double));

    // Генерация случайных чисел от 10 до 50
    for (int i = 0; i < n; i++) a[i] = 10.0 + (rand() % 41); // [10, 50]
    for (int i = 0; i < m; i++) b[i] = 10.0 + (rand() % 41);
    for (int i = 0; i < l; i++) c[i] = 10.0 + (rand() % 41);

    int d_size = n + m + l;
    double *d = malloc(d_size * sizeof(double));

    
    int idx_a = 0, idx_b = 0, idx_c = 0;
    int idx_d = 0;
    
    // Чередование: берём по одному элементу из каждого массива по очереди
    while (idx_a < n || idx_b < m || idx_c < l) {
        if (idx_a < n) d[idx_d++] = a[idx_a++];
        if (idx_b < m) d[idx_d++] = b[idx_b++];
        if (idx_c < l) d[idx_d++] = c[idx_c++];
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

// === Лаба 17 ===
void sort_bubble(int *ptarr,int n ){
    int temp;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (ptarr[j] > ptarr[j+1]){
                temp = ptarr[j];
                ptarr[j] = ptarr[j+1];
                ptarr[j+1] = temp;
            }
        }
    }
}
void easy_sort(int *ptarr, int n){
    int imax, temp; // индекс максимального элемента
    for (int i = 0; i < n-1; i++){ // проходим по всему массиву
        imax = i;
        for (int j = i+1; j < n; j++){ // ищем максимальный элемент в неотсортированной части массива
            if (ptarr[j] > ptarr[imax]){
                imax = j;
            }
        }
        // меняем местами найденный максимальный элемент с первым элементом неотсортированной части
        temp = ptarr[i];
        ptarr[i] = ptarr[imax];
        ptarr[imax] = temp;
    }
}
int * full_array(int *ptarr, int n){
    // Заполнение массива случайными числами от 0 до 100
    srand(time(NULL)); 
    for (int i = 0; i < n; i++){
        ptarr[i] = rand() % 101; // случайное число от 0 до 100
    }
    return ptarr;
}

int putt_array(int *ptarr, int n){
    printf("Элементы массива:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", ptarr[i]);
    }
    printf("\n");
    return 0;
}
void sort_bubble_flag(int *ptarr, int n){
    int temp;
    int flag;
    for (int i = 0; i < n-1; i++){
        flag = 0; // флаг для проверки, были ли обмены
        for (int j = 0; j < n-i-1; j++){
            if (ptarr[j] > ptarr[j+1]){
                temp = ptarr[j];
                ptarr[j] = ptarr[j+1];
                ptarr[j+1] = temp;
                flag = 1; // обмен произошёл
            }
        }
        if (flag == 0){
            break; // массив уже отсортирован
        }
    }
}
void lab_17(void) {
    printf("\n=== Лаба 17 ===\n");
    int n;
    printf("\n=== Сортировка пузырьком ===\n");
    printf("Введите размер массива : ");
    scanf("%d", &n);
    int *ptarr = (int *)malloc(n * sizeof(int)); // Выделение памяти под массив
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ptarr[i]);
    }
    sort_bubble(ptarr, n);
    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptarr[i]);    
        
    }
    printf("\n");
    printf("\n=== Сортировка простым выбором ===\n");
    printf("Введите размер массива : ");
    scanf("%d", &n);
    ptarr = (int *)realloc(ptarr, n * sizeof(int)); 
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ptarr[i]);
    }
    easy_sort(ptarr, n);
    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptarr[i]);
    }
    printf("\n");
    

    
}
void lab_17_experiment(void){
    int size;
    clock_t t;
    double total_time;
    int repeats = 10;

    printf("Введите размер массива для эксперимента: ");
    scanf("%d", &size);
    printf("Количество повторений: %d\n\n", repeats);

    // === Сортировка пузырьком ===
    total_time = 0;
    for (int r = 0; r < repeats; r++) {
        int *ptarr_1 = (int *)malloc(size * sizeof(int));
        full_array(ptarr_1, size);
        t = clock();
        sort_bubble(ptarr_1, size);
        t = clock() - t;
        total_time += ((double)t) / CLOCKS_PER_SEC;
        free(ptarr_1);
    }
    printf("Сортировка пузырьком для %d элементов:\n", size);
    printf("  Среднее время за %d повторений: %.8f секунд\n\n", repeats, total_time / repeats);

    // === Сортировка простым выбором ===
    total_time = 0;
    for (int r = 0; r < repeats; r++) {
        int *ptarr_2 = (int *)malloc(size * sizeof(int));
        full_array(ptarr_2, size);
        t = clock();
        easy_sort(ptarr_2, size);
        t = clock() - t;
        total_time += ((double)t) / CLOCKS_PER_SEC;
        free(ptarr_2);
    }
    printf("Сортировка простым выбором для %d элементов:\n", size);
    printf("  Среднее время за %d повторений: %.8f секунд\n\n", repeats, total_time / repeats);

    // === Сортировка пузырьком с флагом ===
    total_time = 0;
    for (int r = 0; r < repeats; r++) {
        int *ptarr_3 = (int *)malloc(size * sizeof(int));
        full_array(ptarr_3, size);
        t = clock();
        sort_bubble_flag(ptarr_3, size);
        t = clock() - t;
        total_time += ((double)t) / CLOCKS_PER_SEC;
        free(ptarr_3);
    }
    printf("Сортировка пузырьком с флагом для %d элементов:\n", size);
    printf("  Среднее время за %d повторений: %.8f секунд\n\n", repeats, total_time / repeats);
}