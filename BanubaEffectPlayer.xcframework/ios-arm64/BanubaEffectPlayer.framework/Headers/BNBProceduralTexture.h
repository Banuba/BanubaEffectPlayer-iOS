// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from scene.djinni

#import "BNBProceduralAlgorithmType.h"
#import <Foundation/Foundation.h>
@class BNBCameraComposer;
@class BNBImage;
@class BNBNeuroBeautificationProcessedTexture;


/**
 * Class, which represent some predefined processing algorithm for some image.
 * May or may NOT take some image as input (depends on algorithm). Result image is procedural texture itself.
 * Image processing occurs before any render list task executing.
 * Subclass of image.
 */

#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBProceduralTexture : NSObject

- (BNBProceduralAlgorithmType)getAlgorithmType;

- (void)setSrcImage:(nullable BNBImage *)src;

- (nullable BNBImage *)getSrcImage;

/**@return upcast to base type */
- (nullable BNBImage *)asImage;

- (nullable BNBNeuroBeautificationProcessedTexture *)asNeuroBeautificationProcessedTexture;

- (nullable BNBCameraComposer *)asCameraComposer;

@end
