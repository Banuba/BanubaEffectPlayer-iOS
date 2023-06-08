/// \file
/// \addtogroup Scene
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from scene.djinni

#pragma once

#include "bnb/types/interfaces/feature_id.hpp"
#include "bnb/types/interfaces/feature_parameter.hpp"
#include <bnb/utils/defs.hpp>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace bnb { namespace interfaces {

class asset_manager;
class camera;
class component;
class entity;
class layer;
class render_list;
enum class component_type;
enum class trigger_status_type;
enum class trigger_type;

/**
 * A class representing a displayable scene. Aggregates in one place the
 * hierarchy of Entities with their Components,  AssetManager and RenderList
 * and makes it work all together.
 */
class BNB_EXPORT scene {
public:
    virtual ~scene() {}

    /** Set a new name for a scene. The name could be empty. */
    virtual void set_name(const std::string & name) = 0;

    /** Get a scene name. */
    virtual std::string get_name() const = 0;

    /** Get the root of entities hierarchy. It always exists and has a name "Root". */
    virtual std::shared_ptr<entity> get_root() const = 0;

    /** Get the AssetManager of a current scene. It always exists. */
    virtual std::shared_ptr<asset_manager> get_asset_manager() const = 0;

    virtual void add_layer(const std::shared_ptr<layer> & layer) = 0;

    virtual std::vector<std::shared_ptr<layer>> get_layers() const = 0;

    /** Get all components present in this scene of specified type */
    virtual std::vector<std::shared_ptr<component>> get_components(component_type type) const = 0;

    /** Return first found layer with name `layer_name` or NULL if such layer doesn't exist. */
    virtual std::shared_ptr<layer> get_layer(const std::string & layer_name) const = 0;

    virtual void remove_layer(const std::shared_ptr<layer> & layer) = 0;

    virtual void set_render_list(const std::shared_ptr<render_list> & render_list) = 0;

    virtual std::shared_ptr<render_list> get_render_list() const = 0;

    virtual void clear_render_list() = 0;

    virtual std::shared_ptr<camera> get_camera() const = 0;

    virtual void enable_recognizer_feature(::bnb::interfaces::feature_id feature) = 0;

    virtual void disable_recognizer_feature(::bnb::interfaces::feature_id feature) = 0;

    virtual void add_feature_param(::bnb::interfaces::feature_id feature, const std::vector<::bnb::interfaces::feature_parameter> & params) = 0;

    virtual trigger_status_type get_trigger_status(trigger_type trigger) const = 0;

    virtual std::shared_ptr<entity> create_entity(const std::string & name) = 0;

    virtual int64_t get_native_context() = 0;
};

} }  // namespace bnb::interfaces
/// @}

