### 2.2.0
* 新增：  
添加应用内快捷支付（cnp）  
添加壹收款模块

### 2.1.4
* 更改：  
修复编译 warning 问题  
修改 podspec 默认不包含 bfb

### 2.1.3
* 更改：  
更新银联 SDK 到 3.1.1 版本  
修复 CocoaPods 导入问题  
更新支付宝 SDK  
Ping++ 静态库文件支持 Bitcode

### 2.1.2
* 更改：  
更新银联 SDK 到 3.1.0 版本

### 2.1.1
* 更改：  
修正 charge 格式不正确时的回调

### 2.1.0
* 新增：  
添加 Debug 模式，可打印出 log，方便调试。开启方法：`[Pingpp setDebugMode:YES];`
* 更改：  
charge 可以用 NSDictionary 格式传入  
更新支付宝、微信（不支持 armv7s）和百度钱包 SDK  
不包含微信静态库文件也可以调用支付

### 2.0.6
* 更改：  
添加 handleOpenURL 返回值

### 2.0.5
* 更改：  
分离各渠道静态库

### 2.0.4 (20150428)
* 更改：  
分离 Apple Pay 静态库  
更新 AlipaySDK.framework

### 2.0.4
* 新增：  
支持 Apple Pay

### 2.0.3
* 更改：  
支持 iOS 5.1.1

### 2.0.2
* 更改：  
新的测试模式  
百度钱包 SDK 静态库文件更新

### 2.0.1(20150112)
* 更改：  
更换银联静态库文件

### 2.0.1
* 更改：  
方法 `+handleOpenURL:withCompletion:` 中 `completion` 可以传 `nil`

### 2.0.0
* 更改：  
支持 arm64  
添加新渠道：百付宝  
调用方法更改  
callback 添加返回错误信息

### 1.0.5
* 更改：  
更换了测试环境 URL