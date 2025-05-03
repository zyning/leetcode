class Solution {
    public:
        std::set<int> m_output;
        void dfs(int currentPos, int previousNum, int currentVal, int n, int k){
            int nextVal = previousNum * 10 + currentVal;
            if (currentPos == n - 1){
                m_output.insert(nextVal);
            }
            if (currentVal + k < 10 && currentPos < n - 1){
                dfs(currentPos + 1, nextVal, currentVal + k, n, k);
            }
            if (currentVal - k >= 0 && currentPos < n - 1){
                dfs(currentPos + 1, nextVal, currentVal - k, n, k);
            }
        }
        vector<int> numsSameConsecDiff(int n, int k) {
            for (int firstVal = 1; firstVal<10; firstVal++){
                dfs(0, 0, firstVal, n, k);
            }
            return vector<int>(m_output.begin(), m_output.end());
        }
    };