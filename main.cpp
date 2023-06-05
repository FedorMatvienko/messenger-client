#include "main.hpp"
using namespace std;
class ConsoleCP
{
    int oldin;
    int oldout;

public:
    ConsoleCP(int cp)
    {
        oldin = GetConsoleCP();
        oldout = GetConsoleOutputCP();
        SetConsoleCP(cp);
        SetConsoleOutputCP(cp);
    }

    // поскольку мы изменили свойства внешнего объекта — консоли, нам нужно
    // вернуть всё как было (если программа вылетит, пользователю не повезло)
    ~ConsoleCP()
    {
        SetConsoleCP(oldin); 
        SetConsoleOutputCP(oldout);
    }
};
int main()
{   
    ios_base::sync_with_stdio(false);
    std::string local = std::setlocale(LC_ALL, "");
    ConsoleCP cp(1251);

    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddress;
    wchar_t buffer[1024];
    std::wstring s = L"";

    // Инициализация Winsock
    if ( WSAStartup(MAKEWORD(2, 2), &wsaData) != 0 )
    {
        std::wcout << L"Ошибка инициализации Winsock" << std::endl;
        return 1;
    }
    else
    {
        std::wcout << L"Сокет инициализирован" << std::endl;
    }

    // Создание сокета для клиента
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        std::wcout << L"Ошибка создания сокета" << std::endl;
        return 1;
    }
    else
    {
        std::wcout << L"Сокет создан" << std::endl;
    }

    // Настройка адреса сервера
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("10.4.2.160");  // Адрес сервера
    serverAddress.sin_port = htons(8080);  // Порт сервера

    // Подключение к серверу
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::wcout << L"Ошибка подключения к серверу" << std::endl;
        closesocket(clientSocket);
        return 1;
    }
    else
    {
        std::wcout << L"Есть подключение к серверу" << std::endl;
    }


    // Отправка данных серверу
    const wchar_t* message = L"Привет, сервер!";
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    while ( s != L"--exit" )
    {
        std::string str;
        std::getline(std::wcin, s);
        str = converter.to_bytes(s);
        print_code(str);
        print_wcode(s);
        if ( send(clientSocket, str.c_str(), str.size(), 0) < 0 )
        {
            break;
        }
    }

    // Закрытие сокета и очистка Winsock
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
/*int main()
{
    Json::Value config;
    std::filesystem::path path = std::filesystem::current_path() / "client.json";
    cout << path << endl;
    std::ifstream file_json(path.string());
    file_json >> config;
    string s1 = config["first"].asString();
    string s2 = config["second"].asString();
    cout << s1 << " " << s2 << endl;

    
 


    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddress;
    char buffer[1024];
    string s = "";

    // Инициализация Winsock
    if ( WSAStartup(MAKEWORD(2, 2), &wsaData) != 0 )
    {
        cout << "Ошибка инициализации Winsock" << endl;
        return 1;
    }
    else
    {
        cout << "Сокет инициализирован" << endl;
    }

    // Создание сокета для клиента
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        cout << "Ошибка создания сокета" << endl;
        return 1;
    }
    else
    {
        cout << "Сокет создан" << endl;
    }

    // Настройка адреса сервера
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("10.4.2.160");  // Адрес сервера
    serverAddress.sin_port = htons(8080);  // Порт сервера

    // Подключение к серверу
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        cout << "Ошибка подключения к серверу" << endl;
        closesocket(clientSocket);
        return 1;
    }
    else
    {
        cout << "Есть подключение к серверу" << endl;
    }

    printf("Подключено к серверу.\n");

    // Отправка данных серверу
    const char* message = "Привет, сервер!";
    while ( s != "--exit" )
    {
        std::getline(std::cin, s);
        if ( send(clientSocket, s.c_str(), s.size(), 0) < 0 )
        {
            break;
        }
    }


    // Получение ответа от сервера
    int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead <= 0) {
        printf("Ошибка получения данных.\n");
        closesocket(clientSocket);
        return 1;
    }

    printf("Получено от сервера: %.*s\n", bytesRead, buffer);

    // Закрытие сокета и очистка Winsock
    closesocket(clientSocket);
    WSACleanup();
*/
/*
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "Hello from client";
    char* exit_f = "-exit";
    string s = "";
    char buffer[1024] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
  
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if ( inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0 )
    {
        return -1;
    }
  
    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    while ( s != "--exit" )
    {
        std::getline(std::cin, s);
        send(client_fd, s.c_str(), s.size(), 0);
    }
    // closing the connected socket
    close(client_fd);
*/


    // // Инициализация GLFW
    // if (!glfwInit()) {
    //     // Обработка ошибки инициализации GLFW
    //     return -1;
    // }
    
    // // // Создание окна
    // GLFWwindow* window = glfwCreateWindow(800, 600, "Мое окно", nullptr, nullptr);
    // if (!window)
    // {
    //     // Обработка ошибки создания окна
    //     glfwTerminate();
    //     return -1;
    // }
    // glfwMakeContextCurrent(window);

    //     // Инициализация GLEW
    // if (glewInit() != GLEW_OK) {
    //     std::cout << "Failed to initialize GLEW" << std::endl;
    //     glfwTerminate();
    //     return 0;
    // }

    // // Инициализация ImGui
    // IMGUI_CHECKVERSION();
    // ImGui::CreateContext();

    // // Настройка ImGui для работы с GLFW
    // ImGui_ImplGlfw_InitForOpenGL(window, true);
    // ImGui_ImplOpenGL3_Init("#version 130");



    // // Основной цикл программы
    // while (!glfwWindowShouldClose(window)) {
    //     glClear(GL_COLOR_BUFFER_BIT);
    //     // Обработка событий
    //     glfwPollEvents();

    //     // Начало нового кадра ImGui
    //     ImGui_ImplOpenGL3_NewFrame();
    //     ImGui_ImplGlfw_NewFrame();    
    //     ImGui::NewFrame();

    //     // Создание пользовательского интерфейса ImGui
    //     ImGui::Begin("Hello, ImGui!");
    //     ImGui::Text("Welcome to ImGui!");
    //     if (ImGui::Button("Click Me!"))
    //     {
    //     }



    //     ImGui::End();
    //             // Рендеринг ImGui
    //     ImGui::Render();
    //     ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
    //     // Swap буферов
    //     glfwSwapBuffers(window);
    // }
    
    // // Очистка и выход из программы
    // glfwTerminate();

//     return 0;
// }