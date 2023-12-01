/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 4.1 - Подпрограммы, библиотечные функции                             
Задача G. Игра в числа.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
18.11.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/


#include <stdio.h>

#define size_arr 1000

/**
 * @brief функция удаляет первый или последний элемент (в зависимости от того, какой элемент больше) 
 * и прибавляет его к переданному игроку, после чего выбранный элемент обнуляет.
 * 
 * @param player указатель на игрока. Непосредственно изменяется значение у игрока.
 * @param start указатель на первый элемент массива. Непосредственно изменяется значение данного элемента.
 * @param end указатель на последний элемент массива. Непосредственно изменяется значение данного элемента.
 * @return 0 или 1. 0 - в случае обнуления первого элемента массива, 1 в случае обнуления последнего элемента.
 */
int delete_number(int *player, int* start, int* end);

int main(void) {
    int n, numbers[size_arr] = {0}, first_player = 0, second_player = 0;
    int *p_numbers_start = numbers, *p_numbers_end = NULL;

    scanf("%d", &n);

    p_numbers_end = &(numbers[n - 1]);

    for (int i = 0; i < n; i++) {
        scanf("%d", &(numbers[i]));
    }

    int i = 0;
    while (*p_numbers_end && *p_numbers_start) {
        int how_delete = 0;

        // удаляем число и выясняем какое удалили (в конце или начале)
        how_delete = (i % 2 == 0) ? 
        (delete_number(&first_player, p_numbers_start, p_numbers_end)) : 
        (delete_number(&second_player, p_numbers_start, p_numbers_end));

        how_delete ? p_numbers_end-- : p_numbers_start++;
        i++;
    }    

    printf("%d:%d", first_player, second_player);

    return 0;
}


int delete_number(int *player, int* start, int* end) {
    int result = 0;
    
    // условие с тремя инструкциями 
    (*end > *start) ? (*player += *end, *end = 0, result = 1) : (*player += *start, *start = 0, result = 0); 

    return result;
}