#ifndef LEET_INPUTS
#define LEET_INPUTS

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

#include <tao/pegtl.hpp>
namespace pegtl = tao::pegtl;

#include "details/error.hpp"
#include "details/log.hpp"

namespace leet {

namespace parse {

struct open_bracket : pegtl::one<'['> {};
struct close_bracket : pegtl::one<']'> {};
struct comma : pegtl::one<','> {};
struct number : pegtl::plus<pegtl::digit> {};
struct padded_number : pegtl::pad<number, pegtl::blank> {};
struct number_list : pegtl::seq<pegtl::star<pegtl::list<padded_number, comma>>,
                                pegtl::star<number>> {};

} // namespace parse

namespace vector_parser {

struct grammar : pegtl::must<parse::open_bracket, parse::number_list,
                             parse::close_bracket> {};

template <typename Rule>
struct action {};

template <>
struct action<parse::open_bracket> {
    template <typename ParseInput>
    static void apply(const ParseInput &in, std::vector<int> &v) {
        // log(color::Yellow("Found opening bracket"));
    }
};

template <>
struct action<parse::comma> {
    template <typename ParseInput>
    static void apply(const ParseInput &in, std::vector<int> &v) {
        // log(color::Yellow("Found comma"));
    }
};

template <>
struct action<parse::padded_number> {
    template <typename ParseInput>
    static void apply(const ParseInput &in, std::vector<int> &v) {
        // log(color::Yellow("Found (maybe padded) number"));
    }
};

template <>
struct action<parse::number> {
    template <typename ParseInput>
    static void apply(const ParseInput &in, std::vector<int> &v) {
        auto n = in.string();
        // log(color::Yellow("Parsing number: "), n);
        v.emplace_back(std::stoi(n));
    }
};

template <>
struct action<parse::close_bracket> {
    template <typename ParseInput>
    static void apply(const ParseInput &in, std::vector<int> &v) {
        // log(color::Yellow("Found closing bracket"));
    }
};

} // namespace vector_parser

template <typename PathType>
std::ifstream load_input(PathType &&path) {
    std::ifstream ifs{std::filesystem::path{"../src/"} / path};
    if (!ifs) {
        throw FileStreamException(path);
    }
    return ifs;
}

template <typename T, typename PathType>
std::vector<T> read_vector(PathType &&path) {
    std::vector<T> ans;
    auto ifs = load_input(std::forward<PathType>(path));
    auto in = pegtl::istream_input(ifs, 4096, std::forward<PathType>(path));
    pegtl::parse<vector_parser::grammar, vector_parser::action>(in, ans);
    return ans;
}

} // namespace leet

#endif