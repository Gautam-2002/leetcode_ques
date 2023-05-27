class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,ArrayList<String>> mp = new HashMap<>();
        
        for(int i=0;i<strs.length;i++){
            String x = generateKey(strs[i]);
            if(!mp.containsKey(x)){
                mp.put(x,new ArrayList<>());
            }
            mp.get(x).add(strs[i]);
        }
        List<List<String>> ans = new ArrayList<>();
        for(String key:mp.keySet()){
            ans.add(mp.get(key));
        }
        return ans;
    }
    public String generateKey(String str){
        int []f = new int[26];
        for(int i=0;i<str.length();i++){
            f[str.charAt(i)-'a']++;
        }
        StringBuilder s = new StringBuilder();
        for(int i=0;i<26;i++){
            s.append(f[i]);
            s.append("-");
        }
        // System.out.println(s);
        return s.toString();
    }
}