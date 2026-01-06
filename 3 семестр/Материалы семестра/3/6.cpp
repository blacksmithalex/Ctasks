class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector <int> empty(n);
        // empty[i] - макс. прибыль к i-ому дню, если в i-й день пустой
        vector <int> hold(n);
        // hold[i] - макс. прибыль к i-ому дню, если в i-й день полный
        empty[0] = 0;
        hold[0] = -prices[0];
        for (int i = 1; i < n; i++){
            hold[i] = max(hold[i - 1], empty[i - 1] - prices[i]);
            empty[i] = max(empty[i - 1], hold[i - 1] + prices[i] - fee);
        }
        return empty[n - 1];
    }
};