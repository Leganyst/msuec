/*
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Южный Федеральный Университет                                                            
Институт Компьютерных Технологий и Информационной Безопасности                           
Кафедра МОП ЭВМ                                                                          
Программирование и Основы Теории Алгоритмов                                              
Лабораторная работа 5.1 - Текстовые и бинарные файлы                     
Задача B. Jивой Jурнал.                                                       
Степичев Олег Геннадиевич (КТбо1-8)                                                      
03.12.2023, 00:20                                                                                
-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
Условие задачи:
https://acmp.ru/index.asp?main=task&id_task=56
..............................................

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FRIENDS 200
#define MAX_NAME_LENGTH 20

/**
 * @brief Сравнивает две строки (массивы символов) в контексте сортировки для использования в qsort.
 *
 * @param s1 Указатель на первую строку (массив символов).
 * @param s2 Указатель на вторую строку (массив символов).
 * @return Возвращает отрицательное значение, если s1 меньше s2, положительное, если s1 больше s2, и 0, если строки равны.
 */
int compare_strings(const void *s1, const void *s2);


int main(void) {

    char have_friends[MAX_FRIENDS + 1][MAX_NAME_LENGTH + 1], be_friend[MAX_FRIENDS + 1][MAX_NAME_LENGTH + 1];
    int n, m;

    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        fclose(file);
        exit(1);
    } 

    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s", have_friends[i]);
    }

    fscanf(file, "%d", &m);
    for (int i = 0; i < m; i++) {
        fscanf(file, "%s", be_friend[i]);
    }

    // qsort(be_friend, m, sizeof(be_friend[0]), (int (*)(const void *, const void *))compare_strings);
    qsort(have_friends, n, sizeof(have_friends[0]), compare_strings);
    qsort(be_friend, m, sizeof(be_friend[0]), compare_strings);
    // qsort(have_friends, n, sizeof(have_friends[0]), (int (*)(const void *, const void *))compare_strings);

    char mutural_friends[MAX_FRIENDS + 1][MAX_NAME_LENGTH + 1];
    int mutural_count = 0;

    int mutual_count = 0;
    char mutual_friends[MAX_FRIENDS][MAX_NAME_LENGTH + 1];
    for (int i = 0; i < n; ++i) {
        int found = 0;
        for (int j = 0; j < m; ++j) {
            if (strcmp(have_friends[i], be_friend[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            strcpy(mutual_friends[mutual_count++], have_friends[i]);
        }
    }

    int also_count = 0;
    char also_friend_of_list[MAX_FRIENDS][MAX_NAME_LENGTH + 1];
    for (int i = 0; i < m; ++i) {
        int found = 0;
        for (int j = 0; j < n; ++j) {
            if (strcmp(be_friend[i], have_friends[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(also_friend_of_list[also_count++], be_friend[i]);
        }
    }    

	printf("Friends: ");
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1) printf("%s, ", have_friends[i]);
		else printf("%s", have_friends[i]);
	}
	printf("\nMutual Friends: ");
	for (int i = 0; i < mutual_count; i++)
	{
		if (i != mutual_count - 1) printf("%s, ", mutual_friends[i]);
		else printf("%s", mutual_friends[i]);
	}
	printf("\nAlso Friend of: ");
	for (int i = 0; i < also_count; i++)
	{
		if (i != also_count - 1) printf("%s, ", also_friend_of_list[i]);
		else printf("%s", also_friend_of_list[i]);
	}

    fclose(file);

    return 0;
}

int compare_strings(const void *s1, const void *s2) {
    return strcmp(*(const char (*)[MAX_NAME_LENGTH + 1])s1, *(const char (*)[MAX_NAME_LENGTH + 1])s2);
    // return strcmp(*(const char **)s1, *(const char **)s2);
}
