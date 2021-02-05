#ifndef LEET_LOG
#define LEET_LOG

#include <iostream>

namespace leet {
namespace color {

enum class Color {
    red,
    green,
    yellow,
};

template <Color c>
struct ColorSpec {};

template <>
struct ColorSpec<Color::red> {
    static constexpr const char *const value = "0;31";
};

template <>
struct ColorSpec<Color::green> {
    static constexpr const char *const value = "0;32";
};

template <>
struct ColorSpec<Color::yellow> {
    static constexpr const char *const value = "0;33";
};

template <typename Printable, typename Derived>
struct ColorWrapper {
    const Printable &data;

    ColorWrapper(const Printable &p) : data(p) {}
    ~ColorWrapper() = default;

    friend std::ostream &operator<<(std::ostream &os, const Derived &p) {
        os << "\033[" << Derived::color_spec::value << "m" << p.data
           << "\033[0m";
        return os;
    }
};

template <typename Printable>
struct Red : ColorWrapper<Printable, Red<Printable>> {
    using color_spec = ColorSpec<Color::red>;
    Red(const Printable &p) : ColorWrapper<Printable, Red<Printable>>(p) {}
};

template <typename Printable>
struct Green : ColorWrapper<Printable, Green<Printable>> {
    using color_spec = ColorSpec<Color::green>;
    Green(const Printable &p) : ColorWrapper<Printable, Green<Printable>>(p) {}
};

template <typename Printable>
struct Yellow : ColorWrapper<Printable, Yellow<Printable>> {
    using color_spec = ColorSpec<Color::yellow>;
    Yellow(const Printable &p)
        : ColorWrapper<Printable, Yellow<Printable>>(p) {}
};

} // namespace color

template <typename... Args>
void log(Args &&... args) {
    (std::cout << ... << std::forward<Args>(args));
    std::cout << std::endl;
}

} // namespace leet

#endif