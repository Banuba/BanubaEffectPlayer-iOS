/// \file
/// \addtogroup Types
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from types.djinni

#pragma once

#include <cstdint>
#include <utility>

namespace bnb { namespace interfaces {

struct pixel_rect final {
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;

    pixel_rect(int32_t x_,
               int32_t y_,
               int32_t w_,
               int32_t h_)
    : x(std::move(x_))
    , y(std::move(y_))
    , w(std::move(w_))
    , h(std::move(h_))
    {}
};

} }  // namespace bnb::interfaces
/// @}

