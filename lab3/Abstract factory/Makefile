CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Исполняемый файл
TARGET = movie_rental

# Исходные файлы
SOURCES = main.cpp

# Объектные файлы
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)