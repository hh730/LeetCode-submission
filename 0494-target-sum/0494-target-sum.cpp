class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(abs(target)>sum||(target+sum)%2!=0){
            return 0;
        }
        sum=(target+sum)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                int excl=dp[i-1][j];
                int incl=0;
                if(nums[i-1]<=j){
                    incl=dp[i-1][j-nums[i-1]];
                }
                dp[i][j]=incl+excl;
            }
        }
        return dp[n][sum];
    }
};