class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int cur,t;
        for(int i=1;i<=n;i++){
            cur=i;t=0;
            while(cur){
                cur-=(cur&(-cur));
                t++;
            }
            ans[i] = t;
        }
        return ans;
    }
};