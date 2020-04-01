/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-01 20:25:13
 * @LastTime: 2020-04-01 20:49:04
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\maxcontinue.cpp
 * @Description:leetcode 695 ����������
 */
#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y) {
    int sum = 1;
    int row = grid.size();
    int col = grid[0].size();

    //�����˸õ�Ϳ��Խ�grid��Ϊ0����ֹ�ظ�
    grid[x][y] = 0;
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < 4; ++i) {
        //�ֱ����ĸ������ƶ�
        int x1 = x + direction[i][0];
        int y1 = y + direction[i][1];
        //�µĵ㲻Խ�粢��������
        if (x1 >= 0 && x1 < row && y1 >= 0 && y1 < col && grid[x1][y1] == 1)
            sum += dfs(grid, x1, y1);
    }
    return sum;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int sum = 0;
    int row = grid.size();
    int col = grid[0].size();
    //������ά���飬�����������صĵ㿪ʼdfs����dfs�б������ĵ㣬�ڴ˲����ٴα����ˣ���Ϊgrid��dfs����Ϊ0��
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (grid[i][j] == 1) sum = max(sum, dfs(grid, i, j));
    return sum;
}

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> data;
    int num;
    for(int i  =0;i<m;i++){
        vector<int> temp;
        for(int j = 0;j<n;j++){
            cin>>num;
            temp.push_back(num);
        }
        data.push_back(temp);
    }
    int res = maxAreaOfIsland(data);
    cout<<res<< endl;
    return 0;
}