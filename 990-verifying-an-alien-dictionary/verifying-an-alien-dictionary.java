class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        if(words.length <= 1)
            return true;
        
        HashMap<Character, Integer> mp = new HashMap<>();

        for(int i = 0; i<order.length(); i++)
        {
            mp.put(order.charAt(i), i);
        }

        for(int i = 1; i<words.length; i++)
        {
            String a = words[i-1];
            String b = words[i];

            for(int j = 0; j<a.length(); j++)
            {
                if(j == b.length())
                    return false;

                char cha = a.charAt(j);
                char chb = b.charAt(j);

                if (mp.get(cha) < mp.get(chb)){
                    break;
                }
                if (mp.get(cha) > mp.get(chb)){
                    return false;
                }
            }
        }

        return true;
    }
}