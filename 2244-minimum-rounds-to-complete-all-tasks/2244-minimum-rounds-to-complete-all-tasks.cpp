class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        int size=tasks.size();
        for(int i=0;i<size;i++){
            mp[tasks[i]]++;
        }
        int count=0;
        for(auto x:mp){
            int a=x.second;
            if(a<2){
                return -1;
            }
            if(a%3==0){
                count += a/3;
            }
            else{
                count += a/3 + 1;
            }
        }
        return count;
    }
};