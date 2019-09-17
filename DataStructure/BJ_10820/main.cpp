#include <stdio.h>

int main() {

    char word[101];

    while (fgets(word, 101, stdin)) {
        int num = 0;
        for(int i = 0; i < 101; i++) {
            printf("%c\n", word[i]);
            if(word[i] == '\0')
                break;

            num++;
            printf("END : %d\n", num);

        }
//        printf("END : %d\n", num);
    }

    return 0;
}