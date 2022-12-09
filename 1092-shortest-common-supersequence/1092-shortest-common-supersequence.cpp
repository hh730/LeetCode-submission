class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        if(str1==str2){
            return str1;
        }
        // 1. Find the longest common subsequence
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string lcsString="";
        int i=n;
        int j=m;
        //2. Now we will iterate our dp tabel 
        // if char is same then we will go to i-- and j--
        // else we will go to max value in the tabel
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                lcsString+=str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    lcsString+=str1[i-1];
                    i--;
                }
                else{
                    lcsString+=str2[j-1];
                    j--;
                }
            }
        }
        //Now we have to add remaining chars
        while(i>0)
        {
            lcsString+=str1[i-1];
            i--;
        }
        while(j>0)
        {
            lcsString+=str2[j-1];
            j--;
        }
        //3. Reverse the string as we are iterating from last
        reverse(lcsString.begin(),lcsString.end());
        return lcsString;
    }
};