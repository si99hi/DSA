class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n, 0);
        for(auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for(auto& [v, cost] : graph[u]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        
        long long lo = 0, hi = 1e9;
        int ans = -1;
        
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(canAchieve(graph, online, k, mid, topo, n)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
    
    bool canAchieve(vector<vector<pair<int,int>>>& graph, vector<bool>& online, long long k, long long minCost, vector<int>& topo, int n) {
        vector<long long> dp(n, LLONG_MAX);
        dp[0] = 0;
        
        for(int u : topo) {
            if(dp[u] == LLONG_MAX) continue;
            if(u != 0 && u != n-1 && !online[u]) continue;
            
            for(auto& [v, cost] : graph[u]) {
                if(cost >= minCost && dp[u] + cost <= k) {
                    if(v == 0 || v == n-1 || online[v]) {
                        dp[v] = min(dp[v], dp[u] + cost);
                    }
                }
            }
        }
        
        return dp[n-1] <= k;
    }
};