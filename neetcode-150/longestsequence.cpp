class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s;

        // Insert all numbers into the hash set
        for (int num : nums) {
            s.insert(num);
        }

        int longest = 0;

        // Check every number
        for (int num : s) {

            // If there is a previous number,
            // this cannot be the start of a sequence.
            if (s.count(num - 1))
                continue;

            int current = num;
            int length = 1;

            // Count the consecutive numbers
            while (s.count(current + 1)) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};
