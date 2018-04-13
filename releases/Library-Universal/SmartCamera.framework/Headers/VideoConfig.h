//
//  VideoConfig.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/19.
//  Copyright © 2018年 阿智. All rights reserved.
//

#ifndef VideoConfig_h
#define VideoConfig_h


typedef NS_ENUM(NSInteger, VideoCodec) {
    VCODEC_UNDEFINED = 0,
    VCODEC_H264 = 264,
    VCODEC_H265 = 265
};

typedef NS_ENUM(NSInteger, VideoReso) {
    RESO_UNDEFINED = 0,
    RESO_720P = 720,
    RESO_1080P = 1080
};

typedef NS_ENUM(NSInteger, VideoBrCtrl) {
    CTRL_UNDEFINED = 0,
    CTRL_CBR = 1,
    CTRL_VBR = 2,
    CTRL_CVBR = 3
};


@interface VideoConfig : NSObject

@property (nonatomic) BOOL          enabled;
@property (nonatomic) VideoCodec    codec;
@property (nonatomic) VideoReso     reso;
@property (nonatomic) VideoBrCtrl   brctrl;
@property (nonatomic) int16_t       bitrate;
@property (nonatomic) int16_t       framerate;

@end

#endif /* VideoConfig_h */
