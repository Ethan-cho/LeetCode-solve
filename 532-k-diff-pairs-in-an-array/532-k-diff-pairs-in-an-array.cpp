class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> seen, done;
      set<int> s;
      if (k < 0)
         return 0;
      for (int i = 0; i < nums.size(); i++) {
         seen[nums[i]]++;
         s.insert(nums[i]);
      }
      int ans = 0;
      for (auto it = s.begin(); it != s.end(); it++) {
         if (k == 0) {
            if (seen[*it] > 1)
            ans++;
         }
         else {
            done[*it]++;
            if (seen.find(*it + k) != seen.end() && done.find(*it + k) == done.end())
               ans++;
            if (seen.find(*it - k) != seen.end() && done.find(*it - k) == done.end())
               ans++;
         }
      }
      return ans;
    }
};