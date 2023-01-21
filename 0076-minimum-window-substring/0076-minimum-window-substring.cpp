class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        if(s.size()==1&&t.size()==1){
            if(s[0]==t[0]){
                return t;
            }
            return "";
        }
        vector<int>char_count(128,0);
        for(auto i:t){
            char_count[i]++;
        }
        int i=0;
        int j=0;
        int mini=INT_MAX;
        int start=0;
        int required=t.size();
        while(i<=s.size()&&j<=s.size()){
            if(required){
                if(i==s.size()){
                    break;
                }
                char_count[s[i]]--;
                if(char_count[s[i]]>=0){
                    required--;
                }
                i++;
            }
            else{
                if(i-j<mini){
                    mini=i-j;
                    start=j;
                }
                char_count[s[j]]++;
                if(char_count[s[j]]>0){
                    required++;
                }
                j++;
            }
        }
        return mini==INT_MAX?"":s.substr(start,mini);
    }
};