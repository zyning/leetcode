class Solution {
    public:
        bool dfs(int currentNode, int endNode, vector<vector<int>> graph, vector<int> visited){
            //cout << "searching: " << currentNode << endl;
            if (currentNode == endNode){
                return true;
            }
            visited[currentNode] = 1;
            bool result = false;
            for (int nextNode : graph[currentNode]){
                //cout << "nextNode: " << nextNode << endl;
                if (visited[nextNode] == 0){
                     result = result || dfs(nextNode, endNode, graph, visited);
                }
            }
            return result;
        }
        vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            vector<vector<int>> graph(n, vector<int>());
            vector<bool> output;
            int leftPtr = 0;
            int rightPtr = 0;
            while (rightPtr < n && leftPtr < n){
                while (rightPtr < n && abs(nums[rightPtr] - nums[leftPtr]) <= maxDiff)
                {
                    //cout << "left" << leftPtr << " right" << rightPtr << endl;
                    graph[leftPtr].push_back(rightPtr);
                    graph[rightPtr].push_back(leftPtr);
                    rightPtr += 1;
                }
                leftPtr += 1;
            }
            for (vector<int> query : queries){
                int startNode = query[0];
                int endNode = query[1];
                vector<int> visited(n, 0);
                output.push_back(dfs(startNode, endNode, graph, visited));
            }
            return output;
        }
    };