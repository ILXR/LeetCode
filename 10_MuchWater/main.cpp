#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int curMax = 0, len = height.size(), maxH = 0;
    for (size_t i = 0; i < len; i++)
    {
        maxH = max(maxH, height[i]);
    }

    for (size_t i = 0, j = len - 1; j > i;)
    {
        if (maxH * (j - i) < curMax)
        {
            break;
        }
        int temp = min(height[i], height[j]) * (j - i);
        curMax = max(curMax, temp);
        if (height[i] == height[j])
        {
            i++;
            j--;
        }
        else if (height[i] > height[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return curMax;
}

int main()
{
    vector<int> height{2, 3, 4, 5, 18, 17, 6};
    cout << maxArea(height) << endl;
}