class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx=0;
        for(char c:t)
            if(s[idx]==c)   idx++;
        
        return idx==s.size();
    }
};