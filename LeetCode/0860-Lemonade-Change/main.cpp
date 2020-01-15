#include<iostream>
#include<vector>
using namespace std;

bool lemonadeChange(vector<int>& bills);


int main(){
	vector<int> nums = { 5,5,5,10,20 };
	vector<int> nums2 = { 5,5,10,10,20 };
	cout << lemonadeChange(nums) << endl << lemonadeChange(nums2);

	return 0;
}

bool lemonadeChange(vector<int>& bills) {
	int changes[2] = { 0,0 };
	for (auto i : bills) {
		if (i == 5)
			changes[0]++;
		else if (i == 10) {
			if (changes[0] > 0) {
				changes[0]--;
				changes[1]++;
			}
			else {
				return 0;
			}
		}else if (i == 20) {
			if (changes[0] > 0 && changes[1] > 0) {
				changes[0]--;
				changes[1]--;
			}
			else if (changes[0] > 2) {
				changes[0]= changes[0]-3;
			}
			else
				return 0;
		}
	}
	return 1;
}

