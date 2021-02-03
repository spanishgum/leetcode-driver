#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace leet {

template <typename PathType>
std::ifstream load_stream(PathType &&path) {
    std::ifstream ifs{path.c_str()};
    return ifs;
}

template <typename T, typename PathType>
std::vector<T> read_vector(PathType &&path) {
    std::vector<T> ans;
    return ans;
}

} // namespace leet