
ALL_PROJECT_DIR=$PWD
function build_clean() {
  cd ${ALL_PROJECT_DIR}
  rm -rf build/ output/ deploy/ bin/
}

# 1. check clean
if [ $# -eq 1 ];then
  HOBOT_COMPILE_MODE=${1}
  if [ x"${HOBOT_COMPILE_MODE}" == x"clean" ];then
    build_clean
    exit
  fi
fi

function cmake_build() {
  mkdir build
  cd build
  cmake .. $*
  echo "##############################################"
  echo $1
  make -j16
  if [ $? -ne 0 ] ; then
    echo "failed to build"
    exit 1
  fi
  # make copy
#   make install
  cd ${ALL_PROJECT_DIR}
}

build_clean
cmake_build