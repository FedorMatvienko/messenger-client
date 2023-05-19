BUILD=$PWD/.build
WIN=$PWD/toolchain-win.cmake
echo $WIN
rm -rf $BUILD
mkdir -p $BUILD

cd $BUILD

cmake -D CMAKE_TOOLCHAIN_FILE=$WIN \
      ../
cmake --build .

# cmake ..
# cmake --build .

./client