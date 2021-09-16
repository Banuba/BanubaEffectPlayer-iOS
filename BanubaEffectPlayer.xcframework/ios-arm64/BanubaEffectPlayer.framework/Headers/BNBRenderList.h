// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from scene.djinni

#import <Foundation/Foundation.h>
@class BNBEntity;
@class BNBLayer;
@class BNBRenderList;
@class BNBRenderTarget;


@interface BNBRenderList : NSObject

+ (nullable BNBRenderList *)create:(nonnull NSString *)name;

- (void)setName:(nonnull NSString *)name;

- (nonnull NSString *)getName;

- (int32_t)addTask:(nullable BNBEntity *)camera
             layer:(nullable BNBLayer *)layer
            target:(nullable BNBRenderTarget *)target;

- (nullable BNBEntity *)getTaskCamera:(int32_t)taskIndex;

- (nullable BNBLayer *)getTaskLayer:(int32_t)taskIndex;

- (nullable BNBRenderTarget *)getTaskTarget:(int32_t)taskIndex;

- (void)clear;

@end