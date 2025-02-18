/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Parsing.hpp"

namespace RType
{
    const char *Parsing::Help::what() const noexcept
    {
        std::ifstream file(RType::Helpers::Path::get()->path() + "data/help.txt");
        if (!file.is_open())
            return "Failed to open help file.";
        std::string content;
        std::string line;
        while (std::getline(file, line))
            content += line + "\n";
        file.close();
        std::cout << content << std::endl;
        return "";
    }
} // namespace RType
