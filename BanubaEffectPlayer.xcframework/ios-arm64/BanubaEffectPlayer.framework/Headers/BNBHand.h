// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from scene.djinni

#import "BNBGestureType.h"
#import <Foundation/Foundation.h>
@class BNBMesh;



#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBHand : NSObject

/**@return hand name (string) */
- (nonnull NSString *)getName;

/**
 *sets hand mesh.
 *@param mesh (mesh): hand mesh
 */
- (void)setMesh:(nullable BNBMesh *)mesh;

/**@return hand mesh (mesh) */
- (nullable BNBMesh *)getMesh;

- (BNBGestureType)getGesture;

@end
