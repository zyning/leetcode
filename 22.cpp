class Solution {
    public:
        vector<string> output;
        void dfs(string current, int degree, int leftRemain, int rightRemain) {
            if (degree == 0 && leftRemain == 0 && rightRemain == 0){
                output.push_back(current);
            }
            if (leftRemain > 0){
                dfs(current + "(", degree + 1, leftRemain - 1, rightRemain);
            }
            if (rightRemain > 0 && degree > 0){
                dfs(current + ")", degree - 1, leftRemain, rightRemain - 1);
            }
        }
        vector<string> generateParenthesis(int n) {
            dfs("", 0, n, n);
            return output;
        }
    };