class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //N<60000
        int N = time.size();
        int cnt[60]={0,};
        int ans = 0;
        for(int i=0;i<N;i++){
            ans += cnt[(60 - time[i]%60)%60];
            cnt[time[i]%60]++;
        }
        return ans;
    }
};