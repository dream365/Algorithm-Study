//
// Created by ko sewon on 2019-10-21.
//

#include <stdio.h>
#include <vector>
using namespace std;

#define MAX 87654322

int mem[MAX][9][9] = {0, };

bool valid(vector<int>& nums) {
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] > nums[i + 1])
            return false;
    }

    return true;
}

void reverse(vector<int>& nums, int from, int to) {
    int size = to - from + 1;
    bool even = size % 2;


}

int main() {
    printf("NICE");
}