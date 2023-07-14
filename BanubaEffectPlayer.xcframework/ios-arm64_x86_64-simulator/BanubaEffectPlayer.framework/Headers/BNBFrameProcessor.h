// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from effect_player.djinni

#import "BNBFrameData.h"
#import "BNBProcessorResult.h"
#import "BNBProcessorType.h"
#import "BNBRealtimeProcessorMode.h"
#import <Foundation/Foundation.h>
@class BNBFrameProcessor;
@class BNBProcessorConfiguration;



#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBFrameProcessor : NSObject

/** Realtime feed processor. See RealtimeProcessorMode for more info. */
+ (nullable BNBFrameProcessor *)createRealtimeProcessor:(BNBRealtimeProcessorMode)mode
                                                 config:(nullable BNBProcessorConfiguration *)config;

/**
 * Photo processor. `push` to set photo, processing happens on `pop` synchronously.
 * Several `pop` calls return same result without unnecessary processing,
 * except case when recognizer pipeline was changed by EffectPlayer, processing will be restarted.
 */
+ (nullable BNBFrameProcessor *)createPhotoProcessor:(nullable BNBProcessorConfiguration *)config;

/** Video processor. Consistent `push` - `pop` will process frames synchronously. */
+ (nullable BNBFrameProcessor *)createVideoProcessor:(nullable BNBProcessorConfiguration *)config;

- (BNBProcessorType)getType;

- (void)push:(nullable BNBFrameData *)fd;

- (nonnull BNBProcessorResult *)pop;

@end