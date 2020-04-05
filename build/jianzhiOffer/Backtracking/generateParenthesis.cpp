/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-05 20:19:19
 * @LastTime: 2020-04-05 20:55:06
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Backtracking\generateParenthesis.cpp
 * @Description: Éú³ÉÀ¨ºÅ
 */
#include <bits\stdc++.h>
using namespace std;

// ÅÐ¶Ï×Ö·û´®ÊÇ·ñºÏ·¨
bool isValid(string s) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.length(); i++) {
        if(s[i]=='('){
            left++;
        }else{
            right++;
        }
        if(right>left){
            return false;
        }
    }
    if(left!=right){
        return false;
    }else{
        return true;
    }
}

void Backtracking(vector<string> &res, string temp, int len) {
    if (temp.size() == len) {
        if (isValid(temp)) {
            res.push_back(temp);
        }
        return;
    }
    temp.push_back('(');
    Backtracking(res, temp, len);
    temp.pop_back();
    temp.push_back(')');
    Backtracking(res, temp, len);
    temp.pop_back();
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    Backtracking(res, "", 2 * n);
    return res;
}

int main() {
    vector<string> res = generateParenthesis(3);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}