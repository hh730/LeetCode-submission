class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int sum=amount;
        //Initialization
        //When n==0 (no coins) then we need infinite amount of coin to make sum=amount
        // if amount==0 then we need zero coin;
        
        for(int i=0;i<sum+1;i++){
            dp[0][i]=INT_MAX-1;
        }
        for(int i=1;i<n+1;i++){
            dp[i][0]=0;
        }
        
        // Now we have to initialize 2nd row also
        // in 2nd row we have size ==1
        // so if a j%coins[0]==0 then t[1][j]=j/coins[0];
        // else INT_MAX
        
        for(int i=1;i<sum+1;i++){
            if(i%coins[0]==0){
                dp[1][i]=i/coins[0];
            }
            else{
                dp[1][i]=INT_MAX-1;
            }
        }
        
        // i will start from 2 as we have filled/initialised first 2 rows already
        //Now we need to fill our tabel
        // We have two choice take or reject
        
        for(int i=2;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                int incl=INT_MAX-1;
                int excl=dp[i-1][j];
                if(coins[i-1]<=j){
                    incl=1+dp[i][j-coins[i-1]];
                }
                dp[i][j]=min(incl,excl);
            }
        }
        // as if not possible we need to retutn -1
        if(dp[n][sum]==INT_MAX||dp[n][sum]==INT_MAX-1){
            return -1;
        }
        return dp[n][sum];
    }
};