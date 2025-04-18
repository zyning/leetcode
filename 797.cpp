#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<int>> d_allPaths;
        void dfs(vector<vector<int>>& graph, int current, int target, vector<int> previousPath, vector<int> visited){
            previousPath.push_back(current);
            visited[current] = 1;
            if (current == target){
                d_allPaths.push_back(previousPath);
            }
            for (int nextNode : graph[current]){
                if (visited[nextNode] == 0){
                    dfs(graph, nextNode, target, previousPath, visited);
                }
            }
        }
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<int> visited(graph.size(), 0);
            dfs(graph, 0, graph.size() - 1, {}, visited);
            return d_allPaths;
        }
    };

// Add a main function to test the Solution class
int main() {
    Solution solution;
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> result = solution.allPathsSourceTarget(graph);

    cout << "All paths from source to target:" << endl;
    for (const auto& path : result) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}