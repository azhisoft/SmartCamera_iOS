//
//  CameraProvier.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/19.
//  Copyright © 2018年 阿智. All rights reserved.
//
#import "Camera.h"
#import "CameraDiscoveryConsumer.h"

#ifndef CameraProvier_h
#define CameraProvier_h


@protocol CameraProvider <NSObject>

@required

- (NSString *)getName;
- (NSString *)getDesc;

- (void)discover:(id<CameraDiscoveryConsumer>)consumer timeout:(int16_t)timeout;

- (id<Camera>)connect:(NSString *)url;

@end

#endif /* CameraProvier_h */
