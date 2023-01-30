// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from effect_player.djinni

#import "BNBFeatureId.h"
#import <Foundation/Foundation.h>


#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBEffectInfo : NSObject
- (nonnull instancetype)initWithUrl:(nonnull NSString *)url
                 recognizerFeatures:(nonnull NSSet<NSNumber *> *)recognizerFeatures
                          usesAudio:(BOOL)usesAudio
                          usesVideo:(BOOL)usesVideo
                        usesTouches:(BOOL)usesTouches
                   usesBgSeparation:(BOOL)usesBgSeparation;
+ (nonnull instancetype)effectInfoWithUrl:(nonnull NSString *)url
                       recognizerFeatures:(nonnull NSSet<NSNumber *> *)recognizerFeatures
                                usesAudio:(BOOL)usesAudio
                                usesVideo:(BOOL)usesVideo
                              usesTouches:(BOOL)usesTouches
                         usesBgSeparation:(BOOL)usesBgSeparation;

@property (nonatomic, readonly, nonnull) NSString * url;

@property (nonatomic, readonly, nonnull) NSSet<NSNumber *> * recognizerFeatures;

@property (nonatomic, readonly) BOOL usesAudio;

@property (nonatomic, readonly) BOOL usesVideo;

@property (nonatomic, readonly) BOOL usesTouches;

@property (nonatomic, readonly) BOOL usesBgSeparation;

@end
