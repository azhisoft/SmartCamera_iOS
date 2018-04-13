//
//  NetworkConfig.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/19.
//  Copyright © 2018年 阿智. All rights reserved.
//

#ifndef NetworkConfig_h
#define NetworkConfig_h


@interface NetworkConfig : NSObject

@property (nonatomic) NSString  *macAddr;
@property (nonatomic) BOOL      dhcp;
@property (nonatomic) NSString  *ip;
@property (nonatomic) NSString  *mask;
@property (nonatomic) NSString  *gateway;
@property (nonatomic) NSString  *dns1;
@property (nonatomic) NSString  *dns2;

@end

#endif /* NetworkConfig_h */
