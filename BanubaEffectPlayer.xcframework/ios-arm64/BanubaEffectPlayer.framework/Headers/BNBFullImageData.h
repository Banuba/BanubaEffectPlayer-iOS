#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>

#if __has_include(<BNBCameraOrientation.h>)
    #import <BNBCameraOrientation.h>
#else
    #import <BanubaEffectPlayer/BNBCameraOrientation.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 * Container for image data designed for Banuba SDK.
 */
__attribute__((__visibility__("default")))
@interface BNBFullImageData : NSObject

/**
 * A method for initializing a new object.
 *
 * @param buffer is a pixel buffer stores an image in main memory.
 * @param cameraOrientation is an enum value of camera orientation. It is present camera orientation in degrees.
 * @param requireMirroring is responsible for mirroring image during rendering; if it is true image will be mirrored.
 * @param faceOrientation present the face orientation in degrees.
 * @param fieldOfView is a angle of field view in degrees.
 *
 * @return Returns initialized object of BNBFullImageData, or nil if an object coldn't be created for some reason.
 */
- (instancetype)init:(CVPixelBufferRef)buffer
    cameraOrientation:(BNBCameraOrientation)cameraOrientation
     requireMirroring:(BOOL)requireMirroring
      faceOrientation:(NSInteger)faceOrientation
          fieldOfView:(float)fieldOfView;

/**
 * It is a readonly property representing width of image in pixels.
 */
@property(nonatomic, readonly) uint32_t width;
/**
 * It is a readonly property representing height of image in pixels.
 */
@property(nonatomic, readonly) uint32_t height;
/**
 * It is a readonly property representing filed of view in degrees.
 */
@property(nonatomic, readonly) float fieldOfView;
/**
 * It is a readonly property representing camera orientation in degrees as enum value.
 */
@property(nonatomic, readonly) BNBCameraOrientation cameraOrientation;
/**
 * It is a readonly property representing necessity of mirroring during rendering.
 */
@property(nonatomic, readonly) BOOL requireMirroring;
/**
 * It is a readonly property representing face orientation in degrees.
 */
@property(nonatomic, readonly) int faceOrientation;
/**
 * It is a readonly property representing a pixel buffer stores an images.
 */
@property(nonatomic, readonly) __nullable CVPixelBufferRef pixelBuffer;

@end

NS_ASSUME_NONNULL_END
