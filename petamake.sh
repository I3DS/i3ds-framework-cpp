#!/bin/sh

ASN1CC_ROOT=$HOME/dl/asn1scc

BSP_NAME=i3ds_bsp
BSP_ROOT=/opt/bsp/$BSP_NAME/build/tmp/sysroots/plnx_aarch64

mkdir -p build_petalinux
cd build_petalinux
cmake .. -DCMAKE_C_COMPILER="aarch64-linux-gnu-gcc" \
      -DCMAKE_CXX_COMPILER="aarch64-linux-gnu-c++" \
      -DCMAKE_FIND_ROOT_PATH="$BSP_ROOT" \
      -DZMQHPP_INCLUDE_DIR=external \
      -DBUILD_EMBEDDED=ON \
      -DBUILD_TOOLS=OFF \
      -DBUILD_TESTS=OFF \
      -DASN1CC_SRC_ROOT_FOLDER=$ASN1CC_ROOT

make -j4

