#ifndef LEET_ERROR
#define LEET_ERROR

#include <exception>
#include <filesystem>
#include <string>

namespace leet {

struct FileStreamException : public std::exception {
    std::string path;

    FileStreamException(const std::filesystem::path &p) : path(p.string()) {}

    const char *what() const throw() { return this->path.c_str(); }
};

struct BadInputException : public std::exception {
    const char *what() const throw() { return "Bad input"; }
};

} // namespace leet

#endif