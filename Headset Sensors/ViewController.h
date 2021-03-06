//
//  ViewController.h
//  Headset Sensors
//
//  Created by Mick on 1/24/14.
//  Copyright (c) 2014 Mick. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <AVFoundation/AVAudioSession.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <MediaPlayer/MPMusicPlayerController.h>
#import <MediaPlayer/MPVolumeView.h>
#import <AudioToolbox/AudioToolbox.h>

@import MapKit;
#import <SDCAlertView.h>
#import <UIView+SDCAutoLayout.h>


@interface ViewController : UIViewController

// input properties
@property AVAudioRecorder *recorder;
@property NSTimer *levelTimer;
@property NSTimer *alertTimer;
@property double lowPassFiltered;
@property (weak, nonatomic) IBOutlet UILabel *avgInput;
@property (weak, nonatomic) IBOutlet UILabel *peakInput;
@property (weak, nonatomic) IBOutlet UILabel *lowpassInput;
@property (weak, nonatomic) IBOutlet UILabel *inputSource;
@property (weak, nonatomic) IBOutlet UISwitch *headsetSwitch;
@property SDCAlertView *sensorAlert;

// output properties
@property AudioComponentInstance powerTone;
@property double frequency;
@property double amplitude;
@property double sampleRate;
@property double theta;
@property (nonatomic, strong) UISlider *volumeSlider;
@property (weak, nonatomic) IBOutlet UISlider *frequencySlider;
@property (weak, nonatomic) IBOutlet UILabel *frequencyOut;
@property (weak, nonatomic) IBOutlet UISlider *amplitudeSlider;
@property (weak, nonatomic) IBOutlet UILabel *amplitudeOut;

// function prototypes
- (void)levelTimerCallBack:(NSTimer *) timer;
- (void) alertTimerCallBack:(NSTimer *) timer;
- (BOOL)isHeadsetPluggedIn;
- (IBAction)flippedHeadset:(id)sender;

- (IBAction)frequencySliderChange:(id)sender;
- (IBAction)amplitudeSliderChange:(id)sender;
- (void)togglePower:(BOOL)powerOn;
- (void) processInput: (AudioBufferList*) bufferList;

@end

// global audioIO variable to be accessed in callbacks
extern ViewController* audioIO;
