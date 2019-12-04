//
//  BleLockLib.h
//  BleLockLib
//
//  Created by frey on 2019/12/4.
//  Copyright © 2019 frey. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


//服务和特征标识UUID
static NSString * const KBaseUUID = @"FFE0";  //基础服务通知
static NSString * const kHeartServerUUID = @"FFE1"; //心跳通知UUID 待定
static NSString * const kNotifyServerUUID = @"FFE2"; //特征通知UUID 待定

typedef NS_ENUM(NSInteger, OperationType) {
    /**
     *  蓝牙绑定
     */
    DEVICE_BIND = 1,
    /**
     *  蓝牙解绑
     */
    DEVICE_UNBIND,
    /**
     *  蓝牙开锁
     */
    BLE_UNLOCK,
    /**
     *  新增常规密码
     */
    ADD_NORMAL_PASSWORD,
    /**
    *  新增计次密码
    */
    ADD_METER_PASSWORD,
    /**
    *  新增固定计时密码
    */
    ADD_FIXED_PASSWORD,
    /**
    *  新增周期计时密码
    */
    ADD_CYCLE_PASSWORD,
    /**
    *  删除密码
    */
    DELETE_PASSWORD,
    /**
    *  新增固定蓝牙授权
    */
    ADD_BLE_FIXED_AUTH,
    /**
    *  新增周期蓝牙授权
    */
    ADD_BLE_CYCLE_AUTH,
    /**
    *  删除蓝牙授权
    */
    DELETE_AUTH,
    /**
    *  新增NFC固定授权
    */
    ADD_NFC_FIXED_AUTH,
    /**
    *  新增NFC周期授权
    */
    ADD_NFC_CYCLE_AUTH,
    /**
    *  删除NFC授权
    */
    DELETE_NFC,
    
};


typedef NS_ENUM(NSInteger, BleLinkType){//蓝牙连接状态
    BlEMANAGER_STARTLINK =1,//开始
    BLEMANAGER_LINKING,//连接中
    BLEMANAGER_LINKED ,//链接成功
    BLEMANAGER_UNLINKED//断开
};


typedef NS_ENUM(NSInteger, CharaReceiveType) {//特征接受状态
    CHARA_UNRECEIVE=1,//未接收
    CHARA_START_RECEIVE,//开始接收
    CHARA_ALREADY_RECEIVE//接收成功
};

//失败类型
typedef NS_ENUM(NSInteger,ErrorType) {
    BLE_LIMITS = 0x700, //蓝牙权限关闭 (手机未打开蓝牙开关 或 手机蓝牙功能异常)
    COMMAND_NO_BREAK,//命令不能中断 (一次命令未结束之前,无法再次发起其他蓝牙操作.操作互斥)
    BLE_OFFLINE, //蓝牙断开 (手机主动断开连接 或 设备主动断开连接)
    NO_BLE_AROUND,//周围无蓝牙 (SDK未扫描到周围安谷设备)
    BLE_LINK_OUT_TIME,//蓝牙连接超时 (扫描到安谷设备,但是在5秒之内无法成功连接设备)
    BLE_NOT_SERVER,//蓝牙无服务 (成功连接设备后.根据服务UUID,未找到蓝牙相关服务)
    BLE_RECEIVE_OUT_TIME,//蓝牙接受特征值超时 (收到设备相关服务之后,未接收到服务的任何特征数据)
    BLE_BACK_DATA_ERROR,//蓝牙返回数据有误 (收到服务特征数据之后,发现蓝牙返回的数据不符合文档格式)
    BLE_NOT_INNET,//蓝牙不在网 (收到正确之后蓝牙数据之后.检测出设备没有和蓝牙网管链接.设备断网)
    DEVICE_OPERATION_FAIL//设备操作失败 (设备接收蓝牙命令后.没有操作成功)
};


typedef void (^BleSucBlock) (OperationType operaType); //成功回调(参数:操作类型)
typedef void (^BleErrorBlock) (NSString * errMsg,ErrorType errType); //失败回调(参数1:错误信息,参数2:错误类型)

@interface BleLockLib : NSObject
 
/**
 * 获取单例
 * @return 单例
 */
+ (instancetype)getInstance;

-(instancetype)init NS_UNAVAILABLE;//SDK主类初始化不允许调用此方法.请使用单例调用

#pragma mark - 操作方法

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

@end

NS_ASSUME_NONNULL_END
