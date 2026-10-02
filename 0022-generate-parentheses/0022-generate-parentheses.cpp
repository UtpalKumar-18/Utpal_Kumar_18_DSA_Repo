class Solution {
public:
    vector<string> str;
    vector<char> c;
     void backtrack(int open,int close,int n) {
            if(open==n && close==n){
                string s(c.begin(),c.end());
                str.push_back(s);
                return;
            }
            if(open < n){
                c.push_back('(');
                backtrack(open+1,close,n);
                c.pop_back();
            }
            if(close<open){
                c.push_back(')');
                backtrack(open,close+1,n);
                c.pop_back();
            }

        }
    
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,n);
        return str;
      
    }
};