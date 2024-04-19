#define TINYOBJLOADER_IMPLEMENTATION
#include "build/_deps/tinyobjloader-src/tiny_obj_loader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "build/_deps/stb-src/stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>

#include <unordered_map>


#include "include/MyRenderer.hpp"

template <> struct std::hash<Vertex>
{
    size_t operator()(Vertex const &vertex) const
    {
        return ((std::hash<glm::vec3>()(vertex.pos) ^ (std::hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^ (std::hash<glm::vec2>()(vertex.texCoord) << 1);
    }
};

Object::Object(std::string meshPath, std::string texturePath)
{
    this->meshPath = meshPath;
    this->texturePath = texturePath;
    loadMesh();
    loadTexture();
}

void Object::loadMesh()
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::unordered_map<Vertex, uint32_t> uniqueVertices{};
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, meshPath.c_str()))
    {
        throw std::runtime_error("Failed to open mesh file!");
    }

    for (const auto &shape : shapes)
    {
        for (const auto &index : shape.mesh.indices)
        {
            Vertex vertex{};
            vertex.pos = {
                attrib.vertices[3 * index.vertex_index + 0],
                attrib.vertices[3 * index.vertex_index + 1],
                attrib.vertices[3 * index.vertex_index + 2]};
            vertex.texCoord = {
                attrib.texcoords[2 * index.texcoord_index + 0],
                1.0f - attrib.texcoords[2 * index.texcoord_index + 1]};
            vertex.color = {1.0f, 1.0f, 1.0f};

            if (uniqueVertices.count(vertex) == 0)
            {
                uniqueVertices[vertex] = static_cast<uint32_t>(mesh.vertices.size());
                mesh.vertices.push_back(vertex);
            }

            mesh.indices.push_back(uniqueVertices[vertex]);
        }
    }
    meshPath = meshPath;
}

void Object::loadTexture() {
    texture.channels = STBI_rgb_alpha;
    texture.pixels = stbi_load(texturePath.c_str(), &texture.width, &texture.height, nullptr, STBI_rgb_alpha);
    if (!texture.pixels)
    {
        throw std::runtime_error("failed to load texture image!");
    }
}

Object::~Object() {
    stbi_image_free(texture.pixels);
}

Mesh Object::getMesh()
{
    return mesh;
}

Texture Object::getTexture()
{
    return texture;
}
