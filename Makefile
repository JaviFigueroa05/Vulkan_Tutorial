STB_INCLUDE_PATH = include

RELEASE_CFLAGS = -std=c++17 -O3 -DNDEBUG=1 -I$(STB_INCLUDE_PATH)
CFLAGS = -std=c++17 -O2 -I$(STB_INCLUDE_PATH)
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

Compute: Compute.cpp
	g++ $(CFLAGS) -o bin/Compute Compute.cpp $(LDFLAGS)

CompileComputeShaders: shaders/shader_compute.comp shaders/shader_compute.vert shaders/shader_compute.frag
	glslc shaders/shader_compute.comp -o shaders/comp.spv
	glslc shaders/shader_compute.vert -o shaders/vert.spv
	glslc shaders/shader_compute.frag -o shaders/frag.spv

ReleaseCompute: Compute.cpp
	g++ $(RELEASE_CFLAGS) -o bin/Compute Compute.cpp $(LDFLAGS)

testCompute: Compute CompileComputeShaders
	./bin/Compute

Graphics: Graphics.cpp
	g++ $(CFLAGS) -o bin/Graphics Graphics.cpp $(LDFLAGS)

CompileGrapicsShaders: shaders/shader.vert shaders/shader.frag
	glslc shaders/shader.vert -o shaders/vert.spv
	glslc shaders/shader.frag -o shaders/frag.spv

ReleaseGraphics: Graphics.cpp
	g++ $(RELEASE_CFLAGS) -o bin/Graphics Graphics.cpp $(LDFLAGS)

testGraphics: Graphics CompileGrapicsShaders
	./bin/Graphics

.PHONY: test clean

clean:
	rm -f bin/*
	rm -f shaders/*.spv