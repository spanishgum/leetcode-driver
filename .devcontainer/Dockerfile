FROM ubuntu:18.04

RUN apt-get update -y && apt-get install -y git wget software-properties-common

RUN wget https://apt.llvm.org/llvm.sh \
  && chmod +x llvm.sh
  && ./llvm.sh 10

RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null \
  | gpg --dearmor - \
  | tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null \
  && apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main' \
  && apt-get update -y \
   && DEBIAN_FRONTEND=noninteractive apt-get install -y cmake

# Start from a Bash prompt
CMD [ "/bin/bash" ]
