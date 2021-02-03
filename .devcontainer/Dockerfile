FROM ubuntu:20.04

RUN apt-get update -y \
  && DEBIAN_FRONTEND=noninteractive apt-get install -y git wget software-properties-common

RUN wget https://apt.llvm.org/llvm.sh \
  && chmod +x llvm.sh \
  && ./llvm.sh 10 \
  && apt-get update -y \
  && DEBIAN_FRONTEND=noninteractive apt-get install -y clang-format-10 clang-tidy-10

RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null \
  | gpg --dearmor - \
  | tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null \
  && apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main' \
  && apt-get update -y \
  && DEBIAN_FRONTEND=noninteractive apt-get install -y cmake

RUN apt-get update -y \
  && DEBIAN_FRONTEND=noninteractive apt-get install -y python-pip \
  && pip install conan

# Start from a Bash prompt
CMD [ "/bin/bash" ]
