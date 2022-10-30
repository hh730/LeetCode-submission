class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        int n = first.length();
        string last = strs[strs.size()-1];
        
        for(int i=0; i<n; i++){
            if(first[i] == last[i]){
                res += first[i];
            }
            else{
                break;
            }
        }
        return res;
        // int minLen=INT_MAX;
        // for(int i=0;i<strs.size();i++){
        //     if(strs[i].length()<minLen){
        //         minLen=strs[i].length();
        //     }
        // }
        // string ans="";
        // bool stop=false;
        // for(int i=0;i<minLen;i++){
        //     char ch=strs[0][i];
        //     for(int j=1;j<strs.size();j++){
        //         if(strs[j][i]!=ch){
        //             stop=true;
        //             break;
        //         }
        //     }
        //     if(stop){
        //         break;
        //     }
        //     ans=ans+ch;
        // }
        // return ans;
    }
};