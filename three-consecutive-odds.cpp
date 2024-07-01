#include <vector>
#include <cassert>


typedef std::vector<int> vector;


class Solution {
public:
    
    static bool threeConsecutiveOdds(vector& arr) {

        if (arr.size() < 3) return false;
        
        for (int i = 0; i < arr.size() - 2; ++i) {
            if (arr[i] % 2 == 1 && arr[i+1] % 2 == 1 && arr[i+2] % 2 == 1) {
                return true;
            }
        }

        return false;
    }
};


int main(int, char* []) {
    auto v = vector{2,6,4,1};
    assert(!Solution::threeConsecutiveOdds(v));

    v = vector{1,2,34,3,4,5,7,23,12};
    assert(Solution::threeConsecutiveOdds(v));

    return 0;
}
