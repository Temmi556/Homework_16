#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>

// === Классная работа 11 ===
#define PI 3.14
#define N 10.0

float funct_1(float x);
int task_1(void);
int task_2(void);

// === ДЗ к 11 ===
void count_between_zeros(void);

// === Лабы 14, 16 и ДЗ к ним ===
double f(double x);
double* full_elements(double *ptr_array, int n);
int put_elements(double *ptr_array, int n);
double* calc_elements(double *ptr_array, int n);
double sum_elements(double *ptr_array, int begin, int end);
int find_element(double *ptr_array, int n, double element);
double max_begin_end(double *ptr_array, int begin, int end);

// === ДЗ к 16 ===
void generate_and_merge_arrays(void);

// === Лаба 17 ===
void lab_17(void);
void lab_17_experiment(void); // Экспериментальная часть Лабы 17
void sort_bubble(int *ptarr, int n); // Пузырьковая сортировка
void sort_bubble_flag(int *ptarr, int n); // Пузырьковая сортировка с флагом
void easy_sort(int *ptarr, int n); // Сортировка простым выбором
int * full_array(int *ptarr, int n); //Функция заполнения массива
int putt_array(int *,int); // Функция вывода массива
#endif 