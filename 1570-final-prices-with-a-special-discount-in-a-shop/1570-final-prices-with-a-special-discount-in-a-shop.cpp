class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
       int n=prices.size(); 
       vector<int>ans(n,0);
       ans[n-1]=prices[n-1];
       stack<int>s;
       for(int i=n-1;i>=0;i--){
        while(!s.empty()&&prices[i]<s.top()){
            s.pop();
        }
        if(!s.empty()){
        ans[i]=prices[i]-s.top();
        }else{
            ans[i]=prices[i];
        }
        s.push(prices[i]);
       }
       return ans;
    }
};