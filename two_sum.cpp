/*
 * Accepted
 * Runtime 548 ms. Beats 18.46%
 * Memory 10 MB ms. Beats 92.82%
 */

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> vec;
        for (int i = 0; i < nums.size() -1; ++i) {
            for (int j = i +1; j< nums.size(); ++j) {
                if (nums[i] + nums[j] == target)  {
                    vec.insert(vec.end(), {i, j});
                    return vec;
                }
            }
        }
        return std::vector<int>{0,0};
    }
};

void print_vec(std::vector<int>& vec) {
    for (auto a : vec) std::cout << a << '\n';
}

int main (int argc, char *argv[]) {
    //
    // test 1
    std::vector<int> vec{2,7,11,15};
    int target = 9;
    std::vector<int> ans{0, 1};
    assert(Solution::twoSum(vec, target) == ans);

    // test 2
    vec = {3, 2, 4};
    target = 6;
    ans = {1, 2};
    std::vector<int> res = Solution::twoSum(vec, target);
    // print_vec(res);
    assert(res == ans);
    //
    // test 3
    vec = {3, 3};
    target = 6;
    ans = {0, 1};
    res = Solution::twoSum(vec, target);
    assert(res == ans);

    return 0;
}
