class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List <String> res = new ArrayList<>();
        if(s.length() < 10) return res;
        Map <Integer, Integer> countMap = new HashMap<>();
        Map <Character, Integer> val = new HashMap<>();
        val.put('A', 0);
        val.put('C', 1);
        val.put('G', 2);
        val.put('T', 3);
        int hash = 0;
        int n = s.length();
        for(int i= 0; i< n; i++){
            hash = ((hash << 2)|val.get(s.charAt(i)))&((1<<20)-1); 
            if(i >= 9){
                countMap.put(hash, countMap.getOrDefault(hash, 0) + 1);
                if(countMap.get(hash) == 2){
                    res.add(s.substring(i-9, i+1));
                }
            }
        }
        return res;
    }
}