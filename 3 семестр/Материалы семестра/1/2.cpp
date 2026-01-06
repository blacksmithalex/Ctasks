class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        int cost = 0;
        for (int i = 0; i < 2 * n; i++)
            cost += costs[i][0];
        vector <int> diff(2 * n);
        for (int i = 0; i < 2 * n; i++)
            diff[i] = costs[i][1] - costs[i][0];
        sort(diff.begin(), diff.end()); //сортировка по возрастанию
        for (int i = 0; i < n; i++)
            cost += diff[i];
        return cost;
    }
};