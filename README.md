# SmartCamera_iOS
适用于 iOS 平台的智能摄像头 SDK，支持 SmartLink 智能配网、局域网发现，和摄像头的网络配置、音视频参数设置，以及 RTMP 推流设置等。

SmartCamera 旨在提供简单易用的 SDK，兼容包括互联网摄像头、监控摄像头等各种摄像头设备，实现对摄像头管理和配置的智能化和移动化。

## 认识 SmartCamera
- SDK 主体结构：
![Overview](overview.png)
- SmartCamera，SmartCamera 是一个单例实例，是使用 SDK 的总入口
- CameraProvider，CameraProvider 是一个接口，针对不同厂商的摄像头，提供不同的 CameraProvider 实现
- Camera，Camera 同样是一个接口，针对不同厂商提供对应的实现

## 使用 SmartCamera
- 导入 SmartCamera.framework 到工程。
- 范例代码：
```Objective-C
- (void)cameraDiscoverAbort:(CameraProviderSource *)source
{
    NSLog(@"ABORT: %@", source.name);
}

- (void)cameraDiscoverTimeout:(CameraProviderSource *)source
{
    NSLog(@"TIMEOUT: %@", source.name);
}

- (void)cameraDiscovered:(CameraSource *)source
{
    NSLog(@"FOUND: %@, %@", source.name, source.url);
    
    SmartCamera *g = [SmartCamera getInstance];

    // 连接摄像头
    id<Camera>  camera = [g connect:source.url];
    
    NSLog(@"CAMERA: %@", [camera getName]);

    // 获取网络配置信息
    NetworkConfig   *network = [camera getNetwork];

    NSLog(@"NETWORK: %@, %@, %@, %@, %@, %@, %@", network.macAddr, network.dhcp == YES ? @"YES" : @"NO", network.ip, network.mask, network.gateway, network.dns1, network.dns2);

    // 获取 WiFi 设置
    WiFiConfig  *wifi = [camera getWiFi];

    NSLog(@"WIFI: %@, %@, %@", wifi.enabled ? @"YES" : @"NO", wifi.ssid, wifi.password);

    // 获取音频参数配置
    AudioConfig *audio = [camera getAudio];
    
    NSLog(@"AUDIO: %@, %d, %d, %d, %d", audio.enabled ? @"YES" : @"NO", audio.codec, audio.samplerate, audio.bitrate, audio.volume);
    
    // 获取视频参数配置
    VideoConfig *video = [camera getVideo];
    
    NSLog(@"VIDEO: %@, %d, %d, %d, %d, %d", video.enabled ? @"YES" : @"NO", video.codec, video.reso, video.brctrl, video.bitrate, video.framerate);

    // 获取 RTMP 推流设置
    RtmpConfig  *rtmp = [camera getRtmp];
    
    NSLog(@"RTMP: %@, %@, %@, %@", rtmp.enabled ? @"YES" : @"NO", rtmp.rtmpUrl, rtmp.user, rtmp.password);

    // 获取 RTSP 信息
    RtspConfig  *rtsp = [camera getRtsp];
    
    NSLog(@"RTSP: %@, %@", rtsp.mainUrl, rtsp.subUrl);
    
    if([source.name isEqualToString:@"192.168.1.120"])
    {
        network.dhcp = NO;
        network.ip = @"192.168.1.121";

        // 设置网络信息        
        [camera setNetwork:network];
        
        rtmp.enabled = NO;

        // 设置直播推流        
        [camera setRtmp:rtmp];
        
        video.brctrl = CTRL_CBR;
        video.bitrate = 800;
        video.framerate = 21;

        // 设置视频参数        
        [camera setVideo:video];
    }

    // 恢复出厂设置
//    [camera restore];

    // 断开连接
    [camera disconnect];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    SmartCamera *g = [SmartCamera getInstance];
    
    [g discover:[g getSupported] consumer:self timeout:5];
}
```


## 反馈及意见
当你遇到任何问题时，可以通过在 GitHub 的 repo 提交 issues 来反馈问题，请尽可能的描述清楚遇到的问题，如果有错误信息也一同附带，并且在 Labels 中指明类型为 bug 或者其他。
[通过这里查看已有的 issues 和提交 Bug](https://github.com/azhisoft/SmartCamera_iOS/issues)
