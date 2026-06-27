class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.length()!= s.length()) return false;
        return (s+s).find(goal)!=string::npos;
        
    }
};