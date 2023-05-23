#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <GLFW/glfw3.h>
#ifdef UBUNTU
    #include <jsoncpp/json/json.h>
    #include "libraries/imgui/imgui.h"
    #include "libraries/imgui/imgui_impl_glfw.h"    
#endif
#ifdef WINDOWS
    #include <json.h>
    #include <imgui.h>
    #include <imgui_impl_glfw.h>
#endif