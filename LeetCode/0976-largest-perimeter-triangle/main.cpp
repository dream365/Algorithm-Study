class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        
        for(int i = A.size() - 1; 0 <= i; i--) {
            if(2 <= i && A[i] < A[i - 1] + A[i - 2]) {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }
        
        return 0;
    }
};
