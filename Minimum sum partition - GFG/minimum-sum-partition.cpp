//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
bool isSubsetSum(int arr[],int n,int sum,vector<vector<int>>&dp){
        if(n==0){
            return (sum==0)?true:false;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(arr[n-1]<=sum){
            dp[n][sum]=isSubsetSum(arr,n-1,sum-abs(arr[n-1]),dp)||isSubsetSum(arr,n-1,sum,dp);
        }
        else{
            dp[n][sum]=isSubsetSum(arr,n-1,sum,dp);
        }
        return dp[n][sum];
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(arr[i]);
        }
        sum=abs(sum);
        // vector<int>range(sum+1,0);
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        vector<int>v;
          for(int i=0;i<(sum+1);i++){
              isSubsetSum(arr,n,i,dp);
        }
        for(int i=0;i<(sum/2+1);i++){
            if(dp[n][i]){
                v.push_back(i);
            }
        }
        // for(int i=0;i<sum+1;i++){
        //     range[i]=isSubsetSum(arr,n,i,dp);
        // }
        // int ans=INT_MAX;
        // for(int i=0;i<range.size();i++){
        //     if(range[i]==1){
        //         int s2=sum-i;
        //         ans=min(ans,abs(s2-i));
        //     }
        // }
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++){
            ans=min(ans,sum-2*v[i]);
        }
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends