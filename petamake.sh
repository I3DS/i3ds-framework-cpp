#!/bin/bash
set -e
BSP_PATH="/opt/bsp"
BSP_NAME="eross_v4"

if [[ "${BSP_NAME}" == "eross_v3" ]]; then
    source /opt/petalinux/2019.1/settings.sh
elif [[ "${BSP_NAME}" == "eross_v4" ]]; then
    source /opt/petalinux/2019.2/settings.sh
else
    echo "Unkonwn BSP"
    exit 0
fi
test -e${BSP_PATH}/$BSP_NAME/images/linux/sdk/environment-setup-aarch64-xilinx-linux || { echo "Could not find environment, has sdk (petalinux-build --sdk)  been generate?"; exit 1; }
source ${BSP_PATH}/$BSP_NAME/images/linux/sdk/environment-setup-aarch64-xilinx-linux
BSP_ROOT=${BSP_PATH}/$BSP_NAME/images/linux/sdk/sysroots/aarch64-xilinx-linux

BUILDPATH="petalinux_build"

mkdir -p ${BUILDPATH}
cd ${BUILDPATH}

cmake .. -DCMAKE_C_COMPILER="aarch64-xilinx-linux-gcc" \
      -DCMAKE_CXX_COMPILER="aarch64-xilinx-linux-g++" \
      -DBUILD_SYSROOT="${BSP_ROOT}" \
      -DBUILD_EMBEDDED=ON \
      -DBUILD_DEBUG=OFF \
      -DBUILD_TOOLS=ON \
      -DBUILD_TESTS=OFF \
      -DBUILD_BINDINGS=OFF \
      -DGENERATE_ASN=OFF \
      -DNO_OPENCV=OFF

test -z ${NUM_CPUS} && NUM_CPUS=$(grep ^cpu\ MHz /proc/cpuinfo | wc -l)
make -j${NUM_CPUS}
