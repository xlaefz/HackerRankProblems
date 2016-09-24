class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int minnum = prices[0];
        int result = 0;
        for(int i =1; i < prices.size(); i++){
            result = max(prices[i]-minnum, result);
            minnum = min(minnum, prices[i]);
        }
        return result;
    }
};