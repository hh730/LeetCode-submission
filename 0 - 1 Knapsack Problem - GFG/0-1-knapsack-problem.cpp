//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSackHelper(int wt[],int val[],int W,int n,vector<vector<int>>&memo){
        if(n==0||W==0){
            return 0;
        }
        if(memo[n][W]!=-1){
            return memo[n][W];
        }
        if(wt[n-1]<=W){
            memo[n][W]=max(val[n-1]+knapSackHelper(wt,val,W-wt[n-1],n-1,memo),knapSackHelper(wt,val,W,n-1,memo));
            return memo[n][W];
        }
        else if(wt[n-1]>W){
            memo[n][W]=knapSackHelper(wt,val,W,n-1,memo);
            return memo[n][W];
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>memo(n+1,vector<int>(W+1,-1));
       knapSackHelper(wt,val,W,n,memo);
       return memo[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends