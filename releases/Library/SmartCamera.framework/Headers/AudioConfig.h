//
//  AudioConfig.h
//  SmartCamera
//
//  Created by 阿智 on 2018/3/19.
//  Copyright © 2018年 阿智. All rights reserved.
//

#ifndef AudioConfig_h
#define AudioConfig_h


typedef NS_ENUM(NSInteger, AudioCodec) {
    ACODEC_UNDEFINED = 0,
    ACODEC_AAC = 1
};

typedef NS_ENUM(NSInteger, AudioSample) {
    SAMPLE_BASE = 8000,
    SAMPLE_TELEPHONE = 11025,
    SAMPLE_BROADCAST = 22050,
    SAMPLE_VCD = 44100,
    SAMPLE_DVD = 64000,
    SAMPLE_HD_DVD = 96000
};


@interface AudioConfig : NSObject

@property (nonatomic) BOOL          enabled;
@property (nonatomic) AudioCodec    codec;
@property (nonatomic) AudioSample   samplerate;
@property (nonatomic) int16_t       bitrate;
@property (nonatomic) int16_t       volume;

@end

#endif /* AudioConfig_h */
