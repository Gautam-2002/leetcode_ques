class Solution {
    public int longestPalindrome(String s) {
        HashMap<Integer,Integer> mp = new HashMap<Integer,Integer>();
        for(char i:s.toCharArray()){
            int x=0;
            if(mp.containsKey(i-'a')){
                x+=mp.get(i-'a');
            }
            mp.put(i-'a',x+1);
        }
        int ans=0;
        // for(auto it:mp){
        //     if(it.second%2==0){
        //         ans+=it.second;
        //     }
        //     else{
        //         ans+=it.second-1;
        //     }
        // }
//         for(Map.Entry m:mp.entrySet()){
            
//         }
        for(int it:mp.keySet()){
            int x = mp.get(it);
            // System.out.println(x); 
            if(mp.get(it)%2==0){
                ans+=mp.get(it);
            }
            else{
                ans+=mp.get(it)-1;
            }
        }
           // for(Map.Entry m : map.entrySet()){    
           //  System.out.println(m.getKey()+" "+m.getValue());    
           // }  
        if(ans<s.length()){
            ans++;
        }
        return ans;
    }
}