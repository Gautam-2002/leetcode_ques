//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long nums[], int n, long long k)
	{
	    // Your code goes here
        unordered_map<long long,long long> mp;
        vector<long long > prefix(n);
        prefix[0] = nums[0]>0?nums[0]:(nums[0]*(-1)*k)+nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
            if(prefix[i]<0){
                prefix[i]%=k;
                prefix[i]+=k;
            }
        }
        for(int i=0;i<n;i++){
            mp[prefix[i]%k]++;
        }
        mp[0]++;
        long long ans = 0;
        for(auto it:mp){
            ans += (it.second * (it.second-1))/2;
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
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends