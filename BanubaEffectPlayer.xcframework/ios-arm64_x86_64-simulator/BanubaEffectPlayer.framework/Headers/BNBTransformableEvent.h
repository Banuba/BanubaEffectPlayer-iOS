// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from types.djinni

#import "BNBPixelRect.h"
#import <Foundation/Foundation.h>


#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBTransformableEvent : NSObject
- (nonnull instancetype)initWithBasisTransform:(nonnull NSArray<NSNumber *> *)basisTransform
                                       fullRoi:(nonnull BNBPixelRect *)fullRoi;
+ (nonnull instancetype)transformableEventWithBasisTransform:(nonnull NSArray<NSNumber *> *)basisTransform
                                                     fullRoi:(nonnull BNBPixelRect *)fullRoi;

/** (common -> some event data basis) transformation */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> * basisTransform;

/** rectangle area in common basis that encloses all valid & usable data */
@property (nonatomic, readonly, nonnull) BNBPixelRect * fullRoi;

@end
