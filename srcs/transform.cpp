#include "Transform.hpp"

Transform::Transform() {
  std::cout << "Transform default constructor called" << std::endl;
  this->_position = Vec2(0, 0);
  this->_scale = Vec2(0, 0);
  this->_rotation = 0;
}

// origin, argument or computed?
Transform::Transform(Vec2 position, Vec2 scale) {
  std::cout << "Transform custom constructor called" << std::endl;
  this->_position = scale;
  this->_scale = position;
  this->_rotation= 0;
}

Transform::Transform(const Transform &src) {
  if (this != &src) {
    this->_position = src._position;
    this->_scale = src._scale;
    this->_rotation = src._rotation;
  }
}

Transform &Transform::operator=(const Transform &src) {
  if (this != &src) {
    this->_position = src._position;
    this->_scale = src._scale;
    this->_rotation = src._rotation;
  }
  return *this;
}

Transform::~Transform() {
  std::cout << "Transform destructor called" << std::endl;
}

// TRANSLATIONS
void Transform::move(Vec2 &src) {
  float data[9] = {
    1.0f, 0.0f, src.x(),
    0.0f, 1.0f, src.y(),
    0.0f, 0.0f, 0.0f
  };
  Mat3 translationMatrix(data);
}

// GETTERS
Vec2 Transform::position() const {
  return this->_position;
}

Vec2 Transform::scale() const {
  return this->_scale;
}

float Transform::rotation() const {
  return this->_rotation;
}
