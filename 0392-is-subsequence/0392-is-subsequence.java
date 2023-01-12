class Solution {
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
    public boolean isSubsequence(String s, String t) {
        int match = solve(s,0,t,0);
        
        return match==s.length() ? true : false;
    }
}