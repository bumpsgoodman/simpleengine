#include "Vector2.h"

Vector2::Vector2(int x, int y)
	: x(x)
	, y(y)
{

}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

Vector2& Vector2::operator*=(const Vector2& rhs)
{
	x *= rhs.x;
	y *= rhs.y;

	return *this;
}

Vector2& Vector2::operator/=(const Vector2& rhs)
{
	x /= rhs.x;
	y /= rhs.y;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	Vector2 result(x + rhs.x, y + rhs.y);
	return result;
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 result(x + rhs.x, y + rhs.y);
	return result;
}

Vector2 Vector2::operator+(int rval)
{
	Vector2 result(x + rval, y + rval);
	return result;
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
	Vector2 result(x - rhs.x, y - rhs.y);
	return result;
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 result(x - rhs.x, y - rhs.y);
	return result;
}

Vector2 Vector2::operator-(int rval)
{
	Vector2 result(x - rval, y - rval);
	return result;
}

Vector2 Vector2::operator*(const Vector2& rhs) const
{
	Vector2 result(x * rhs.x, y * rhs.y);
	return result;
}

Vector2 Vector2::operator*(const Vector2& rhs)
{
	Vector2 result(x * rhs.x, y * rhs.y);
	return result;
}

Vector2 Vector2::operator*(int rval)
{
	Vector2 result(x * rval, y * rval);
	return result;
}

Vector2 Vector2::operator/(const Vector2& rhs) const
{
	Vector2 result(x / rhs.x, y / rhs.y);
	return result;
}

Vector2 Vector2::operator/(const Vector2& rhs)
{
	Vector2 result(x / rhs.x, y / rhs.y);
	return result;
}

Vector2 Vector2::operator/(int rval)
{
	Vector2 result(x / rval, y / rval);
	return result;
}

bool Vector2::operator==(const Vector2& rhs) const
{
	return (x == rhs.x && y == rhs.y);
}

bool Vector2::operator==(const Vector2& rhs)
{
	return (x == rhs.x && y == rhs.y);
}

bool Vector2::operator!=(const Vector2& rhs) const
{
	return (x != rhs.x || y != rhs.y);
}

bool Vector2::operator!=(const Vector2& rhs)
{
	return (x != rhs.x || y != rhs.y);
}

const Vector2& Vector2::ZeroVector()
{
	static Vector2 zero(0, 0);
	return zero;
}