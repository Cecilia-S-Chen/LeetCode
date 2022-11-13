#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_map;
        int begin_ptr = 0, end_ptr = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (char_map.find(s[i]) != char_map.end())  {
                max_len = (end_ptr - begin_ptr) > max_len ? (end_ptr - begin_ptr) : max_len;
                while (begin_ptr < char_map[s[i]] + 1) {
                    auto iter = char_map.find(s[begin_ptr]);
                    char_map.erase(iter);
                    begin_ptr++;
                }
            }
            char_map[s[i]] = i;
            end_ptr++;
        }
        max_len = (end_ptr - begin_ptr) > max_len ? (end_ptr - begin_ptr) : max_len;
        return max_len;
    }
};

int main()
{
    Solution s;
    int rst = s.lengthOfLongestSubstring("abba");
    cout << rst << endl;
}

