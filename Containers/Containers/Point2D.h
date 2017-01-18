#ifndef __POINT2D__
#define __POINT2D__

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

#include <math.h>

template<class TYPE>
class Point2D
{
public:

	//--------------------------------
	//Constructors

	Point2D() : x(0), y(0)
	{}

	Point2D(const TYPE& x, const TYPE& y) : x(x), y(y)
	{}

	Point2D(const Point2D& p) : x(p.x), y(p.y)
	{}

	//--------------------------------
	//Setter

	const Point2D set(const TYPE& x, const TYPE& y)
	{
		this->x = x; this->y = y;
		return (*this);
	}

	//--------------------------------
	//Destructor

	virtual ~Point2D()
	{}

	//--------------------------------
	//Math

	Point2D operator+(const Point2D& p)const
	{
		return Point2D((x + p.x), (y + p.y));
	}

	Point2D operator-(const Point2D& p)const
	{
		return Point2D((x - p.x),(y - p.y));
	}

	Point2D operator*(const TYPE& f)const
	{
		return Point2D((x * f), (y * f));
	}

	Point2D operator/(const TYPE& f)const
	{
		return Point2D((x / f), (y / f));
	}

	const Point2D operator+=(const Point2D& p)
	{
		x += p.x; y += p.y;
		return (*this);
	}

	const Point2D operator-=(const Point2D& p)
	{
		x -= p.x; y -= p.y;
		return (*this);
	}

	const Point2D operator*=(const TYPE& f)
	{
		x *= f; y *= f;
		return (*this);
	}

	const Point2D operator/=(const TYPE& f)
	{
		x /= f; y /= f;
		return (*this);
	}

	//--------------------------------
	//Utils

	bool isZero()const
	{
		return (x == 0 && y == 0);
	}

	bool operator==(const Point2D& p)const
	{
		return (x == p.x && y == p.y);
	}

	bool operator!=(const Point2D& p)const
	{
		return (x != p.x || y != p.y);
	}

	const Point2D setZero()
	{
		x = y = 0;
		return (*this);
	}

	const Point2D negate()
	{
		x = -x; y = -y;
		return (*this);
	}

	//--------------------------------
	//Distances

	float distanceTo(const Point2D& p)const
	{
		return sqrtf(((x - p.x) * (x - p.x)) + ((y - p.y) * (y - p.y)));
	}

	float distanceToNoSqrt(const Point2D& p)const
	{
		return ((x - p.x) * (x - p.x)) + ((y - p.y) * (y - p.y));
	}

	float distanceToManhattan(const Point2D& p)const
	{
		return abs(p.x - x) + abs(p.y - y);
	}

	//--------------------------------
	//Vector

	float getModule()const
	{
		return distanceTo({ 0, 0 });
	}

	void normalize()
	{
		float module = getModule();
		if (module != 0)
		{
			x /= module;
			y /= module;
		}
		else
		{
			x = y = 0;
		}
	}

	const Point2D normalized()const //NOTE!!!
	{
		Point2D p(x, y);
		p.normalize();
		return p;
	}

	const Point2D getNormal()const
	{
		float module = getModule();
		if (module != 0)
			return ({ (x / module), (y / module) });
		else
			return ({ 0, 0 });
	}

	void setModule(const float& f)
	{
		normalize();

		x *= f;
		y *= f;
	}

	/** Return angle in radiants. */
	float getAngle()const
	{
		return atan2(x, y);
	}

	/** Return angle in degrees. */
	float getAngleDeg()const
	{
		return atan2(x, y) * RADTODEG;
	}

	/** Return direction angle in radiants. */
	float getDirectionAngle(const Point2D& p)
	{
		return atan2((x - p.x), (y - p.y));
	}

	/** Return direction angle in degrees. */
	float getDirectionAngleDeg(const Point2D& p)
	{
		return atan2((x - p.x), (y - p.y)) * RADTODEG;
	}

	//--------------------------------
	//Convertion

	const Point2D<float> convToFloat()
	{
		return Point2D<float>((float)x, (float)y);
	}

	const Point2D<int> convToInt()
	{
		return Point2D<int>((int)x, (int)y);
	}

	//--------------------------------

public:
	TYPE x, y;
};

typedef Point2D<int> iPoint;
typedef Point2D<float> fPoint;

#endif // !__POINT2D__