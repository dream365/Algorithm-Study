#include <stdio.h>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define MAX 87654322

struct NumElement{
    int num;
    int depth;
};

set<int> visit;
int ans = -1;

//1 -> 3, 2 -> 2, 3 -> 1
//5 4 3 2 1, size = 5, from = 1, to = 3 -> 5 2 3 4 1
int getRvsNum(vector<int>& num, int from, int to) {
    int multiply = 1;
    int idx = 0;
    int rvsNum = 0;
    int size = num.size();

    for(int i = 0; i < size - 1; i++) {
        multiply *= 10;
    }

    while(idx < size) {
        if(idx == from) {
            for(int i = to; from <= i; i--) {
                rvsNum += multiply * num[i];
                multiply /= 10;
            }
            idx = to + 1;
        } else {
            rvsNum += multiply * num[idx];
            multiply /= 10;
            idx++;
        };
    }

    return rvsNum;
}

//잘 소팅된 숫자인지 판별
bool isValid(vector<int>& num) {
    for(int i = 0; i < num.size() - 1; i++) {
        if(num[i] > num[i + 1])
            return false;
    }

    return true;
}

vector<int> makeNumVect(int num, int size) {
    vector<int> numVect;
    int multiply = 1;
    int temp = num;

    for(int i = 0; i < size - 1; i++) {
        multiply *= 10;
    }

    for(int i = 0; i < size; i++) {
        numVect.push_back(temp / multiply);
        temp %= multiply;
        multiply /= 10;
    }

    return numVect;
}
// 1 400 401 500 - > 1 2 3 4
vector<int> makeLittleNums(vector<int>& numVect) {
    int curMin = -1;
    int size = numVect.size();
    vector<int> littleNums(size);

    for(int i = 1; i <= size; i++) {
        int min = 1000001;
        int idx = 0;
        for(int j = 0; j < size; j++) {
            if(numVect[j] < min && curMin < numVect[j]) {
                min = numVect[j];
                idx = j;
            }
        }

        littleNums[idx] = i;
        curMin = min;
    }

    return littleNums;
}

void BFS(NumElement startNum, int size) {
    queue<NumElement> q;
    q.push(startNum);

    while(q.empty() == false) {
        NumElement curNum = q.front();
        q.pop();
        vector<int> curNumVect = makeNumVect(curNum.num, size);

        if(isValid(curNumVect)) {
            if(ans == -1) {
                ans = curNum.depth;
            } else {
                if(curNum.depth < ans)
                    ans = curNum.depth;
            }
        }

        for(int i = 0; i < size - 1; i++) {
            for(int j = i + 1; j < size; j++) {
                int rsvNum = getRvsNum(curNumVect, i, j);
                if(visit.find(rsvNum) == visit.end()) {
                    NumElement rsvNumEle;
                    rsvNumEle.num = rsvNum;
                    rsvNumEle.depth = curNum.depth + 1;
                    q.push(rsvNumEle);
                    visit.insert(rsvNum);
                }
            }
        }
    }
}

int main() {
    int C;
    int target = 0;
    scanf("%d", &C);

    for(int i = 0; i < C; i++) {
        int N, cnt;
        scanf("%d", &N);
        cnt = N - 1;

        vector<int> nums;
        for(int j = 0; j < N; j++) {
            int num;
            scanf("%d", &num);
            nums.push_back(num);

        }

        vector<int> littleNums = makeLittleNums(nums);
        nums.clear();

        for(int j = 0; j < littleNums.size(); j++) {
            int num = littleNums[j];

            for(int k = 0; k < cnt; k++) {
                num *= 10;
            }
            target += num;
            cnt--;
        }
        littleNums.clear();

        NumElement numele;
        numele.num = target;
        numele.depth = 0;
        BFS(numele, N);
        printf("%d\n", ans);

        ans = -1;
        target = 0;

        visit.clear();
    }

    return 0;
}

//1. 뒤집는다 찾는다 (시간 사용)
//2. 안뒤집는다 찾는다 (공간 사용)