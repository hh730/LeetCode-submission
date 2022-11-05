//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void computeLpsArray(string concat,vector<int>&lps){
    int n=concat.size();
    int len=0,i=1;
    while(i<n){
        if(concat[len]==concat[i]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
    int minChar(string str){
        string strDup=str;
        reverse(strDup.begin(),strDup.end());
        string concat=str+"$"+strDup;
        vector<int>lps(concat.length(),0);
        computeLpsArray(concat,lps);
        return (str.length() - lps.back());
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends