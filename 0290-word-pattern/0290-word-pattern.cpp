class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
         set<string> st;
        int len1=pattern.size();
        int len2=s.size();
        int i=0;
        for(int j=0;j<len2;j++){
            string word="";
            while(j<len2&&s[j]!=' '){
                word+=s[j];
                j++;
            }
            if(mp.find(pattern[i])!=mp.end()){
                if(mp[pattern[i]]!=word){
                    return false;
                }
            }
            else{
                if (st.count(word) > 0) return false;
                mp[pattern[i]]=word;
                st.insert(word);
            }
            i++;
        }
        if(i!=len1){
            return false;
        }
        return true;
    }
};