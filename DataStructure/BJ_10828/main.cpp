#include <stdio.h>
#include <string.h>

struct Stack {
    int top;
    int stack[10001];
};

void StackInit(Stack * sp) {
    sp->top = -1;
}

void Push(Stack * sp, int num) {
    sp->top += 1;
    sp->stack[sp->top] = num;
}

int Pop(Stack * sp) {
    if(sp->top == -1)
        return -1;

    int popNum = sp->stack[sp->top];
    sp->top -= 1;

    return popNum;
}

int Size(Stack * sp) {
    return sp->top + 1;
}

int Empty(Stack * sp) {
    return sp->top == -1 ? 1 : 0;
}

int Top(Stack * sp) {
    if(sp->top == -1)
        return -1;

    return sp->stack[sp->top];
}

int main() {
    Stack stack;
    char cmd[6];
    int cmdNum;
    int num;
    StackInit(&stack);

    scanf("%d", &cmdNum);
    for(int i = 0; i < cmdNum; i++) {
        scanf("%s", cmd);

        if(!strcmp(cmd, "push")) {
            scanf("%d", &num);
            Push(&stack, num);
        } else if(!strcmp(cmd, "pop")) {
            printf("%d\n", Pop(&stack));
        } else if(!strcmp(cmd, "size")) {
            printf("%d\n", Size(&stack));
        } else if(!strcmp(cmd, "empty")) {
            printf("%d\n", Empty(&stack));
        } else if(!strcmp(cmd, "top")) {
            printf("%d\n", Top(&stack));
        }
    }

    return 0;
}