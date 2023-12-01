/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 5.1 - Текстовые и бинарные файлы                     
Задача A. Лестница.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
30.12.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input_file = fopen("INPUT.txt", "r");
    FILE *output_file = fopen("OUTPUT.txt", "wt");
    
    if (input_file == NULL || output_file == NULL) {
        exit(1);
    }
    int k, height = 0;

    fscanf(input_file, "%d", &k);
    fclose(input_file);

    while (k >= height + 1) {  
        height++;
        k -= height;
    }

    fprintf(output_file, "%d", height);
    
    fclose(output_file);

    return 0;
    }