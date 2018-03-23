//
//  RtmpConfig.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/19.
//  Copyright © 2018年 阿智. All rights reserved.
//

#ifndef RtmpConfig_h
#define RtmpConfig_h


@interface RtmpConfig : NSObject

@property (nonatomic) BOOL      enabled;
@property (nonatomic) NSString  *rtmpUrl;
@property (nonatomic) NSString  *user;
@property (nonatomic) NSString  *password;

@end

#endif /* RtmpConfig_h */
