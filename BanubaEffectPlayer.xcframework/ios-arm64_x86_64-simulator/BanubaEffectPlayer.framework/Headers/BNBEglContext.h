// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from utils.djinni

#import <Foundation/Foundation.h>
@class BNBEglContext;



#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBEglContext : NSObject

+ (nullable BNBEglContext *)create:(int32_t)width
                            height:(int32_t)height;

- (BOOL)check;

- (void)activate;

- (void)deactivate;

@end
