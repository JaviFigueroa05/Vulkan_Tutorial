CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

DrawingTriangle: main.cpp
	g++ $(CFLAGS) -o DrawingTriangle main.cpp $(LDFLAGS)

.PHONY: test clean

test: DrawingTriangle
	./DrawingTriangle

clean:
	rm -f DrawingTriangle