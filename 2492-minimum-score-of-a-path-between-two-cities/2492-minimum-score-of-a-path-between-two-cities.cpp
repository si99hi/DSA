class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };
        
        for (auto& r : roads) {
            int a = find(r[0]), b = find(r[1]);
            if (a != b) parent[a] = b;
        }
        
        int root = find(1);
        int ans = INT_MAX;
        for (auto& r : roads) {
            if (find(r[0]) == root && find(r[1]) == root) {
                ans = min(ans, r[2]);
            }
        }
        return ans;
    }
};