class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prev_level;
        prev_level.push_back(1);
        result.push_back(prev_level);
        for(int i = 1; i < numRows; i) {
            vector <int> cur_level;
            cur_level.push_back(1);
            for(int j = 0; j < prev_level.size() - 1; j) {
                cur_level.push_back(prev_level[j] + prev_level[j + 1]);
            }
            cur_level.push_back(1);
            result.push_back(cur_level);
            prev_level = cur_level; 
        }
        return result;
    }
};