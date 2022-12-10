class Solution {
public:
    bool isSubsequence(string s, string t) {
        // int i=0;
        // int j=0;
        // while(i<s.size()&&j<t.size()){
        //     if(s[i]==t[j]){
        //         i++;
        //     }
        //     j++;
        // }
        // return i==s.size();
        // one more method is to use LCS
        // if LCS of s and t is eqaul to length of s then it is a subsequence
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m]==n;
    }
};