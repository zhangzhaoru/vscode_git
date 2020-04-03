<!--
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-02 19:57:59
 * @LastTime: 2020-04-03 11:47:23
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\linuxCommand.md
 * @Description: linux常见命令
 -->
# Ubantu常用快捷键
## 桌面常用快捷键
Alt + F1：聚焦到桌面左侧任务导航栏，可按上下键进行导航
>Alt + F2：运行命令
Alt + F4：关闭当前窗口
Alt + Tab：切换程序窗口
Alt + 空格：打开窗口菜单
PrtSc：桌面截图
Win + A：搜索/浏览程序
Win + F：搜索/浏览文件
Win + M：搜索/浏览音乐文件
Win：搜索/浏览程序、文件、音乐文件等
## 常见终端快捷键
>Ctrl + Alt + T：打开终端
>Tab：命令或文件名自动补全
>Ctrl + Shift + C：复制
Ctrl + Shift + V：粘贴
Ctrl + Shift + T：在同一个窗口新建终端标签页
Ctrl + Shift + W：关闭标签页
Ctrl + Shift + N：新建终端窗口
Ctrl + Shift + Q：关闭终端窗口
Ctrl + Shift + PageUp：标签页左移
Ctrl + Shift + PageDown：标签页右移
>Ctrl + D：关闭标签页,键盘结束输入，退出终端
>Ctrl + L：清除屏幕
>Ctrl + C：终止当前任务
Ctrl + P：显示上一条历史命令
Ctrl + N：显示下一条历史命令
Ctrl + R：反向搜索历史命令
Ctrl + J/M：回车（同enter键功能）
>Ctrl + A：光标移动到行首
>Ctrl + E：光标移动到行尾
>Ctrl+k: 删除从光标位置至行末
Ctrl + B：关闭想后移动一个位置（backward）
>Ctrl + Z：把当前任务放到后台运行,恢复至前台命令为fg
Ctrl + PageUp：前一个终端标签页
Ctrl + PageDown：下一个终端标签页
F1：打开帮助指南
F11：全屏切换
Alt + F：打开“文件”菜单（file）
Alt + E：打开“编辑”菜单（edit）
Alt + V：打开“查看“菜单（view）
Alt + S：打开“搜索”菜单（search）
Alt + T：打开“终端”菜单（terminal）
Alt + H：打开“帮助”菜单（help）
Ctrl + →：光标移动到上一个单词的词首
Ctrl + ←：光标移动到下一个单词的词尾
Ctrl + T：将光标位置的字符和前一个字符进行位置交换
Ctrl + U：剪切从行的开头到光标前一个位置的所有字符
Ctrl + K：剪切从光标位置到行末的所有字符
Ctrl + Y：粘贴Ctrl + U/Ctrl + K剪切的内容
Ctrl + H/*：删除光标位置的前一个字符（backspace键功能）
Ctrl + D：删除光标位置的一个字符（delete键功能）
Ctrl + W：删除光标位置的前一个单词（Alt + Backspace组合键功能）
Ctrl + &：恢复Ctrl + H/D/W删除的内容
Ctrl + Win + ↑：最大化当前窗口
Ctrl + Win + ↓：还原/最小化当前窗口
Ctrl + Win + D：最小化所有窗口
Win + W：展示所有窗口
Win + T：打开回收站

 # 学会使用帮助命令
 
## 简要说明命令的作用
$whatis command
正则匹配：
$whatis -w "loca*"
更加详细的说明文档：
$info command
## 使用man
查询命令command的说明文档

# Shell常用通配符
$*$	匹配 0 或多个字符
$?$	匹配任意一个字符
[list]	匹配 list 中的任意单一字符
[^list]	匹配 除 list 中的任意单一字符以外的字符
[c1-c2]	匹配 c1-c2 中的任意单一字符 如：[0-9][a-z]
{string1,string2,...}	匹配 string1 或 string2 (或更多)其一字符串
{c1..c2}	匹配 c1-c2 中全部字符 如{1..10}
