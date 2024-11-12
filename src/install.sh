#!/bin/bash
set -eu

### GCC
sudo apt-get install -y "g++-14=${VERSION}"

### Libraries
sudo apt-get install -y build-essential
sudo apt-get install -y pigz
sudo apt-get install -y pbzip2

./sub-installers/abseil.sh
./sub-installers/AC-Library.sh
./sub-installers/Boost.sh
./sub-installers/Eigen.sh
./sub-installers/GMP.sh
./sub-installers/unordered_dense.sh

sudo apt-get remove -y build-essential
sudo apt-get remove -y pigz
sudo apt-get remove -y pbzip2
sudo apt-get autoremove -y
