// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from visual_clip.djinni

#import "BNBVisualClipVideo.h"
#import <Foundation/Foundation.h>
@class BNBVisualClip;
@protocol BNBVisualClipListener;



#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBVisualClip : NSObject

/**
 * Create instance of visual clip processor
 * @param musicDbPath absolute path to folder with embeddings and intervals
 * @param visualEffects list of visual effects to use in recomendations
 * @param transitionEffects list of transition effects to use in recomendations
 */
+ (nullable BNBVisualClip *)create:(nonnull NSString *)musicDbPath
                     visualEffects:(nonnull NSArray<NSString *> *)visualEffects
                 transitionEffects:(nonnull NSArray<NSString *> *)transitionEffects
                          listener:(nullable id<BNBVisualClipListener>)listener;

/**
 * Process video and get recomendations
 * @param videos array of videos to process
 * @param numFrames number of frames in video to process
 * @param resultSize number of recomendations in result array
 * @return array of recomendations, each is json, sorted by relevance
 */
- (nonnull NSArray<NSString *> *)process:(nonnull NSArray<BNBVisualClipVideo *> *)videos
                               numFrames:(int32_t)numFrames
                              resultSize:(int32_t)resultSize;

@end
