class Solution {
    public:
    
        vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            std::map<int, int> buckets;
            int currentBucket = 0;
            for (int left = 0, right = 0; left < n; ++left) {
                while (right < n && abs(nums[right] - nums[left]) <= maxDiff) {
                    if (buckets.contains(left)){
                        buckets[right] = buckets[left];
                        ++right;
                    } else {
                        currentBucket += 1;
                        buckets[left] = currentBucket;
                    }
                }
            }
    
            vector<bool> output;
            for (const vector<int>& query : queries) {
                int startNode = query[0];
                int endNode = query[1];
                output.push_back(buckets[startNode] == buckets[endNode]);
            }
            return output;
        }
    };
    