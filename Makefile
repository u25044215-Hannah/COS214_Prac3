CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g
TARGET = eventflow

SOURCES = \
	main.cpp \
	Subject.cpp \
	EventUnit.cpp \
	EventGroup.cpp \
	EventControl.cpp \
	Stage.cpp \
	FoodVendor.cpp \
	DrinkVendor.cpp \
	SecurityPost.cpp \
	MedicalUnit.cpp \
	EntranceGate.cpp \
	InfoPoint.cpp \
	CleaningTeam.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

docs:
	doxygen Doxyfile

.PHONY: all clean run docs
