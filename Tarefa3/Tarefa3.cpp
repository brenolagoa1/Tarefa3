#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Vertex {
    float x, y, z;
};

struct Face {
    int v1, v2, v3;
};

class ObjModel {
public:
    std::vector<Vertex> vertices;
    std::vector<Face> faces;

    void LoadModel(const std::string& filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
            return;
        }

        std::string line;

        while (std::getline(file, line)) {
            if (line.substr(0, 2) == "v ") {
                Vertex vertex;
                if (sscanf_s(line.c_str(), "v %f %f %f", &vertex.x, &vertex.y, &vertex.z) == 3) {
                    vertices.push_back(vertex);
                }
                else {
                    std::cerr << "Erro ao analisar a linha: " << line << std::endl;
                }
            }
            else if (line.substr(0, 2) == "f ") {
                Face face;
                if (sscanf_s(line.c_str(), "f %d %d %d", &face.v1, &face.v2, &face.v3) == 3) {
                    faces.push_back(face);
                }
                else {
                    std::cerr << "Erro ao analisar a linha: " << line << std::endl;
                }
            }

        }

        file.close();
    }
};

int main() {
    ObjModel model;
    model.LoadModel("C:\\Users\\lagoa\\source\\repos\\Tarefa3\\wooden_sphere.obj");

    for (const Vertex& vertex : model.vertices) {
        std::cout << "Vertex: (" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")\n";
    }

    for (const Face& face : model.faces) {
        std::cout << "Face: (" << face.v1 << ", " << face.v2 << ", " << face.v3 << ")\n";
    }

    return 0;
}