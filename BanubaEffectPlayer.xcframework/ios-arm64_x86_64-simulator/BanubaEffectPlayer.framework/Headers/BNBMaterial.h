// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from scene.djinni

#import "BNBGeometryTopology.h"
#import "BNBShaderSource.h"
#import "BNBState.h"
#import <Foundation/Foundation.h>
@class BNBImage;
@class BNBParameter;


/**Class, represents material interface */

#ifndef DJINNI_EXPORT
    #define DJINNI_EXPORT __attribute__((__visibility__("default")))
#endif

DJINNI_EXPORT
@interface BNBMaterial : NSObject

/**@return material name (string) */
- (nonnull NSString *)getName;

/**
 *adds shader parameter to parameters list, after what you'll can get access to this parameter in shader by it's name. 
 *Type of parameter in shader will match with type of parameter, except int, float, vector2, vector3, 
 *this types will be replaces on vec4, which x component will have needed value, other components will be filled by garbage.
 *@param parameter (parameter): parameter to add
 */
- (void)addParameter:(nullable BNBParameter *)parameter;

/**@return list of shader parameters (list<parameter>) */
- (nonnull NSArray<BNBParameter *> *)getParameters;

/**
 *removes parameter from list.
 *@param parameter (parameter): parameter to remove
 */
- (void)removeParameter:(nullable BNBParameter *)parameter;

/**
 *find parameter by name
 *@param name (string)
 *@return parameter (parameter) or null
 */
- (nullable BNBParameter *)findParameter:(nonnull NSString *)name;

/**
 *set material geometry topology.
 *@param topology (geometry_topology): geometry topology type. Can be triangles_list, lines_list, points_list. Default: triangles_list
 */
- (void)setTopology:(BNBGeometryTopology)topology;

/**@return current geometry topology (geometry_topology) */
- (BNBGeometryTopology)getCurrentTopology;

/**
 *sets render state (i.e blending mode, color/depth writing, depth testing, etc.)
 *@param state (state) render state
 */
- (void)setState:(nonnull BNBState *)state;

/**@return render state (state) */
- (nonnull BNBState *)getState;

/**
 *add image sampler, after what you'll can get acess to image and sampler in shader by formula: image_index = i * 2. sampler_index = i * 2 + 1. 
 *Where i is image index in images list (which you can get by get_images call). 
 *Note that you need to declare images samplers in shader manually and sampler name in name must match with sampler name in material.
 *@param sampler (string): sampler name
 *@param image (image): sampler image
 */
- (void)addImage:(nonnull NSString *)sampler
           image:(nullable BNBImage *)image;

/**@return list of samplers images (list<parameter>) */
- (nonnull NSArray<BNBImage *> *)getImages;

/**
 *removes image from list (if exist). Will be ignored if effect was activated.
 *@param sampler (string): sampler name
 */
- (void)removeImage:(nonnull NSString *)sampler;

/**@return list of samplers name (list<string>) */
- (nonnull NSArray<NSString *> *)getSamplers;

/**@return compiled and combined shaders sources */
- (nonnull BNBShaderSource *)getShaderSource;

@end
