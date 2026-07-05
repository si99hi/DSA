class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        
        dp[n-1][n-1] = {0, 1};
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 'X') continue;
                
                if (i == n-1 && j == n-1) continue;
                
                int maxSum = -1;
                int count = 0;
                
                vector<pair<int, int>> moves = {{i+1, j}, {i, j+1}, {i+1, j+1}};
                
                for (auto& move : moves) {
                    int ni = move.first, nj = move.second;
                    if (ni < n && nj < n && board[ni][nj] != 'X') {
                        if (dp[ni][nj].first != -1) {
                            int val = dp[ni][nj].first;
                            if (board[i][j] != 'S' && board[i][j] != 'E') {
                                val += board[i][j] - '0';
                            }
                            
                            if (val > maxSum) {
                                maxSum = val;
                                count = dp[ni][nj].second;
                            } else if (val == maxSum) {
                                count = (count + dp[ni][nj].second) % MOD;
                            }
                        }
                    }
                }
                
                if (maxSum != -1) {
                    dp[i][j] = {maxSum, count % MOD};
                }
            }
        }
        
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
                return {dp[0][0].first, dp[0][0].second % MOD};
    }
};