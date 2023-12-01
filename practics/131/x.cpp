/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Практикум по программированию 13.1 - Подпрограммы, библиотечные функции                             
Задача X. Сумма кубов.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
22.11.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/
#include <cmath>
#include <stdio.h>

int cube(int number, int count);


int main(void) {
    int number, count = 0;
    scanf("%d", &number);
    if (!(cube(number, count))) {
        printf("IMPOSSIBLE");
    };

    return 0;
    }

int cube(int number, int count) {
    int cube_number = (int) cbrt(number);
    int result = 1;

    if (count > 8){
        result = 0;
    } else if (cube_number == 0 && count == 0) {
        printf("%d", number);
        result = 1;
    } else if (cube_number != 0 && count >= 0 && count + 1 <= 9) {
        result = cube(number - pow(cube_number, 3), count + 1);
        if (result) {
            printf("%d ", cube_number);
        }
    }

    return result;
}
