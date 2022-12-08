//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int>rod;
        for(int i=0;i<n;i++){
            rod.push_back(i+1);
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                int incl=0;
                int excl=dp[i-1][j];
                if(rod[i-1]<=j){
                    incl=price[i-1]+dp[i][j-rod[i-1]];
                }
                dp[i][j]=max(incl,excl);
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends