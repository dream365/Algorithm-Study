#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);
void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int direct,int num);

int main() {

	int r,c;
	int k;
	vector<vector<int>> a;
	cin >> r >> c;
	for (int i = 0; i < c; i++) {
		vector<int> temp;
		
		for (int j = 0; j < r; j++) {
			cin >> k;
			temp.push_back(k);
		}
		a.push_back(temp);

	}
	int sr, sc,nc;
	cin >> sr >> sc >> nc;
	vector<vector<int>> b = floodFill(a, sr, sc, nc);
	cout <<endl << a[0].size()-1<<endl;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++)
			cout << a[i][j];
		cout << endl;

	}

	return 0;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int  num = image[sr][sc];
	if (num == newColor)
		return image;
	if (sc > 0) {
		if (image[sr][sc - 1] == image[sr][sc]) {
			image[sr][sc - 1] = newColor;
			floodFill(image, sr, sc - 1, newColor, 1, num);
			
		}
	}
	if (sc < image[0].size() - 1) {
		if (image[sr][sc + 1] == image[sr][sc]) {
			image[sr][sc + 1] = newColor;
			floodFill(image, sr, sc + 1, newColor, 3, num);
			
		}
	}

	if (sr > 0) {
		if (image[sr - 1][sc] == image[sr][sc]) {
			image[sr - 1][sc] = newColor;
			floodFill(image, sr - 1, sc, newColor,0, num);
			
		}
	}
	if (sr < image.size() - 1) {
		if (image[sr + 1][sc] == image[sr][sc]) {
			image[sr + 1][sc] = newColor;
			floodFill(image, sr+1, sc, newColor,2, num);
			
		}
	}
	
	image[sr][sc] = newColor;
	return image;
}

void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int direct , int num) {
	if (sr > 0 && direct != 2) {
	
		if (image[sr - 1][sc] == num) {			
			image[sr - 1][sc] = newColor;
			
			floodFill(image, sr - 1, sc, newColor, 0, num);
		}
	}
	if (sr < image.size() - 1&&direct!=0) {

		if (image[sr + 1][sc] == num) {
			cout << sr << " " << sc << endl;
			image[sr + 1][sc] = newColor;
			floodFill(image, sr+1, sc, newColor,2, num);
			
		}
	}
	if (sc > 0 && direct != 3) {
		
		if (image[sr][sc - 1] == num) {	
			cout << sr << " " << sc << endl;
			image[sr][sc - 1] = newColor;
			floodFill(image, sr, sc - 1, newColor,1, num);
			
		}
	}
	if (sc < image[0].size()-1 && direct != 1) {
		cout << sr << " " << sc<<endl;
		if (image[sr][sc + 1] == num) {			
			image[sr][sc + 1] = newColor;
			floodFill(image, sr, sc + 1, newColor,3, num);			
		}
	}
	image[sr][sc] = newColor;
}