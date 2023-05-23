# Примеры запуска:
# ./cross-build.sh - сборка для Ubuntu
# WINDOWS=1 ./cross-build.sh - сборка для Windows

BUILD=$PWD/.build
WIN=$PWD/toolchain-win.cmake

rm -rf $BUILD
mkdir -p $BUILD
cd $BUILD

# Сборка проекта
if [ "${WINDOWS:-}" ]; then
      echo build for Windows
      cmake -D CMAKE_TOOLCHAIN_FILE=$WIN \
      ..\
      -D BUILD_TYPE=Windows
      cmake --build .
else
      echo build for Ubuntu
      cmake ..
      cmake --build .
fi

# Сборка файлов
if [ "${WINDOWS:-}" ]; then
      mkdir Windows
      cp ../client.json ./Windows
      mv client.exe ./Windows
else
      mkdir Ubuntu
      cp ../client.json ./Ubuntu
      mv client ./Ubuntu
      cd Ubuntu 
      ./client
fi