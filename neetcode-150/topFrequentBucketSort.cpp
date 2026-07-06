#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // bucket[i] stores numbers that appear i times
        vector<vector<int>> bucket(nums.size() + 1);

        // Place numbers into their frequency bucket
        for (auto pair : freq) {
            int number = pair.first;
            int frequency = pair.second;

            bucket[frequency].push_back(number);
        }

        vector<int> ans;

        // Traverse buckets from highest frequency to lowest
        for (int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--) {

            for (int num : bucket[i]) {

                ans.push_back(num);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};
