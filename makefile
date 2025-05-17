CXX = g++
CXXFLAGS = -Wall -O2
LDFLAGS = -lfreeglut -lopengl32 -lglu32 -lwinmm -lgdi32

SRCS = main.cpp imageloader.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = opengl_rumah_adat_bengkulu

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
