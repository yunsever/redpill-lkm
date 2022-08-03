#!/usr/bin/env bash

set -e

TMP_PATH="/tmp"
DEST_PATH="output"

mkdir -p "${DEST_PATH}"

curl -LO "https://github.com/fbelavenuto/arpl/raw/main/PLATFORMS"

# Main
while read PLATFORM KVER; do
# Compile using docker
  docker run --rm -t --user `id -u` -v "${TMP_PATH}":/output \
    -v "${PWD}":/input fbelavenuto/syno-compiler compile-lkm ${PLATFORM}
  mv "${TMP_PATH}/redpill-dev.ko" "${DEST_PATH}/rp-${PLATFORM}-${KVER}-dev.ko"
  rm -f "${DEST_PATH}/rp-${PLATFORM}-${KVER}-dev.ko.gz"
  gzip "${DEST_PATH}/rp-${PLATFORM}-${KVER}-dev.ko"
  mv "${TMP_PATH}/redpill-prod.ko" "${DEST_PATH}/rp-${PLATFORM}-${KVER}-prod.ko"
  rm -f "${DEST_PATH}/rp-${PLATFORM}-${KVER}-prod.ko.gz"
  gzip "${DEST_PATH}/rp-${PLATFORM}-${KVER}-prod.ko"
done < PLATFORMS
