#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Transform.hpp"
#include "Matrix3.hpp"
#include <cassert>

void vector2_tests() {
  std::cout << "----------Starting Vec2 Tests-----------" << std::endl;
  Vec2 vDefault;
  Vec2 vGlobal(4);
  Vec2 vCustom(12, 4);
  assert(vDefault.x() == 0 && vDefault.y() == 0);
  std::cout << "Default Vec2: " << vDefault << std::endl;
  std::cout << "Global Vec2: " << vGlobal << std::endl;
  std::cout << "Custom Vec2: " << vCustom << std::endl;

  std::cout << "Len of " << vDefault << " = " << vDefault.len() << std::endl;
  std::cout << "Len of " << vGlobal << " = " << vGlobal.len() << std::endl;
  std::cout << "Len of " << vCustom << " = " << vCustom.len() << std::endl;
  
  std::cout << "Dot product of " << vDefault << " & " << vGlobal << " = " << vDefault.dotProduct(vGlobal) << std::endl;
  std::cout << "Dot product of " << vGlobal << " & " << vCustom << " = " << vGlobal.dotProduct(vCustom) << std::endl;
  
  std::cout << "Cross product of " << vDefault << " & " << vGlobal << " = " << vDefault.crossProduct(vGlobal) << std::endl;
  std::cout << "Cross product of " << vGlobal << " & " << vCustom << " = " << vGlobal.crossProduct(vCustom) << std::endl;

  std::cout << "Distance from " << vDefault << " to " << vGlobal << " = " << vDefault.distanceTo(vGlobal) << std::endl;
  std::cout << "Distance from " << vGlobal << " to " << vCustom << " = " << vGlobal.distanceTo(vCustom) << std::endl;

  std::cout << "Angle between " << vDefault << " and " << vGlobal << " = " << vDefault.angleWith(vGlobal) << std::endl;
  std::cout << "Angle between " << vGlobal << " and " << vCustom << " = " << vGlobal.angleWith(vCustom) << std::endl;
  std::cout << "Angle between " << vCustom<< " and " << vDefault<< " = " << vCustom.angleWith(vDefault) << std::endl;

}

void vector3_tests() {
  std::cout << "----------Starting Vec3 Tests-----------" << std::endl;
  Vec3 tmp;
  std::cout << "Default Vec3 values when not assigned, x: " << tmp.x() << ", y: " << tmp.y() << ", z: " << tmp.z() << std::endl;
}

void transform_tests() {
  std::cout << "----------Starting Transform Tests-----------" << std::endl;
  Transform tmp;
  std::cout << "Transform default values, position: " << tmp.position() << ", scale: " << tmp.scale() << ", rotation: " << tmp.rotation() << std::endl;
}

int main() {
  vector2_tests();
  std::cout << std::endl;
  vector3_tests();
  std::cout << std::endl;
  transform_tests();
  
  return 0;
}
