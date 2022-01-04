class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        vector<int> v;
        while(n > 0){
            v.push_back(n%2);
            n/=2;
        }
        int ans = 0;
        for(int i = v.size()-1; i >=0; i--){
            if(v[i]==0){
                ans += 1<<i; //fast
            }
        }
        return ans;
    }
};