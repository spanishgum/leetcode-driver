#ifndef LEET_INPUTS
#define LEET_INPUTS

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace leet {

struct FileStreamException : public std::exception {
    std::string path;

    template <typename PathType>
    FileStreamException(const PathType &p) : path(p.string()) {}

    const char *what() const throw() { return this->path.c_str(); }
};

struct BadInputException : public std::exception {
    const char *what() const throw() { return "Bad input"; }
};

template <typename PathType>
std::ifstream load_stream(PathType &&path) {
    const std::string base_dir =
        std::filesystem::path{"../src/questions/example/inputs"};
    const std::filesystem::path p{std::forward<PathType>(path)};
    auto full_path = base_dir / p;
    std::ifstream ifs{full_path.c_str()};
    if (!ifs) {
        throw FileStreamException(full_path);
    }
    return ifs;
}

template <typename T, typename Stream>
std::vector<T> read_vector_impl(Stream &ifs) {
    std::vector<T> ans;

    // open the array
    if (ifs.peek() == '[') {
        ifs.get();
    } else {
        throw BadInputException();
    }

    // start parsing
    T element;
    // make sure stream is good
    while (ifs) {
        auto next = ifs.peek();
        // check for end of input, or delimiter
        // anything else is bad input
        if (next == ']') {
            break;
        } else if (next == ',') {
            ifs.get();
        } else {
            throw BadInputException();
        }

        // expect T to be readable
        // anything else is bad input
        if (ifs >> element) {
            ans.push_back(element);
        } else {
            throw BadInputException();
        }
    }

    return ans;
}

template <typename T, typename PathType>
std::vector<T> read_vector(PathType &&path) {
    std::vector<T> ans;
    auto ifs = load_stream(std::forward<PathType>(path));
    ans = std::move(read_vector_impl<T>(ifs));
    return ans;
}

} // namespace leet

#endif