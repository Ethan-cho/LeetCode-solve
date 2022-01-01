class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //N <= 500
        int N = nums.size();
        if(N==0)    return 0;
        vector<int> values(N+2);
        values[0] = 1;
        values[N+1] = 1;
        for(int i=1;i<=N;i++){
            values[i] = nums[i-1];
        }
        
        int M = values.size();
        vector<vector<int> > dp(M, vector<int>(M));
        for(int len = 3; len<=M; len++){
            for(int i=0;i<=M-len;i++){
                int j = len+i-1;
                for(int k=i+1;k<j;k++){
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+values[i]*values[k]*values[j]);
                }
            }
        }
        return dp[0][M-1];
    }
};