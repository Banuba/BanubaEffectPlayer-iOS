/// \file
/// \addtogroup EffectPlayer
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from effect_player.djinni

#pragma once

#include "bnb/types/interfaces/size.hpp"
#include <bnb/utils/defs.hpp>
#include <cstdint>
#include <memory>
#include <string>

namespace bnb { namespace interfaces {

class effect;
class effect_activated_listener;
class effect_event_listener;
class error_listener;
class hint_listener;
struct effect_info;
struct surface_data;

class BNB_EXPORT effect_manager {
public:
    virtual ~effect_manager() {}

    /**
     * Add callback to receive errors messages from Effect Player.
     * Thread-safe. May be called from any thread
     */
    virtual void add_error_listener(const std::shared_ptr<error_listener> & error_listener) = 0;

    /**
     * Remove callback to receive errors messages from Effect Player.
     * Thread-safe. May be called from any thread
     */
    virtual void remove_error_listener(const std::shared_ptr<error_listener> & error_listener) = 0;

    /**
     * Add callback to receive user-visible messages from effects.
     * You should display them on UI.
     * Thread-safe. May be called from any thread
     */
    virtual void add_hint_listener(const std::shared_ptr<hint_listener> & hint_listener) = 0;

    /**
     * Remove callback to receive user-visible messages from effects.
     * Thread-safe. May be called from any thread
     */
    virtual void remove_hint_listener(const std::shared_ptr<hint_listener> & hint_listener) = 0;

    /**
     * Add callback to receive events from effect.
     * Thread-safe. May be called from any thread
     */
    virtual void add_effect_event_listener(const std::shared_ptr<effect_event_listener> & effect_event_listener) = 0;

    /**
     * Remove callback to receive events from effect.
     * Thread-safe. May be called from any thread
     */
    virtual void remove_effect_event_listener(const std::shared_ptr<effect_event_listener> & effect_event_listener) = 0;

    /**
     * Add callback to receive notifications on effect change.
     * Thread-safe. May be called from any thread
     */
    virtual void add_effect_activated_listener(const std::shared_ptr<effect_activated_listener> & effect_activated_listener) = 0;

    /**
     * Remove callback to receive notifications on effect change.
     * Thread-safe. May be called from any thread
     */
    virtual void remove_effect_activated_listener(const std::shared_ptr<effect_activated_listener> & effect_activated_listener) = 0;

    /** Create empty effect. If working directory path is empty string then effect assumed as an in-memory effect. */
    virtual std::shared_ptr<effect> create_effect(const std::string & work_dir) const = 0;

    /**
     * Set current effect.
     * Thread-safe. May be called from any thread
     */
    virtual void set_current_effect(const std::shared_ptr<effect> & effect) = 0;

    /**
     * load and activate effect sync
     * MUST be called from the render thread
     */
    virtual std::shared_ptr<effect> load(const std::string & url) = 0;

    /**
     * load effect async, activate in the draw() call when it will be ready
     * Thread-safe. May be called from any thread
     */
    virtual std::shared_ptr<effect> load_async(const std::string & url) = 0;

    /**
     * Get effect info. May be called before loading effect
     * "render type" and "recognizer features" fields won't be filled
     * Thread-safe. May be called from any thread
     */
    static effect_info get_effect_info(const std::string & url);

    /**
     * Unload effect from cache. if no currently loading effect -
     * works the same way as load(""); launches empty effect loading.
     * MUST be called from the render thread
     */
    virtual void unload(const std::shared_ptr<effect> & effect) = 0;

    /**
     * Get active effect
     * Thread-safe. May be called from any thread
     */
    virtual std::shared_ptr<effect> current() const = 0;

    /**
     * Update effect loading state
     * @param sync syncronize effect manager, block until effect loaded
     * MUST be called from the render thread
     */
    virtual void update(bool sync) = 0;

    /**
     * Get current effect size
     * Thread-safe. May be called from any thread
     */
    virtual ::bnb::interfaces::size effect_size() const = 0;

    /**
     * Get current surface size
     * Thread-safe. May be called from any thread
     */
    virtual ::bnb::interfaces::size surface_size() const = 0;

    /**
     * Set effect audio volume.
     * Thread-safe. May be called from any thread
     * @param volume A value in range `[0, 1]`, where `1` means maximum volume.
     */
    virtual void set_effect_volume(float volume) = 0;

    /**
     * Changes effect player render size, should be called on render thread.
     * MUST be called from the render thread
     */
    virtual void set_effect_size(int32_t fx_width, int32_t fx_height) = 0;

    /** set different render surfaces. Can be treated as void* */
    virtual void set_render_surface(const surface_data & data) = 0;

    /** disable surface presentation. Needed for offscreen rendering */
    virtual void disable_surface_presentation() = 0;
};

} }  // namespace bnb::interfaces
/// @}

