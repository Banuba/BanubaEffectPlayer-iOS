// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from recognizer.djinni

#import "BNBFrameData.h"
#import <Foundation/Foundation.h>


@protocol BNBFeature

/**must return unique id (e.g. a feature pointer or a true random number(most likely) satisfies this criteria) */
- (int64_t)id;

- (BOOL)requiresMainThread;

- (void)clean;

- (void)process:(nullable BNBFrameData *)frameData;

@end
