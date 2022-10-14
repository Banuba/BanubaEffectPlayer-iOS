#include <bnb/glsl.frag>

BNB_DECLARE_SAMPLER_2D(0, 1, s_downscale_tex);

BNB_IN(0)
vec2 var_uv;

void main()
{
    vec4 pixel = BNB_TEXTURE_2D(BNB_SAMPLER_2D(s_downscale_tex), var_uv);
    // clang-format off
    vec3 sum = (0.5 * pixel.xyz * (1. - pixel.w) + 0.125 * 
        (textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(1, 1)).xyz * (1. - textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(1, 1)).w) +
         textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(-1, 1)).xyz * (1. - textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(-1, 1)).w) +
         textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(-1, -1)).xyz * (1. - textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(-1, -1)).w) +
         textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(1, -1)).xyz * (1. - textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(1, -1)).w))) /
        (0.5 * (1. - pixel.w) + 0.125 * 
        ((1. - textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(1, 1)).w) + 
        (1. - textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(-1, 1)).w) + 
        (1. - textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(-1, -1)).w) +
        (1. - textureOffset(BNB_SAMPLER_2D(s_downscale_tex), var_uv, ivec2(1, -1)).w)));
    // clang-format on
    bnb_FragColor = vec4(sum, pixel.w);
}