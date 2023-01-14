class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char ch[26];
        for (int i=0; i<26; i++){
            ch[i] = 'a' + i;
        }

        for (int i=0; i<s1.size(); i++) {
            char toReplace = max(ch[s1[i]-'a'], ch[s2[i]-'a']);
            char replaceWith = min(ch[s1[i]-'a'], ch[s2[i]-'a']);
            for (int i=0; i<26; i++){
                if (ch[i] == toReplace){
                    ch[i] = replaceWith;
                }
            }
        }
        
        for (int i = 0; i<baseStr.size(); i++){
            baseStr[i] = ch[baseStr[i]-'a'];
        }

        return baseStr;
        
        // using Map
//         unordered_map<char,char>mp;
//         for (int i=0; i<26; i++){
//             mp['a'+i]='a'+i;
//         }

//         for (int i=0; i<s1.size(); i++) {
//             char toReplace = max(mp[s1[i]], mp[s2[i]]);
//             char replaceWith = min(mp[s1[i]], mp[s2[i]]);
//             mp[toReplace]=replaceWith;
//         }
        
//         for (int i = 0; i<baseStr.size(); i++){
//          baseStr[i]=mp[baseStr[i]];
//         }

//         return baseStr;
        
    }
};