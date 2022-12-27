class Solution {
public:
    int solve(int e, int f,vector<vector<int>>&dp){
        if(e==1||f==0||f==1){
            return f;
        }
        if(dp[e][f]!=-1){
            return dp[e][f];
        }
        int mn=INT_MAX;
        int l=0,h=f;
         while(l<=h)
        {
            int mid=(l+h)/2;
            int left=solve(e-1,mid-1,dp);   //egg broken check for down floors of mid
            int right=solve(e,f-mid,dp) ;   // not broken check for up floors of mid
            int temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            mn=min(mn,temp);               //store minimum attempts
        }
        // for(int k=1;k<=f;k++){
        //     int low=INT_MIN;
        //     if(dp[e-1][k-1]!=-1){
        //         low=dp[e-1][k-1];
        //     }
        //     else{
        //         low=solve(e-1,k-1,dp);
        //         dp[e-1][k-1]=low;
        //     }
        //     int high=INT_MIN;
        //     if(dp[e][f-k]!=-1){
        //         high=dp[e][f-k];
        //     }
        //     else{
        //         high=solve(e,f-k,dp);
        //         dp[e][f-k]=high;
        //     }
        //     int temp=1+max(low,high);
        //     mn=min(mn,temp);
        // }
        return dp[e][f]=mn;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
        
        
//         //This loop initializes the base case for the table, which is that it takes 1 move to check the first floor with any number of eggs.
//         for (int i = 1; i <= k; i++) {
//             dp[i][1] = 1;
//         }

//        //This loop initializes the base case for the table, which is that it takes j moves to check j floors with 1 egg.
//          for (int j = 1; j <= n; j++) {
//             dp[1][j] = j;
//         }

//         // These nested loops fill the table using the formula mentioned earlier, which is:
//         // dp[i][j] = 1 + min(max(dp[i-1][k-1], dp[i][j-k]))
//         // where k goes from 1 to j.
//         // The inner loop uses binary search to find the value of k that minimizes the maximum of dp[i-1][k-1] and dp[i][j-k]. The value of dp[i][j] is then set to 1 + the minimum value of dp[i-1][k-1].
//         for (int i = 2; i <= k; i++) {
//             for (int j = 2; j <= n; j++) {
//                 int left = 1, right = j;
//                 while (left < right) {
//                     int mid = left + (right - left) / 2;
//                     if (dp[i-1][mid-1] < dp[i][j-mid]) {
//                         left = mid + 1;
//                     } else {
//                         right = mid;
//                     }
//                 }
//                 dp[i][j] = 1 + dp[i-1][left-1];
//             }
//         }
        
//         //This line returns the value of dp[k][n] as the result, which is the minimum number of moves needed to determine the value of f with k eggs and n floors.
//         return dp[k][n];
    }
};