#include <stdio.h>
#include <vector>
using namespace std;

int N, num, strike, ball;
vector<int> ans;

bool checkValidateNum(int curNum) {
    int curNumArr[3];

    curNumArr[0] = curNum / 100;
    curNumArr[1] = (curNum % 100) / 10;
    curNumArr[2] = (curNum % 100) % 10;

    return curNumArr[0] != curNumArr[1] && curNumArr[0] != curNumArr[2] && curNumArr[1] != curNumArr[2]
            && curNumArr[1] != 0 && curNumArr[2] != 0;
}

bool checkDeleteNum(int curNum) {
    int curNumArr[3];
    int numArr[3];
    int curStrike = 0;
    int curBall = 0;

    curNumArr[0] = curNum / 100, numArr[0] = num / 100;
    curNumArr[1] = (curNum % 100) / 10, numArr[1] = (num % 100) / 10;
    curNumArr[2] = (curNum % 100) % 10, numArr[2] = (num % 100) % 10;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(numArr[i] == curNumArr[j]) {
                if(i == j)
                    curStrike++;
                else
                    curBall++;
                break;
            }
        }
    }

    return strike == curStrike && ball == curBall;
}

void setAnswer() {
    for(int i = 111; i < 1000; i++)
        if(checkValidateNum(i))
            ans.push_back(i);
}

void deleteNoneAnswer() {
    vector<int> temp;
    for(int i = 0; i < ans.size(); i++) {
        if(checkDeleteNum(ans[i])) {
            temp.push_back(ans[i]);
        }
    }

    ans.assign(temp.begin(), temp.end());
}

int main() {
    setAnswer();

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &num, &strike, &ball);
        deleteNoneAnswer();
    }

    printf("%d", ans.size());
}