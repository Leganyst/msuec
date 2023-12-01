/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 5.1 - Текстовые и бинарные файлы                     
Задача C. Баллы.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
30.12.2023                                                                               
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
*/

#include <stdio.h>

#define students_count 200000

/**
 * @brief Реализация бинарного поиска в упорядоченном массиве.
 * 
 * @param arr Упорядоченный массив целых чисел.
 * @param size Размер массива.
 * @param x Элемент, который необходимо найти.
 * @return int Возвращает 1, если элемент найден, и 0 в противном случае.
 */
int binary_search(long long int arr[], int size, long long int x);

int main() {
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);

    int n, k;
    scanf("%d %d", &n, &k);

    long long int arr[students_count];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    for (int i = 0; i < k; i++) {
        long long int x;
        scanf("%lld", &x);

        if (binary_search(arr, n, x)) {
            printf("YES ");
        } else {
            printf("NO ");
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}


int binary_search(long long int arr[], int size, long long int x) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return 1;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}
