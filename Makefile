CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -pedantic 
# Путь к заголовочным файлам jsoncpp
JSONCPP_INCLUDE=-I/home/fedor/iss/client-mes/json/include

# Путь к библиотеке jsoncpp
JSONCPP_LIB=-L/home/fedor/iss/client-mes/json/include nlohmann_json::nlohmann_json

# Имя исполняемого файла
TARGET=./buld-make/my_program

# Список исходных файлов
SRCS=main.cpp

# Список объектных файлов
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(JSONCPP_LIB)
	

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(JSONCPP_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)