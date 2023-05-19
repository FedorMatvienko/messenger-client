# set(JSONCPP_INCLUDE_DIR "/usr/include/jsoncpp/json/" CACHE PATH "Path to jsoncpp include directory")
# set(JSONCPP_LIBRARY "/usr/lib/x86_64-linux-gnu/libjsoncpp.a" CACHE FILEPATH "Path to jsoncpp library")
# add_library(jsoncpp STATIC IMPORTED)
# include_directories(${JSONCPP_INCLUDE_DIR})
# set_target_properties(jsoncpp PROPERTIES IMPORTED_LOCATION ${JSONCPP_LIBRARY})

# Определение библиотек и опций компиляции
cmake_minimum_required( VERSION 3.8.0 )
set ( project client )
project ( ${project})
set(CMAKE_CXX_STANDARD 17)

add_executable( ${project} main.cpp )
# set(CMAKE_PREFIX_PATH /usr/lib/x86_64-linux-gnu)

include_directories("/home/fedor/iss/client-mes/dist/json")
find_library( JSONLIB NAMES libjsoncpp PATHS "/home/fedor/iss/client-mes/dist/" REGISTRY_VIEW BOTH)
find_library( GLFWLIB NAMES libglfw3 PATHS "/home/fedor/iss/client-mes/dist/" REGISTRY_VIEW BOTH)

# set(CMAKE_FIND_ROOT_PATH "/usr/lib/x86_64-linux-gnu/")
# find_package(jsoncpp CONFIG REQUIRED)
# set(SOURCE_CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH})
# set(CMAKE_PREFIX_PATH "/usr/lib/i386-linux-gnu/cmake/jsoncpp/;/usr/lib/x86_64-linux-gnu/cmake/jsoncpp/")
# find_package(jsoncpp CONFIG REQUIRED)
# set(CMAKE_PREFIX_PATH ${SOURCE_CMAKE_PREFIX_PATH})

# Создание dll библиотеки
# add_library(mylib SHARED "/usr/lib/x86_64-linux-gnu/libjsoncpp.a")
# set_target_properties(mylib PROPERTIES LINKER_LANGUAGE CXX)
# set_target_properties(mylib PROPERTIES LINKER_LANGUAGE C)
# set_target_properties(mylib PROPERTIES OUTPUT_NAME "mylib" SUFFIX ".dll")


target_link_libraries(${project} ${JSONLIB} ${GLFWLIB})
# target_link_libraries(${project} jsoncpp glfw)