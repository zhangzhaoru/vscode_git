//归并有序数组
#include <iostream>
#include <vector>
using namespace std;

void mergeSortVec(vector<pair<int, int>> &vec1, vector<pair<int, int>> &vec2,
                  vector<pair<int, int>> &vec, vector<int> &count);
void mergeSort(vector<pair<int, int>> &vec, vector<int> &count);
vector<int> reserveNum(vector<int> &nums);

vector<int> reserveNum(vector<int> &nums) {
    vector<pair<int, int>> vec;
    vector<int> count;
    for (int i = 0; i < nums.size(); i++) {
        vec.push_back(make_pair(nums[i], i));
        count.push_back(0);
    }
    mergeSort(vec, count);
    return count;
}

void mergeSort(vector<pair<int, int>> &vec, vector<int> &count) {
    if (vec.size() < 2) {
        return;
    }
    int mid = vec.size() / 2;
    vector<pair<int, int>> vec1;
    vector<pair<int, int>> vec2;
    for (int i = 0; i < mid; i++) {
        vec1.push_back(vec[i]);
    }
    for (int i = mid; i < vec.size(); i++) {
        vec2.push_back(vec[i]);
    }
    mergeSort(vec1, count);
    mergeSort(vec2, count);
    vec.clear();//清空容器但不回收内存
    mergeSortVec(vec1, vec2, vec, count);
}

void mergeSortVec(vector<pair<int, int>> &vec1, vector<pair<int, int>> &vec2,
                  vector<pair<int, int>> &vec, vector<int> &count) {
    int i = 0;
    int j = 0;
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i].first <= vec2[j].first) {
            count[vec1[i].second] += j;
            vec.push_back(vec1[i]);
            i++;
        } else {
            vec.push_back(vec2[j]);
            j++;
        }
    }
    for (; i < vec1.size(); i++) {
        count[vec1[i].second] += j;
        vec.push_back(vec1[i]);
    }
    for (; j < vec2.size(); j++) {
        vec.push_back(vec2[j]);
    }
}

int main() {
    vector<int> nums = {5, -7, 9, 1, 3, 5, -2, 1};
    vector<int> count = reserveNum(nums);
    for (int i = 0; i < count.size(); i++) {
        cout << count[i] << " ";
    }
    cout << endl;
    return 0;
}