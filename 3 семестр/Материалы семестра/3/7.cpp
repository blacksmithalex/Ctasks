class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i, j, count;
        i = 0;
        j = people.size() - 1;
        count = 0;
        while(i <= j) { 
            if(people[i] + people[j] <= limit) {
                count;
                i;
                j--;
            } else {
                count++;
                j--;
            }
        }
        return count;
    }
};