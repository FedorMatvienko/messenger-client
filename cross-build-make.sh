BUILD=$PWD/.build-make
rm -rf $BUILD
mkdir -p $BUILD


make -f MakefileWin
# make -f MakefileWin clean