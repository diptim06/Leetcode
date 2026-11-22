class Solution {
    public int minLength(String s) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);

            if (stack.isEmpty()) {
                stack.push(curr);
                continue;
            }
      
            if (curr == 'B' && stack.peek() == 'A') {
                stack.pop();
            }
            else if (curr == 'D' && stack.peek() == 'C') {
                stack.pop();
            }
            else {
                stack.push(curr);
            }
        }

        return stack.size();
    }
}