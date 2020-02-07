//射击气球
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}
int findMinArrowsShots(vector<pair<int, int>> &points) {
    if (points.size() < 1) return 0;
    sort(points.begin(), points.end(), cmp);
    int shootBegin = points[0].first;
    int shootEnd = points[0].second;
    int shootNum = 1;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].first < shootEnd) {
            shootBegin = points[i].first;
            if (shootEnd > points[i].second) {
                shootEnd = points[i].second;
            }
        } else {
            shootBegin = points[i].first;
            shootEnd = points[i].second;
            shootNum++;
        }
    }
    return shootNum;
}

int main() {
    vector<pair<int, int>> points;
    points.push_back(pair<int, int>(1, 6));
    points.push_back(pair<int, int>(2, 8));
    points.push_back(pair<int, int>(7, 12));
    points.push_back(pair<int, int>(10, 16));
    int res = findMinArrowsShots(points);
    cout << res << endl;
    system("pause");
    return 0;
}