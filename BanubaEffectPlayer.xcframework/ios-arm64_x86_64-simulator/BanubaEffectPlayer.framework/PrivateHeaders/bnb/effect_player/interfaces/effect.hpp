/// \file
/// \addtogroup EffectPlayer
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from effect_player.djinni

#pragma once

#include "bnb/scene/interfaces/scene.hpp"
#include <bnb/utils/defs.hpp>
#include <cstdint>
#include <memory>
#include <string>

namespace bnb { namespace interfaces {

class js_callback;

class BNB_EXPORT effect {
public:
    virtual ~effect() {}

    /** Thread-safe. May be called from any thread */
    virtual std::string url() = 0;

    /**
     * Call js method in effect. 
     * @param method_name JS global function name. Member functions are not supported.
     * @param params Function arguments.
     * @depreacted Use `evalJs` instead.
     */
    virtual void call_js_method(const std::string & method_name, const std::string & params) = 0;

    /**
     * Evaluate the `script` in effect. This method is thread safe.
     * @param sctipt JS string to execute 
     * @param js_callback Callback for result, will be called in render thread.
     */
    virtual void eval_js(const std::string & script, const std::shared_ptr<js_callback> & result_callback) = 0;

    /**
     * Evaluate the `script` in effect.
     * MUST be called from the render thread
     * @param sctipt JS string to execute 
     * @return JS evaluation result
     */
    virtual std::string eval_js_sync(const std::string & script) = 0;

    /**
     * Reset effect state
     * MUST be called from the render thread
     */
    virtual void reset() = 0;

    /**
     * Update effect state (evaluate scheduled JS calls)
     * MUST be called from the render thread
     */
    virtual void update() = 0;

    /**
     * If effect is based on Scene engine and it is activated completly - returns Scene object from the effect.
     * Otherwise returns null.
     * MUST be called from the render thread
     * Returned Scene object MUST be used only from the render thread and only while the effect is in the activated state.
     */
    virtual std::shared_ptr<::bnb::interfaces::scene> scene() = 0;

    /**
     * deserialize effect from config.json.
     * can be called from any thread
     */
    virtual void deserialize(const std::string & resolved_url) = 0;

    /**
     * activate current effect
     * MUST be called from the render thread for OpenGL backends.
     */
    virtual void activate(int32_t fx_width, int32_t fx_height, int32_t surface_width, int32_t surface_height) = 0;

    virtual void dump_fs(const std::string & out_dir) = 0;

    virtual void dump() = 0;

    virtual std::string dump_json() = 0;
};

} }  // namespace bnb::interfaces
/// @}

