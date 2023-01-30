// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from neuro_beauty.djinni

#import <Foundation/Foundation.h>

/** Tuple with neuro_beauty output. */

#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBNeuroBeautyOutput : NSObject
- (nonnull instancetype)initWithWidth:(int32_t)width
                               height:(int32_t)height
                             channels:(int32_t)channels
                                image:(nonnull NSData *)image;
+ (nonnull instancetype)neuroBeautyOutputWithWidth:(int32_t)width
                                            height:(int32_t)height
                                          channels:(int32_t)channels
                                             image:(nonnull NSData *)image;

@property (nonatomic, readonly) int32_t width;

@property (nonatomic, readonly) int32_t height;

@property (nonatomic, readonly) int32_t channels;

@property (nonatomic, readonly, nonnull) NSData * image;

@end
