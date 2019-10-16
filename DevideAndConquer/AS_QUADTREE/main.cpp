#include <stdio.h>
#include <vector>
using namespace std;

#define MAX_WORD 1001
#define QUAD 4

void swapVect(vector<char>& v1, vector<char>& v2) {
    vector<char> temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

void putChar(vector<char>& v, vector<char> input) {
    for(int i = 0; i < input.size(); i++)
        v.push_back(input[i]);
}

vector<char> getReverseQuadTree(char words[], int& cur) {
    vector<char> v;
    char curWord = words[cur];

    if(curWord == 'x') {
         vector<vector<char>> temp;
         v.push_back(curWord);

         for(int i = 0; i < QUAD; i++) {
             char nextCur = words[++cur];

             if(nextCur == 'x')
                 temp.push_back(getReverseQuadTree(words, cur));
             else {
                 vector<char> singleWord;
                 singleWord.push_back(nextCur);
                 temp.push_back(singleWord);
             }
         }

        swapVect(temp[0], temp[2]);
        swapVect(temp[1], temp[3]);

        for(int i = 0; i < QUAD; i++)
            putChar(v, temp[i]);

        return v;
    } else {
        v.push_back(curWord);
        return v;
    }
}

void printVect(vector<char> v) {
    for(int i = 0; i < v.size(); i++)
        printf("%c", v[i]);
    printf("\n");
}

int main() {
    int C;
    scanf("%d", &C);


    for(int i = 0; i < C; i++) {
        char words[MAX_WORD];
        int curIdx = 0;

        scanf("%s", words);

        printVect(getReverseQuadTree(words, curIdx));
    }

    return 0;
}