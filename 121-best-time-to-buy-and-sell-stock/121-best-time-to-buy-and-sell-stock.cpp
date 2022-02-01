class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = INT_MAX;
        int cash = 0;
        
        for(int price : prices){
            cash = max(cash, price - buy);
            buy = min(buy, price);
            ans = max(ans, cash);
        }
        
        return ans;
    }
};