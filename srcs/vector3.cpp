#include "Vector3.hpp"
#include <cmath>

Vec3::Vec3() {
  std::cout << "Vec3 default constructor called" << std::endl;
  this->_x = 0;
  this->_y = 0;
  this->_z = 0;
}

Vec3::Vec3(float x, float y, float z) {
  std::cout << "Vec3 custom constructor called" << std::endl;
  this->_x = x;
  this->_y = y;
  this->_z = z;
}

Vec3::Vec3(float n) {
  std::cout << "Vec3 simple constructor called" << std::endl;
  this->_x = n;
  this->_y = n;
  this->_z = n;
}

Vec3::Vec3(const Vec3 &src) {
  std::cout << "Vec3 copy constructor called" << std::endl;
  this->_x = src._x;
  this->_y = src._y;
  this->_z = src._z;
}

Vec3::~Vec3() {
  std::cout << "Vec3 destructor called" << std::endl;
}

// OPERATORS
Vec3 &Vec3::operator=(const Vec3 &src) {
  if (this != &src) {
    this->_x = src._x;
    this->_y = src._y;
    this->_z = src._z;
  }
  return *this;
}

Vec3 Vec3::operator+(const Vec3 &src) const {
  Vec3 result;
  result._x = this->_x + src._x;
  result._y = this->_y + src._y;
  result._z = this->_z + src._z;
  return result;
}

Vec3 Vec3::operator+(float n) const {
  Vec3 result;
  result._x = this->_x + n;
  result._y = this->_y + n;
  result._z = this->_z + n;
  return result;
}

Vec3 &Vec3::operator+=(const Vec3 &src) {
  this->_x += src._x;
  this->_y += src._y;
  this->_z += src._z;
  return *this;
}

Vec3 &Vec3::operator+=(float n) {
  this->_x += n;
  this->_y += n;
  this->_z += n;
  return *this;
}

Vec3 Vec3::operator-(const Vec3 &src) const {
  Vec3 result;
  result._x = this->_x - src._x;
  result._y = this->_y - src._y;
  result._z = this->_z - src._z;
  return result;
}

Vec3 Vec3::operator-(float n) const {
  Vec3 result;
  result._x = this->_x + n;
  result._y = this->_y + n;
  result._z = this->_z + n;
  return result;
}

Vec3 &Vec3::operator-=(const Vec3 &src) {
  this->_x -= src._x;
  this->_y -= src._y;
  this->_z -= src._z;
  return *this;
}

Vec3 &Vec3::operator-=(float n) {
  this->_x -= n;
  this->_y -= n;
  this->_z -= n;
  return *this;
}

Vec3 Vec3::operator*(const Vec3 &src) const {
  Vec3 result;
  result._x = this->_x * src._x;
  result._y = this->_y * src._y;
  result._z = this->_z * src._z;
  return result;
}

Vec3 Vec3::operator*(float n) const {
  Vec3 result;
  result._x = this->_x * n;
  result._y = this->_y * n;
  result._z = this->_z * n;
  return result;
}

Vec3 &Vec3::operator*=(const Vec3 &src) {
  this->_x *= src._x;
  this->_y *= src._y;
  this->_z *= src._z;
  return *this;
}

Vec3 &Vec3::operator*=(float n) {
  this->_x *= n;
  this->_y *= n;
  this->_z *= n;
  return *this;
}

Vec3 Vec3::operator/(const Vec3 &src) const {
  Vec3 result;
  result._x = this->_x / src._x;
  result._y = this->_y / src._y;
  result._z = this->_z / src._z;
  return result;
}

Vec3 &Vec3::operator/=(const Vec3 &src) {
  this->_x /= src._x;
  this->_y /= src._y;
  this->_z /= src._z;
  return *this;
}

bool Vec3::operator==(const Vec3 &src) const {
  float tolerence = 0.000001f;
  bool x = fabsf(_x - src._x) <=(tolerence*fmaxf(1.0f, fmaxf(fabsf(_x), fabsf(src._x))));
  bool y = fabsf(_y - src._y) <=(tolerence*fmaxf(1.0f, fmaxf(fabsf(_y), fabsf(src._y))));
  bool z = fabsf(_z - src._z) <=(tolerence*fmaxf(1.0f, fmaxf(fabsf(_z), fabsf(src._z))));
  return (x && y && z);
}

std::ostream &operator<<(std::ostream &os, const Vec3 &src) {
  os << "(" << src.x() << ", " << src.y() << ", " << src.z() << ")";
  return os;
}


// MATHS
float Vec3::len() const {
  float result = sqrtf((_x * _x) + (_y * _y) + (_z * _z));
  return result;
}

float Vec3::lenSqr() const {
  float result = (_x * _x) + (_y * _y) + (_z * _z);
  return result;
}

Vec3 Vec3::crossProduct(Vec3 &src) const {
  Vec3 result;
  result._x = this->_y * src._z - this->_z * src._y;
  result._y = this->_z * src._x - this->_x * src._z;
  result._z = this->_x * src._y - this->_y * src._x;
  return result;
}

float Vec3::dotProduct(Vec3 &src) const {
  float result = (_x * src._x) + (_y * src._y) + (_z * src._z);
  return result;
}

float Vec3::distanceTo(Vec3 &src) const {
  float dx = _x - src._x;
  float dy = _y - src._y;
  float dz = _z - src._z;
  float result = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
  return result;
}

float Vec3::distanceToSqr(Vec3 &src) const {
  float dx = _x - src._x;
  float dy = _y - src._y;
  float dz = _z - src._z;
  float result = (dx * dx) + (dy * dy) + (dz * dz);
  return result;
}

float Vec3::angleWith(Vec3 &src) const {
  Vec3 cross = this->crossProduct(src);
  float cross_len = cross.len();
  float dot = this->dotProduct(src);
  float result = atan2f(cross_len, dot);
  return result;
}

Vec3 Vec3::negate() const {
  Vec3 result;
  result._x = -this->_x;
  result._y = -this->_y;
  result._z = -this->_z;
  return result;
}

Vec3 Vec3::normalize() const {
  Vec3 result;
  float len = this->len();
  if (len != 0.0f) {
    float ilen = 1.0f/len;
    result._x = this->_x * ilen;
    result._y = this->_y * ilen;
    result._z = this->_z * ilen;
  }
  return result;
}

// GETTERS
float Vec3::x() const {
  return this->_x;
}

float Vec3::y() const {
  return this->_y;
}

float Vec3::z() const {
  return this->_z;
}
