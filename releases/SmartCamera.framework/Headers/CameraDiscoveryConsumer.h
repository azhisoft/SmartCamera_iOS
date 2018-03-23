//
//  CameraDiscoveryConsumer.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/19.
//  Copyright © 2018年 阿智. All rights reserved.
//
#import "CameraProviderSource.h"
#import "CameraSource.h"

#ifndef CameraDiscoveryConsumer_h
#define CameraDiscoveryConsumer_h


@protocol CameraDiscoveryConsumer <NSObject>

@required

- (void)cameraDiscoverAbort:(CameraProviderSource *)source;
- (void)cameraDiscoverTimeout:(CameraProviderSource *)source;
- (void)cameraDiscovered:(CameraSource *)source;

@end

#endif /* CameraDiscoveryConsumer_h */
