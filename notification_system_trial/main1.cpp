#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        if (nums.empty()) return {};

        // Sort the numbers
        std::sort(nums.begin(), nums.end());

        // Memoization map to store results of subproblems
        std::unordered_map<int, std::vector<int>> memo;

        // Helper function to find the largest divisible subset starting from index `i`
        std::function<std::vector<int>(int)> dfs = [&](int i) -> std::vector<int> {
            if (memo.count(i)) return memo[i];

            std::vector<int> maxSubset;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] % nums[i] == 0) {
                    auto subset = dfs(j);
                    if (subset.size() > maxSubset.size()) {
                        maxSubset = subset;
                    }
                }
            }

            maxSubset.push_back(nums[i]);
            return memo[i] = maxSubset;
        };

        std::vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            auto subset = dfs(i);
            if (subset.size() > result.size()) {
                result = subset;
            }
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
