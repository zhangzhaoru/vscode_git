#标题的写法

* 第一种
#一级标题
##二级标题
###三级标题

* 第二种

一级标题
====
二级标题
===
三级标题
---

# 列表
* 1
* 2
* 3
- 1
- 2
- 3
+ 1
+ 2
+ 3
###有序列表
1. 111
2. 222
3. 333


#区块引用
* 标题
>>>>>>>>> 引用
11111111111

> 一级引用
>> 二级引用
>>> 三级引用

* 其他用法
## 标题
>> * 小标题

> "引用"

>>>* 小标题
>其他引用

#字体斜体与加粗
*字体倾斜*
_安徽省都安排将_
**字体加粗**
__字体加粗__

#分割线与中划线
* 分割线由_组成，至少三个，不需连续
***
___
##中划线
~~中划线~~

#特殊符号转义
* \\
* \+
* \-
* \~
* \*

#代码框
* 第一种使用显示使用 \`
`void printVec(vector<int> data)`
* 第二种使用``````
```
void printVec(vector<int> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i];
    }
    cout << endl;
}
```

#表格
Name | Academy | score
- | :-: | -:
Harry Potter | Gryffindor| 90
Hermione Granger | Gryffindor | 100
Draco Malfoy | Slytherin | 90

#链接与图片
* 无参数
点击[百度链接](www.baidu.com)

#颜色
$\color{red}{talk}$ is cheap, $\color{rgba(0,255,0,.8)}{show}$me the $\color{#ff0000}{code}$