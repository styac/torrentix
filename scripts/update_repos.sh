#!/bin/bash

# here we should be in torrentix/scripts
THIS=$(basename $(pwd))
if [[ ${THIS} == 'scripts' ]]
then
    cd ..
fi

declare -r HERE=$(pwd)
declare -r REPO="${HERE}/repo"



echo "update libtorrent"
if [[ ! -f "${REPO}/libtorrent/CMakeLists.txt" ]]
then
    mkdir -p ${REPO}
    cd ${REPO}
    git clone --recursive https://github.com/arvidn/libtorrent/
else
    cd ${REPO}/libtorrent
    git fetch origin
    git reset --hard origin/master
fi


echo "update qBittorrent"
if [[ ! -f "${REPO}/qBittorrent/CMakeLists.txt" ]]
then
    mkdir -p ${REPO}
    cd ${REPO}
    git clone https://github.com/qbittorrent/qBittorrent
else
    cd ${REPO}/qBittorrent
    git fetch origin
    git reset --hard origin/master
fi


echo "update i2pd"
if [[ ! -f "${REPO}/i2pd/build/CMakeLists.txt" ]]
then
    mkdir -p ${REPO}
    cd ${REPO}
    git clone https://github.com/PurpleI2P/i2pd
else
    cd ${REPO}/i2pd
    git fetch origin
    git reset --hard origin/master
fi


echo "update miniupnp"
if [[ ! -f "${REPO}/miniupnp/LICENSE" ]]
then
    mkdir -p ${REPO}
    cd ${REPO}
    git clone https://github.com/miniupnp/miniupnp
else
    cd ${REPO}/miniupnp
    git fetch origin
    git reset --hard origin/master
fi

# openssl
