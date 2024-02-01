#ifndef HELLOGL_TYPE_ALIASES_HPP_
#define HELLOGL_TYPE_ALIASES_HPP_

#include <cstdint>
#include <memory>

namespace hellogl {

    using int32 = int32_t;
    using uint32 = uint32_t;

    template<typename T>
    using unique = std::unique_ptr<T>;
    using std::make_unique;
}

#endif
