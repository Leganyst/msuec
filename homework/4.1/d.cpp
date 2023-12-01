/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 4.1 - Подпрограммы, библиотечные функции                             
Задача D. Судоку                                                             
Степичев Олег Геннадиевич (КТбо1-8)                                                      
15.11.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/
 
#include <stdio.h>
 
#define size_arr 100
 
/**
 * @brief проверяет на корректность условия судоку каждый средний квадрат в заданной сетке.
 * 
 * @param arr указатель на двумерный массив, который представляет собой поле судоку
 * @param n размерность поля судоку
 * @return 0 в случае не соблюдения условия и 1 в случае соблюдения
 */
int check_square(int (*arr)[size_arr], int n);
 
/**
 * @brief проверяет на корректность условия судоку каждую строку в заданной сетке
 * 
 * @param arr указатель на двумерный массив, который представляет собой поле судоку
 * @param n размерность поля судоку
 * @return 0 в случае не соблюдения условия и 1 в случае соблюдения
 */
int check_line(int (*arr)[size_arr], int n); 
 
/**
 * @brief проверяет на корректность условия судоку каждый столбец в заданной сетке
 * 
 * @param arr указатель на двумерный массив, который представляет собой поле судоку
 * @param n размерность поля судоку
 * @return 0 в случае не соблюдения условия и 1 в случае соблюдения
 */
int check_column(int (*arr)[size_arr], int n);
 
int main(void) {
    int n, sudoku[size_arr][size_arr], (*ptr_sudoku)[size_arr] = sudoku;
    int correct = 1;
 
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
        for (int j = 0; j < n * n; j++) {
            scanf("%d", &(sudoku[i][j]));
        }
    }
 
    ptr_sudoku = sudoku;
    if (correct) {
        if (!(check_line(ptr_sudoku, n))) {
            correct = 0;
        }
    }
 
    ptr_sudoku = sudoku;
    if (correct) {
        if (!(check_column(ptr_sudoku, n))) {
            correct = 0;
        }
    }
 
    if (correct) {
        if (!(check_square(ptr_sudoku, n))) {
            correct = 0;
        }
    }
 
    if (correct)
        printf("Correct");
    else
        printf("Incorrect");
 
    return 0;
}
 
 
int check_square(int (*arr)[size_arr], int n) {
    int correct = 1;

    for (int step_row = 0; step_row < n * n && correct; step_row += n) {
        for (int step_column = 0; step_column < n * n; step_column += n) {
            int arr_check[size_arr] = {0};
            for (int i = step_row; i < step_row + n; i++) {
                for (int j = step_column; j < step_column + n; j++) {
                    arr_check[arr[i][j]] = 1;
                }
            }
            for (int i = 1; i <= n * n && correct; i++) {
                if (arr_check[i] == 0) {
                    correct = 0;
                }
            }

        }
    }

    return correct;
}
  
int check_column(int (*arr)[size_arr], int n) {
    int correct = 1;
     
    for (int j = 0; j < n * n; j++) {
        int arr_check[size_arr] = {0};
        for (int i = 0; i < n * n; i++) {
            arr_check[arr[i][j]] = 1;
        }
        for (int i = 1; i <= n * n && correct; i++) {
            if (arr_check[i] == 0) {
                correct = 0;
            }
        }
    }

    return correct;
}
 
int check_line(int (*arr)[size_arr], int n) {
    int correct = 1;
     
    for (int i = 0; i < n * n; i++) {
        int arr_check[size_arr] = {0};
        for (int j = 0; j < n * n; j++) {
            arr_check[arr[i][j]] = 1;
        }
        for (int i = 1; i <= n * n && correct; i++) {
            if (arr_check[i] == 0) {
                correct = 0;
            }
        }
    }
    return correct;
}