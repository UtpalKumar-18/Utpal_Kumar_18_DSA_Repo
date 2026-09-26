class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        string s1 ="";

        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                int start_ind = i+1;
                while(s[i] != ')'){
                    i++;
                }
                if(mp.find(s.substr(start_ind,i-start_ind)) == mp.end()) s1 += "?";
                else
                s1 += (mp[s.substr(start_ind,i - start_ind)]);
            }
            else{
                s1.push_back(s[i]);
            }
        }
        return s1;
    }
};