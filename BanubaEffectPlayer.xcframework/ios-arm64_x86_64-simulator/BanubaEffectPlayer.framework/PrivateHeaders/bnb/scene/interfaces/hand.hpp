/// \file
/// \addtogroup Scene
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from scene.djinni

#pragma once

#include <bnb/utils/defs.hpp>
#include <memory>
#include <string>

namespace bnb { namespace interfaces {

class mesh;
enum class gesture_type;

class BNB_EXPORT hand {
public:
    virtual ~hand() {}

    /**@return hand name (string) */
    virtual std::string get_name() const = 0;

    /**
     *sets hand mesh.
     *@param mesh (mesh): hand mesh
     */
    virtual void set_mesh(const std::shared_ptr<mesh> & mesh) = 0;

    /**@return hand mesh (mesh) */
    virtual std::shared_ptr<mesh> get_mesh() = 0;

    virtual gesture_type get_gesture() const = 0;
};

} }  // namespace bnb::interfaces
/// @}
