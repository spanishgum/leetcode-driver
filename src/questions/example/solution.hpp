#include "leet.hpp"

class Solution {
    using test_type = pair<int, tuple<vector<int>>>;

  public:
    int array_sum(const vector<int> &nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0);
    }

    vector<test_type> tests() {
        return {
            make_pair(0, make_tuple(read_vector<int>("01-empty-array"))),
        };
    }
};