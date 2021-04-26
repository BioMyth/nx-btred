#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    AudioTarget_Invalid = 0,
    AudioTarget_Speaker = 1,
    AudioTarget_Headphone = 2,
    AudioTarget_Tv = 3,
    AudioTarget_UsbOutputDevice = 4,
} AudioTarget;

typedef enum {
    AudioOutputMode_Invalid = 0,
    AudioOutputMode_Pcm1ch = 1,
    AudioOutputMode_Pcm2ch = 2,
    AudioOutputMode_Pcm6ch = 3,
    AudioOutputMode_PcmAuto = 4,
} AudioOutputMode;

typedef enum {
    AudioForceMutePolicy_Disable = 0,
    AudioForceMutePolicy_SpeakerMuteOnHeadphoneUnplugged = 1,
} AudioForceMutePolicy;

typedef enum {
    HeadphoneOutputLevelMode_Normal = 0,
    HeadphoneOutputLevelMode_HighPower = 1,
} HeadphoneOutputLevelMode;

Result _audctlInitialize(void);
void _audctlCleanup(void);

Result audctlGetTargetVolume(float* volume_out, AudioTarget target);
Result audctlSetTargetVolume(AudioTarget target, float volume);
Result audctlGetTargetVolumeMin(float* volume_out);
Result audctlGetTargetVolumeMax(float* volume_out);
Result audctlIsTargetMute(bool* mute_out, AudioTarget target);
Result audctlSetTargetMute(AudioTarget target, bool mute);
Result audctlIsTargetConnected(bool* connected_out, AudioTarget target);
Result audctlSetDefaultTarget(AudioTarget target, u64 fade_in_ns, u64 fade_out_ns);
Result audctlGetDefaultTarget(AudioTarget* target_out);
Result audctlGetAudioOutputMode(AudioOutputMode* mode_out, AudioTarget target);
Result audctlSetAudioOutputMode(AudioTarget target, AudioOutputMode mode);
Result audctlSetForceMutePolicy(AudioForceMutePolicy policy);
Result audctlGetForceMutePolicy(AudioForceMutePolicy* policy_out);
Result audctlGetOutputModeSetting(AudioOutputMode* mode_out, AudioTarget target);
Result audctlSetOutputModeSetting(AudioTarget target, AudioOutputMode mode);
Result audctlSetOutputTarget(AudioTarget target);
Result audctlSetInputTargetForceEnabled(bool enable);
Result audctlSetHeadphoneOutputLevelMode(HeadphoneOutputLevelMode mode);
Result audctlGetHeadphoneOutputLevelMode(HeadphoneOutputLevelMode* mode_out);
Result audctlAcquireAudioVolumeUpdateEventForPlayReport(Event* event_out);
Result audctlAcquireAudioOutputDeviceUpdateEventForPlayReport(Event* event_out);
Result audctlGetAudioOutputTargetForPlayReport(AudioTarget* target_out);
Result audctlNotifyHeadphoneVolumeWarningDisplayedEvent(void);
Result audctlSetSystemOutputMasterVolume(float volume);
Result audctlGetSystemOutputMasterVolume(float* volume_out);

#ifdef __cplusplus
};
#endif
