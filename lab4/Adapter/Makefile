CC = g++
CFLAGS = -Wall -std=c++11

SRCS = main.cpp GasCylinder.cpp GasAdapter.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = GasApp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)