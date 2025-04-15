#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
class Solution {
    public:
        bool largestIsValid(vector<int>& nums, int targetSum, int k){
            // Check if targetSum is a valid largest sum
            int nextIndex = 0;
            int totalCount = 0;
            while (nextIndex < nums.size()){
                int currentSum = 0;
                while (nextIndex < nums.size() && currentSum <= targetSum){
                    // if any element > targetSum, automatically fail the test
                    //cout << "currentSum:" << currentSum << endl;
                    //cout << "nextIndex:" << nextIndex << endl;
                    if (nums[nextIndex] > targetSum) {
                        return false;
                    }
                    if (currentSum + nums[nextIndex] <= targetSum){
                        currentSum += nums[nextIndex];
                        nextIndex += 1;
                    } else {
                        break;
                    }
                }
                totalCount += 1;
            }
            //cout << "target=" << targetSum << " final k=" << totalCount << endl;
            if (totalCount > k){
                return false;
            } 
            return true;
        }
    
        int splitArray(vector<int>& nums, int k) {
            int left = 0;
            int right = std::accumulate(nums.begin(), nums.end(), 0) + 1;
            while (left < right){
                int mid = (left + right)/2;
                if (largestIsValid(nums, mid, k)){
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }
    };
// Add a main function to test the Solution class
int main() {
    Solution solution;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    int result = solution.splitArray(nums, k);
    cout << "The minimum largest sum is: " << result << endl;
    return 0;
}