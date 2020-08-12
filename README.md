# ncmdump-GUI v1.1

跨平台的ncmdump图形界面，**实验性项目**。
 
本项目使用 [anonymous5l/ncmdump](https://github.com/anonymous5l/ncmdump) 作为后端，稍作改动以适应GUI的情形。

# 升级日志

 - 增加一列显示文件名
 - 添加好看的icon

## 使用方法

使用`Add`按钮添加文件，也可以直接将文件拖放到窗口上。不是`ncm`格式的文件将被忽略。

点击下方的`Convert`按钮开始转换。转换完成的项目将会被标记成**绿色**，转换失败的项目会被标记为**红色**。进度条和状态栏都将显示转换进度。


## 编译依赖

 1. wxWidgets - GUI库
 2. taglib - ncmdump的依赖
