CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

DrawingTriangle: main.cpp
	g++ $(CFLAGS) -o ../bin/DrawingTriangle main.cpp $(LDFLAGS)

.PHONY: test clean

test: DrawingTriangle
	./../bin/DrawingTriangle

clean:
	rm -f ../bin/DrawingTriangle