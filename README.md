# ncmdump-GUI v1.2

跨平台的ncmdump图形界面，**实验性项目**。
 
本项目使用 [anonymous5l/ncmdump](https://github.com/anonymous5l/ncmdump) 作为后端，稍作改动以适应GUI的情形。

# 升级日志

 - 新功能：转换后删除源文件
 - 添加删除同名音质较差文件的小工具
 - 针对底层ncmdump做了一些调整，提升稳定性，解决了一些内存泄露

## 使用方法

使用`Add`按钮添加文件，也可以直接将文件拖放到窗口上。不是`ncm`格式的文件将被忽略。

点击下方的`Convert`按钮开始转换。转换完成的项目将会被标记成**绿色**，转换失败的项目会被标记为**红色**。进度条和状态栏都将显示转换进度。

可以在`Option`中设置是否删除原文件和是否修复元数据


## 编译依赖

 1. wxWidgets - GUI库
 2. taglib - ncmdump的依赖
