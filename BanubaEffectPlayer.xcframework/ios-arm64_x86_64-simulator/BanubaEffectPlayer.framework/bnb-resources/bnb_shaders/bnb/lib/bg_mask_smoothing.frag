#include <bnb/glsl.frag>

BNB_DECLARE_SAMPLER_2D(0, 1, s_tex);

BNB_IN(0)
vec2 var_uv;

void main()
{
    vec4 pixel = BNB_TEXTURE_2D(BNB_SAMPLER_2D(s_tex), var_uv);

    vec3 sum = pixel.rgb;

    const float eps = 1e-8;

    // clang-format off
    if (abs(pixel.w - 1.0) > eps) {
        sum =
            0.125 *
            (textureOffset(BNB_SAMPLER_2D(s_tex), var_uv, ivec2(0, -1)).xyz +
            textureOffset(BNB_SAMPLER_2D(s_tex), var_uv, ivec2(0, 1)).xyz +
            textureOffset(BNB_SAMPLER_2D(s_tex), var_uv, ivec2(-1, 0)).xyz +
            textureOffset(BNB_SAMPLER_2D(s_tex), var_uv, ivec2(1, 0)).xyz +
            textureOffset(BNB_SAMPLER_2D(s_tex), var_uv, ivec2(-1, -1)).xyz +
            textureOffset(BNB_SAMPLER_2D(s_tex), var_uv, ivec2(-1, 1)).xyz +
            textureOffset(BNB_SAMPLER_2D(s_tex), var_uv, ivec2(1, -1)).xyz +
            textureOffset(BNB_SAMPLER_2D(s_tex), var_uv, ivec2(1, 1)).xyz);
    }
    // clang-format oт

    bnb_FragColor = vec4(sum, 1.);
}