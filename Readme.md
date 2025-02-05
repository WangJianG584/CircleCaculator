
# CircleCaculator（圆形计算者)
---
# 编译和执行
### Linux食用指南 
为取得最佳效果，你需要一路CD到存放本源码的文件夹，然后执行以下命令
>gcc main.cpp -o CircleCaculator -Ofast
然后用./CircleCaculator打开程序
### Windows 用户必看
使用Microsoft Visual Studio调试本程序

你可能会遇到编译完此程序后部分单位显示错误，比如![显示有误](img/1.png)  
>解决方案下面一行点右键→属性→平台工具集选择clang  
在第12行添加
>>system("chcp 65001");


