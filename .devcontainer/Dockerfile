FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
  git \
  xz-utils \
  build-essential \
  curl \
  && rm -rf /var/lib/apt/lists/* \
  && curl -SL https://github.com/llvm/llvm-project/releases/download/llvmorg-10.0.0/clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz \
  | tar -xJC . && \
  mv clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04 clang_10.0.0 && \
  echo 'export PATH=/clang_10.0.0/bin:$PATH' >> ~/.bashrc && \
  echo 'export LD_LIBRARY_PATH=/clang_10.0.0/lib:$LD_LIBRARY_PATH' >> ~/.bashrc

RUN curl -L -O -J http://www.cmake.org/files/v3.2/cmake-3.2.2.tar.gz \
  && tar xf cmake-3.2.2.tar.gz \
  && cd cmake-3.2.2 \
  && ./configure \
  && make -j \
  && make install \
  && cd .. \
  && rm -rf cmake-3.2.2 \
  && rm cmake-3.2.2 cmake-3.2.2.tar.gz

# Start from a Bash prompt
CMD [ "/bin/bash" ]