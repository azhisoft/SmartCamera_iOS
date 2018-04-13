//
//  SmartCamera.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/22.
//  Copyright © 2018年 阿智. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for SmartCamera.
FOUNDATION_EXPORT double SmartCameraVersionNumber;

//! Project version string for SmartCamera.
FOUNDATION_EXPORT const unsigned char SmartCameraVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SmartCamera/PublicHeader.h>
#import "Camera.h"
#import "CameraDiscoveryConsumer.h"


@interface SmartCamera : NSObject

+ (SmartCamera *)getInstance;

- (NSArray *)getSupported;

- (void)discover:(NSArray *)providers consumer:(id<CameraDiscoveryConsumer>)consumer timeout:(int16_t)timeout;

- (id<Camera>)connect:(NSString *)url;

- (void)smartlink:(NSString *)ssid password:(NSString *)password timeout:(int16_t)timeout;

@end
