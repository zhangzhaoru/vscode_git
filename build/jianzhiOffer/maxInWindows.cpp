//找出所有滑动窗口里数值的最大值
#include <iostream>
#include <vector>

using namespace std;
int findmax(const vector<int> &num, int index, int size);
vector<int> maxInWindows(const vector<int> &num, unsigned int size);

vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
    vector<int> res;
    for (int i = size - 1; i < num.size(); i++)
    {
        res.push_back(findmax(num, i, size));
    }
    return res;
}

int findmax(const vector<int> &num, int index, int size)
{
    int maxNum = num[index];
    for (int i = index - 1; i >= index - size + 1; i--)
    {
        if (num[i] > maxNum)
        {
            maxNum = num[i];
        }
    }
    return maxNum;
}

int main()
{
    vector<int> num = {2, 3, 4, 2, 6, 2, 5, 1};
    unsigned int size = 3;
    vector<int> res;
    res = maxInWindows(num, size);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    cout << endl;
    system("pause");
    return 0;
}