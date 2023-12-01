/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 4.1 - Подпрограммы, библиотечные функции                             
Задача H. Две кучки камней.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
21.11.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/

#include <stdio.h>
#include <stdlib.h>

#define stones_count 20

/**
 * @brief Разделяет массив камней на две кучки с минимальной разницей в массе.
 *
 * Функция рекурсивно исследует все возможные варианты разделения массива камней
 * на две кучки и возвращает минимальную разницу в массе между этими кучками.
 *
 * @param stones Указатель на массив камней.
 * @param sum1 Текущая сумма массы кучки 1.
 * @param sum2 Текущая сумма массы кучки 2.
 * @return Минимальная разница в массе между двумя кучками.
 */
int stones_heaps(int *stones, int sum1, int sum2);


int main(void) {
    int n, stones[stones_count] = {0};

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &(stones[i]));
    }

    int sum1 = 0, sum2 = 0, result = 0;
    result = stones_heaps(stones, sum1, sum2);

    printf("%d", result);
}

int stones_heaps(int *stones, int sum1, int sum2) {
    if (*stones) {
        int option1 = stones_heaps(stones + 1, sum1 + *stones, sum2);
        int option2 = stones_heaps(stones + 1, sum1, sum2 + *stones);

        return (option1 < option2) ? option1 : option2;
    } else {
        return abs(sum1 - sum2);
    }
}