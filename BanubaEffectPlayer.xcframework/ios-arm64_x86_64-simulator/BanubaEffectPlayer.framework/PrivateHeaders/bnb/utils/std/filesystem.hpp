
#pragma once

#include <bnb/utils/defs.hpp>

#if BNB_OS_WINDOWS || BNB_OS_EMSCRIPTEN
    #include <filesystem>
#else
    #include <boost/filesystem.hpp>
#endif

// we can't pollute global namespace in header
namespace bnb
{
#if BNB_OS_WINDOWS
    namespace fs = std::filesystem;

    using error_code = std::error_code;
    using file_time_type = std::filesystem::file_time_type;

    inline fs::path replace_extension(fs::path p, const std::string& ext)
    {
        return p.replace_extension(std::string(".") + ext);
    }

    inline std::string path_to_utf8(const fs::path& p)
    {
        return std::string(reinterpret_cast<const char*>(p.generic_u8string().c_str()));
    }

    inline fs::path utf8_to_path(const std::string& s)
    {
        return fs::path(reinterpret_cast<const char8_t*>(s.c_str()));
    }
#elif BNB_OS_EMSCRIPTEN
    namespace fs = std::filesystem;

    using error_code = std::error_code;
    using file_time_type = std::filesystem::file_time_type;

    inline fs::path replace_extension(fs::path p, const std::string& ext)
    {
        return p.replace_extension(std::string(".") + ext);
    }

    inline std::string path_to_utf8(const fs::path& p)
    {
        return p.string();
    }

    inline fs::path utf8_to_path(const std::string& s)
    {
        return fs::path(s);
    }
#else
    namespace fs = boost::filesystem;

    using error_code = boost::system::error_code;
    using file_time_type = std::time_t;

    inline fs::path replace_extension(const fs::path& p, const std::string& ext)
    {
        return fs::change_extension(p, ext);
    }

    inline std::string path_to_utf8(const fs::path& p)
    {
        return p.generic_string();
    }

    inline fs::path utf8_to_path(const std::string& s)
    {
        return fs::path(s);
    }
#endif
    template<typename... T>
    bool match_extesions(const fs::path& path, T&&... extensions)
    {
        auto ext = bnb::path_to_utf8(path.extension());
        std::transform(ext.begin(), ext.end(), ext.begin(), [](unsigned char c) { return std::tolower(c); });
        bool match = false;
        ([&]() {
            if (match) {
                return;
            }
            std::string ext_to_lower(extensions);
            std::transform(ext_to_lower.begin(), ext_to_lower.end(), ext_to_lower.begin(), [](unsigned char c) { return std::tolower(c); });
            match = ext == ext_to_lower;
        }(),
         ...);

        return match;
    }
} // namespace bnb
