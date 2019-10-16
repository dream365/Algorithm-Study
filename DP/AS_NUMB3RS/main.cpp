#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int c;

    scanf("%d", &c);

    for(int i = 0; i < c; i++) {
        int n, d, p, t;
        scanf("%d %d %d", &n, &d, &p);

        vector<vector<int>> A(n);
        vector<vector<double>> probs(d + 1);
        vector<vector<bool>> validVils(d + 1);

        for(int j = 0; j < n; j++) {
            vector<int> vils(n, 0);
            A[j] = vils;
        }

        for(int j = 0; j < d + 1; j++) {
            vector<double> prob(n, 0.);
            vector<bool> vaildVil(n, false);
            probs[j] = prob;
            validVils[j] = vaildVil;
        }

        validVils[0][p] = true;
        probs[0][p] = 1.0;

        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) {
                scanf("%d", &A[j][k]);
            }

        //Set probability
        for(int j = 1; j < d + 1; j++) {
            //get towns to go when day is j - 1
            vector<bool> prevVaildVils = validVils[j - 1];

            for(int vil = 0; vil < prevVaildVils.size(); vil++) {
                int validVilNum = 0;
                vector<int> vils;

                if(prevVaildVils[vil] == true) {
                    for(int k = 0; k < n; k++) {
                        //
                        if(A[vil][k] == 1) {
                            validVils[j][k] = true;
                            validVilNum++;
                            vils.push_back(k);
                        }
                    }

                    for(int k = 0; k < vils.size(); k++) {
                        probs[j][vils[k]] += 1.0 / (double) validVilNum * probs[j-1][vil];
                    }
                }
            }
        }

        //Print
        scanf("%d", &t);
        vector<int> vilNums;

        for(int j = 0; j < t; j++) {
            int vilNum;
            scanf("%d", &vilNum);
            vilNums.push_back(vilNum);
        }

        for(int j = 0; j < t; j++) {
            printf("%.8f ", probs[d][vilNums[j]]);
        }
        printf("\n");
    }

    return 0;
}