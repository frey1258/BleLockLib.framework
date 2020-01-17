# BleLockLib.framework

安装条件:
1. iOS 9.0 以上系统

支持CPU架构: 
1. armv7 arm64

安装教程: 
1. 在info.plist文件中添加蓝牙白名单 => Privacy - Bluetooth Always Usage Description
1. 调用该framework的app需要在 Build Settings ->Other Linker Flags 设置为-Objc

方法调用:
详情查看 BleLockLib.h头文件
