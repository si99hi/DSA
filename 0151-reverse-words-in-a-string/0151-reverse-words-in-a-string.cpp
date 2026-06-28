class Solution {
public:
    string reverseWords(string s) {
        string words;
        string result="";
        stringstream ss(s);
        while(ss>>words){
            if(result==""){
                result= words;
            }
            else{
                result= words+" "+ result;
            }
        }
        return result;
        
    }
}; 