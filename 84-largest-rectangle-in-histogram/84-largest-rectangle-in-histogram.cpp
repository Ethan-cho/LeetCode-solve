class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<long long> s;
        long long ans = 0;
        for (int i=0; i<n; i++) {
            int left = i;
            
            while(!s.empty() && heights[s.top()] > heights[i]) {
                long long height = heights[s.top()];
                s.pop();
                long long width = i;
                if (!s.empty()) {
                    width = (i - s.top() - 1);    
                }
                if (ans < width*height) {
                    ans = width*height;
                }    
            }
            s.push(i);    
        }
        while(!s.empty()) {
            long long height = heights[s.top()];
            s.pop();
            long long width = n;
            if (!s.empty()) {
                width = n-s.top()-1;    
            }
            if (ans < width*height) {
                ans = width*height;
            }    
        }
        return ans;
    }
};