//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            
            String a = sc.next();
            String b = sc.next();
            Solution ob = new Solution();
            if(ob.isSubSequence(a,b))
            System.out.println(1);
            else
            System.out.println(0);
 		
        }
    }
}


// } Driver Code Ends


//User function Template for Java

class Solution{
    public int solve(String s,int i,String t,int j){
        int ans = 0;
        if(i>=s.length() || j>=t.length()){
            return 0;
        }
        if(s.charAt(i)==t.charAt(j)){
            ans += solve(s,i+1,t,j+1) + 1;
        }
        else{
            ans = solve(s,i,t,j+1);
        }
        return ans;
    }
    boolean isSubSequence(String s, String t){
        int match = solve(s,0,t,0);
        
        return match==s.length() ? true : false;
    }
}