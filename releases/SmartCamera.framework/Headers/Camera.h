//
//  Camera.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/19.
//  Copyright © 2018年 阿智. All rights reserved.
//
#import "CameraConfiguration.h"
#import "CameraSource.h"

#ifndef Camera_h
#define Camera_h


@protocol Camera <CameraConfiguration>

@required

- (CameraSource *)getSource;

- (BOOL)restore;
- (BOOL)reboot;

- (BOOL)disconnect;

@end

#endif /* Camera_h */
