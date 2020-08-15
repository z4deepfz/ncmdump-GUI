# ncmdump-GUI v1.3

跨平台的ncmdump图形界面，**实验性项目**。
 
本项目使用 [anonymous5l/ncmdump](https://github.com/anonymous5l/ncmdump) 作为后端，稍作改动以适应GUI的情形。

## 升级日志

 - 启用了多线程优化，现在解密ncm文件的时候GUI将保持响应(不支持Windows XP及以下)

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