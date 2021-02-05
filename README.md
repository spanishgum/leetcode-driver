# leetcode-driver

A devcontainer driven repo to test leetcode problems on the fly in C++.

## Setup

I use vscode + microsoft remote container extension. I haven't tested anywhere else.

This depends on `C++17` with a `filesystem` built in.

To use this outside of the devcontainer environment, you will probably have to tweak the cmake file.

If you want to see how the environment is set up, take a look at `.devcontainer/Dockerfile`.

## Building

Currently depends on `taocpp/PEGTL`. I didn't set up git submodules or CMake fanciness. Instead I added a script to clone into a folder which is added to cmake via `add_subdirectory`:

```bash
./get_pegtl.sh
```

The project uses cmake:

```bash
mkdir build && cd build
cmake ..
make
```

Then run with `./leet`!


## Usage

To leet, look at `src/questions/example`.

The idea is that you use the typicaly leetcode structure but with my include:

```c++
#include "leet.hpp"

class Solution {
  public:
    int array_sum(const vector<int> &nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0);
    }
};
```

To "drive" each problem, you will have to change `src/main.cpp`. Literally all it does is this:

```c++
#include "questions/example/solution.hpp"

int main() { Solution::test(); }
```

Just change the include to your solution.


For this to work though, obviously you need `Solution::test()`.

This can do whatever you want. I've provided `leet::test(...)` and `leet::expect(...)`, but these are experimental. I'm still in the tinkering phase.