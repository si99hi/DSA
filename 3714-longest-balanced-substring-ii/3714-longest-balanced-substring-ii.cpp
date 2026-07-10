class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 1;
            }
        }
        ans = max(ans, cnt);

        vector<pair<char, char>> pairs = {{'a','b'}, {'a','c'}, {'b','c'}};
        for (auto [c1, c2] : pairs) {
            unordered_map<int, int> first;
            first[0] = -1;  
            int diff = 0;  

            for (int i = 0; i < n; i++) {
                if (s[i] == c1) diff++;
                else if (s[i] == c2) diff--;
                else {
                    diff = 0;
                    first.clear();
                    first[0] = i;
                    continue;
                }

                if (first.count(diff)) {
                    ans = max(ans, i - first[diff]);
                } else {
                    first[diff] = i;
                }
            }
        }

        unordered_map<string, int> firstState;
        firstState["0,0"] = -1;
        int ca = 0, cb = 0, cc = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else cc++;

            string key = to_string(ca - cb) + "," + to_string(cb - cc);

            if (firstState.count(key)) {
                ans = max(ans, i - firstState[key]);
            } else {
                firstState[key] = i;
            }
        }

        return ans;
    }
};