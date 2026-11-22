class Solution {
    public String removeStars(String s) {
        Stack<Character> st = new Stack<>();

        for(int i = 0; i<s.length(); i++)
        {
            char c = s.charAt(i);
            if(c == '*')
            {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(c);
        }

        StringBuilder ans = new StringBuilder();
        
        while(!st.empty())
        {
            ans.append(st.pop());
        }

        return ans.reverse().toString();
    }
}