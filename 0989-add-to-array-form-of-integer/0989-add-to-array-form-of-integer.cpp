class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int carry=0;
        int i=num.size()-1;
        while(i>=0){
            int sum=num[i]+(k%10)+carry;
            ans.push_back(sum%10);
            carry=sum/10;
            k=k/10;
            i--;
        }
        while(k!=0){
            int sum=k%10+carry;
            ans.push_back(sum%10);
            carry=sum/10;
            k=k/10;
        }
        if(carry==1){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};