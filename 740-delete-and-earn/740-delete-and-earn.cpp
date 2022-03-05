class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        map <int, int> m;
        int ret = 0;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        int cnt = 0;
        map <int, int> :: iterator it = m.begin();
        while(it != m.end()){
            int x = it->first;
            int temp = x * it->second;
            map <int, int> :: iterator it1 = prev(it);
            map <int, int> :: iterator it2 = prev(it1);
            
            if(cnt >= 1 && x - it1->first > 1){
                temp += m[it1->first];
            }
            else if(cnt >= 2){
                temp += m[it2->first];
            }
            m[it->first] = max(temp, cnt >= 1 ? m[it1->first] : 0);
            ret = max(ret, temp);
            
            it++;
            cnt++;
        }
        
        return ret;
    }
};