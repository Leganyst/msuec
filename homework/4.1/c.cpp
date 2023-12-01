/*---------------------------------------------------------------------------------------|
Южный Федеральный Университет                                                            |
Институт Компьютерных Технологий и Информационной Безопасности                           |
Кафедра МОП ЭВМ                                                                          |
Программирование и Основы Теории Алгоритмов                                              |
Лабораторная работа 4.1 - Подпрограммы, библиотечные функции                             |
Задача С. Расстояние Хээминга                                                            |
Степичев Олег Геннадиевич (КТбо1-8)                                                      |
15.11.2023                                                                               |
*///-------------------------------------------------------------------------------------|
#include <stdio.h>
#define size_arr 65000


/**
 * @brief Находит и возвращает расстояние Хэмминга в двух строках.
 *
 * @param p_s искомая строка
 * @param p_b строка в которой ищем расстояние
 * @return int 
 */
int distance_hamming(char* p_s, char* p_b);

int main (void) {
    char s[size_arr];
    char b[size_arr];
    int result[size_arr] = {0};
    int counter = 0, n, min_distance = size_arr;
    int* p_result = result;

    scanf("%s", s);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int distance;

        scanf("%s", b);
        distance = distance_hamming(s, b);
        if (distance < min_distance) {
            min_distance = distance;
            p_result = result;
            *p_result = i + 1;
            p_result++;
            counter = 1;
        } else if (distance == min_distance) {
            *p_result = i + 1;
            p_result++;
            counter++;
        }
    }
    *(p_result + 1) = 0;

    printf("%d\n", counter);
    
    for (int i = 0; i < counter; i++) {
        printf("%d ", result[i]);
    }
}

int distance_hamming(char* p_s, char* p_b) {
    int distance = 0;
    
    while (*p_s && *p_b) {
        if (*p_s != *p_b) {
            distance++;
        }
        p_s++;
        p_b++;

    }

    return distance;
}

