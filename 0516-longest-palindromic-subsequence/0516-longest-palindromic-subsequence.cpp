class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        // longestPalindromeSubseq = LCS(s,reverse(s));
        //LCS= Longest common subsequence
        string s2=s;
        reverse(s.begin(),s.end());
        if(s==s2){
            return s.length();
        }
        int n=s.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==s2[j-1]){
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