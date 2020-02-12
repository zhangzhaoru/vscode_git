#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#define maxN 1000
using namespace std;

void inputCol(vector<vector<int>> &data,int col) {
    for (int k = 0; k < col; k++) {
        int a[maxN];
        char c;
        int i = 0;
        string str = "";
        while ((c = getchar()) != '\n') {
            if (c >= '0' && c <= '9') {
                str += c;
            } else if (c == ' ') {
                a[i++] = atoi(str.c_str());
                str = "";
            }
        }
        vector<int> temp;
        for (int j = 0; j < i; j++) {
            temp.push_back(a[j]);
        }
        data.push_back(temp);
    }
}

int main() {
    vector<vector<int>> data;
    int col = 3;
    inputCol(data,col);
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}