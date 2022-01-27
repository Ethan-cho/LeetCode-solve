class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int C = 0;
        int mask = 0;
        int size = nums.size();
        
        for(int i = 30; i >= 0; i--){
            mask |= (1 << i);
            set<int> prefixSet;
            for(int j=0; j < size; j++){
                prefixSet.insert(mask & nums[j]);
            }

            int potentialC = C | (1 << i);
            for(int A : prefixSet){
                if(prefixSet.find(A ^ potentialC) != prefixSet.end()){
                    C = potentialC;
                    break;
                }
            }
        }
        return C;
    }
};