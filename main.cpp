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
    
    // // Создание окна
    GLFWwindow* window = glfwCreateWindow(800, 600, "Мое окно", nullptr, nullptr);
    if (!window)
    {
        // Обработка ошибки создания окна
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Инициализация ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Настройка ImGui для работы с GLFW
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");



    // Основной цикл программы
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        // Обработка событий
        glfwPollEvents();

        // Начало нового кадра ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();    
        ImGui::NewFrame();

        // Создание пользовательского интерфейса ImGui
        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("Welcome to ImGui!");
        if (ImGui::Button("Click Me!"))
        {
        }



        ImGui::End();
                // Рендеринг ImGui
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        // Swap буферов
        glfwSwapBuffers(window);
    }
    
    // Очистка и выход из программы
    glfwTerminate();

    return 0;
}