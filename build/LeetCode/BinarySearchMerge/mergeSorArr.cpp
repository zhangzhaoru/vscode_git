//合并两个有序数组
#include <iostream>
#include <vector>

using namespace std;
void mergeSortVec(vector<int> &vec1, vector<int> &vec2, vector<int> &vec) {
    int i = 0;
    int j = 0;
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) {
            vec.push_back(vec1[i]);
            i++;
        } else {
            vec.push_back(vec2[j]);
            j++;
        }
    }
    for (; i < vec1.size(); i++) {
        vec.push_back(vec1[i]);
    }
    for (; j < vec2.size(); j++) {
        vec.push_back(vec2[j]);
    }
}

int main() {
    vector<int> vec1 = {2, 4, 6, 8, 10};
    vector<int> vec2 = {1, 3, 5, 7, 9};
    vector<int> res;
    mergeSortVec(vec1, vec2, res);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i]<<" ";
    }
    cout << endl;
    return 0;
}
