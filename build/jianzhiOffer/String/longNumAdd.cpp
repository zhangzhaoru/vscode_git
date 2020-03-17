/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 21:24:37
 * @LastTime: 2020-03-17 21:32:33
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\longNumAdd.cpp
 * @Description: 长数字加法运算
 */
#include <iostream>
#include <vector>
using namespace std;

class bigint {
   public:
    bigint();
    ~bigint() {}

    vector<char> add(char *, char *);
    vector<char> add(vector<char>, vector<char>);

   protected:
   private:
};

bigint::bigint() {}

vector<char> bigint::add(char *ch1, char *ch2) {
    vector<char> vchR, vch1, vch2;
    int isAddOne = 0;

    while (*ch1 || *ch2) {
        if (*ch1 && *ch2) {
            vch1.push_back(*ch1);
            vch2.push_back(*ch2);
            *(ch1++);
            *(ch2++);
        } else if (*ch1 && !*ch2) {
            vch1.push_back(*ch1);
            *(ch1++);
        } else if (!*ch1 && *ch2) {
            vch1.push_back(*ch2);
            *(ch2++);
        }
    }

    vchR = add(vch1, vch2);

    return vchR;
}

vector<char> bigint::add(vector<char> vch1, vector<char> vch2) {
    vector<char> vchR;
    int isAddOne = 0;
    while (vch1.size() || vch2.size()) {
        char chRe;

        if (vch1.size() && vch2.size()) {
            int iNum1 = vch1.back();
            int iNum2 = vch2.back();
            chRe = iNum1 + iNum2 - 96;
            vch1.pop_back();
            vch2.pop_back();
        } else if (vch1.size() && !vch2.size()) {
            int iNum1 = vch1.back();
            chRe = iNum1 - 48;
            vch1.pop_back();
        } else if (!vch1.size() && vch2.size()) {
            int iNum2 = vch2.back();
            chRe = iNum2 - 48;
            vch2.pop_back();
        } else {
            printf("");
        }
        int temp = chRe;  //存放来判断是否进位
        chRe = chRe % 10 + isAddOne;
        isAddOne = temp / 10;

        vchR.push_back(chRe);
    }
    return vchR;
}

int main() {
    bigint b;
    vector<char> vch = b.add("100000000", "1");
    while (vch.size()) {
        printf("%d", vch.back());
        vch.pop_back();
    }
    printf("\n");

    return 0;
}