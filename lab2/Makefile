CC = g++
CFLAGS = -Wall -std=c++11

# Список всех исходных файлов
SRCS = main.cpp person.cpp student.cpp teacher.cpp head_of_department.cpp lecture_hall.cpp
# Преобразование .cpp в .o
OBJS = $(SRCS:.cpp=.o)
# Имя исполняемого файла
TARGET = university_app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	