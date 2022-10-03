// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from scene.djinni

#import <Foundation/Foundation.h>


/** Class, which provide neural beautification algorithms adjust interface. */
__attribute__((__visibility__("default"))) @interface BNBNeuroBeautificationProcessedTexture : NSObject

/** Receive map with neural beautification parameters. */
- (void)setParameters:(nonnull NSDictionary<NSString *, NSString *> *)parameters;

- (nonnull NSDictionary<NSString *, NSString *> *)getParameters;

- (void)setActive:(BOOL)active;

- (BOOL)isActive;

@end