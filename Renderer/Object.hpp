#pragma once

#include <string>
#include <vector>

#include "Vertex.hpp"

struct Mesh {
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
};

struct Texture {
    int width;
    int height;
    int channels;
    unsigned char* pixels;
};

class Object {
private:
    std::string meshPath;
    Mesh mesh;
    void loadMesh();

    std::string texturePath;
    Texture texture;
    void loadTexture();
    
public:
    Object(std::string meshPath, std::string texturePath);
    ~Object();
    Mesh getMesh();
    Texture getTexture();
};