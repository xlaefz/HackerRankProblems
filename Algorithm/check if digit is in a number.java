/*
 * Complete the function below.
 */

    static String find_numbers(int digit, int start, int end) {
       String mdigit = Integer.toString(digit);
        StringBuilder result = new StringBuilder();
        for(int i = start; i <= end; i++){
            if(Integer.toString(i).contains(mdigit)){
                result.append(Integer.toString(i) + " ");
            }
        }
        return result.toString();
    }

