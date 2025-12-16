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
void count_words_and_letters(void);

// === Лабы 14, 16 и ДЗ к ним ===
double f(double x);
double* full_elements(double *ptr_array, int n);
int put_elements(double *ptr_array, int n);
double* calc_elements(double *ptr_array, int n);
double sum_elements(double *ptr_array, int begin, int end);
int find_element(double *ptr_array, int n, double element);
double max_begin_end(double *ptr_array, int begin, int end);

// === ДЗ к 16 (по фото) ===
void generate_and_merge_arrays(void);

#endif // FUNCTIONS_H