<!--
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-07 16:40:54
 * @LastTime: 2020-03-22 10:03:27
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \undefinedd:\vscodegit\vscode_git\Series.md
 * @Description: 
 -->
# C 
1. CountString 统计str指向字符串中字母的个数
2. my_strcpy 实现字符串的赋值，最后需添加'\0'
3. NumberExtract 将字符串数字转化为整形数字
4. string C语言中关于字符输入函数的用途
5. stringDeclarationandInitialization
对于字符串数组的不同声明方式sizeof得到的结果不同
6. stringEOF string中终止符的使用方式
7. stringPrint 字符串的输入方式

# C Program
1. char2String 实现整形字符串与字符串数组之间相互转化

## Anagram
1. anagramChar 字符串全排列 
tolower 将大写字母转化为小写字母
next_permutation(s, s + len, cmp) 全排列函数
2. amagramNum 数组全排列

## class
1. Const const 成员只能调用const函数 ，普通成员变量可以调用非const对象也可以调用const函数
2. mapExapmple 对于字符串定义map并定义对应标号
3. myString实现string构造过程
4. OperatorVecIn 重载vector输入与输出，按行输出矩阵
5. smartPrintf 实现printf工作原理


## Sort
1. bubble 冒泡排序法 
istream& operator >> 重载>> 使得直接输入vector
2. quickSort 快排
3. smartSort C语言是实现不同类型排序过程
应用回调函数实现 


# jianzhiOffer
1. FindFirstCommonNode 发现链表首个公共节点将节点依次输入栈中，从后向前依次遍历
2. FindContinuousSequence 输出所有和为S的连续整数序列 设置双指针，当前和小于目标大指针右移，否则小指针右移
3. twosum 设置头尾双指针，和大右指针左移否则做指针右移
4. FindNumbersWithSum 找到两数之和等于目标数，同时和最小
双指针法 同twosum
5. FindNumsAppearOnce 发现只出现依次的数字
建立map计数器 numCount[*iter++]++
6.  FirstNotRepeatintChar发现字符串中的首个只出现一次的字符
设置256字符hash表
7.  GetMeddian动态维护数据流的中位数
设置一个大顶堆与一个小顶堆，动态进行维护，使得两个堆之间的个数不超过1
8. GetNumberOfK统计数据中目标数出现的次数
二分法获得目标数出现的左端点与右端点
9. 输出下标最小的丑数
丑数 因子只包含2,3,5
设置数组记录下标为index的最小丑数，而该抽出必然是上一个丑数乘以2,3,5得到
10. hasPath 判断矩阵中是否存在一条包含字符串的路径
 设置flags记录该位置是否以及使用过，
condition = (condition || isPath(matrix, flags, str, i, j, rows, cols));短路运算类似与累加器
以各个位置为起点判断，
11. InversePairs判断数组中逆序数的个数 归并左中第i个数小于右区间j则i之后均小于j 先归并排序逆序数依次添加至数组，详reverseNumber
12. LeftRotateString左旋字符串 方法1substr抓取前n个及后面的字符串，重新组合
方法2：前n个翻转，后面翻转，整体翻转
13. maxInWindows找出窗口中数值的最大值 
14. PrintMinNumber将数组排列成最小的数 两两组合进行排列
15. ReverseSentence 引入两个指针分别记录单词的头尾，翻转单词
16. FindFirstCommonNode 找到
17. 2DArrSearch寻找目标数是否在二维数组中出现
19. replaceSpace将字符串中空格替换为“%20”
20. printListFromTailToHead将链表逆序转换为vector输出
21. reConstructBinaryTree根据前序与中序序列建立树
前序序列的第一个值是root，遍历vin将数组划分成左右子序列
建立输的输出方式
22. Stack2Queue 使用两个栈实现队列
23. minNumberInRotateArray寻找旋转数组的最小元素 二分查找
24. Fibonacci递归实现Fibonacci数列
25. artiSequence递归实现等差数列与等比数列之和
26. jumpFloor递归实现跳台阶
27. jumpFloor2递归实现跳台阶(单次跳阶数不限)
28. rectCover递归实现2$*$1矩形覆盖2$*$n矩形
29. NumberOf1统计二进制数的1的个数
n = (n - 1) & n;将二进制代码中最第位1变为0
30. Power计算指数函数
31. string2int字符串与整形相互转化
32. longNumAdd 长数据相加
33. reOrderArray奇数偶数重新排序 类似冒泡排序法
34. FindKthToTail发现倒数第k个节点
35. ReverseList头插法翻转链表
36. Merge合并两个有序链表
37. HasSubTree 判断树B是树A的子结构
38. Mirror变换二叉树的镜像dfs
39. printMatrix顺时针打印数组
40. StackMin实现带有min函数的栈
41. isPopOrder判断出栈序列是否合法
42. VerifySquenceOfBST判断序列是否是二叉搜索树的后序遍历序列
最后一个节点为root节点，遍历序列小于root连续节点为左子树，右子树中若有小于root的节点则返回false。递归遍历
43. FindPath 判断二叉树路径之和是否等于目标数，递归
44. RandomLists 复制随机指针链表，在各个节点之后插入复制指针，pClone->random = pNode->random->next  