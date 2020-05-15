#pragma once

class Vector2 final
{
public:
	Vector2() = default;
	Vector2(int x, int y);
	Vector2(const Vector2&) = default;
	Vector2& operator=(const Vector2&) = default;
	~Vector2() = default;

	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);
	Vector2& operator*=(const Vector2& rhs);
	Vector2& operator/=(const Vector2& rhs);

	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator+(const Vector2& rhs);
	Vector2 operator+(int rval);

	Vector2 operator-(const Vector2& rhs) const;
	Vector2 operator-(const Vector2& rhs);
	Vector2 operator-(int rval);

	Vector2 operator*(const Vector2& rhs) const;
	Vector2 operator*(const Vector2& rhs);
	Vector2 operator*(int rval);

	Vector2 operator/(const Vector2& rhs) const;
	Vector2 operator/(const Vector2& rhs);
	Vector2 operator/(int rval);

	bool operator==(const Vector2& rhs) const;
	bool operator==(const Vector2& rhs);

	bool operator!=(const Vector2& rhs) const;
	bool operator!=(const Vector2& rhs);

	static const Vector2& ZeroVector();

public:
	int x = 0;
	int y = 0;
};