
 longest subarray of sum <= k
    static int maxLength(int[] a, int k) {
        
        List<Integer> lengths = new ArrayList<Integer>();
        int currsum = a[0];
        int left = 0;
        int right = 0;
        int currlength = 1;
        while(left < a.length){
            if(currsum <= k){
                lengths.add(currlength);
                left++;
                if(left < a.length){
                    currsum += a[left];
                    currlength++;
                }
            }else{
                currsum -= a[right];
                right++;
                currlength--;
            }
        }
        
        int max = -1;
        for(int i = 0; i < lengths.size(); i ++){
            if(lengths.get(i) > max){
                max = lengths.get(i);
            }
        }
        return max;
    }

