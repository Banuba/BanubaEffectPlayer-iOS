// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from types.djinni

#import <Foundation/Foundation.h>


#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBPoint2d : NSObject
- (nonnull instancetype)initWithX:(float)x
                                y:(float)y;
+ (nonnull instancetype)point2dWithX:(float)x
                                   y:(float)y;

@property (nonatomic, readonly) float x;

@property (nonatomic, readonly) float y;

@end
