class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> st = new Stack<>();

        for(int i = 0; i<operations.length; i++)
        {
            if(operations[i].equals("+"))
            {
                if(!st.empty())
                {
                    int a = st.peek();
                    st.pop();
                    int b = 0;
                    if(!st.empty())
                    {
                        b = st.peek();
                        st.pop();
                    
                    }
                    st.push(b);
                    st.push(a);
                    st.push(a+b);
                }
            }
            else if(operations[i].equals("D"))
            {
                if(!st.empty())
                {
                    int a = st.peek();
                    st.push(a*2);
                }
            }
            else if(operations[i].equals("C"))
            {
                if(!st.empty())
                    st.pop();
            }
            else
            {
                st.push(Integer.parseInt(operations[i]));
            }
        }

        int total = 0;
        while(!st.empty())
        {
            total+= st.peek();
            st.pop();
        }

        return total;
    }
}