#include "leet.hpp"

class Solution {
  public:
    int array_sum(const vector<int> &nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0);
    }

    static void test() {
        leet::test(
            leet::expect(0,
                         [&]() {
                             Solution s;
                             auto v =
                                 leet::read_vector<int>("01-empty-array.txt");
                             return s.array_sum(v);
                         }),
            leet::expect(0,
                         [&]() {
                             Solution s;
                             auto v =
                                 leet::read_vector<int>("02-small-array.txt");
                             return s.array_sum(v);
                         }),
            leet::expect(1,
                         [&]() {
                             Solution s;
                             auto v =
                                 leet::read_vector<int>("03-small-array.txt");
                             return s.array_sum(v);
                         }),
            leet::expect(0, [&]() {
                Solution s;
                auto v = leet::read_vector<int>("04-large-array.txt");
                return s.array_sum(v);
            }));
    }
};