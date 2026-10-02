class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
         vector<int> ans(n,0);
         string A = "";
         string B = "";

        int depth =0;
        stack<char> s;
         for(int i =0;i<n;i++){
            if(seq[i] == '('){
                depth++;
                if(depth%2 != 0){
                    A += '(';
                    ans[i] = 0;
                    s.push('A');
                    
                }
                else{
                    B += '(';
                    ans[i] = 1;
                    s.push('B');
                }
            }
            else{
                char ch = s.top();
                s.pop();
                if(ch == 'A'){
                     A += ')';
                    ans[i] = 0;
                    depth--;
                }
                else if(ch == 'B'){
                    B += ')';
                    ans[i] = 1;
                    depth--;
                }
            }
         }

         return ans;

    }
};