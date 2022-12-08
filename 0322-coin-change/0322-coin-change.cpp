class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int sum=amount;
        for(int i=0;i<sum+1;i++){
            dp[0][i]=INT_MAX-1;
        }
        for(int i=1;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<sum+1;i++){
            if(coins[0]%i==0){
                dp[1][i]=coins[0]/i;
            }
            else{
                dp[1][i]=INT_MAX-1;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                int incl=INT_MAX-1;
                int excl=dp[i-1][j];
                if(coins[i-1]<=j){
                    incl=1+dp[i][j-coins[i-1]];
                }
                dp[i][j]=min(incl,excl);
            }
        }
        if(dp[n][sum]==INT_MAX||dp[n][sum]==INT_MAX-1){
            return -1;
        }
        return dp[n][sum];
    }
};