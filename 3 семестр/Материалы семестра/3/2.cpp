class Solution {
public:
    int minAddToMakeValid(string s) {
           stack<char> qwerty;
    int count = 0;
    for(int i = 0; i < s.length(); i) {
        if(s[i] == '(') {
            qwerty.push('(');
        }
        else {
            if(qwerty.empty()) {
                count;
            } else {
                qwerty.pop();
            }
        }
        }
        return count + qwerty.size();
    } 
};