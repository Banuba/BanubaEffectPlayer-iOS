#include <bnb/glsl.vert>

BNB_LAYOUT_LOCATION(0)
BNB_IN vec3 attrib_pos;


BNB_OUT(0)
vec4 var_uv;

void main()
{
    vec2 v = attrib_pos.xy;
    gl_Position = vec4(v, 0., 1.);
    var_uv.xy = v * 0.5 + 0.5;
    mat3 basis = mat3(background_nn_transform);
    var_uv.zw = vec2(vec3(v, 1.) * basis);
    var_uv.w += 0.5 / 256.;
#ifdef BNB_VK_1
    var_uv.y = 1. - var_uv.y;
#endif
}