class Solution {
    public String maximumOddBinaryNumber(String s) {
        int one = 0;

        StringBuilder st = new StringBuilder();

        for(int i = 0; i<s.length(); i++)
        {
            if(s.charAt(i) == '1')
                one++;
        }

        for(int i = 0; i<s.length(); i++)
        {
            if(one > 1)
            {
                st.append('1');
                one--;
            }

            else if(one == 1 && i == s.length()-1)
            {
                st.append('1');
                one--;
            }

            else 
                st.append('0');

        }

        return st.toString();
    }
}