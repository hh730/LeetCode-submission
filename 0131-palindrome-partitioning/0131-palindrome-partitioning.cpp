class Solution {
public:
    bool checkPalindrome(int si,int ei,string s){
        while(si<=ei){
            if(s[si++]!=s[ei--]){
                return false;
            }
        }
        return true;
    }
    void helper(int ind,string s,vector<vector<string>>&ans,vector<string>&subAns){
        if(ind==s.length()){
            ans.push_back(subAns);
            return;
        }
        for(int i=ind;i<s.length();i++){
            if(checkPalindrome(ind,i,s)){
                subAns.push_back(s.substr(ind,i-ind+1));
                helper(i+1,s,ans,subAns);
                subAns.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>subAns;
        helper(0,s,ans,subAns);
        return ans;
    }
};