#pragma once
#include <cmath>
#include <ostream>

template <typename T>
class Vector2D
{
public:
	//public member data
	T x, y;
	
	Vector2D() : x(T()), y(T()) {};

	Vector2D(T x, T y) : x(x), y(y) {};

	Vector2D(const Vector2D& other) = default;

	Vector2D& operator= (const Vector2D& other) = default;
	
	~Vector2D() {};

	T Vlen() const {
		return sqrt(x * x + y * y);
	};
	
	T VlenSq() const {
		return x * x + y * y;
	};

	T length_along(const Vector2D& v) const {
		return (*this) * v / v.Vlen();
	};

	void normalize() {
		double len = Vlen();
		if (len == 0.0) {
			return;
		}		
		x /= len;
		y /= len;
	};
	
	void rotate(T angle) {
		double costheta = cos(angle);
		double sintheta = sin(angle);
		x = x * costheta - y * sintheta;
		y = x * sintheta + y * costheta;
	};	

	Vector2D rotated(T angle) const {
		double costheta = cos(angle);
		double sintheta = sin(angle);
		double x = this->x * costheta - this->y * sintheta;
		double y = this->x * sintheta + this->y * costheta;
		return Vector2D(x, y);
	};

	Vector2D operator+ (const Vector2D& v) const {
		return Vector2D(x + v.x, y + v.y);
	};

	Vector2D& operator+= (const Vector2D& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	
	Vector2D operator- (const Vector2D& v) const {
		return Vector2D(this.x - v.x, this.y - v.y);
	}; 

	Vector2D operator-= (const Vector2D& v) const {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	
	T operator* (const Vector2D& v) const {
		return x * v.x + y * v.y;
	};
	
	Vector2D operator* (T s) const {
		return Vector2D(x * s, y * s);
	};

	Vector2D& operator*= (T s) {
		x *= s;
		y *= s;
		return *this;
	};

	Vector2D operator/ (T s) const {
		return Vector2D(x / s, y / s);
	};

	Vector2D& operator/= (T s) {
		x /= s; 
		y /= s;
		return *this;
	};

	friend Vector2D operator* (T s, const Vector2D& v) {
		return Vector2D(s * v.x, s * v.y);
	};  

	template<typename U>
	explicit operator Vector2D<U>() {
		return Vector2D<U>(static_cast<U>(this->x), static_cast<U>(this->y));
	}

	bool operator== (const Vector2D<T>& v) const {
		return x == v.x && y == v.y;
	}

	bool operator!= (const Vector2D<T>& v) const {
		return !operator==(v);
	}

};

template <typename T>
std::ostream& operator << (std::ostream& outs, const Vector2D<T>& v) {
	return outs << "(" << v.x << ", " << v.y << ")";
}

template <typename T>
std::string to_string(const Vector2D<T>& v) {
	return "(" + v.x + ", " + v.y + ")";
}