#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Func.h"

char *change_c_text(char str1[], char str2[], int search, int replace) {
    // Выделение памяти для новой строки
    char *new_str = (char *) malloc((strlen(str1) + 1) * sizeof(char));
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (search <= 0 || search > len1 || replace <= 0 || replace > len2) {
        printf("Index out of array!\n");
        return NULL; // Предотвращаем выход за границы
    }
    if (!new_str) {
        printf("Memory allocation error!\n");
        return NULL;
    }
    int replace_index;
    for (int i = 0; i < len1; i++) {
        if ((i + 1) % search == 0) {
            // Индекс с циклическим смещением для замены
            replace_index = (search + replace - 1) % len2;
            new_str[i] = str2[replace_index];
        } else {
            new_str[i] = str1[i];
        }
    }
    new_str[len1] = '\0'; // Завершаем строку
    return new_str;
}

int run() {
    char first_str[300], second_str[300];
    printf("First string:");
    fgets(first_str, 300, stdin);
    fflush(stdin);
    printf("Second string:");
    fgets(second_str, 300, stdin);
    fflush(stdin);

    int search_character, replace_character;
    printf("Search character:");
    scanf("%d", &search_character);
    printf("Replace character:");
    scanf("%d", &replace_character);

    char *new_str = change_c_text(first_str, second_str, search_character, replace_character);

    if (new_str != NULL) {
        printf("Modified string: %s\n", new_str);
        free(new_str);
    }
    fflush(stdin);
    run();
    return 0;
}
