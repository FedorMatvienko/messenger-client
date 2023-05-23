#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#ifdef UBUNTU
    #include <jsoncpp/json/json.h>
    #include <GLFW/glfw3.h>
#endif
#ifdef WINDOWS
    #include <glfw3.h>
    #include <json.h>
#endif