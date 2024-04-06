#pragma once

#include <string>
#include <vector>

#include "Vertex.hpp"

struct Mesh {
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
};

class Object {
private:
    std::string meshPath;
    Mesh mesh;
public:
    Object(std::string meshPath);
    ~Object();
    Mesh getMesh();
};