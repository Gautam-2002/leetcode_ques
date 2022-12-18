class Solution {
    public int[] nextGreaterElement(int[] nums) {
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        int []ans = new int[nums.length];
        for(int i=nums.length-1;i>=0;i--){
            int curr = nums[i];
            while(st.peek()!=-1 && nums[st.peek()]<=curr ){
                st.pop();
            }
            ans[i]=st.peek();
            st.push(i);
        }
        return ans;
    }
    public int[] dailyTemperatures(int[] temperatures) {
        int [] nextg = nextGreaterElement(temperatures);
        int []ans = new int[temperatures.length];
        for(int i=0;i<temperatures.length;i++){
            if(nextg[i]==-1)ans[i]=0;
            else{
                ans[i]=nextg[i]-i;
            }
        }
        return ans;
    }
}