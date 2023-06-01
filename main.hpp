#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>


#ifdef UBUNTU
    #include <jsoncpp/json/json.h>
    #include "libraries/imgui/imgui.h"
    #include "libraries/imgui/imgui_impl_glfw.h"    
    #include "libraries/imgui/imgui_impl_opengl3.h"
    //Файлы для работы с сокетами
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <string.h>

#endif
#ifdef WINDOWS
    #include <JSON/json.h>
    #include <imgui.h>
    #include <imgui_impl_glfw.h>
    #include <imgui_impl_opengl3.h>
     //Файлы для работы с сокетами 
    #include <winsock2.h>
    #include <windows.h>
#endif