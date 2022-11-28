#!/usr/bin/env bash

set -e

TMP_PATH="/tmp"
DEST_PATH="output"

mkdir -p "${DEST_PATH}"

curl -sLO "https://github.com/fbelavenuto/arpl/raw/main/PLATFORMS"

function compileLkm() {
  PLATFORM=$1
  KVER=$2
  OUT_PATH="${TMP_PATH}/${PLATFORM}"
  VER="7.1"
  mkdir -p "${OUT_PATH}"
  # Compile using docker
  docker run --rm -t -v "${OUT_PATH}":/output -v "${PWD}":/input \
    fbelavenuto/syno-toolkit:${PLATFORM}-${VER} compile-lkm
  mv "${OUT_PATH}/redpill-dev.ko" "${DEST_PATH}/rp-${PLATFORM}-${KVER}-dev.ko"
  rm -f "${DEST_PATH}/rp-${PLATFORM}-${KVER}-dev.ko.gz"
  gzip "${DEST_PATH}/rp-${PLATFORM}-${KVER}-dev.ko"
  mv "${OUT_PATH}/redpill-prod.ko" "${DEST_PATH}/rp-${PLATFORM}-${KVER}-prod.ko"
  rm -f "${DEST_PATH}/rp-${PLATFORM}-${KVER}-prod.ko.gz"
  gzip "${DEST_PATH}/rp-${PLATFORM}-${KVER}-prod.ko"
  rm -rf "${OUT_PATH}"
}

# Main
while read PLATFORM KVER; do
  compileLkm "${PLATFORM}" "${KVER}" &
done < PLATFORMS
wait