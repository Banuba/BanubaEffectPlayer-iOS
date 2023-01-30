// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from scene.djinni

#import <Foundation/Foundation.h>
@class BNBImage;
@class BNBResource;



#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBTextTexture : NSObject

- (void)loadResource:(nullable BNBResource *)res;

- (int32_t)getWidth;

- (int32_t)getHeight;

- (void)setWidth:(int32_t)value;

- (void)setHeight:(int32_t)value;

- (void)setText:(nonnull NSString *)text;

- (nonnull NSString *)getText;

- (void)setFont:(nonnull NSString *)path;

- (nonnull NSString *)getFont;

/**@return upcast to base type */
- (nullable BNBImage *)asImage;

@end
