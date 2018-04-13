//
//  WiFiConfig.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/19.
//  Copyright © 2018年 阿智. All rights reserved.
//

#ifndef WiFiConfig_h
#define WiFiConfig_h


@interface WiFiConfig : NSObject

@property (nonatomic) BOOL      enabled;
@property (nonatomic) NSString  *ssid;
@property (nonatomic) NSString  *password;

@end

#endif /* WiFiConfig_h */
