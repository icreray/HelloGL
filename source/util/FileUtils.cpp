#include "FileUtils.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

namespace hellogl::FileUtils {

    std::string readString(const std::string& path) {
        std::string output{};
        std::ifstream inputStream{};

        inputStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            inputStream.open(path.c_str());
            std::stringstream stringStream{};
            stringStream << inputStream.rdbuf();
            inputStream.close();
            output = stringStream.str();
        }
        catch (std::ifstream::failure& e) {
            std::cerr << "Error: ifstream error occurred with file \"" << path << "\".\n    " << e.what() << '\n';
        }

        return output;
    }
}
