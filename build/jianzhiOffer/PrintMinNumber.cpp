//�������ų���С����
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//����sort��Ҫ����ͷ�ļ�<algorithm>

using namespace std;
static bool compare(int nums1, int nums2);
string PrintMinNumber(vector<int> numbers);

string PrintMinNumber(vector<int> numbers)
{
    if (!numbers.size())
        return "";
    sort(numbers.begin(), numbers.end(), compare);
    string res;
    for (int i = 0; i < numbers.size(); i++)
    {
        res += to_string(numbers[i]);
    }
    return res;
}

static bool compare(int nums1, int nums2)
{
    string str1 = to_string(nums1) + to_string(nums2);
    string str2 = to_string(nums1) + to_string(nums1);
    return str1 < str2;
} //sort�������������

int main()
{
    vector<int> numbers = {3, 32, 321};
    string res;
    res = PrintMinNumber(numbers);
    cout << "The min number is : " << res << endl;
    system("pause");
    return 0;
}