class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            std::vector<int> costMap(cost.size(), INT_MAX);
            costMap[0] = cost[0];
            costMap[1] = cost[1];
            //costMap[2] = min(cost[2] + costMap[1], cost[2] + costMap[0]);
            for (int i = 2; i < cost.size(); i++){
                cout << i << endl;
                costMap[i] = min(cost[i] + costMap[i - 1], cost[i] + costMap[i - 2]);
            }
            return min(costMap.back(), costMap[costMap.size() - 2]);
        }
    };