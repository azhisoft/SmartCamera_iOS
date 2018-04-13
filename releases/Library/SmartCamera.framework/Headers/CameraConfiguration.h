//
//  CameraConfiguration.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/19.
//  Copyright © 2018年 阿智. All rights reserved.
//
#import "NetworkConfig.h"
#import "WiFiConfig.h"
#import "AudioConfig.h"
#import "VideoConfig.h"
#import "RtmpConfig.h"
#import "RtspConfig.h"

#ifndef CameraConfiguration_h
#define CameraConfiguration_h


@protocol CameraConfiguration <NSObject>

@required

- (NSString *)getName;
- (BOOL)setName:(NSString *)name;

- (NetworkConfig *)getNetwork;
- (BOOL)setNetwork:(NetworkConfig *)config;

- (WiFiConfig *)getWiFi;
- (BOOL)setWiFi:(WiFiConfig *)config;

- (AudioConfig *)getAudio;
- (BOOL)setAudio:(AudioConfig *)config;

- (VideoConfig *)getVideo;
- (BOOL)setVideo:(VideoConfig *)config;

- (RtmpConfig *)getRtmp;
- (BOOL)setRtmp:(RtmpConfig *)config;

- (RtspConfig *)getRtsp;

@end

#endif /* CameraConfiguration_h */
