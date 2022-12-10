class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans=0;
        for(int i=0;i<strs.size();i++){
            int num=0;
            bool flag=false;
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]>='a'&&strs[i][j]<='z'){
                    flag=true;
                    break;
                }
            }
            if(flag){
                num=strs[i].length();
            }
            else{
                num=stoi(strs[i]);
            }
            ans=max(ans,num);
        }
        return ans;
    }
};