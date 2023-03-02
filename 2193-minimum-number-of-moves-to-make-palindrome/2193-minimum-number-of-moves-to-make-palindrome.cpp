class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        while(i<j){
            int x = i,y=j;
            
            while(s[x]!=s[y])y--;
            
             //accbb,abb case for dry run
            if(x==y){
                swap(s[y],s[y+1]);
                ans++;
                continue;
            }
            //aabb case
            else{
                while(y<j){
                    swap(s[y],s[y+1]);
                    y++;
                    ans++;
                }
            }
            
            i++;j--;
        }
        return ans;
    }
};