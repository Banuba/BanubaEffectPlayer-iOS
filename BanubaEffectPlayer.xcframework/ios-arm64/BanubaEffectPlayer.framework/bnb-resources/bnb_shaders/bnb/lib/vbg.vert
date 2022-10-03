#include <bnb/glsl.vert>

BNB_LAYOUT_LOCATION(0)
BNB_IN vec2 attrib_pos;

BNB_OUT(0)
vec2 var_uv;
BNB_OUT(1)
vec2 var_bg_uv;
BNB_OUT(2)
vec2 var_bg_mask_uv;

#include <bnb/quat_rotation.glsl>
#include <bnb/transform_uv.glsl>

void main()
{
    vec2 v = attrib_pos;
    gl_Position = vec4(v, 0., 1.);
    var_uv = v * 0.5 + 0.5;
    var_bg_uv = var_uv;

#ifdef BNB_VK_1
    var_uv.y = 1. - var_uv.y;
    var_bg_uv.y = 1. - var_bg_uv.y;
#endif

    float is_mirrored_coeff = mix(-1., 1., vbg_mirroring.x);
    if (bnb_camera_orientation.x < 0.)
        is_mirrored_coeff = -1.;

    vec2 bg_tex_size = vbg_texture_size.xy;

    if (vbg_texture_size.x < 1.0 || vbg_texture_size.y < 1.0) {
        bg_tex_size = bnb_SCREEN.xy;
    }

    float background_rotation_angle = 0.;
    background_rotation_angle += vbg_rotation.x;

    float degrees_to_radians = 0.017453292;
#ifdef BNB_VK_1
    degrees_to_radians *= -1.0;
#endif

    var_bg_uv = bnb_rotate_uv(var_bg_uv, degrees_to_radians * (background_rotation_angle));
    var_bg_uv = bnb_scale_uv(var_bg_uv, vbg_scale.xy);
    var_bg_uv = bnb_contain_uv(var_bg_uv, bg_tex_size, vbg_content_mode.x, background_rotation_angle);

    vec4 uv = vec4(v, 1., 1.) * background_nn_transform;
    var_bg_mask_uv = uv.xy;
}