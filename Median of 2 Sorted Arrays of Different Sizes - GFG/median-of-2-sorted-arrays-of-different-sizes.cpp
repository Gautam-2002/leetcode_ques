//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
        double ans = 0.0;
        if(arr1.size()>arr2.size())return MedianOfArrays(arr2,arr1);
        
        int n1 = arr1.size();
        int n2 = arr2.size();
        int low = 0;
        int high = n1;
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            int r1 = cut1 == n1 ? INT_MAX : arr1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : arr2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                if((n1+n2)%2!=0){
                    ans = max(l1,l2);
                }
                else{
                    ans = ((1.0)*(max(l1,l2)+min(r1,r2)))/2.0;
                }
                return ans;
            }
            else if(l1 > r2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends