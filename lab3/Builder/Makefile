# Компилятор
CXX = g++

# Флаги компилятора
# -std=c++17: используем стандарт C++17
# -Wall: включаем все предупреждения
# -g: добавляем отладочную информацию
CXXFLAGS = -std=c++17 -Wall -g

# Имя исполняемого файла
TARGET = converter

# Исходные файлы
SRCS = main.cpp Article.cpp ArticleBuilder.cpp TxtReaderDirector.cpp

# Объектные файлы (генерируются из исходных)
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию: собрать всё
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Правило для компиляции .cpp файлов в .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки
clean:
	rm -f $(OBJS) $(TARGET)

# Сообщаем make, что 'all' и 'clean' - это не файлы
.PHONY: all clean