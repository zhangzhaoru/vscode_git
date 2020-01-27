//判断在一个矩阵中是否存在一条包含某字符串所有字符的路径
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPath(const char *matrix, vector<char> flags,const char *str, int x, int y, int rows, int cols)
{
    if (x < 0 || x >= rows || y < 0 || y >= cols) //越界的点
        return false;

    if (matrix[x * cols + y] == *str && flags[x * cols + y] == 0)
    {
        flags[x * cols + y] = 1;

        if (*(str + 1) == 0) // 字符串结尾了（最后一个满足的）
            return true;

        bool condition = isPath(matrix, flags, (str + 1), x, y - 1, rows, cols) ||
                         isPath(matrix, flags, (str + 1), x - 1, y, rows, cols) ||
                         isPath(matrix, flags, (str + 1), x, y + 1, rows, cols) ||
                         isPath(matrix, flags, (str + 1), x + 1, y, rows, cols);
        if (condition == false)
            flags[x * cols + y] = 0;
        return condition;
    }
    else
        return false;
}

bool hasPath(const char *matrix, int rows, int cols, const char *str)
{

    vector<char> flags(rows * cols, 0);
    bool condition = false;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            condition = (condition || isPath(matrix, flags, str, i, j, rows, cols));
        //短路运算，第一个为true结果则不执行后面条件判断
        }
    return condition;
}

int main(){
    string str = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* matrix = str.c_str();
	string str2 = "SGGFIECVAASABCEEJIGOEM";
    const char* c = str2.c_str();
    if(hasPath(matrix, 5, 8, c))
        cout<<"the str is ture!"<<endl;
    else
        cout<<"the str is false!"<<endl;

    system("pause");
    return 0;
}