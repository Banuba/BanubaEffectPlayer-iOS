/// \file
/// \addtogroup EffectPlayer
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from effect_player.djinni

#pragma once

#include "bnb/effect_player/interfaces/processor_status.hpp"
#include "bnb/types/interfaces/frame_data.hpp"
#include <memory>
#include <optional>
#include <utility>

namespace bnb { namespace interfaces {

struct processor_result final {
    processor_status status;
    std::shared_ptr<::bnb::interfaces::frame_data> frame_data;

    processor_result(processor_status status_,
                     std::shared_ptr<::bnb::interfaces::frame_data> frame_data_)
    : status(std::move(status_))
    , frame_data(std::move(frame_data_))
    {}
};

} }  // namespace bnb::interfaces
/// @}
