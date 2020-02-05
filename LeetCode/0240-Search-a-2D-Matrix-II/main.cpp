#include <iostream>
#include <vector>

#define DOWN 1
#define RIGHT 2
#define UP 3
#define LEFT 0

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);
bool searchMatrix(vector<vector<int>>& matrix, int target, int row, int col,int dir);

int main() {
	vector<vector<int>> mat = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
	cout << searchMatrix(mat, 15);

	return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0)
		return false;
	else if (matrix[0].size() == 0)
		return false;
	else if (matrix[0][0] > target)
		return false;
	return searchMatrix(matrix, target, 0, 0, DOWN);
}

bool searchMatrix(vector<vector<int>>& matrix, int target, int row, int col,int dir) {
	cout << matrix[row][col] << endl;
	if (matrix[row][col] == target)
		return true;
	else if (matrix[row][col] < target) {
		if (dir == LEFT)
			return false;
		else if (row + 1 == matrix.size()) {
			if (col + 1 == matrix[0].size())
				return false;
			return searchMatrix(matrix, target, row, col + 1, RIGHT);
		}
		else if (matrix[row + 1][col] < target) {
			return searchMatrix(matrix, target, row + 1, col, DOWN);
		}
		else if (matrix[row + 1][col] == target)
			return true;
		else if (matrix[row + 1][col] > target) {
			if (col + 1 == matrix[0].size())
				return false;
			else if (matrix[row][col + 1] == target)
				return true;
			else 
				return searchMatrix(matrix, target, row, col+1, RIGHT);
		}
	}
	else{
		if (row == 0) {
			if (dir == RIGHT)
				return false;
			searchMatrix(matrix, target, row, col - 1, LEFT);
		}
		else if (matrix[row - 1][col] == target)
			return true;
		else if (matrix[row - 1][col] > target) {
			if (searchMatrix(matrix, target, row - 1, col, UP) || searchMatrix(matrix, target, row, col - 1, LEFT))
				return true;
			else
				return false;
		}else if (matrix[row - 1][col] < target) {
			//return searchMatrix(matrix, target, row, col - 1, LEFT);
			if (searchMatrix(matrix, target, row - 1, col, UP) || searchMatrix(matrix, target, row, col - 1, LEFT))
				return true;
			else
				return false;
		}
	}		
}