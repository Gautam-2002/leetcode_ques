// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    int n = s.size();
    int m = x.size();
    // int sm = (n<m)?n:m;
    string str = "";
    for(int i=0;i<n-m+1;i++){
        str=s.substr(i,m);
        if(str==x){
            return i;
        }
    }
    return -1;
}