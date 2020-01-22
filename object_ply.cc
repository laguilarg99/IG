#include "object_ply.h"
#include "file_ply_stl.h"

Object_Ply::Object_Ply(float size)
{
    _file_ply file;

    if (file.open("../skeleton/beethoven.ply")){
      file.read(this->Vertices,this->Triangles);
      std::cout << "File read correctly" << std::endl;
    }

    else std::cout << "File can't be opened" << std::endl;
    this->calculaNormales();

}
