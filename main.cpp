#include "main.hpp"

using namespace std;
int main()
{

    Json::Value config;
    std::filesystem::path path = std::filesystem::current_path() / "client.json";
    cout << path << endl;
    std::ifstream file_json(path.string());
    file_json >> config;
    string s1 = config["first"].asString();
    string s2 = config["second"].asString();
    cout << s1 << " " << s2 << endl;

    // Инициализация GLFW
    if (!glfwInit()) {
        // Обработка ошибки инициализации GLFW
        return -1;
    }
    
    // Создание окна
    GLFWwindow* window = glfwCreateWindow(800, 600, "Мое окно", nullptr, nullptr);
    if (!window) {
        // Обработка ошибки создания окна
        glfwTerminate();
        return -1;
    }
    
    // Основной цикл программы
    while (!glfwWindowShouldClose(window)) {
        // Обработка событий
        glfwPollEvents();
        
        // Ваш код отрисовки и обновления окна
        
        // Swap буферов
        glfwSwapBuffers(window);
    }
    
    // Очистка и выход из программы
    glfwTerminate();

    return 0;
}