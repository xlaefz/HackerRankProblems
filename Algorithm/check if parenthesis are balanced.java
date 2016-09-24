/*
 * Complete the function below.
 */
    //private HashSet<char> set = new HashSet<char>();
    
    static Boolean checkBalance(String curr){
        if(curr.length() == 0) return true;
        if(curr.length() %2 != 0) return false;
        Stack<Character> mStack = new Stack<Character>();
        for(int i =0; i < curr.length(); i++){
            if(curr.charAt(i) == '[' || curr.charAt(i) == '{' || curr.charAt(i) == '('){
                mStack.push(curr.charAt(i));
            }else if(curr.charAt(i) == ']'){
                if(mStack.peek() != '['){
                    return false;
                }else{
                    mStack.pop();
                }
            }else if(curr.charAt(i) == '}'){
                if(mStack.peek() != '{'){
                    return false;
                }else{
                    mStack.pop();
                }
            }else if(curr.charAt(i) == ')'){
                if(mStack.peek() != '('){
                    return false;
                }else{
                    mStack.pop();
                }
            }
        }
        if(!mStack.empty()){
            return false;
        }
        return true;
    }

    static String[] braces(String[] values) {
       // set.add
        List<String> list = new ArrayList<String>();
        int numstrings = values.length;
        for(int i =0; i < numstrings; i++){
            String curr = values[i];
            Boolean result = checkBalance(curr);
            if(result){
                list.add("YES");   
            }else{
                list.add("NO");
            }
        }
        return (String[]) list.toArray(new String[0]);
    }

