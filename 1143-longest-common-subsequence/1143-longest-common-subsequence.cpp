class Solution {
public:
    //pure recursion
    
    // int LCS(string x, string y, int n, int m){
    //     if(n==0||m==0){
    //         return 0;
    //     }
    //     if(x[n-1]==y[m-1]){
    //         return 1+LCS(x,y,n-1,m-1);
    //     }
    //     else{
    //         return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
    //     }
    // }
    
    //memoized
    
    // int LCS(string x, string y, int n, int m,vector<vector<int>>&dp){
    //     if(n==0||m==0){
    //         return 0;
    //     }
    //     if(dp[n][m]!=-1){
    //         return dp[n][m];
    //     }
    //     if(x[n-1]==y[m-1]){
    //         dp[n][m] = 1+LCS(x,y,n-1,m-1,dp);
    //     }
    //     else{
    //         dp[n][m] = max(LCS(x,y,n-1,m,dp),LCS(x,y,n,m-1,dp));
    //     }
    //     return dp[n][m];
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        //pure recursive
        
        // return LCS(text1,text2,text1.length(),text2.length());
        
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //memoized
        
        // return LCS(text1,text2,n,m,dp);
        
        //top down approach
        //initialization
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=0;
        }
        //fill table
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};