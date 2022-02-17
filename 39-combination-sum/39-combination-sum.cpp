class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> tRet; 
        sort(candidates.begin(), candidates.end()); 
        vector<int> sum; 
        makeSum(candidates, tRet, sum, 0, target); 
        return tRet;
    }
    void makeSum(vector<int> &nums, vector<vector<int>> &ret, vector<int> &sum, int start, int remain) { 
        if (remain == 0)
            ret.push_back(sum);
        else if (remain > 0) {
            for (int i = start; i < nums.size(); ++i) { 
                sum.push_back(nums[i]); 
                makeSum(nums, ret, sum, i, remain - nums[i]);
                sum.pop_back(); 
            }
        }
    }

};