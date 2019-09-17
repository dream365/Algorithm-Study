#include <stdio.h>

struct PS {
    int cur;
};

void InitPS(PS * ps) {
    ps->cur = 0;
}

bool IsValid(PS * ps) {
    return ps->cur == 0 ? true : false;
}

bool IsMinus(PS * ps) {
    return ps->cur < 0 ? true : false;
}

void Left(PS * ps) {
    ps->cur += 1;
}

void Right(PS * ps) {
    ps->cur -= 1;
}

int main(){
    PS ps;
    int num;
    char psWord[51];


    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        InitPS(&ps);
        scanf("%s", &psWord);
        fgetc(stdin);
        bool minus = false;
        for(int j = 0; j < 50; j++) {
            if(psWord[j] == '\0')
                break;

            if(psWord[j] == '(')
                Left(&ps);
            else if(psWord[j] == ')')
                Right(&ps);

            if(IsMinus(&ps)) {
                minus = true;
                break;
            }
        }

        if(minus)
            printf("No\n");
        else
            printf(IsValid(&ps) ? "YES\n" : "NO\n");
    }

    return 0;
}