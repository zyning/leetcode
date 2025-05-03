class Solution {
    public:
        vector<vector<int>> output;
        void dfs(vector<int> currentComb, int k, int n, int currentSum){
            if (currentComb.size() == k && currentSum == n){
                output.push_back(currentComb);
                return;
            }
            if (currentComb.size() < k && currentSum < n){
                if (currentComb.size() != 0){
                    for (int next = currentComb.back() + 1; next < 10; next++){
                        currentComb.push_back(next);
                        dfs(currentComb, k, n, currentSum + next);
                        currentComb.pop_back();
                    }
                } else {
                    for (int next = 1; next < 10; next++){
                        currentComb.push_back(next);
                        dfs(currentComb, k, n, currentSum + next);
                        currentComb.pop_back();
                    }
                }
            }
        }
        vector<vector<int>> combinationSum3(int k, int n) {
            dfs({}, k, n, 0);
            return output;
        }
    };