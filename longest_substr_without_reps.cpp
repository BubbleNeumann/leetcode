#include <cstddef>
#include <string>
#include <cassert>

typedef std::string string;


class Solution {
public:
    static int lengthOfLongestSubstring(string s) {

        string buf = "";
        size_t max_len = 0, i = 0, buf_starting_ind = 0, ind_in_buf;

        while (i < s.length()) {
            ind_in_buf = buf.find(s[i]);

            // substring doesn't contain the current char, so add it
            if (ind_in_buf == string::npos) {

                buf += s[i++];

            } else {

                // find prev occurence of the cur char in buf
                int ind_in_s = buf_starting_ind + ind_in_buf;

                // move the buf forward
                buf_starting_ind = ind_in_s + 1;
                buf = s.substr(buf_starting_ind, i - buf_starting_ind + 1);
                ++i;
            }

            max_len = buf.size() > max_len ? buf.size() : max_len;
        }
        return max_len;
    }
};

int main(int, char* []) {

    assert(Solution::lengthOfLongestSubstring("abcabcbb") == 3);
    assert(Solution::lengthOfLongestSubstring("bbbbb") == 1);
    assert(Solution::lengthOfLongestSubstring("pwwkew") == 3);
    assert(Solution::lengthOfLongestSubstring("aab") == 2);
    return 0;
}

