
/// <summary>
/// Custom Class to store a 3D point in space using x,y and z coordinates
/// Contains the following operations
/// Addition (+),
/// Euclidean Distance (*),
/// Scalar Multiplication (*),
/// Scalar Division (/),
/// Comparisons (== !=),
/// Vector Generation(-)
/// </summary>
class Point_3D
{
public:
	float x, y, z;

	/// <summary>
	/// Constructor for Point_3D
	/// </summary>
	Point_3D(float X = 0, float Y = 0, float Z = 0) : x(X), y(Y), z(Z) {};

	/// <summary>
	/// Addition of two Point_3D using operator overloading 
	/// </summary>
	/// <param name="pt"> Second Point_3d ie the Point_3D on the right of the operator</param>
	/// <returns> Point_3D which is the sum of two Point_3D </returns>
	inline Point_3D operator +(const Point_3D& pt)const
	{
		return Point_3D(this->x + pt.x, this->y + pt.y, this->z + pt.z);
	}

	/// <summary>
	///  operator '*' is used for calcualting the euclidean distance between two points in space 
	/// </summary>
	/// <param name="beta"> Second Point_3d ie the Point_3D on the right of the operator </param>
	/// <returns> Euclidean distance between these 2 Point_3D</returns>
	inline float operator *(const Point_3D& beta)const
	{
		return abs((sqrt((x - beta.x)*(x - beta.x) + (y - beta.y)*(y - beta.y) + (z - beta.z)*(z - beta.z))));
	}

	/// <summary>
	/// operator '*' with a constant is used for scaling the coordinates of  points in space 
	/// </summary>
	/// <param name="c"> Constant value to be multiplied for scaling</param>
	/// <returns> Scaled Point_3d </returns>
	inline Point_3D operator *(const float c)const
	{
		return Point_3D(c*x, c*y, c*z);
	}

	/// <summary>
	/// operator '/' with a constant is used for scaling the coordinates of  points in space 
	/// </summary>
	/// <param name="c"> Constant value to be divided for scaling</param>
	/// <returns> Scaled Point_3d </returns>
	inline Point_3D operator /(const float c)const
	{
		return Point_3D(x / c, y / c, z / c);
	}

	/// <summary>
	/// Compares the 2 Point_3D to check if they are equal
	/// </summary>
	/// <param name="pt"> Second Point_3D ie the point on the right of the operator </param>
	/// <returns> Boolean true if equal, Boolean false if NOT equal</returns>
	inline bool operator ==(const Point_3D& pt)const
	{
		return (x == pt.x && y == pt.y && z == pt.z) ? true : false;
	}

	/// <summary>
	/// Compares the 2 Point_3D to check if they are NOT equal
	/// </summary>
	/// <param name="pt"> Second Point_3D ie the point on the right of the operator </param>
	/// <returns> Boolean true if NOT equal, Boolean false if equal</returns>
	inline bool operator !=(const Point_3D& pt)const
	{
		return (x == pt.x && y == pt.y && z == pt.z) ? false : true;
	}

	/// <summary>
	/// Generate Vector_3D between two points using operator overloading.
	/// </summary>
	/// <param name="pt"> Second Point_3D ie the point on the right of the operator </param>
	/// <returns> Unit Vector_3D from First Point_3D to second Point_3D </returns>
	Vector_3D operator -(const Point_3D& pt)const
	{
		Vector_3D temp;
		float norm = sqrt((this->x - pt.x)*(this->x - pt.x) + (this->y - pt.y)*(this->y - pt.y) + (this->z - pt.z)*(this->z - pt.z));
		temp.i = (this->x - pt.x) / norm;
		temp.j = (this->y - pt.y) / norm;
		temp.k = (this->z - pt.z) / norm;
		return temp;
	}
};


/// <summary>
/// Creating a  triangle class containing  three vertices (point_3D objects) an done normal (Vector_3D) as its members.
/// </summary>
class Triangle
{
public:
	Point_3D v1, v2, v3;
	Vector_3D n;
	float min_z = 0;
	float max_z = 0;

	/// <summary>
	/// Operators to do basic sorting by hieght
	/// </summary>
	/// <param name="other"> Other Traingle object</param>
	/// <returns> True if first Triangle min_z small than second Triangle min_z </returns>
	bool operator< (const Triangle &other) const {
		return min_z < other.min_z;
	}

	/// <summary>
	/// Operators to do basic sorting by hieght
	/// </summary>
	/// <param name="other"> Other Traingle object</param>
	/// <returns> True if first Triangle and second Triangle are equal </returns>
	bool operator== (const Triangle &other) const {
		if (v1 == other.v1 && v2 == other.v2 && v3 == other.v3)
			return true;
		else
			return false;
	}

	/// <summary>
	/// Constructor for the triangle class
	/// </summary>
	Triangle(const Point_3D& pt1, const Point_3D& pt2, const Point_3D& pt3, const Vector_3D& normal) :v1(pt1), v2(pt2), v3(pt3), n(normal) {};

};
