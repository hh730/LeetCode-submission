class Solution {
public:
    bool equalHelper(vector<int>& arr,int N,int sum,vector<vector<int>>&dp){
    if(sum==0){
        return true;
    }
    if(N==0){
        return (sum==0);
    }
    if(dp[N][sum]!=-1){
        return dp[N][sum];
    }
        if(arr[N-1]<=sum){
    dp[N][sum]= equalHelper(arr,N-1,sum-arr[N-1],dp)||equalHelper(arr,N-1,sum,dp);
        }
        else{
            dp[N][sum]=equalHelper(arr,N-1,sum,dp);
        }
    return dp[N][sum];
}
    bool canPartition(vector<int>& arr) {
        int N=arr.size();
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        int temp=sum;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        equalHelper(arr,N,sum/2,dp);
        return dp[N][sum/2];
    }
};