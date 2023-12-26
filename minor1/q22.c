#include<stdio.h>
#define MAX 1000

int findString( char* arr,  char* str, char** pos) {
    if (*str == '\0') {
        *pos = (char*)arr;
        return 1;
    }
    while (*arr != '\0') {
        const char* arr_ptr = arr;
        const char* str_ptr = str;
        while (*str_ptr != '\0' && *arr_ptr == *str_ptr) {
            arr_ptr++;
            str_ptr++;
        }
        if (*str_ptr == '\0') {
            *pos = (char*)arr;
            return 1;
        }
        arr++;
    }
    return 0;
}

int main() {
    char arr[MAX];char str[MAX];
    printf("enter the string1 to be in char array\n");
    fgets(arr, sizeof(arr), stdin);
    printf("You entered: %s\n", arr);

    printf("enter the string2 to find in str1(char_array):\n");
    fgets(str, sizeof(str), stdin);
    printf("You entered: %s\n", str);
    // const char arr[] = "This is a sample string.";
    // const char str[] = "sample";
    char* pos;

    int found = findString(arr, str, &pos);

    if (found) {
        printf("String found at position: %ld\n", pos-arr);
    } else {
        printf("String not found.\n");
    }

    return 0;
}