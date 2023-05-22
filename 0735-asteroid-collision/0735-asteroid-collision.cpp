class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i:asteroids){
            if(st.empty() || st.top() < 0){
                st.push(i);
            }
            else if(i > 0){
                st.push(i);
            }
            else if(!st.empty() && i<0){
                bool f = false;
                while(!st.empty() && st.top() > 0 && st.top() <= abs(i)){
                    if(st.top()==abs(i)){
                        f = true;
                        st.pop();
                        break;
                    }
                    st.pop();                    
                }
                if(!f && (st.empty() || st.top() < 0)){
                    st.push(i);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};