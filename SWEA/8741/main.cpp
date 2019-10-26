#include <stdio.h>
using namespace std;

int main() {
    int T;
    char diff = 'A' - 'a';

    scanf("%d", &T);

    for(int i = 1; i <= T; i++) {
        char shortWord[4];
        for(int j = 0; j < 3; j++) {
            char word[21];
            scanf("%s", word);
            shortWord[j] = word[0] + diff;
        }
        printf("#%d %s\n", i, shortWord);
    }

    return 0;
}