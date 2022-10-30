class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen=INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].length()<minLen){
                minLen=strs[i].length();
            }
        }
        string ans="";
        bool stop=false;
        for(int i=0;i<minLen;i++){
            char ch=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=ch){
                    stop=true;
                    break;
                }
            }
            if(stop){
                break;
            }
            ans=ans+ch;
        }
        return ans;
    }
};