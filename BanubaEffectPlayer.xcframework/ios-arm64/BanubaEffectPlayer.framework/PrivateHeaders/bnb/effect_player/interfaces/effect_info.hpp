/// \file
/// \addtogroup EffectPlayer
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from effect_player.djinni

#pragma once

#include "bnb/types/interfaces/feature_id.hpp"
#include <string>
#include <unordered_set>
#include <utility>

namespace bnb { namespace interfaces {

struct effect_info final {
    std::string url;
    std::unordered_set<::bnb::interfaces::feature_id> recognizer_features;
    bool uses_audio;
    bool uses_video;
    bool uses_touches;
    bool uses_bg_separation;

    effect_info(std::string url_,
                std::unordered_set<::bnb::interfaces::feature_id> recognizer_features_,
                bool uses_audio_,
                bool uses_video_,
                bool uses_touches_,
                bool uses_bg_separation_)
    : url(std::move(url_))
    , recognizer_features(std::move(recognizer_features_))
    , uses_audio(std::move(uses_audio_))
    , uses_video(std::move(uses_video_))
    , uses_touches(std::move(uses_touches_))
    , uses_bg_separation(std::move(uses_bg_separation_))
    {}
};

} }  // namespace bnb::interfaces
/// @}

