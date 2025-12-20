CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = calorie_app
SRCS = main.cpp
HEADERS = Enums.h BodyTypes.h BMRCalculator.h NutritionFacade.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)