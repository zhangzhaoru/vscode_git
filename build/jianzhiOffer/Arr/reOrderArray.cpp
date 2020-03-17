/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 21:38:45
 * @LastTime: 2020-03-17 22:40:38
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\reOrderArray.cpp
 * @Description: 将奇数偶数重新排序
 */
#include <iostream>
#include <vector>
using namespace std;
void Swap(int *&pointer1, int *&pointer2);
void reOrderArray(vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = array.size() - 1; j > i; j--) {
            if (array[j] % 2 == 1 && array[j - 1] % 2 == 0) {
                int *pointer1 = &array[j];
                int *pointer2 = &array[j - 1];
                Swap(pointer1, pointer2);
            }
        }
    }
}

void Swap(int *&pointer1, int *&pointer2) {
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

int main() {
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reOrderArray(array);
    for (int i = 0; i < array.size(); i++) {
        cout << array[i];
    }
    cout << endl;
    return 0;
}