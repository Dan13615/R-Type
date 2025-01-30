/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Path.hpp"

namespace RType
{
    namespace Helpers
    {
        Path *Path::get()
        {
            static Path instance;
            return &instance;
        }

        Path::Path()
        {
            _path = "assets/";

            if (!Utils::DirectoryExists(_path.c_str()))
                _path = "../assets/";
            if (!Utils::DirectoryExists(_path.c_str()))
                _path = "Client/assets/";
        }

        std::string Path::path() const
        {
            return _path;
        }
    } // namespace Helpers
} // namespace RType