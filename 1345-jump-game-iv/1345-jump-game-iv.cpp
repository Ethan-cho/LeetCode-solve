class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int> > m;
      int n = arr.size();
      for (int i = 0; i < n; i++) {
         m[arr[i]].push_back(i);
      }
      set<int> visited;
      visited.insert(0);
      queue<int> q;
      q.push(0);
      for (int lvl = 0; !q.empty(); lvl++) {
         int sz = q.size();
         while (sz--) {
            int cur = q.front();
            q.pop();
            if (cur == n - 1)
            return lvl;
            int i = cur;
            if (i - 1 >= 0 && !visited.count(i - 1)) {
               q.push(i - 1);
               visited.insert(i - 1);
            }
            if (i + 1 < n && !visited.count(i + 1)) {
               q.push(i + 1);
               visited.insert(i + 1);
            }
            for (int j = 0; j < m[arr[cur]].size(); j++) {
               if (!visited.count(m[arr[cur]][j])) {
                  q.push(m[arr[cur]][j]);
                  visited.insert(m[arr[cur]][j]);
               }
            }
            if (m.count(arr[cur])) {
               m.erase(arr[cur]);
            }
         }
      }
      return -1;
    }
};