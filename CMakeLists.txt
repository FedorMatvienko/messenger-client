
# Определение библиотек и опций компиляции
cmake_minimum_required( VERSION 3.8.0 )

# Получение значение из cross-build.sh, по умолчанию значение Ubuntu
set( BUILD_TYPE "Ubuntu" CACHE STRING "build type" )
set( UBUNTU )
set( WINDOWS )
# Установка стандарта для компилятора, чтобы программа видела стандарт +17
set( CMAKE_CXX_STANDARD 17 )
# Установка названия проекта
set ( project client )
project ( ${project} )

add_executable( ${project}
    main.cpp
    libraries/imgui/imgui_impl_opengl3.cpp
    libraries/imgui/imgui_draw.cpp
    libraries/imgui/imgui_impl_glfw.cpp
    libraries/imgui/imgui_tables.cpp
    libraries/imgui/imgui_widgets.cpp
    libraries/imgui/imgui.cpp
    )

if ( BUILD_TYPE STREQUAL "Windows")
    # Сборка для Windows
    add_compile_definitions( WINDOWS )
    # set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -municode")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -municode")
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/libraries/include")
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/libraries/imgui")
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".dll")
    find_library( JSONLIB NAMES libjsoncpp PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libraries" REGISTRY_VIEW BOTH )
    find_library( GLFWLIB NAMES glfw3 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libraries" REGISTRY_VIEW BOTH )
    find_library( OPENGLLIB NAMES opengl32 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libraries" REGISTRY_VIEW BOTH )
    find_library( GLEWLIB NAMES glew32 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/libraries" REGISTRY_VIEW BOTH )
    target_link_libraries(${project} PUBLIC ${JSONLIB} ${OPENGLLIB} ${GLFWLIB} ${GLEWLIB} ws2_32)
else()
    # Сборка для Ubuntu
    add_compile_definitions( UBUNTU )
    target_link_libraries(${project} jsoncpp glfw dl GL GLEW)
endif()
