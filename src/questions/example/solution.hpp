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
                             auto v = leet::read_vector<int>(
                                 "questions/example/inputs/01-empty-array.txt");
                             return s.array_sum(v);
                         }),
            leet::expect(0,
                         [&]() {
                             Solution s;
                             auto v = leet::read_vector<int>(
                                 "questions/example/inputs/02-small-array.txt");
                             return s.array_sum(v);
                         }),
            leet::expect(1,
                         [&]() {
                             Solution s;
                             auto v = leet::read_vector<int>(
                                 "questions/example/inputs/03-small-array.txt");
                             return s.array_sum(v);
                         }),
            leet::expect(
                10,
                [&]() {
                    Solution s;
                    auto v = leet::read_vector<int>(
                        "questions/example/inputs/04-medium-array.txt");
                    return s.array_sum(v);
                }),
            leet::expect(0, [&]() {
                Solution s;
                auto v = leet::read_vector<int>(
                    "questions/example/inputs/05-large-array.txt");
                return s.array_sum(v);
            }));
    }
};