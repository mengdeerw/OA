// https://leetcode.com/discuss/interview-question/861453/
/* For each position in string I am keeping track of next "|" index(by scanning right to left) 
and previous "|" index (by scanning left to right) and total sum in map at for each "|" only.
*/


public static List<Integer> numberOfItems(String s, List<Integer> startIndices, List<Integer> endIndices) {

    int n = startIndices.size();
    List<Integer> result = new ArrayList<>();
    HashMap<Integer, Integer> sum = new HashMap<>();
    int[] lr = new int[s.length()];
    int curBuffer = 0;
    int curSum = 0;
    int marker = 0;
    boolean open = false;
    for (int i = 0; i < s.length(); i++) {
        char c = s.charAt(i);
        if (c == '|') {
            if(open){
                curSum += curBuffer;
            }
            else{
                open = true;
            }
            marker = i;
            sum.put(i, curSum);
            curBuffer = 0;
        }
        else {
            curBuffer++;
        }
        lr[i] = marker;
    }
    
    open = false;
    marker = s.length() - 1;
    int[] rl = new int[s.length()];
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s.charAt(i);
        if (c == '|') {
            marker = i;
        }
        rl[i] = marker;
    }

    for (int i = 0; i < n; i++) {
        int start = startIndices.get(i) - 1;
        int end = endIndices.get(i) - 1;
        start = rl[start];
        end = lr[end];

        if(start >= end) {
            result.add(0);
        }
        else {
            result.add(sum.get(end) - sum.get(start));
        }
    }

    return result;
}
