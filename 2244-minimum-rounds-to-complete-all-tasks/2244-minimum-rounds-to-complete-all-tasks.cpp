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
            while(a>0){
                if(a>=3){
                    a=a-3;
                    count++;
                }
                else if(a>0){
                    a=a-2;
                    count++;
                }
            }
        }
        return count;
    }
};