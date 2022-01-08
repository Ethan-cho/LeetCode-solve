class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        
        for(int i = 1; i < m; i++){
            for(int a = 0; a < n; a++){
                for(int b = 0; b < n; b++){
                    for(int l = a-1; l <= a+1; l++){
                        for(int r = b-1; r <= b+1; r++){
                            if(l < 0 || l >= n || r < 0 || r >= n) continue;
                            dp[i%2][a][b] = max(dp[i%2][a][b], ((a != b) ? grid[i][a] + grid[i][b] : grid[i][a]) + dp[(i-1)%2][l][r]);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int a = 0; a < n; a++){
            for(int b = 0; b < n; b++){
                ans = max(ans, dp[(m-1)%2][a][b]);
            }
        }
        
        return ans;
    }
};