class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        for(int i = 1; i < A.size(); i ++)
        {
            for(int j = 0; j <A[i].size(); j++)
            {
                if(j == 0)
                    A[i][j] += min(A[i-1][j],A[i-1][j+1]);
                else if(j == A[i].size() - 1)
                    A[i][j] += min(A[i-1][j],A[i-1][j-1]);
                else
                    A[i][j] += min(min(A[i-1][j],A[i-1][j-1]),A[i-1][j+1]);
            }
        }
        int min = A[A.size()-1][0];
        for(int j = 0; j < A[A.size()-1].size(); j++)
        {
            if(A[A.size()-1][j] < min)
                min = A[A.size()-1][j];
        }
        return min;
        
                                      
    }
};