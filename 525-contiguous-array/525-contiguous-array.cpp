class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        int sum = 0;
        map <int, int> m;
        m[0] = -1;
        for(int i = 0; i < nums.size(); i++){
             sum += nums[i] == 1 ? 1: -1;
             if(m.count(sum)){
                ret = max(ret, i - m[sum]);
             }else m[sum] = i;
          }
        return ret;
    }
};