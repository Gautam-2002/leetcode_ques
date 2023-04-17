//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    
    void solve(stack<int>&s,int sz,int mid){
        if(s.empty())return;
        if(mid==sz/2){
            s.pop();
            return;
        }
        int x = s.top();s.pop();
        solve(s,sz,mid+1);
        s.push(x);
    }
    
    //Function to delete middle element of a stack.
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        solve(s,sizeOfStack,0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends