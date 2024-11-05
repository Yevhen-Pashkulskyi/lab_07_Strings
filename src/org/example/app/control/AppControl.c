#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Func.h"


char *change_c_text(char *str1, char *str2, int search, int replace) {
    // Выделение памяти для новой строки
    char *new_str = (char *) malloc((strlen(str1) + 1) * sizeof(char));
    char c = str1[search - 1];
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (search <= 0 || search > len1 || replace <= 0 || replace > len2) {
        return "Index out of array"; // Предотвращаем выход за границы
    }
    if (!new_str) {
        printf("Memory allocation error.\n");
        return NULL;
    }

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == c) {
            str1[i] = str2[replace - 1];
        }
        new_str[i] = str1[i];
    }
    new_str[len1] = '\0';
    return new_str;
}

int run() {
    char first_str[300], second_str[300];
    printf("Enter first string: ");
    fgets(first_str, 300, stdin);
    fflush(stdin);
    printf("Enter second string: ");
    fgets(second_str, 300, stdin);
    fflush(stdin);
    printf("Enter the number of the character to replace:");
    int search_character;
    scanf("%d", &search_character);

    printf("Enter the number of the character you want to replace:");
    int replace_character;
    scanf("%d", &replace_character);
    replace_character = replace_character + search_character;

    printf("\n%s\n", first_str);
    printf("%s\n", second_str);

    printf("\n%d - %c", search_character, first_str[search_character - 1]);
    printf("\n%d - %c\n\n", replace_character, second_str[replace_character - 1]);

    char *new_str = change_c_text(first_str, second_str, search_character, replace_character);

    if (new_str != NULL) {
        printf("%s\n", new_str);
        free(new_str);
    }
    run();
    return 0;
}
