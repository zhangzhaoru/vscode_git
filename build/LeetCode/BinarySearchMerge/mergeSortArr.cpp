//归并有序数组
#include <iostream>
#include <vector>
using namespace std;

void mergeSortTwoVec(vector<int> &vec1, vector<int> &vec2, vector<int> &vec) {
    int i = 0;
    int j  =0;
    while(i<vec1.size() && j<vec2.size()){
        if(vec1[i]<=vec2[j]){
            vec.push_back(vec1[i]);
            i++;
        }else{
            vec.push_back(vec2[j]);
            j++;
        }
    }
    for(;i<vec1.size();i++){
        vec.push_back(vec1[i]);
    }
    for(;j<vec2.size();j++){
        vec.push_back(vec2[j]);
    }
}

void mergeSort(vector<int> &vec) {
    if(vec.size()<2){
        return;
    }
    int mid = vec.size()/2;
    vector<int> vec1;
    vector<int> vec2;
    for(int i = 0;i<mid;i++){
        vec1.push_back(vec[i]);
    }
    for(int i = mid;i<vec.size();i++){
        vec2.push_back(vec[i]);
    }
    mergeSort(vec1);
    mergeSort(vec2);
    vec.clear();
    mergeSortTwoVec(vec1,vec2,vec);
}

int main() {
    vector<int> vec = {2, 1, 4, 3, 6, 5, 8, 7, 10, 9};
    mergeSort(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}