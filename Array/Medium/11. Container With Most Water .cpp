#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin = 0;
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            int end = height.size() - 1;
            int curArea = min(height[i], height[end]) * (end - i);
            maxArea = curArea > maxArea ? curArea : maxArea;
            if (height[i] < height[begin]) {
                continue;
            }
            for (int j = height.size() - 1; j > i; j--) {
                if (height[j] < height[end]) {
                    continue;
                }
                curArea = min(height[i], height[j]) * (j - i);
                maxArea = curArea > maxArea ? curArea : maxArea;
                end = j;
                if (height[j] >= height[i]) {
                    break;
                }
            }
            begin = i;
        }
        return maxArea;
    }
};

int main()
{
    vector<int> v = {1,8,100,2,100,4,8,3,7};
    Solution s;
    cout << s.maxArea(v) << endl;
}