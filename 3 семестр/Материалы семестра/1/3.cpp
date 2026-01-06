class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <int> hold(n);
        vector <int> empty(n);
        hold[0] = -prices[0];
        empty[0] = 0;
        for(int i = 1; i < n; i++) {
            hold[i] = max(-prices[i] + empty[i - 1], hold[i - 1]);
            empty[i] = max(hold[i - 1] + prices[i], empty[i - 1]);
        }
        return empty[n - 1];

    }
};