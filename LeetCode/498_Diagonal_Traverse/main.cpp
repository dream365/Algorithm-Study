#include<vector>
#include<iostream>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    if(matrix.empty())
        return ans;

    int dir[2][2] = {{-1, 1}, {1, -1}};
    int M = matrix.size(), N = matrix[0].size();
    int y = 0, x = 0, nextY = 0, nextX = 0;
    bool idUpDir = true;

    ans.push_back(matrix[0][0]);

    while(!(y == M - 1 && x == N - 1)) {
        nextY = idUpDir ? nextY + dir[0][0] : nextY + dir[1][0];
        nextX = idUpDir ? nextX + dir[0][1] : nextX + dir[1][1];

        if(nextY == -1 || nextX == -1 ||
           nextY == M || nextX == N) {
            nextY = idUpDir ? nextY - dir[0][0] : nextY - dir[1][0];
            nextX = idUpDir ? nextX - dir[0][1] : nextX - dir[1][1];

            if(idUpDir){
                nextY = nextX + 1 < N ? nextY : nextY + 1;
                nextX = nextX + 1 < N ? nextX + 1 : nextX;
            } else {
                nextX = nextY + 1 < M ? nextX : nextX + 1;
                nextY = nextY + 1 < M ? nextY + 1 : nextY;
            }

            idUpDir = !idUpDir;
        }

        y = nextY;
        x = nextX;
        ans.push_back(matrix[y][x]);
    }

    return ans;
}

int main() {

    vector<vector<int>> matrix;
    vector<int> row;
    row.push_back(2);
    row.push_back(3);
    matrix.push_back(row);
    /*int num = 1;

    for(int i = 0; i < 3; i++) {
        vector<int> row;
        for(int j = 0; j < 3; j++) {
            row.push_back(num++);
        }
        matrix.push_back(row);
    }*/

    vector<int> ans = findDiagonalOrder(matrix);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}