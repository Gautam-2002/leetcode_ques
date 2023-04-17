class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        int a=0,b=0;
        while(!st.empty()){
            if(st.top() == '[')a++;
            else b++;
            st.pop();
        }
        int ans = (((a+1)/2) + ((b+1)/2))/2;
        return ans;
    }
};