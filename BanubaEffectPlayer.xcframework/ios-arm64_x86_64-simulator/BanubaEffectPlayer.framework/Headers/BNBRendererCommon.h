// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from renderer_common.djinni

#import "BanubaEffectPlayer/BNBFullImageData.h"
#import <Foundation/Foundation.h>


__attribute__((__visibility__("default"))) @interface BNBRendererCommon : NSObject

/** return rgba image, srcImage can be rgb or rgba */
+ (nonnull BNBFullImageData *)morphMesh:(nonnull BNBFullImageData *)srcImage
                          originalVerts:(nonnull NSArray<NSNumber *> *)originalVerts
                           morphedVerts:(nonnull NSArray<NSNumber *> *)morphedVerts
                                indices:(nonnull NSArray<NSNumber *> *)indices
                                    mvp:(nonnull NSArray<NSNumber *> *)mvp;

@end