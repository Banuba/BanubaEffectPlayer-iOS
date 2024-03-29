/// \file
/// \addtogroup Utils
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from utils.djinni

#pragma once

#include <functional>

namespace bnb { namespace interfaces {

enum class severity_level : int {
    debug,
    info,
    warning,
    error,
};

} }  // namespace bnb::interfaces

namespace std {

template <>
struct hash<::bnb::interfaces::severity_level> {
    size_t operator()(::bnb::interfaces::severity_level type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
/// @}

