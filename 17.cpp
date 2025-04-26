#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
    public:
        std::map<char, vector<string>> numbersMap;
        std::vector<string> m_allCombinations;
        void dfs(int position, string combination, string digits){
            if (position == digits.size()){
                if (combination != ""){
                    m_allCombinations.push_back(combination);
                }
                return;
            }
            char currentDigit = digits[position];
            for (string letter : numbersMap[currentDigit]){
                string nextCombination = combination + letter;
                dfs(position + 1, nextCombination, digits);
            }
        }
        vector<string> letterCombinations(string digits) {
            if (digits.empty()) return {};
            numbersMap['2'] = {"a", "b", "c"};
            numbersMap['3'] = {"d", "e", "f"};
            numbersMap['4'] = {"g", "h", "i"};
            numbersMap['5'] = {"j", "k", "l"};
            numbersMap['6'] = {"m", "n", "o"};
            numbersMap['7'] = {"p", "q", "r", "s"};
            numbersMap['8'] = {"t", "u", "v"};
            numbersMap['9'] = {"w", "x", "y", "z"};
            dfs(0, "", digits);
            return m_allCombinations;        
        }
};

// Add a main function to test the Solution class
int main() {
    Solution solution;
    string digits = "23";
    vector<string> result = solution.letterCombinations(digits);

    cout << "Letter combinations for digits \"" << digits << "\":" << endl;
    for (const auto& combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}