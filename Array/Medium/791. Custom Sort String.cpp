#include <iostream>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        string ret;
        for (char c : order) {
            int begin = 0;
            while (begin != s.size()) {
                if (s[begin] == c) {
                    ret += s[begin];
                    s.erase(s.begin()+begin);
                } else {
                    begin++;
                }
            }
        }
        ret += s;
        return ret;
    }
};


int main()
{
    string order = "cba";
    string s = "abcd";
    Solution solution;
    cout << solution.customSortString(order, s) << endl;
}
