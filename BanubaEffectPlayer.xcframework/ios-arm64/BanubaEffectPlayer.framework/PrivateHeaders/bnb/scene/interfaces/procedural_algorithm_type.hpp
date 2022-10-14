/// \file
/// \addtogroup Scene
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from scene.djinni

#pragma once

#include <functional>

namespace bnb { namespace interfaces {

/** All available images processing algorithms. */
enum class procedural_algorithm_type : int {
    /**
     * Doesn't requires any src image on input.
     * Result: RGBA camera image with correct device-relative orientation.
     */
    camera_composer,
    /**
     * Doesn't requires any src image on input.
     * Result: RGBA processed image using neural networks beautification.
     */
    neuro_beautification,
};

} }  // namespace bnb::interfaces

namespace std {

template <>
struct hash<::bnb::interfaces::procedural_algorithm_type> {
    size_t operator()(::bnb::interfaces::procedural_algorithm_type type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
/// @}

