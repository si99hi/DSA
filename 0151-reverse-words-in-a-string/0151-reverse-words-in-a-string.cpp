class Solution {
public:
    string reverseWords(string s) {
        string words;
        stringstream ss(s);
        string result= "";

        while(ss>> words){
            if(result==""){
                result= words;
            }
            else{
                result= words+ " " + result;
            }
        }
        return result;
        
    }
};