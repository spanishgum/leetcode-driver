#include <iostream>

namespace leet {
using stream_type = std::ostream;

template <typename Arg, typename... Args>
void log(Arg &&arg, Args &&... args) {
    std::cout << std::forward<Arg>(arg);
    ((std::cout << std::forward<Args>(args)), ...);
}

} // namespace leet