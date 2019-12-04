# BleLockLib.framework

安装条件:
1. iOS 9.0 以上系统

支持CPU架构: 
1. armv7 arm64

安装教程: 
1. 调用该framework的app需要在 Build Settings ->Other Linker Flags 设置为-Objc

类初始化:
+ (instancetype)getInstance;

类方法调用:
/// 绑定或者解绑设备
/// @param bleLocalName 设备识别标识符
/// @param type 操作类型
/// @param password 操作附带密码
/// @param suc 成功回调
/// @param error 失败回调
- (void)bindOrUnbindWithBle: (NSString *)bleLocalName andOperation: (OperationType)type andPassword: (NSString *)password andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;


/// 添加常规密码
/// @param bleLocalName 设备识别标识符
/// @param password 常规密码
/// @param suc 成功回调
/// @param error 失败回调
- (void)addNormalPassword: (NSString *)bleLocalName andPassword: (NSString *)password andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;

/// 添加计次密码
/// @param bleLocalName 设备识别标识符
/// @param meter 次数
/// @param suc 成功回调
/// @param error 失败回调
- (void)addMeterPassword: (NSString *)bleLocalName andPassword: (NSString *)password andMeter: (NSInteger)meter andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;

/// 固定计时密码
/// @param bleLocalName 设备识别标识符
/// @param password 计时密码
/// @param startTime 开始时间
/// @param endTime 结束时间
/// @param suc 成功回调
/// @param error 失败回调
- (void)addFixedPassword: (NSString *)bleLocalName andPassword: (NSString *)password andStartTime: (NSInteger)startTime andEndTime:(NSInteger)endTime andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;

/// 添加周期计时密码
/// @param bleLocalName 设备识别标识符
/// @param password 计时密码
/// @param week 周规律
/// @param shour 开始小时
/// @param ehour 结束小时
/// @param smin 开始分钟
/// @param emin 结束分钟
/// @param suc 成功回调
/// @param error 失败回调
- (void)addCyclePassword: (NSString *)bleLocalName andPassword: (NSString *)password andWeek: (NSInteger)week andSHour: (NSInteger)shour andEHour: (NSInteger)ehour andSMin: (NSInteger)smin andEMin: (NSInteger)emin andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;
    

/// 删除密码
/// @param bleLocalName 设备识别标识符
/// @param password 密码
/// @param suc 成功回调
/// @param error 失败回调
- (void)deletePasswrod: (NSString *)bleLocalName andPassword: (NSString *)password andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;


/// 添加蓝牙固定授权
/// @param bleLocalName 设备识别标识符
/// @param password 授权密码
/// @param startTime 开始时间
/// @param endTime 结束时间
/// @param suc 成功回调
/// @param error 失败回调
- (void)addBleFixedAuth: (NSString *)bleLocalName andPassword: (NSString *)password andStartTime: (NSInteger)startTime andEndTime:(NSInteger)endTime andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;


/// 添加蓝牙周期授权
/// @param bleLocalName 设备识别标识符
/// @param password 授权密码
/// @param week 周规律
/// @param shour 开始小时
/// @param ehour 结束小时
/// @param smin 开始分钟
/// @param emin 结束分钟
/// @param suc 成功回调
/// @param error 失败回调
- (void)addBleCycleAuth: (NSString *)bleLocalName andPassword: (NSString *)password andWeek: (NSInteger)week andSHour: (NSInteger)shour andEHour: (NSInteger)ehour andSMin: (NSInteger)smin andEMin: (NSInteger)emin andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;


/// 蓝牙开锁 或 删除蓝牙授权 或 删除NFC授权
/// @param bleLocalName 设备识别标识符
/// @param key 秘钥(4字节)
/// @param type 操作类型
/// @param suc 成功回调
/// @param error 失败回调
- (void)bleUnLockOrDeleteLockOrNFC: (NSString *)bleLocalName andKey: (NSData *)key andOperation: (OperationType)type andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;
    

/// 添加NFC固定授权
/// @param bleLocalName 设备识别标识符
/// @param key 秘钥(4字节)
/// @param startTime 开始时间
/// @param endTime 结束时间
/// @param suc 成功回调
/// @param error 失败回调
- (void)addNFCFixedAuth: (NSString *)bleLocalName andKey: (NSData *)key andStartTime: (NSInteger)startTime andEndTime:(NSInteger)endTime andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;


/// 添加NFC周期授权
/// @param bleLocalName 设备识别标识符
/// @param key 秘钥(4字节)
/// @param week 周规律
/// @param shour 开始小时
/// @param ehour 结束小时
/// @param smin 开始分钟
/// @param emin 结束分钟
/// @param suc 成功回调
/// @param error 失败回调
- (void)addNFCCycleAuth: (NSString *)bleLocalName andKey: (NSData *)key andWeek: (NSInteger)week andSHour: (NSInteger)shour andEHour: (NSInteger)ehour andSMin: (NSInteger)smin andEMin: (NSInteger)emin andSuc: (BleSucBlock)suc andError: (BleErrorBlock)error;
