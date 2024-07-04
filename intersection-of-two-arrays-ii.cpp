// https://leetcode.com/problems/intersection-of-two-arrays-ii/
#include <algorithm>
#include <cassert>
#include <vector>

typedef std::vector<int> vector;


class Solution {
    static vector intersect_(vector& nums1, vector& nums2) {

        auto res = vector{};
        auto tmpRes = vector{};

        // so that nums1 is always longer or equal to nums2
        if (nums2.size() > nums1.size()) {
            auto tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }

        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                
                if (i + j >= nums1.size()) break;
                if (nums1[i+j] == nums2[j]) {
                    tmpRes.push_back(nums1[i+j]);

                } else {
                    if (res.size() < tmpRes.size()) {
                        res = tmpRes;
                    }
                    tmpRes.clear(); // drop the previous sequence
                    break;
                }
            }

            if (res.size() < tmpRes.size()) {
                res = tmpRes;
                tmpRes.clear();
            }

            // we won't be able to find the longer sequence
            if (res.size() == nums2.size()) break;
        }
        return res;
    }

public:
    static vector intersect(vector& nums1, vector& nums2) {

        auto res =  intersect_(nums1, nums2);
        std::reverse(nums2.begin(), nums2.end());
        auto res1 =  intersect_(nums1, nums2);


        return res.size() > res1.size() ? res : res1;
    } 
};

int main(int, char*[]) {

    auto vec1 = vector{1, 2, 2, 1};
    auto vec2 = vector{2, 2};
    auto vecRes = vector{2, 2};

    assert(Solution::intersect(vec1, vec2) == vecRes);

    vec1 = vector{4, 9, 5};
    vec2 = vector{9, 4, 9, 8, 4};
    vecRes = vector{4, 9};

    assert(Solution::intersect(vec1, vec2) == vecRes);

    vec1 = vector{1, 2};
    vec2 = vector{2, 1};
    vecRes = vector{1, 2};

    assert(Solution::intersect(vec1, vec2) == vecRes);

    return 0;
}

