FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
	autoconf automake autotools-dev curl python3 python3-pip python3-tomli libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev libpixman-1-dev device-tree-compiler expect vim \
	&& rm -rf /var/lib/apt/lists/*

