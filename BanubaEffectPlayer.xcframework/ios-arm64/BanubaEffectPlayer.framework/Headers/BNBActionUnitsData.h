// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from types.djinni

#import "BNBActionUnits.h"
#import <Foundation/Foundation.h>


#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBActionUnitsData : NSObject
- (nonnull instancetype)initWithFaces:(nonnull NSArray<BNBActionUnits *> *)faces;
+ (nonnull instancetype)actionUnitsDataWithFaces:(nonnull NSArray<BNBActionUnits *> *)faces;

@property (nonatomic, readonly, nonnull) NSArray<BNBActionUnits *> * faces;

@end
