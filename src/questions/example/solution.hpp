#include "leet.hpp"

class Solution {
  public:
    int array_sum(const vector<int> &nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0);
    }
};