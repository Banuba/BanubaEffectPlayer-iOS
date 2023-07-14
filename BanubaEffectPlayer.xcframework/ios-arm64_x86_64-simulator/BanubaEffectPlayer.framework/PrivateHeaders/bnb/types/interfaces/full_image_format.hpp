/// \file
/// \addtogroup Types
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from types.djinni

#pragma once

#include "bnb/types/interfaces/rotation.hpp"
#include <cstdint>
#include <utility>

namespace bnb { namespace interfaces {

struct full_image_format final {
    int32_t width;
    int32_t height;
    rotation orientation;

    full_image_format(int32_t width_,
                      int32_t height_,
                      rotation orientation_)
    : width(std::move(width_))
    , height(std::move(height_))
    , orientation(std::move(orientation_))
    {}
};

} }  // namespace bnb::interfaces
/// @}
