#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// int count_character(char str[], int search_c) {
//     char c = str[search_c - 1];
//     int count = 0;
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (str[i] == c) {
//             count++;
//         }
//     }
//     return count;
// }

char *change_c_text(char str1[], char str2[], int search, int replace) {
    // Выделение памяти для новой строки
    char *new_str = (char *) malloc((strlen(str1) + 1) * sizeof(char));
    char c = str1[search - 1];
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (search <= 0 || search > len1) {
        return NULL; // Предотвращаем выход за границы
    }
    if (!new_str) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }
    // for (int i = 0; str1[i] != '\0'; i++) {
    //     if (str1[i] == c) {
    //         str1[i] = str2[search + replace - 1];
    //     }
    //     new_str[i] = str1[i];
    // }
    for (int i = 0; i < len1; i++) {
        if ((i + 1) % search == 0) {
            // Индекс с циклическим смещением для замены
            int replace_index = (search + replace - 1) % len2;
            new_str[i] = str2[replace_index];
        } else {
            new_str[i] = str1[i];
        }
    }
    // Копирование и замена символов
    // for (int i = 0; i < len1; i++) {
    //     if (str1[i] == c && (search + replace - 1) < len2) {
    //         new_str[i] = str2[(search + replace - 1)];
    //     } else {
    //         new_str[i] = str1[i];
    //     }
    // }
    new_str[len1] = '\0'; // Завершаем строку
    return new_str;
}

void print_array(int arr[]) {
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int run() {
    char first_str[] = "Search character";
    char second_str[] = "Replace with a character";
    int search_character, replace_character; //n m
    printf("n");
    scanf("%d", &search_character);
    printf("m");
    scanf("%d", &replace_character);

    char *new_str = change_c_text(first_str, second_str, search_character, search_character + replace_character);
    puts(first_str);
    puts(second_str);
    if (new_str != NULL) {
        print_array(new_str);
        free(new_str);
    }

    return 0;
}
