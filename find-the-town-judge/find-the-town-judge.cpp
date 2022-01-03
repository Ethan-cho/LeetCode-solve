class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //n <= 1000
        vector<int> tsum(n);
        int nsum = (n)*(n+1)/2;
        for(int i=0;i<trust.size();i++){
            tsum[trust[i][1]-1] = tsum[trust[i][1]-1] + trust[i][0];
            tsum[trust[i][0]-1] = -1;
        }
        for(int i=0 ; i<n ; i++){
            if(tsum[i]+i+1 == nsum){
                return i+1;
            }
        }
        return -1;
    }
};