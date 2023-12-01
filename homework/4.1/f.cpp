/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 4.1 - Подпрограммы, библиотечные функции                             
Задача F. Ферзь, ладья и конь.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
19.11.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/
#include <iostream> 

#define field_size 8

/**
 * @brief Проверяет, может ли ферзь (королева) походить в переданную координату из её позиции.
 * 
 * @param x_start переданная координата по X.
 * @param y_start переданная координата по Y.
 * @param x_figure координата X ферзя (королевы).
 * @param y_figure координата Y ферзя (королевы).
 * @return 0 или 1. 0 - в случае если не может, 1 в случае если может.
 */
int step_queen(int x_start, int y_start, int x_figure, int y_figure);


/**
 * @brief Проверяет, может ли ладья походить в переданную координату из её позиции.
 * 
 * @param x_start переданная координата по X.
 * @param y_start переданная координата по Y.
 * @param x_figure координата X ладьи.
 * @param y_figure координата Y ладьи.
 * @return 0 или 1. 0 - в случае если не может, 1 в случае если может.
 */
int step_rook(int x_start, int y_start, int x_figure, int y_figure);

/**
 * @brief Проверяет, может ли конь походить в переданную координату из её позиции.
 * 
 * @param x_start переданная координата по X.
 * @param y_start переданная координата по Y.
 * @param x_figure координата X коня.
 * @param y_figure координата Y коня.
 * @return 0 или 1. 0 - в случае если не может, 1 в случае если может.
 */
int step_horse(int x_start, int y_start, int x_figure, int y_figure);

int main(void) {
    int field[field_size][field_size] = {0};
    char y_cords[3];
    int x_cords[3];

    // ферзь ладья и конь
    scanf("%c%d %c%d %c%d", &(y_cords[0]), &(x_cords[0]), &(y_cords[1]), &(x_cords[1]), &(y_cords[2]), &(x_cords[2]));

    int (*functions[3]) (int, int, int, int) = {step_queen, step_rook, step_horse};

    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < field_size; x++) {
            for (int y = 0; y < field_size; y++) {
                if (!field[x][y]) {
                    field[x][y] = functions[i](x, y, x_cords[i] - 1, y_cords[i] - 'A');
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < field_size; i++) {
        for (int j = 0; j < field_size; j++) {
            result += field[i][j];
        }
    }

    result -= 3;

    printf("%d", result);

    return 0;
}

int step_rook(int x_start, int y_start, int x_figure, int y_figure) {
    int result;
    result = (x_start == x_figure) || (y_start == y_figure);
    return result;
}

int step_horse(int x_start, int y_start, int x_figure, int y_figure) {
    int result;
    result = (((x_figure - x_start) * (y_figure - y_start) == 2) || ((x_figure - x_start) * (y_figure - y_start) == -2)) || 
    ((x_figure == x_start) && (y_figure == y_start));

    return result;
}

int step_queen(int x_start, int y_start, int x_figure, int y_figure) {
    int diagonal_x, diagonal_y, line, result;
    diagonal_x = ((x_start - x_figure) > 0) ? x_start - x_figure : -(x_start - x_figure);
    diagonal_y = ((y_start - y_figure) > 0) ? y_start - y_figure : -(y_start - y_figure);

    line = ((x_figure == x_start) && (y_figure != y_start)) || ((x_start != x_figure) && (y_figure == y_start));

    result = ((!(diagonal_x - diagonal_y)) || line);
    return result;
}