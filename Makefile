STB_INCLUDE_PATH = include

RELEASE_CFLAGS = -std=c++17 -O3 -DNDEBUG=1 -I$(STB_INCLUDE_PATH)
CFLAGS = -std=c++17 -O2 -I$(STB_INCLUDE_PATH)
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

DrawingTriangle: main.cpp
	g++ $(CFLAGS) -o bin/DrawingTriangle main.cpp $(LDFLAGS)

CompileShaders: shaders/shader.vert shaders/shader.frag
	glslc shaders/shader.vert -o shaders/vert.spv
	glslc shaders/shader.frag -o shaders/frag.spv

Release: main.cpp
	g++ $(RELEASE_CFLAGS) -o bin/DrawingTriangle main.cpp $(LDFLAGS)

.PHONY: test clean

test: DrawingTriangle CompileShaders
	./bin/DrawingTriangle

clean:
	rm -f bin/DrawingTriangle
	rm -f shaders/*.spv