class Solution {
public:
    int findMin(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0||j>=matrix[0].size()){
            return 100000;
        }
        if(i==0){
            return matrix[0][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int upSum=matrix[i][j]+findMin(i-1,j,matrix,dp);
        int leftDiagonalSum=matrix[i][j]+findMin(i-1,j-1,matrix,dp);
        int rightDiagonalSum=matrix[i][j]+findMin(i-1,j+1,matrix,dp);
        return dp[i][j]= min(upSum,min(leftDiagonalSum,rightDiagonalSum));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int minSum=100000;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int sUp=100000;
                int ld=100000;
                int rd=100000;
                sUp=matrix[i][j]+dp[i-1][j];
                if(j>0){
                    ld=matrix[i][j]+dp[i-1][j-1];
                }
                if(j+1<m){
                    rd=matrix[i][j]+dp[i-1][j+1];
                }
                dp[i][j]=min(sUp,min(ld,rd));
            }
        }
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            // minSum=min(minSum,findMin(n-1,j,matrix,dp));
            minSum=min(minSum,dp[n-1][j]);
        }
        return minSum;
    }
};