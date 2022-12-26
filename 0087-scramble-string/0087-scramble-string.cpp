class Solution {
public:
    unordered_map<string,bool>mp;
    bool solve(string s1,string s2){
        if(s1==s2){
            return true;
        }
        if(s1.length()<=1){
            return false;
        }
        string key=s1;
        key.push_back(' ');
        key.append(s2);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        int n=s1.length();
        bool flag=false;
        for(int i=1;i<n;i++){
            bool case1= solve(s1.substr(0,i),s2.substr(n-i,i))&&solve(s1.substr(i,n-i),s2.substr(0,n-i));
            bool case2= solve(s1.substr(0,i),s2.substr(0,i))&&solve(s1.substr(i,n-i),s2.substr(i,n-i));
            if(case1||case2){
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n!=m){
            return false;
        }
        if(n==0&&m==0){
            return true;
        }
        return solve(s1,s2);
    }
};