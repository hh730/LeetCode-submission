//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,0));
        for(int i=0;i<N+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<N+1;i++){
            for(int j=1;j<sum+1;j++){
                long long int incl=0;
                long long int excl=dp[i-1][j];
                if(coins[i-1]<=j){
                    incl=dp[i][j-coins[i-1]];
                }
                dp[i][j]=incl+excl;
            }
        }
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends