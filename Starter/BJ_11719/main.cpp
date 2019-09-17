#include <stdio.h>

char word[101];

int main() {

    while (fgets(word, 101, stdin)) {
        printf("%s", word);
    }

    return 0;
}