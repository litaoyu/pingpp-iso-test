//
//  Pingpp+Cnp.h
//  Pingpp
//
//  Created by Afon on 15/9/23.
//  Copyright © 2015年 pingplusplus. All rights reserved.
//

#import "Pingpp.h"
#import "PingppURLResponse.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^PingppResultCompletion)(NSString *result, PingppURLResponse * __nullable response, NSError * __nullable error);

typedef NS_ENUM(NSUInteger, PingppCardOperationOption) {
    PingppCardOperationAdd,
    PingppCardOperationRemove,
    PingppCardOperationSetDefault
};

typedef NS_ENUM(NSUInteger, PingppCardOperationResultOption) {
    PingppCardOperationResultSucceeded,
    PingppCardOperationResultFailed,
    PingppCardOperationResultCancelled
};

typedef NS_ENUM(NSUInteger, PingppCardNetworkOption) {
    PingppCardNetworkUnionPay = 1,
    PingppCardNetworkInternational = 1<<1,
};

@protocol PingppCardManagerDelegate <NSObject>

- (void)manageWithData:(NSDictionary *)data option:(PingppCardOperationOption)operationOption;

@end

@interface Pingpp (Cnp)

/**
 *  调用支付接口
 *  @param  orderNo   商户订单号
 *  @param  amount    订单金额
 *  @param  params    自定义附加字段，会放在 custom_params 字段，POST 到 chargeURL
 */
+ (void)payInAppWithOrderNo:(NSString *)orderNo
                     amount:(NSUInteger)amount
                     params:(nullable NSDictionary *)params
                  chargeURL:(NSString *)url
             viewController:(UIViewController *)viewController
          completionHandler:(PingppResultCompletion)handler;

/**
 *  设置 Publishable Key
 *  @param  publishableKey  请登录 https://dashboard.pingxx.com，到「基本信息」查看
 */
+ (void)setPublishableKey:(NSString *)publishableKey;

+ (NSString *)publishableKey;

/**
 *  设置 Customer
 *  @param  customer  Customer JSON 字符串或 NSDictionary
 *  @param  error     JSON 解析失败时的错误信息
 */
+ (BOOL)setCustomer:(id)customer error:(NSError **)error;

+ (nullable NSDictionary *)customer;

/**
 * 设置 支持的银行卡类型
 * @param type 可设置为  PingppCardNetworkUnionPay(内卡)
 *                      PingppCardNetworkInternational(外卡)
 */
+ (void)setPingppCardNetworkOption:(PingppCardNetworkOption)option;
+ (PingppCardNetworkOption)pingppCardNetworkOption;

/**
 *  打开卡片管理中心
 *  必须先调用过 + (void)setCustomer:error:
 */
+ (void)openCardManager:(UIViewController *)viewController;


/**
 * 设置卡片管理的代理
 */
+(void)setCardManagerDelegate:(id)delegate;

/**
 *  卡片管理回调
 *  @param  operation   操作类型：绑卡、解除绑卡
 *  @param  data        会包含操作所需的参数，比如 token_id，card_id，customer_id
 */
+ (void)setOperationBlock:(nullable void (^)(PingppCardOperationOption operation, NSDictionary *data))block;

/**
 *  卡片管理结果处理
 *  @param  result   操作结果
 *  @param  Customer 服务端 SDK 处理得到的结果
 */
+ (void)continueOperation:(PingppCardOperationResultOption)result operationOption:(PingppCardOperationOption) operationOption withCustomer:(nullable id)Customer;

@end
NS_ASSUME_NONNULL_END
