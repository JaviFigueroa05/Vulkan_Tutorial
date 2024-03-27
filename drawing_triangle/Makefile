CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

DrawingTriangle: main.cpp
	g++ $(CFLAGS) -o ../bin/DrawingTriangle main.cpp $(LDFLAGS)

CompileShaders: shaders/triangle.vert shaders/triangle.frag
	glslc shaders/triangle.vert -o shaders/triangle.vert.spv
	glslc shaders/triangle.frag -o shaders/triangle.frag.spv

.PHONY: test clean

test: DrawingTriangle CompileShaders
	./../bin/DrawingTriangle

clean:
	rm -f ../bin/DrawingTriangle
	rm -f shaders/*.spv