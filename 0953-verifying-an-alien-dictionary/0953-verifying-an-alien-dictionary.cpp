class Solution {
public:
    bool check(string first,string second,unordered_map<char,int>mp){
        int n=min(first.size(),second.size());
        for(int i=0;i<n;i++){
            if(mp[first[i]]<mp[second[i]]){
                return true;
            }
            else if(mp[first[i]]>mp[second[i]]){
                return false;
            }
        }
        if(first.size()>second.size()){
            return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            bool isLexicalOrdered=check(words[i],words[i+1],mp);
            if(!isLexicalOrdered){
                return false;
            }
        }
        return true;
    }
};