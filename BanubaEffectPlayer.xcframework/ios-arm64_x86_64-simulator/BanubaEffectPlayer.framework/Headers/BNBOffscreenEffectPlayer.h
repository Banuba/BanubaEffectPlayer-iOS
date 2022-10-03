#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreVideo/CoreVideo.h>

@class BNBEffectPlayer;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, EPOrientation) {
    EPOrientationAngles0,
    EPOrientationAngles90,
    EPOrientationAngles180,
    EPOrientationAngles270
};


typedef struct
{
    /**
     * the size of the input image
     */
    CGSize imageSize;
    /**
     * Image orientation, Angles0 means head at the top, other angles mean counterlockwise rotation
     */
    EPOrientation orientation;
    /**
     * Resulting image orientation. If it matches the orientation then image will be returned in the same orientation.
     * Set to EPOrientationAngles0 to keep OEP default orientation.
     */
    EPOrientation resultedImageOrientation;
    /**
     * If YES, then the resulted image will be mirrored
     */
    BOOL isMirrored;
    /**
     * TODO: Add support to return YUV with Alpha. Returns BGRA since YUV-Alpha is not supported yet
     * Used for the cases when the returned image should include valid alpha channel
     */
    BOOL needAlphaInOutput;
    /**
     * Input image format determines output image format, conversion takes time. EffectPlayer produces images in RGBA, if you request BGRA the time to get BGRA is minimal.
     */
    BOOL overrideOutputToBGRA;
    /**
     * Omit conversion, returned pixel buffer is the CVPixelBuffer which is associated with Rendered Texture. The buffer type is BGRA, but texture is RGBA, so if such buffer is drawn without additional processing its colors will look unpredictably.
     */
    BOOL outputTexture;
} EpImageFormat;

/**
 * void block for completions
 */
typedef void (^BNBOEPVoidBlock)(void);
/**
 * block to return resulting image after processing
 * NOTE: pixelBuffer can be null if the frame is dropped because of queue or because it passed unsupported image format for the target image
 */
typedef void (^BNBOEPImageReadyBlock)(_Nullable CVPixelBufferRef pixelBuffer, NSNumber* timeStamp);

/**
 * block to return result of execution of JS script in method evalJs
 */
typedef void (^BNBOEPEvalJsResult)(NSString* _Nonnull result);

/**
 * All methods must be called from the same thread
 * (in which the object was created BNBOffscreenEffectPlayer)
 * All methods are synchronous
 *
 * WARNING: the SDK should be initialized with BNBUtilityManager before BNBOfscreenEffectPlayer creation
 */
__attribute__((__visibility__("default")))
@interface BNBOffscreenEffectPlayer : NSObject

/**
 * Initialize with configured BNBEffectPlayer
 */
- (instancetype)initWithEffectPlayer:(BNBEffectPlayer*)effectPlayer
                      offscreenWidth:(NSUInteger)width
                      offscreenHight:(NSUInteger)height;

/**
 * effectWidth andHeight the size of the inner area where the effect is drawn
 * NOTE: There is an assumption that it is the user's responsibility to make sure that
 *       the size of the rendering area is equal to the image size passed to processImage
 */
- (instancetype)initWithEffectWidth:(NSUInteger)width
                          andHeight:(NSUInteger)height
                        manualAudio:(BOOL)manual;

/**
 * EpImageFormat::imageSize - size of input image
 * the size of the output image is equal to the size of the inner area where the effect is drawn
 * Supported input Image formats:
 *   kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange,
 *   kCVPixelFormatType_420YpCbCr8BiPlanarFullRange,
 *   kCVPixelFormatType_420YpCbCr8Planar,
 *   kCVPixelFormatType_420YpCbCr8PlanarFullRange,
 *   kCVPixelFormatType_32ARGB,
 *   kCVPixelFormatType_32BGRA,
 *   kCVPixelFormatType_24RGB,
 */
- (nullable CVPixelBufferRef)processImage:(CVPixelBufferRef _Nonnull)pixelBuffer withFormat:(const EpImageFormat* _Nonnull)imageFormat CF_RETURNS_RETAINED;

/**
 * Async version of processImage method
 */
- (void)processImage:(CVPixelBufferRef _Nonnull)pixelBuffer withFormat:(const EpImageFormat* _Nonnull)imageFormat frameTimestamp:(NSNumber*)timestamp completion:(BNBOEPImageReadyBlock _Nonnull)completion;

/**
 * Load effect with the specified name (used folder name)
 * effectName - usually it is the folder name with the effect resources on local storage
 */
- (void)loadEffect:(NSString*)effectName;

/**
 * Load effect with specified name asynchronously
 * effectName - usually it is folder name with effect resources on local storage
 */
- (void)loadEffect:(NSString* _Nonnull)effectName completion:(BNBOEPVoidBlock _Nonnull)completion;

/**
 * Deactivate the current effect, the same can be achieved by loading effect with the empty name via loadEffect
 */
- (void)unloadEffect;

/**
 * lets the effect player know that the surface has changed
 */
- (void)surfaceChanged:(NSUInteger)width withHeight:(NSUInteger)height;

/**
 * When you use the EffectPlayer with CallKit, you should enable audio manually at the point when CallKit
 * notifies that its Audio Session is ready (CallKit's session is created in privileged mode, so it should be respected).
 */
- (void)enableAudio:(BOOL)enable;

/**
 * Let you call methods defined in the active effect's script passing additional data or changing effect's behaviour
 */
- (void)callJsMethod:(NSString*)method withParam:(NSString*)param;

/**
 * Let you execute scripts or load JS modules to the environment of active effect
 */
- (void)evalJs:(NSString* _Nonnull)script resultCallback:(BNBOEPEvalJsResult _Nullable)resultCallback;

@end

NS_ASSUME_NONNULL_END
