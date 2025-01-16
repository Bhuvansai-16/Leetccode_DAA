#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> matchingBrackets = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (matchingBrackets.count(c)) { // If it's a closing bracket
                if (stk.empty() || stk.top() != matchingBrackets[c]) {
                    return false;
                }
                stk.pop();
            } else { // If it's an opening bracket
                stk.push(c);
            }
        }

        return stk.empty(); // Valid if no unmatched opening brackets remain
    }
};
