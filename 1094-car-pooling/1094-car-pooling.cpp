class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengers(1001);
        
        for(auto trip : trips){
            passengers[trip[1]] += trip[0];
            passengers[trip[2]] -= trip[0];
        }
        
        for (int i=0; i < passengers.size(); i++) {
            capacity -= passengers[i];
            if (capacity < 0) {
                return false;
            }
        }

        return true;
    }
};