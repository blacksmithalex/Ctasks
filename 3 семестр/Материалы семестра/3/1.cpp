class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map <char, int> Last;
        for(int i = 0; i < s.size(); i) {
            Last[s[i]] = i;
        }
        vector<int> result;
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i) {
            end = max(end, Last[s[i]]);
            if(end == i) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};