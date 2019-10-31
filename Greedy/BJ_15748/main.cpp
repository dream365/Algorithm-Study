#include <stdio.h>
#include <vector>
using namespace std;

struct RestStop{
    long long position;
    long long tastiness;
    RestStop() : position(0), tastiness(0) {};
    RestStop(long long p, long long t) : position(p), tastiness(t) {};
};

long long findMaxStopPos(long long startPos, vector<RestStop>& restStops) {
    long long maxTastiness = 0;
    long long pos = -1;
    long long restStopSize = restStops.size();

    for(int i = restStopSize - 1; 0 <= i; i--) {
        if(maxTastiness <= restStops[i].tastiness && startPos <= restStops[i].position) {
            maxTastiness = restStops[i].tastiness;
            pos = i;
        }
    }

    return pos;
}

int main() {
    long long totalTastiness = 0;
    long long L, N, rF, rB;

    scanf("%lld %lld %lld %lld", &L, &N, &rF, &rB);

    vector<long long> farmerRates;
    vector<long long> trainerRates;
    vector<RestStop> restStops;

    for(int i = 1; i <= L; i++) {
        farmerRates.push_back(i * rF);
        trainerRates.push_back(i * rB);
    }

    for(int i = 0; i < N; i++) {
        long long p;
        long long t;
        scanf("%lld %lld", &p, &t);
        RestStop restStop(p, t);
        restStops.push_back(restStop);
    }

    long long pos = 0;

    while(pos <= L) {
        long long maxStopPos = findMaxStopPos(pos, restStops);
        long long maxTastinessPos = restStops[maxStopPos].position;

        if(pos <= maxTastinessPos) {
            long long timeDiff = farmerRates[maxTastinessPos - 1] - trainerRates[maxTastinessPos - 1];
            totalTastiness += timeDiff * restStops[maxStopPos].tastiness;

            for(int i = maxTastinessPos - 1; i < L; i++) {
                trainerRates[i] += timeDiff;
            }

            pos = maxTastinessPos + 1;
        } else {
            pos++;
        }
    }

    printf("%lld", totalTastiness);
}