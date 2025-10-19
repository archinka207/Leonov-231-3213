# Определяем имя исполняемого файла
TARGET = facultative_system

# Определяем директорию для сборки (объектные файлы и исполняемый файл)
BUILD_DIR = build

# Определяем компилятор C++
CXX = g++

# Определяем флаги компиляции
# -std=c++17: используем стандарт C++17
# -Wall: включаем все предупреждения
# -Wextra: включаем дополнительные предупреждения
# -g: включаем отладочную информацию
# -O2: оптимизация кода
# -I.: добавляем текущую директорию (.) в пути поиска заголовков
CXXFLAGS = -std=c++17 -Wall -Wextra -g -O2 -I.

# Определяем библиотеки
LDLIBS = -pthread

# Определяем все .cpp файлы в проекте
SRCS = IdGenerator.cpp Student.cpp Teacher.cpp Course.cpp Enrollment.cpp \
       StudentRepository.cpp TeacherRepository.cpp CourseRepository.cpp EnrollmentRepository.cpp \
       CourseManagementService.cpp EnrollmentService.cpp main.cpp

# Генерируем имена объектных файлов с префиксом BUILD_DIR
# Например, main.o станет build/main.o
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Имя исполняемого файла с указанием пути
EXECUTABLE = $(BUILD_DIR)/$(TARGET)

.PHONY: all clean run setup

# Цель 'all' - это цель по умолчанию
all: setup $(EXECUTABLE)

# Цель 'setup' для создания директории build, если она еще не существует
setup:
	@mkdir -p $(BUILD_DIR)

# Правило для сборки исполняемого файла
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDLIBS)

# Правило для компиляции каждого .cpp файла в соответствующий .o файл внутри BUILD_DIR
# Важно: используем автоматические переменные $< (первый элемент зависимости) и $@ (целевой файл)
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Цель 'run' для запуска программы после компиляции
run: all
	./$(EXECUTABLE)

# Цель 'clean' для удаления скомпилированных файлов и исполняемого файла
clean:
	rm -rf $(BUILD_DIR)