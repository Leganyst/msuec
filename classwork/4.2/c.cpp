/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 4.1 - Подпрограммы, библиотечные функции                             
Задача C. Параграф.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
19.11.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/

#include <string.h>
#include <stdio.h>
#define length 256

int main(void) {
    char string_need[length];
    int m;

    scanf("%d", &m);
    fgets(string_need, length, stdin);

    char line[length];

    char *ptr_s = strtok(string_need, " ");
    strcpy(line, ptr_s);
    ptr_s = strtok(NULL, " ");

    while (ptr_s != NULL) {
        if (strlen(line) + strlen(ptr_s) < m) {
            strcat(line, " ");
            strcat(line, ptr_s);
        } else {
            puts(line);
            strcpy(line, ptr_s);
            printf("\n");
        }
        strtok(NULL, " ");
    }

    puts(line);

    return 0;
}