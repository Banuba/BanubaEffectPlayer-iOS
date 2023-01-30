// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from scene.djinni

#import "BNBEyesStatus.h"
#import <Foundation/Foundation.h>
@class BNBComponent;
@class BNBFace;
@class BNBFaceTracker;


/**
 *Face tracker component. All transformations components of entity with face_tracker component will update
 *relatively face, which index was specified in face asset. Also updates face asset resources. Subclass of component.
 */

#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBFaceTracker : NSObject

/**
 *Fabric method for face tracker creating.
 *@return face tracker component (face_tracker)
 */
+ (nullable BNBFaceTracker *)create;

/**
 *Sets face to face tracker.
 *@param face (face): face asset
 */
- (void)setFace:(nullable BNBFace *)face;

/**@return face (face): face asset */
- (nullable BNBFace *)getFace;

/**
 *true if fase with index, specified in face asset was recognized
 *@return face recognition flag (bool)
 */
- (BOOL)hasFace;

/**
 *true if mouth is open
 *@return flag (bool)
 */
- (BOOL)isMouthOpen;

/**
 *true if is smiling
 *@return flag (bool)
 */
- (BOOL)isSmiling;

/**
 *true if eyebrows up
 *@return flag (bool)
 */
- (BOOL)isEyebrowsUp;

/**
 *true if disgust
 *@return flag (bool)
 */
- (BOOL)isDisgust;

/**@return eyes status (eyes_status) */
- (nonnull BNBEyesStatus *)getEyesStatus;

/**@return upcast to base type */
- (nullable BNBComponent *)asComponent;

@end
