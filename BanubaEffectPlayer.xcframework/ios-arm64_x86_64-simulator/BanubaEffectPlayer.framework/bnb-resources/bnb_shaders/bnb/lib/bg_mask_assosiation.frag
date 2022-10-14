#include <bnb/glsl.frag>


BNB_IN(0)
vec4 var_uv;

BNB_DECLARE_SAMPLER_2D(0, 1, s_segmentation_mask);
BNB_DECLARE_SAMPLER_2D(2, 3, s_camera_tex);


void main()
{
    float mask = BNB_TEXTURE_2D(BNB_SAMPLER_2D(s_segmentation_mask), var_uv.zw).x;
    bnb_FragColor = vec4(BNB_TEXTURE_2D(BNB_SAMPLER_2D(s_camera_tex), var_uv.xy).xyz, 1. - mask);
}
