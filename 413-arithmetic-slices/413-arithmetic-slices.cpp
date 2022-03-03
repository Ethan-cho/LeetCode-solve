class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
         int ret = 0;
         int n = A.size();
         vector <int> dp(n);
         for(int i = 2; i < n; i++){
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]){
               dp[i] = 1 + dp[i - 1];
               ret += dp[i];
            }
         }
         return ret;
      }  
};