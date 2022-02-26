class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
    queue<vector<int> > q;
      int n = graph.size();
      int req = (1 << n) - 1;
      map<int, set<int> > visited;
      for (int i = 0; i < n; i++) {
         q.push({ 0 | (1 << i), i });
      }
      if (n == 1)
      return 0;
      for (int lvl = 1; !q.empty(); lvl++) {
         int sz = q.size();
         while (sz--) {
            vector<int> curr = q.front();
            q.pop();
            for (int i = 0; i < graph[curr[1]].size(); i++) {
               int u = graph[curr[1]][i];
               int newMask = (curr[0] | (1 << u));
               if (newMask == req)
                  return lvl;
               if (visited[u].count(newMask))
               continue;
               visited[u].insert(newMask);
               q.push({ newMask, u });
            }
         }
      }
      return -1;
    }
};