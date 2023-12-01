/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 4.1 - Подпрограммы, библиотечные функции                             
Задача I. Степень строки.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
21.11.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/
 
#include <iostream>
#include <string.h>
 
#define length 1024
 
 
int main(void) {
    char string[length] = {'\0'}, substring[length] = {'\0'};
    int k;
 
    scanf("%s", string);
    scanf("%d", &k);
 
    int flag_mk = 1;
    if (k < 0) {
        strncpy(substring, string, strlen(string) / (-k));
        int len = strlen(substring);
        if (strlen(string) % len != 0) {
            flag_mk = 0;
        }
        for (int i = 0; i < strlen(string); i++) {
            if (string[i] != string[i % len]) {
                flag_mk = 0;
            }
        }
        if (flag_mk) {
           puts(substring);
        } else {
            puts("NO SOLUTION");
        }
    } else if (k > 0) {
        for (int i = 0; i < k; i++) {
            strncat(substring, string, 1024 - strlen(substring) - 1);
        }
        puts(substring);
    }
    return 0;
}