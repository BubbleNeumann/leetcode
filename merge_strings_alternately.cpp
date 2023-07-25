#include <string>
#include <cassert>
#include <iostream>

class Solution {
public:
    static std::string mergeAlternately(std::string word1, std::string word2) {
        std::string res;
        short len1 = word1.length(), len2 = word2.length();
        for (int i = 0; i < len1 + len2; ++i) {

            if (i%2){ //word2
                if (len2 > i/2) { //use word2
                    res.push_back(word2[i/2]);
                } else { //append rest of the word1
                    res.append(word1.substr(i/2+1));
                    break;
                }

            } else { //word1
                if (len1 > i/2) {
                    res.push_back(word1[i/2]);
                } else {
                    res.append(word2.substr(i/2));
                    break;
                }

            }
        }
        return res;
    }
};

int main() {

    // test 1
    std::string word1 = "abc", word2 = "prq", ans = "apbrcq";
    std::string res = Solution::mergeAlternately(word1, word2);
    assert(res == ans);
    std::cout << "test 1 passed\n";

    // test 2
    word1 = "ab", word2 = "pqrs", ans = "apbqrs";
    res = Solution::mergeAlternately(word1, word2);
    assert(res == ans);
    std::cout << "test 2 passed\n";

    // test 3
    word1 = "abcd", word2 = "pq", ans = "apbqcd";
    res = Solution::mergeAlternately(word1, word2);
    assert(res == ans);
    std::cout << "test 3 passed\n";

    // test 4
    word1 = "a", word2 = "", ans = "a";
    res = Solution::mergeAlternately(word1, word2);
    assert(res == ans);
    std::cout << "test 4 passed\n";

    // test 5
    word1 = "dfe", word2 = "beebda", ans = "dbfeeebda";
    res = Solution::mergeAlternately(word1, word2);
    assert(res == ans);
    std::cout << "test 5 passed\n";

    return 0;
}
