class Solution {
public:
    
    //memoized code
    
//     bool equalHelper(vector<int>& arr,int N,int sum,vector<vector<int>>&dp){
//     if(sum==0){
//         return true;
//     }
//     if(N==0){
//         return (sum==0);
//     }
//     if(dp[N][sum]!=-1){
//         return dp[N][sum];
//     }
//         if(arr[N-1]<=sum){
//             dp[N][sum]= equalHelper(arr,N-1,sum-arr[N-1],dp)||equalHelper(arr,N-1,sum,dp);
//         }
//         else{
//             dp[N][sum]=equalHelper(arr,N-1,sum,dp);
//         }
//     return dp[N][sum];
// }
    bool canPartition(vector<int>& arr) {
        int N=arr.size();
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        
        //memoized code
        // equalHelper(arr,N,sum/2,dp);
        // return dp[N][sum/2];
        
        //Top down approach
        
        for(int i=0;i<N+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<sum+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<N+1;i++){
            for(int j=1;j<(sum/2)+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][sum/2];
    }
};