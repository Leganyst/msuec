/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 4.1 - Подпрограммы, библиотечные функции                             
Задача J. Java vs C++.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
22.11.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define length 200

void to_java(char* string, char* new_string);

void to_c(char* string, char* new_string);

int main(void) {
    char string[length] = {'\0'}, new_string[length] = {'\0'};
    int flag_upper = 0, flag_underscore = 0, correct = 0;

    scanf("%s", string);

    for (int i = 0; i < strlen(string); i++) {
        if (isupper(string[i])) {
            flag_upper = 1;
        }   
        if (string[i] == '_') {
            flag_underscore = 1;
            if (string[i + 1] == '_') {
                correct = 1;
            }
        }

    }
    if (!(isalpha(*string)) || !(islower(*string)) || !(isalpha(string[strlen(string) - 1]))) {
        correct = 1;
    }

    if (flag_underscore && flag_upper || correct) {
        puts("Error!");
        printf("\n");
    } else if (flag_underscore) {
        to_java(string, new_string);
        puts(new_string);
        printf("\n");
    } else if (flag_upper) {
        to_c(string, new_string);
        puts(new_string);
        printf("\n");
    } else {
        puts(string);
        printf("\n");
    }

    return 0;
}


void to_java(char* string, char* new_string) {
    int len_s = strlen(string);
    for (int i = 0; i < len_s; i++) {
        if (*string != '_') {
            *new_string = *string;
            string++;
            new_string++;
        } else if (*string == '_') {
            *new_string = toupper(*(string + 1));
            new_string++;
            string += 2; 
        }
    }
    *new_string = '\0';
}


void to_c(char* string, char* new_string) {
    int len_s = strlen(string);
    for (int i = 0; i < len_s; i++) {
        if (isupper(*string)) {
            *new_string = '_';
            *(new_string + 1) = tolower(*string);
            new_string += 2;
            string++;
        } else {
            *new_string = *string;
            string++;
            new_string++;
        }
    }
    *new_string = '\0';
}

