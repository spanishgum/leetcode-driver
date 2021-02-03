namespace leet {

template <typename Result, typename Callable>
bool expect(Result data, Callable func) {
    auto res = func() == data;
    return res;
}

} // namespace leet