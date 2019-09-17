#include <stdio.h>

int main() {
    char word[101];
    int num = 0;

    scanf("%s", word);

    for(int i = 0;i < 100; i++) {
        if(word[i] == '\0')
            break;

        num++;
    }

    printf("%d", num);
}