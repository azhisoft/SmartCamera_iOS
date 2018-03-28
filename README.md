# SmartCamera_iOS
������ iOS ƽ̨����������ͷ SDK��֧�� SmartLink �������������������֣�������ͷ���������á�����Ƶ�������ã��Լ� RTMP �������õȡ�

SmartCamera ּ���ṩ�����õ� SDK�����ݰ�������������ͷ���������ͷ�ȸ�������ͷ�豸��ʵ�ֶ�����ͷ��������õ����ܻ����ƶ�����

## ��ʶ SmartCamera
- SDK ����ṹ��
![Overview](overview.png)
- SmartCamera��SmartCamera ��һ������ʵ������ʹ�� SDK �������
- CameraProvider��CameraProvider ��һ���ӿڣ���Բ�ͬ���̵�����ͷ���ṩ��ͬ�� CameraProvider ʵ��
- Camera��Camera ͬ����һ���ӿڣ���Բ�ͬ�����ṩ��Ӧ��ʵ��

## ʹ�� SmartCamera
- ���� SmartCamera.framework �����̡�
- �������룺
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

    // ��������ͷ
    id<Camera>  camera = [g connect:source.url];
    
    NSLog(@"CAMERA: %@", [camera getName]);

    // ��ȡ����������Ϣ
    NetworkConfig   *network = [camera getNetwork];

    NSLog(@"NETWORK: %@, %@, %@, %@, %@, %@, %@", network.macAddr, network.dhcp == YES ? @"YES" : @"NO", network.ip, network.mask, network.gateway, network.dns1, network.dns2);

    // ��ȡ WiFi ����
    WiFiConfig  *wifi = [camera getWiFi];

    NSLog(@"WIFI: %@, %@, %@", wifi.enabled ? @"YES" : @"NO", wifi.ssid, wifi.password);

    // ��ȡ��Ƶ��������
    AudioConfig *audio = [camera getAudio];
    
    NSLog(@"AUDIO: %@, %d, %d, %d, %d", audio.enabled ? @"YES" : @"NO", audio.codec, audio.samplerate, audio.bitrate, audio.volume);
    
    // ��ȡ��Ƶ��������
    VideoConfig *video = [camera getVideo];
    
    NSLog(@"VIDEO: %@, %d, %d, %d, %d, %d", video.enabled ? @"YES" : @"NO", video.codec, video.reso, video.brctrl, video.bitrate, video.framerate);

    // ��ȡ RTMP ��������
    RtmpConfig  *rtmp = [camera getRtmp];
    
    NSLog(@"RTMP: %@, %@, %@, %@", rtmp.enabled ? @"YES" : @"NO", rtmp.rtmpUrl, rtmp.user, rtmp.password);

    // ��ȡ RTSP ��Ϣ
    RtspConfig  *rtsp = [camera getRtsp];
    
    NSLog(@"RTSP: %@, %@", rtsp.mainUrl, rtsp.subUrl);
    
    if([source.name isEqualToString:@"192.168.1.120"])
    {
        network.dhcp = NO;
        network.ip = @"192.168.1.121";

        // ����������Ϣ        
        [camera setNetwork:network];
        
        rtmp.enabled = NO;

        // ����ֱ������        
        [camera setRtmp:rtmp];
        
        video.brctrl = CTRL_CBR;
        video.bitrate = 800;
        video.framerate = 21;

        // ������Ƶ����        
        [camera setVideo:video];
    }

    // �ָ���������
//    [camera restore];

    // �Ͽ�����
    [camera disconnect];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    SmartCamera *g = [SmartCamera getInstance];
    
    [g discover:[g getSupported] consumer:self timeout:5];
}
```


## ���������
���������κ�����ʱ������ͨ���� GitHub �� repo �ύ issues ���������⣬�뾡���ܵ�����������������⣬����д�����ϢҲһͬ������������ Labels ��ָ������Ϊ bug ����������
[ͨ������鿴���е� issues ���ύ Bug](https://github.com/azhisoft/SmartCamera_iOS/issues)
