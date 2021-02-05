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