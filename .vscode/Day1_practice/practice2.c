#include <stdio.h>
#include <string.h>

void reverse_spell(char *str);

int main() {
    char buffer[100];

    printf("암호문을 입력하세요: ");
    scanf("%s", buffer);

    reverse_spell(buffer);

    printf("해독 결과: %s\n", buffer);
    return 0;
}

void reverse_spell(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    char temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}