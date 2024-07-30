#include <stdio.h>
#include <string.h>

int isValidCFG2(const char *str, int *index) {
    if (str[*index] == '0') {
        (*index)++;
        if (isValidCFG2(str, index) && str[*index] == '0') {
            (*index)++;
            return 1;
        }
        return 0;
    } else if (str[*index] == '1') {
        (*index)++;
        return isValidCFG2(str, index);
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    int index = 0;
    if (isValidCFG2(str, &index) && str[index] == '\0') {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}
