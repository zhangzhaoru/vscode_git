/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-21 18:01:32
 * @LastTime: 2020-03-21 18:41:10
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\PrimePalindrome.cpp
 * @Description: »ØÎÄËØÊý
 */

#include <iostream>
using namespace std;

int isPalindrome(int n) {
    int x = 0;
    int s = n;
    while (s > 0) {
        x = x * 10 + s % 10;
        s = s / 10;
    }
    if (x == n) {
        return 1;
    } else {
        return 0;
    }
}

int isPrime(int n) {
    int x = n;
    int i;
    for (i = 2; i <= n - 1; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = n; i <= m; i++) {
        if (isPalindrome(i) && isPrime(i)) {
            cout << i << " ";
            ans++;
            if (ans % 10 == 0) cout << endl;
        }
    }
    return 0;
}
