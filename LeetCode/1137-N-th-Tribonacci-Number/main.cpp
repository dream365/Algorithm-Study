#include <iostream>
using namespace std;
int tribonacci(int n);

int main() {
	int data[37] = { 0, };
	cout << data[0];
	int c;
	cin >> c;
	cout << tribonacci(c);


	return 0;
}

int tribonacci(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n == 4)
		return 4;
	else
		return double(2)*tribonacci(n - 1) - tribonacci(n - 4);
}