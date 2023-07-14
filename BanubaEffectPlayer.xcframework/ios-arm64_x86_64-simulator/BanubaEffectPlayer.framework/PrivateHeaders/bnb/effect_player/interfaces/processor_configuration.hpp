/// \file
/// \addtogroup EffectPlayer
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from effect_player.djinni

#pragma once

#include <bnb/utils/defs.hpp>
#include <memory>

namespace bnb { namespace interfaces {

class BNB_EXPORT processor_configuration {
public:
    virtual ~processor_configuration() {}

    /** Create with default params */
    static std::shared_ptr<processor_configuration> create();

    /**
     * Use future frame to filter prediction, improves anti-jitter, adds processed frame inconsistency
     * Example: push frame 1 - pop frame 1, push frame 2 - pop frame 1, push frame 3 - pop frame 2, ...
     * Cannot be used together with other configurations
     * Default: true
     */
    virtual void set_use_future_filter(bool value) = 0;

    /**
     * Use future frame to interpolate prediction, improves performance, adds processed frame inconsistency
     * Example: push frame 1 - pop frame 1, push frame 2 - pop frame 1, push frame 3 - pop frame 2, ...
     * Cannot be used together with other configurations
     * Default: false
     */
    virtual void set_use_future_interpolate(bool value) = 0;

    /**
     * Use offline NN's for processing, improces accuracy in exchange to performance
     * Cannot be used together with other configurations
     * Default: false
     */
    virtual void set_use_offline_mode(bool value) = 0;
};

} }  // namespace bnb::interfaces
/// @}
