class Solution {
public:
    bool isPalindrome(string &s,int si,int ei){
        while(si<=ei){
            if(s[si]!=s[ei]){
                return false;
            }
            si++;
            ei--;
        }
        return true;
    }
    // bool isPalindrome (string & s, int i, int j){
    //     while(i<=j){
    //         if(s[i]!=s[j]) return false;
    //         i++; j--;
    //     }
    //     return true;
    // }
    // int solve(string s,int i,int j,vector<vector<int>>&dp){
    int solve(string s,int i,int j,vector<int>&dp){
        if(i>=j||isPalindrome(s,i,j)){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        // if(dp[i][j]!=-1){
        //     return dp[i][j];
        // }
        int mn=INT_MAX;
        for(int k=i;k<j;k++){
             /* 
                Instead of writing below standard line
                We will recurse for only right part
                Only when left part turns out to be palindrome
				
				Reason : If left substring becomes palindrome then there is no need to partition it further 
				(which in turn reduces the number of recursive calls)
                
                int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
            */
            if(isPalindrome(s,i,k)){
                int right=0;
                if(dp[k+1]!=-1){
                    right=dp[k+1];
                }
                else{
                    right=solve(s,k+1,j,dp);
                }
                int temp=1+right;
                mn=min(mn,temp);
            }
        }
        return dp[i]=mn;
        // return dp[i][j]=mn;
    }
//     bool isPalindrome (string & s, int i, int j){
//         while(i<j){
//             if(s[i]!=s[j]) return false;
//             i++; j--;
//         }
//         return true;
//     }
    

//     int solve (string & s, int i, int j, vector<int> & dp){    
        
//         if(i>=j or isPalindrome(s, i, j)) return 0;
        
//         if(dp[i]!=-1) return dp[i];
        
//         int ans = INT_MAX;
        
//         for(int k=i; k<j; k++){
            
//             /* 
//                 Instead of writing below standard line
//                 We will recurse for only right part
//                 Only when left part turns out to be palindrome
				
// 				Reason : If left substring becomes palindrome then there is no need to partition it further 
// 				(which in turn reduces the number of recursive calls)
                
//                 int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
//             */
            
//             if(isPalindrome(s, i, k)){                         
//                 int temp = solve (s, k+1, j, dp) + 1;
//                 ans = min (ans, temp);
//             }
//         }
        
//         return dp[i] = ans;
//     }
    int minCut(string s) {
        int n=s.length();
        vector<int> dp (n+1, -1);   
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1,dp);
    }
};