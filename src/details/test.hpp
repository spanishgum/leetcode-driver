#ifndef LEET_TEST
#define LEET_TEST

#include "details/log.hpp"

namespace leet {

template <typename... Expectations>
void test(Expectations &&... exps) {
    (
        [](auto &&exp) {
            log("\n---- TEST CASE ----");
            auto ans = exp.func();
            if (exp.data == ans) {
                log(color::Green("PASSED"));
            } else {
                log(color::Red("FAILED"));
            }
            log("expected: ", exp.data);
            log("got     : ", ans);
        }(exps),
        ...);
}

template <typename Result, typename Callable>
struct expect {
    Result data;
    Callable func;
    expect(Result data, Callable func) : data(data), func(func) {}
};

} // namespace leet

#endif