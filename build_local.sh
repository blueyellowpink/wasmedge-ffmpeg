#!/bin/sh

export LLVM_DIR=$(brew --prefix)/opt/llvm/lib/cmake
export CC=$(brew --prefix)/opt/llvm/bin/clang
export CXX=$(brew --prefix)/opt/llvm/bin/clang++

echo $LLVM_DIR
echo $CC
echo $CXX

cmake -Bbuild \
      -Wno-unused-parameter \
      -GNinja \
      -DWASMEDGE_BUILD_TESTS=OFF \
      -DWASMEDGE_PLUGIN_FFMPEG=ON \
      -DFFMPEG_INCLUDE_DIR=$HOME/.ffmpeg/include \
      -DFFMPEG_LIB_DIR=$HOME/.ffmpeg/lib \
      .

cmake --build build
# sudo cmake --install build --prefix /usr/local
