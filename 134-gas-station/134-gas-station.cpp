class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idxsum = 0;
        int sum = 0;
        int idx = 0;
        for(int i=0;i<gas.size();i++){
            idxsum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(idxsum<0){
                idx = i+1;
                idxsum = 0;
            }
        }
        return sum < 0 ? -1 : idx;
    }
};