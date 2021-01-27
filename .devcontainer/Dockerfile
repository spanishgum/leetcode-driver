FROM ubuntu:18.04

RUN apt-get update && apt-get install -y \
  git \
  xz-utils \
  build-essential \
  curl \
  libssl-dev \
  && rm -rf /var/lib/apt/lists/* \
  && curl -SL https://github.com/llvm/llvm-project/releases/download/llvmorg-10.0.0/clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz \
  | tar -xJC . && \
  mv clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04 clang_10.0.0 && \
  echo 'export PATH=/clang_10.0.0/bin:$PATH' >> ~/.bashrc && \
  echo 'export LD_LIBRARY_PATH=/clang_10.0.0/lib:$LD_LIBRARY_PATH' >> ~/.bashrc


RUN curl -L -O -J https://github.com/Kitware/CMake/releases/download/v3.19.3/cmake-3.19.3.tar.gz \
  && tar xf cmake-3.19.3.tar.gz \
  && cd cmake-3.19.3 \
  && ./bootstrap -- -DCMAKE_BUILD_TYPE:STRING=Release \
  && make \
  && make install \
  && cd .. \
  && rm -rf cmake-3.19.3 cmake-3.19.3.tar.gz

# Start from a Bash prompt
CMD [ "/bin/bash" ]