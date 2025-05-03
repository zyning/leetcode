class Solution {
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
            // the max y at x position, etc
            vector<int> xExistMax(n, -1);
            vector<int> xExistMin(n, n);
            vector<int> yExistMax(n, -1);
            vector<int> yExistMin(n, n);
            int count = 0;
            for (vector<int> building : buildings){
                int x = building[0] - 1;
                int y = building[1] - 1;
                //cout << "x:" << x << " y:" << y<< endl;
                //cout << "xExistMin[x]" << xExistMin[x] << endl;
                xExistMax[x] = max(xExistMax[x], y);
                xExistMin[x] = min(xExistMin[x], y);
                yExistMax[y] = max(yExistMax[y], x);
                yExistMin[y] = min(yExistMin[y], x);
            }
            for (vector<int> building : buildings){
                int x = building[0] - 1;
                int y = building[1] - 1;
                if (y > xExistMin[x] && y < xExistMax[x] && x > yExistMin[y] && x < yExistMax[y]) {
                    count += 1;
                }
            }
            return count;
        }
    };