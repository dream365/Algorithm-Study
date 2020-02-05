class Solution {
    int dp[101][101][2];
public:
    int getSequences(vector<vector<int>>& grid, int y, int x, bool vertical) {
        int sequence = 1;
        int ySize = grid.size();
        int xSize = grid[0].size();
        
        if(vertical && x == xSize - 1)
            return 1;
        if(vertical && xSize - 1 < x)
            return 0;
        if(!vertical && y == ySize - 1)
            return 1;
        if(!vertical && ySize - 1 < y)
            return 0;
        
        for(int i = (vertical ? x + 1 : y + 1); i < (vertical ? xSize : ySize); i++) {
            if(vertical) {
                if(grid[y][i])
                    sequence++;
                else
                    break;
            } else {
                if(grid[i][x])
                    sequence++;
                else
                    break;
            }
        }
        
        return sequence;
    }
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        int ySize = grid.size();
        int xSize = grid[0].size();
        
        for(int i = 0; i < ySize; i++) {
            for(int j = 0; j < xSize; j++) {
                int& yStart = dp[i][j][0];
                int& xStart = dp[i][j][1];
                
                if(grid[i][j] == 0)
                    continue;
                
                if(i == 0)
                    yStart = getSequences(grid, i, j, false);
                else
                    yStart = dp[i-1][j][0] == -1 ? getSequences(grid, i, j, false) : dp[i-1][j][0] - 1;
                
                if(j == 0)
                    xStart = getSequences(grid, i, j, true);
                else
                    xStart = dp[i][j-1][1] == -1 ? getSequences(grid, i, j, true) : dp[i][j-1][1] - 1;
                
                int minLen = min(yStart, xStart);
                
                for(int k = minLen; 0 < k; k--) {
                    if(k == 1) {
                        ans = max(ans, 1);
                        break;
                    }
                    
                    int& yEnd = dp[i][j + k - 1][0];
				    int& xEnd = dp[i + k - 1][j][1];
				    if (i == 0)
					    yEnd = getSequences(grid, i, j + k - 1, false);
				    else
					    yEnd = dp[i - 1][j + k - 1][0] == -1 ? getSequences(grid, i, j + k - 1, false) : dp[i - 1][j + k - 1][0] - 1;

				    if (j == 0)
					    xEnd = getSequences(grid, i + k - 1, j, true);
				    else
					    xEnd = dp[i + k - 1][j - 1][1] == -1 ? getSequences(grid, i + k - 1, j, true) : dp[i + k - 1][j - 1][1] - 1;

				    if (k <= yEnd && k <= xEnd) {
					    ans = max(ans, k*k);
					    break;
				    }
                }
            }
        }
        
        return ans;
    }
};
