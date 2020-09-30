# ncmdump-GUI v1.3

跨平台的ncmdump图形界面，**实验性项目**。
 
本项目使用 [anonymous5l/ncmdump](https://github.com/anonymous5l/ncmdump) 作为后端，稍作改动以适应GUI的情形。

## 升级日志

 - 启用了多线程优化，现在解密ncm文件的时候GUI将保持响应(不支持Windows XP及以下)
 - (bug fix)修复了前端无法正确显示包含特殊字符的文件名。std::string对特殊字符的支持似乎有些问题。经实验ncmdump似乎无法正确处理。现前端部分已经修复，添加含有特殊文件名的ncm文件不再显示"Not avalible"，但转换过程中由于ncmdump无法识别会报错，更新的目的主要是便于筛选无法识别的文件。实际上将文件名更改后还是可以正常转换的。如果ncmdump不修复这个问题的话，考虑用一些黑科技解决（未来可期）。

## 使用方法

使用`Add`按钮添加文件，也可以直接将文件拖放到窗口上。不是`ncm`格式的文件将被忽略。

点击下方的`Convert`按钮开始转换。转换完成的项目将会被标记成**绿色**，转换失败的项目会被标记为**红色**。进度条和状态栏都将显示转换进度。

可以在`Option`中设置是否删除原文件和是否修复元数据


## 编译依赖

 1. wxWidgets - GUI库
 2. taglib - ncmdump的依赖

## 注意事项

 1. std::thread在Windows XP及以下无法正常工作，小工具在Windows XP及以下可能导致崩溃
 2. 可以选用O3优化，但慎用flto。链接时优化可能干掉CJson的符号(调试下来应该是CJson_Version)，会导致运行时错误