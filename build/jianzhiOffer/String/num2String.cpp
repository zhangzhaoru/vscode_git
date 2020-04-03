/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-03 15:44:25
 * @LastTime: 2020-04-03 20:02:43
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\num2String.cpp
 * @Description: 数字转化为英文
 */
#include <bits/stdc++.h>
using namespace std;

const string ones[] = {"zero", "one", "two",   "three", "four",
                       "five", "six", "seven", "eight", "nine"};
const string tens[] = {"ten",      "eleven",  "twelve",  "thirteen",
                       "fourteen", "fifteen", "sixteen", "seventeen",
                       "eighteen", "nighteen"};
const string twenties[] = {"zero",  "ten",   "twenty",  "thirty", "forty",
                           "fifty", "sixty", "seventy", "eighty", "ninety"};
const int ihundreds[] = {(int)1e3, (int)1e6, (int)1e9, (int)1e12};
const string hundreds[] = {"thousand", "million", "billion"};


//截取最高位3位数字
long long exactFirst3Num(long long &num) {
    vector<int> temp;
    int i = 0;
    while (num) {
        temp.push_back(num % 10);
        num /= 10;
    }
    reverse(temp.begin(), temp.end());
    //从低位到高位排列
    int len = temp.size() % 3;
    long long res = 0;
    if (len == 0) {
        len = 3;
    }
    for (int i = 0; i < len; i++) {
        res = res * 10 + temp[i];
    }
    num = 0;
    for (int i = len; i <= temp.size() - 1; i++) {
        num = num * 10 + temp[i];
    }
    return res;
}

//处理0~999
string num2String(long long num) {
    if (num >= 0 && num <= 9) {
        return ones[num];
    } else if (num >= 10 && num < 19) {
        return tens[num % 10];
    } else if (num > 20 && num < 100) {
        if (num % 10 == 0) {
            return twenties[num / 10];
        } else {
            return twenties[num / 10] + " " + ones[num % 10];
        }
    } else if (num >= 100 && num <= 999) {
        vector<int> temp;
        while (num != 0) {
            temp.push_back(num % 10);
            num /= 10;
        }
        string res;
        res += ones[temp[2]] + " hundred";
        if (temp[1] == 0 && temp[0] == 0) {
            return res;
        } else {
            string str = " and " + num2String(temp[1] * 10 + temp[0]);
            res += str;
            return res;
        }
    }
    return "";
}

// 按3位进行计数
int numlength(long long num){
    int res = 0;
    while(num!=0){
        num/=1000;
        res++;
    }
    return res;
}

string combination(long long num) {
    string res;
    int length = numlength(num); 
    long long num3 = 0;
    int i;
    for(i =length-2;i>=0;i--){
        num3 = exactFirst3Num(num);
        string str =  num2String(num3)+" "+ hundreds[i]+" ";
        res+=str;
    }
    res+=num2String(num);
    return res;
}

int main() {
    long long num = 1234567890;
    string res = combination(num);
    cout << res << endl;
    return 0;
}