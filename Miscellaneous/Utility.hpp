/**
 * All stuff I used for CPSC453 so far, will be updated inconsistently.
 * Compile in g++9 with '-std=c++17 -Wall -Ofast -lstdc++fs'
 *
 * 1. All data structures are written in C-style structs, all fields are exposed.
 * 2. For matrices, use .at(i, j) to access/assign values
 * 3. All exceptions will be thrown using 'assert' since it will give the actual line number.
 * 4. Use camelCase as the default naming convention.
 * 5. All angle arguments in rotate matrix are in radians, and the vector rotates in CCW direction.
 * 6. Elements in a matrix are stored in row-major order, while OpenGL uses column-major order. To
 *    convert a row-major order to column-major order, please transpose the matrix.
 * 7. I only consider making assertions on zero division for integers.
 *
 * Created by: Haohu Shen
 * All rights reserved (c) 2019 Haohu Shen
 * Date: 2019-11-19
 */

/**
 * Math3D: My math library
 * Struct: Vec2i, Vec3i, Vec4i, Mat2x2i, Mat3x3i, Mat4x4i (int)
 *         Vec2,  Vec3,  Vec4,  Mat2x2,  Mat3x3,  Mat4x4  (double)
 *         Vec2f, Vec3f, Vec4f, Mat2x2f, Mat3x3f, Mat4x4f (float)
 * (All operations of matrix transformation are base on 'float')
 *
 * Utility: All miscellaneous functions I use for this course so far.
 */

#pragma once

#include <bits/stdc++.h>
#include <experimental/filesystem>

#ifndef M_PI
#define M_PI        3.14159265358979323846264338327950288   /* pi             */
#endif

#ifndef M_PI_2
#define M_PI_2      1.57079632679489661923132169163975144   /* pi/2           */
#endif

// Namespace: Math
// Description: The namespace includes all methods and data structures for 3D Geometry
namespace Math {

    // Three-way-compare the float number and the zero
    // result = 1: larger than 0
    // result = 0: equal to 0
    // result = -1: smaller than 0
    inline
    int threeWayComparator(const double &a) {
        constexpr double Eps = 1e-10;
        if (a > Eps) {
            return 1;
        }
        if (a > -Eps) {
            return 0;
        }
        return -1;
    }

    // Structure: Vec2i
    //
    // Description: A 2D Vector that holds positional data using 2 ints
    struct Vec2i {
        // Fields
        int x;
        int y;

        // Alternative getters for UV Coords
        [[nodiscard]] int s() const {
            return x;
        }

        [[nodiscard]] int t() const {
            return y;
        }

        // Constructor
        explicit Vec2i(int x, int y) : x(x), y(y) {}

        // Default Constructor
        Vec2i() : Vec2i(0, 0) {}

        // Operator overload: [] access only
        int operator[](int index) const {
            // Check if index is valid
            assert(index >= 0 && index <= 1);
            if (index == 0) {
                return x;
            }
            return y;
        }

        // Operator overload: [] for assignment
        int &operator[](int index) {
            // Check if index is valid
            assert(index >= 0 && index <= 1);
            if (index == 0) {
                return x;
            }
            return y;
        }

        // Operator overload: ==
        bool operator==(const Vec2i &other) const {
            return (x - other.x == 0 &&
                    y - other.y == 0);
        }

        // Operator overload: !=
        bool operator!=(const Vec2i &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Vec2i operator+(const Vec2i &rhs) const {
            return Vec2i(x + rhs.x, y + rhs.y);
        }

        // Operator overload: -
        Vec2i operator-(const Vec2i &rhs) const {
            return Vec2i(x - rhs.x, y - rhs.y);
        }

        // Operator overload: / (integer division)
        Vec2i operator/(const int &scalar) const {
            // Abort if scalar = 0
            assert(scalar != 0);
            return Vec2i(x / scalar, y / scalar);
        }

        // Operator overload: +=
        Vec2i &operator+=(const Vec2i &rhs) {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        // Operator overload: -=
        Vec2i &operator-=(const Vec2i &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        // Operator overload: *=
        Vec2i &operator*=(const int &rhs) {
            x *= rhs;
            y *= rhs;
            return *this;
        }

        // Operator overload: /= (integer division)
        Vec2i &operator/=(const int &rhs) {
            // Abort if rhs = 0
            assert(rhs != 0);
            x /= rhs;
            y /= rhs;
            return *this;
        }

        // Operator /= overload of two Vec2i, it works component-wise like GLSL.
        Vec2i &operator/=(const Vec2i &rhs) {
            assert(rhs.x != 0);
            assert(rhs.y != 0);
            x /= rhs.x;
            y /= rhs.y;
            return *this;
        }

        // Operator overload: -()
        Vec2i operator-() const {
            return Vec2i(-x, -y);
        }

        // Operator overload: +()
        const Vec2i &operator+() const {
            return *this;
        }

        // Set all elements as the same value
        void fill(const int &value) {
            x = value;
            y = value;
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Vec2i operator*(const Vec2i &lhs, const int &scalar) {
        return Vec2i(lhs.x * scalar, lhs.y * scalar);
    }

    inline
    Vec2i operator*(const int &scalar, const Vec2i &rhs) {
        return rhs * scalar;
    }

    // Operator * overload of two Vec2i, it works component-wise like GLSL.
    inline
    Vec2i operator*(const Vec2i &lhs, const Vec2i &rhs) {
        return Vec2i(
                lhs.x * rhs.x,
                lhs.y * rhs.y
        );
    }

    // Operator / overload of two Vec2i, it works component-wise like GLSL.
    inline
    Vec2i operator/(const Vec2i &lhs, const Vec2i &rhs) {
        assert(rhs.x != 0);
        assert(rhs.y != 0);
        return Vec2i(
                lhs.x / rhs.x,
                lhs.y / rhs.y
        );
    }

    // dot product
    inline
    int dot(const Vec2i &lhs, const Vec2i &rhs) {
        return (lhs.x * rhs.x + lhs.y * rhs.y);
    }

    // cross product of two 2D vector will result an int
    inline
    int cross(const Vec2i &lhs, const Vec2i &rhs) {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    // norm(length)
    inline
    float norm(const Vec2i &obj) {
        return sqrtf(static_cast<float>(dot(obj, obj)));
    }

    // squareLength: return length * length
    inline
    int squareLength(const Vec2i &obj) {
        return dot(obj, obj);
    }

    // distance of two vectors
    inline
    float distance(const Vec2i &lhs, const Vec2i &rhs) {
        return sqrtf(
                static_cast<float>((lhs.x - rhs.x) * (lhs.x - rhs.x) +
                                   (lhs.y - rhs.y) * (lhs.y - rhs.y))
        );
    }

    // Structure: Vec3i
    //
    // Description: A 3D Vector that holds positional data using 3 ints
    struct Vec3i {
        // Fields
        int x;
        int y;
        int z;

        // Alternative getters for RGB
        [[nodiscard]] int r() const {
            return x;
        }

        [[nodiscard]] int g() const {
            return y;
        }

        [[nodiscard]] int b() const {
            return z;
        }

        // Constructor
        explicit Vec3i(int x, int y, int z) : x(x), y(y), z(z) {}

        // Default Constructor
        Vec3i() : Vec3i(0, 0, 0) {}

        // Constructor with a Vec2i
        explicit Vec3i(const int &x, const Vec2i &vec2i) : Vec3i(x, vec2i.x,
                                                                 vec2i.y) {}

        explicit Vec3i(const Vec2i &vec2i, const int &z) : Vec3i(vec2i.x,
                                                                 vec2i.y, z) {}

        // Operator overload: [] access only
        int operator[](int index) const {
            // Check if index is valid
            assert(index >= 0 && index <= 2);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                default:
                    return z;
            }
        }

        // Operator overload: [] for assignment
        int &operator[](int index) {
            // Check if index is valid
            assert(index >= 0 && index <= 2);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                default:
                    return z;
            }
        }

        // Operator overload: ==
        bool operator==(const Vec3i &other) const {
            return (x - other.x == 0 &&
                    y - other.y == 0 &&
                    z - other.z == 0);
        }

        // Operator overload: !=
        bool operator!=(const Vec3i &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Vec3i operator+(const Vec3i &rhs) const {
            return Vec3i(x + rhs.x, y + rhs.y, z + rhs.z);
        }

        // Operator overload: -
        Vec3i operator-(const Vec3i &rhs) const {
            return Vec3i(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        // Operator overload: / (integer division)
        Vec3i operator/(const int &scalar) const {
            // Abort if scalar = 0
            assert(scalar != 0);
            return Vec3i(x / scalar, y / scalar, z / scalar);
        }

        // Operator overload: +=
        Vec3i &operator+=(const Vec3i &rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            return *this;
        }

        // Operator overload: -=
        Vec3i &operator-=(const Vec3i &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            return *this;
        }

        // Operator overload: *=
        Vec3i &operator*=(const int &rhs) {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            return *this;
        }

        // Operator overload: /= integer division
        Vec3i &operator/=(const int &rhs) {
            // Abort if rhs = 0
            assert(rhs != 0);
            x /= rhs;
            y /= rhs;
            z /= rhs;
            return *this;
        }

        // Operator /= overload of two Vec3i, it works component-wise like GLSL.
        Vec3i &operator/=(const Vec3i &rhs) {
            assert(rhs.x != 0);
            assert(rhs.y != 0);
            assert(rhs.z != 0);
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            return *this;
        }

        // Operator overload: -()
        Vec3i operator-() const {
            return Vec3i(-x, -y, -z);
        }

        // Operator overload: +()
        const Vec3i &operator+() const {
            return *this;
        }

        // Set all elements as the same value
        void fill(const int &value) {
            x = value;
            y = value;
            z = value;
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Vec3i operator*(const Vec3i &lhs, const int &scalar) {
        return Vec3i(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
    }

    inline
    Vec3i operator*(const int &scalar, const Vec3i &rhs) {
        return rhs * scalar;
    }

    // Operator * overload of two Vec3i, it works component-wise like GLSL.
    inline
    Vec3i operator*(const Vec3i &lhs, const Vec3i &rhs) {
        return Vec3i(
                lhs.x * rhs.x,
                lhs.y * rhs.y,
                lhs.z * rhs.z
        );
    }

    // Operator / overload of two Vec3i, it works component-wise like GLSL.
    inline
    Vec3i operator/(const Vec3i &lhs, const Vec3i &rhs) {
        assert(rhs.x != 0);
        assert(rhs.y != 0);
        assert(rhs.z != 0);
        return Vec3i(
                lhs.x / rhs.x,
                lhs.y / rhs.y,
                lhs.z / rhs.z
        );
    }

    // dot product
    inline
    int dot(const Vec3i &lhs, const Vec3i &rhs) {
        return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
    }

    // cross product
    inline
    Vec3i cross(const Vec3i &lhs, const Vec3i &rhs) {
        return Vec3i(
                lhs.y * rhs.z - rhs.y * lhs.z,
                lhs.z * rhs.x - rhs.z * lhs.x,
                lhs.x * rhs.y - rhs.x * lhs.y
        );
    }

    // norm(length)
    inline
    float norm(const Vec3i &obj) {
        return sqrtf(static_cast<float>(dot(obj, obj)));
    }

    // squareLength: return length * length
    inline
    int squareLength(const Vec3i &obj) {
        return dot(obj, obj);
    }

    // distance of two vectors
    inline
    float distance(const Vec3i &lhs, const Vec3i &rhs) {
        return sqrtf(static_cast<float>(
                             (lhs.x - rhs.x) * (lhs.x - rhs.x) +
                             (lhs.y - rhs.y) * (lhs.y - rhs.y) +
                             (lhs.z - rhs.z) * (lhs.z - rhs.z))
        );
    }

    // Structure: Vec4i
    //
    // Description: A 3D Vector that holds positional data using 4 ints in a homogeneous coordinate system.
    struct Vec4i {
        // Fields
        int x;
        int y;
        int z;
        int w;

        // Alternative getters for RGBA
        [[nodiscard]] int r() const {
            return x;
        }

        [[nodiscard]] int g() const {
            return y;
        }

        [[nodiscard]] int b() const {
            return z;
        }

        [[nodiscard]] int a() const {
            return w;
        }

        // Constructor
        explicit Vec4i(int x, int y, int z, int w) : x(x), y(y), z(z), w(w) {}

        // Default Constructor
        Vec4i() : Vec4i(0, 0, 0, 0) {}

        // Constructor with 2 'Vec2i's
        explicit Vec4i(const Vec2i &a, const Vec2i &b) : Vec4i(a.x, a.y, b.x,
                                                               b.y) {}

        // Constructor with 1 'Vec2f'
        explicit Vec4i(const Vec2i &vec2i, const int &z, const int &w) : Vec4i(
                vec2i.x, vec2i.y, z, w) {}

        explicit Vec4i(const int &x, const Vec2i &vec2i, const int &w) : Vec4i(
                x, vec2i.x, vec2i.y, w) {}

        explicit Vec4i(const int &x, const int &y, const Vec2i &vec2i) : Vec4i(
                x, y, vec2i.x, vec2i.y) {}

        // Constructor with 1 'Vec3f'
        explicit Vec4i(const Vec3i &vec3i, const int &w) : Vec4i(vec3i.x,
                                                                 vec3i.y,
                                                                 vec3i.z, w) {}

        explicit Vec4i(const int &x, const Vec3i &vec3i) : Vec4i(x, vec3i.x,
                                                                 vec3i.y,
                                                                 vec3i.z) {}

        // Operator overload: [] access only
        int operator[](int index) const {
            // Check if index is valid
            assert(index >= 0 && index <= 3);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                default:
                    return w;
            }
        }

        // Operator overload: [] for assignment
        int &operator[](int index) {
            // Check if index is valid
            assert(index >= 0 && index <= 3);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                default:
                    return w;
            }
        }

        // Operator overload: ==
        bool operator==(const Vec4i &other) const {
            return (x - other.x == 0 &&
                    y - other.y == 0 &&
                    z - other.z == 0 &&
                    w - other.w == 0);
        }

        // Operator overload: !=
        bool operator!=(const Vec4i &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Vec4i operator+(const Vec4i &rhs) const {
            return Vec4i(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
        }

        // Operator overload: -
        Vec4i operator-(const Vec4i &rhs) const {
            return Vec4i(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
        }

        // Operator overload: / (integer division)
        Vec4i operator/(const int &scalar) const {
            // Abort if scalar = 0
            assert(scalar != 0);
            return Vec4i(x / scalar, y / scalar, z / scalar, w / scalar);
        }

        // Operator /= overload of two Vec4i, it works component-wise like GLSL.
        Vec4i &operator/=(const Vec4i &rhs) {
            assert(rhs.x != 0);
            assert(rhs.y != 0);
            assert(rhs.z != 0);
            assert(rhs.w != 0);
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            w /= rhs.w;
            return *this;
        }

        // Operator overload: +=
        Vec4i &operator+=(const Vec4i &rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            w += rhs.w;
            return *this;
        }

        // Operator overload: -=
        Vec4i &operator-=(const Vec4i &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            w -= rhs.w;
            return *this;
        }

        // Operator overload: *=
        Vec4i &operator*=(const int &rhs) {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            w *= rhs;
            return *this;
        }

        // Operator overload: /=
        Vec4i &operator/=(const int &rhs) {
            // Abort if rhs = 0
            assert(rhs != 0);
            x /= rhs;
            y /= rhs;
            z /= rhs;
            w /= rhs;
            return *this;
        }

        // Operator overload: -()
        Vec4i operator-() const {
            return Vec4i(-x, -y, -z, -w);
        }

        // Operator overload: +()
        const Vec4i &operator+() const {
            return *this;
        }

        // Set all elements as the same value
        void fill(const int &value) {
            x = value;
            y = value;
            z = value;
            w = value;
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Vec4i operator*(const Vec4i &lhs, const int &scalar) {
        return Vec4i(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar,
                     lhs.w * scalar);
    }

    inline
    Vec4i operator*(const int &scalar, const Vec4i &rhs) {
        return rhs * scalar;
    }

    // Operator * overload of two Vec4i, it works component-wise like GLSL.
    inline
    Vec4i operator*(const Vec4i &lhs, const Vec4i &rhs) {
        return Vec4i(
                lhs.x * rhs.x,
                lhs.y * rhs.y,
                lhs.z * rhs.z,
                lhs.w * rhs.w
        );
    }

    // Operator / overload of two Vec4i, it works component-wise like GLSL.
    inline
    Vec4i operator/(const Vec4i &lhs, const Vec4i &rhs) {
        assert(rhs.x != 0);
        assert(rhs.y != 0);
        assert(rhs.z != 0);
        assert(rhs.w != 0);
        return Vec4i(
                lhs.x / rhs.x,
                lhs.y / rhs.y,
                lhs.z / rhs.z,
                lhs.w / rhs.w
        );
    }

    // dot product
    inline
    int dot(const Vec4i &lhs, const Vec4i &rhs) {
        return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w);
    }

    // norm(length)
    inline
    float norm(const Vec4i &obj) {
        return sqrtf(static_cast<float>(dot(obj, obj)));
    }

    // squareLength: return length * length
    inline
    int squareLength(const Vec4i &obj) {
        return dot(obj, obj);
    }

    // distance of two vectors
    inline
    float distance(const Vec4i &lhs, const Vec4i &rhs) {
        return sqrtf(static_cast<float>(
                             (lhs.x - rhs.x) * (lhs.x - rhs.x) +
                             (lhs.y - rhs.y) * (lhs.y - rhs.y) +
                             (lhs.z - rhs.z) * (lhs.z - rhs.z) +
                             (lhs.w - rhs.w) * (lhs.w - rhs.w))
        );
    }

    // Structure: Mat2x2i
    //
    // Description: A 2x2 matrix where each element is an 'int' type, a std::array is used to store all elements.
    // Diagram: {0,1,2,3} --> |0 1|
    //                        |2 3|
    struct Mat2x2i {
        // Field
        std::array<int, 4> data{};

        // Constructor
        explicit Mat2x2i(const int &e0, const int &e1, const int &e2,
                         const int &e3) {
            data[0] = e0;
            data[1] = e1;
            data[2] = e2;
            data[3] = e3;
        }

        // Default constructor
        Mat2x2i() = default;

        // Constructor takes std::array<int, 4>
        explicit Mat2x2i(const std::array<int, 4> &rhs) : data(rhs) {}

        // Constructor std::initializer_list<int>
        Mat2x2i(const std::initializer_list<int> &rhs) {
            // Check if the length of rhs is not 4
            assert(rhs.size() == 4);
            std::copy(rhs.begin(), rhs.end(), data.begin());
        }

        // Constructor as an identity * scalar
        explicit Mat2x2i(const int &scalar) {
            data[0] = scalar;
            data[1] = 0;
            data[2] = 0;
            data[3] = scalar;
        }

        // Operator overload: ==
        bool operator==(const Mat2x2i &other) const {
            for (unsigned int i = 0; i != 2; ++i) {
                for (unsigned int j = 0; j != 2; ++j) {
                    if (this->at(i, j) - other.at(i, j) != 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        // Operator overload: !=
        bool operator!=(const Mat2x2i &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Mat2x2i operator+(const Mat2x2i &rhs) const {
            return Mat2x2i(data[0] + rhs.data[0],
                           data[1] + rhs.data[1],
                           data[2] + rhs.data[2],
                           data[3] + rhs.data[3]);
        }

        // Operator overload: -
        Mat2x2i operator-(const Mat2x2i &rhs) const {
            return Mat2x2i(data[0] - rhs.data[0],
                           data[1] - rhs.data[1],
                           data[2] - rhs.data[2],
                           data[3] - rhs.data[3]);
        }

        // Operator overload: /
        Mat2x2i operator/(const int &scalar) const {
            // Abort if scalar = 0
            assert(scalar != 0);
            return Mat2x2i(data[0] / scalar,
                           data[1] / scalar,
                           data[2] / scalar,
                           data[3] / scalar);
        }

        // Operator overload: +=
        Mat2x2i &operator+=(const Mat2x2i &rhs) {
            data[0] += rhs.data[0];
            data[1] += rhs.data[1];
            data[2] += rhs.data[2];
            data[3] += rhs.data[3];
            return *this;
        }

        // Operator overload: -=
        Mat2x2i &operator-=(const Mat2x2i &rhs) {
            data[0] -= rhs.data[0];
            data[1] -= rhs.data[1];
            data[2] -= rhs.data[2];
            data[3] -= rhs.data[3];
            return *this;
        }

        // Operator overload: *=
        Mat2x2i &operator*=(const int &rhs) {
            data[0] *= rhs;
            data[1] *= rhs;
            data[2] *= rhs;
            data[3] *= rhs;
            return *this;
        }

        // Operator overload: /=
        Mat2x2i &operator/=(const int &rhs) {
            // Abort if rhs = 0
            assert(rhs != 0);
            data[0] /= rhs;
            data[1] /= rhs;
            data[2] /= rhs;
            data[3] /= rhs;
            return *this;
        }

        // Operator overload: -()
        Mat2x2i operator-() const {
            return Mat2x2i(-data[0],
                           -data[1],
                           -data[2],
                           -data[3]);
        }

        // Operator overload: +()
        const Mat2x2i &operator+() const {
            return *this;
        }

        // Operator overload: at(i, j) access only
        [[nodiscard]] int
        at(const unsigned int &i, const unsigned int &j) const {
            // If the index is illegal, then throw an exception.
            return data.at(i * 2 + j);
        }

        // Operator overload: at(i, j) for assignment
        int &at(const unsigned int &i, const unsigned int &j) {
            // If the index is illegal, then throw an exception.
            return data.at(i * 2 + j);
        }

        // Set all elements as the same value
        void fill(const int &value) {
            std::fill(data.begin(), data.end(), value);
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Mat2x2i operator*(const Mat2x2i &lhs, const int &scalar) {
        return Mat2x2i(lhs.data[0] * scalar,
                       lhs.data[1] * scalar,
                       lhs.data[2] * scalar,
                       lhs.data[3] * scalar);
    }

    inline
    Mat2x2i operator*(const int &scalar, const Mat2x2i &rhs) {
        return rhs * scalar;
    }

    // Operator overload as non-member function: * (Mat2x2i * Vec2i) right-multiplication
    // same as glm::ivec2 rhs * glm::imat2x2 lhs
    inline
    Vec2i operator*(const Mat2x2i &lhs, const Vec2i &rhs) {
        return Vec2i(
                lhs.data[0] * rhs.x + lhs.data[1] * rhs.y,
                lhs.data[2] * rhs.x + lhs.data[3] * rhs.y
        );
    }

    // Operator overload as non-member function: * (Mat2x2i * Mat2x2i) right-multiplication
    // same as glm::imat2x2 rhs * glm::imat2x2 lhs
    inline
    Mat2x2i operator*(const Mat2x2i &lhs, const Mat2x2i &rhs) {
        return Mat2x2i(
                lhs.data[0] * rhs.data[0] + lhs.data[1] * rhs.data[2],
                lhs.data[0] * rhs.data[1] + lhs.data[1] * rhs.data[3],
                lhs.data[2] * rhs.data[0] + lhs.data[3] * rhs.data[2],
                lhs.data[2] * rhs.data[1] + lhs.data[3] * rhs.data[3]
        );
    }

    inline
    int determinant(Mat2x2i const &obj) {
        return obj.data[0] * obj.data[3] - obj.data[1] * obj.data[2];
    }

    // transpose
    // | 0 1 |  --> | 0 2 |
    // | 2 3 |  --> | 1 3 |
    inline
    Mat2x2i transpose(Mat2x2i obj) {
        std::swap(obj.at(0, 1), obj.at(1, 0));
        return obj;
    }

    // Structure: Mat3x3f
    //
    // Description: A 3x3 matrix where each element is an 'int' type, a std::array is used to store all elements.
    // Diagram: {0,1,2,3,4,5,6,7,8} --> |0 1 2|
    //                                  |3 4 5|
    //                                  |6 7 8|
    struct Mat3x3i {
        // Field
        std::array<int, 9> data{};

        // Constructor
        explicit Mat3x3i(const int &e0,
                         const int &e1,
                         const int &e2,
                         const int &e3,
                         const int &e4,
                         const int &e5,
                         const int &e6,
                         const int &e7,
                         const int &e8) {
            data[0] = e0;
            data[1] = e1;
            data[2] = e2;
            data[3] = e3;
            data[4] = e4;
            data[5] = e5;
            data[6] = e6;
            data[7] = e7;
            data[8] = e8;
        }

        // Default constructor
        Mat3x3i() = default;

        // Constructor takes std::array<int, 9>
        explicit Mat3x3i(const std::array<int, 9> &rhs) : data(rhs) {}

        // Constructor std::initializer_list<int>
        Mat3x3i(const std::initializer_list<int> &rhs) {
            // Check if the length of rhs is not 9
            assert(rhs.size() == 9);
            std::copy(rhs.begin(), rhs.end(), data.begin());
        }

        // Constructor as an identity * scalar
        explicit Mat3x3i(const int &scalar) {
            data[0] = scalar;
            data[1] = 0;
            data[2] = 0;
            data[3] = 0;
            data[4] = scalar;
            data[5] = 0;
            data[6] = 0;
            data[7] = 0;
            data[8] = scalar;
        }

        // Operator overload: ==
        bool operator==(const Mat3x3i &other) const {
            for (unsigned int i = 0; i != 3; ++i) {
                for (unsigned int j = 0; j != 3; ++j) {
                    if (this->at(i, j) - other.at(i, j) != 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        // Operator overload: !=
        bool operator!=(const Mat3x3i &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Mat3x3i operator+(const Mat3x3i &rhs) const {
            Mat3x3i result;
            for (size_t i = 0; i != 9; ++i) {
                result.data[i] += rhs.data[i];
            }
            return result;
        }

        // Operator overload: -
        Mat3x3i operator-(const Mat3x3i &rhs) const {
            Mat3x3i result;
            for (size_t i = 0; i != 9; ++i) {
                result.data[i] -= rhs.data[i];
            }
            return result;
        }

        // Operator overload: / (integer division)
        Mat3x3i operator/(const int &scalar) const {
            // Abort if scalar = 0
            assert(scalar != 0);
            return Mat3x3i(data[0] / scalar,
                           data[1] / scalar,
                           data[2] / scalar,
                           data[3] / scalar,
                           data[4] / scalar,
                           data[5] / scalar,
                           data[6] / scalar,
                           data[7] / scalar,
                           data[8] / scalar);
        }

        // Operator overload: +=
        Mat3x3i &operator+=(const Mat3x3i &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] += rhs.data[i];
            }
            return *this;
        }

        // Operator overload: -=
        Mat3x3i &operator-=(const Mat3x3i &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] -= rhs.data[i];
            }
            return *this;
        }

        // Operator overload: *=
        Mat3x3i &operator*=(const int &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] *= rhs;
            }
            return *this;
        }

        // Operator overload: /= (integer zero)
        Mat3x3i &operator/=(const int &rhs) {
            // Abort if rhs = 0
            assert(rhs != 0);
            for (size_t i = 0; i != 9; ++i) {
                data[i] /= rhs;
            }
            return *this;
        }

        // Operator overload: -()
        Mat3x3i operator-() const {
            return Mat3x3i(-data[0],
                           -data[1],
                           -data[2],
                           -data[3],
                           -data[4],
                           -data[5],
                           -data[6],
                           -data[7],
                           -data[8]);
        }

        // Operator overload: +()
        const Mat3x3i &operator+() const {
            return *this;
        }

        // Operator overload: at(i, j) access only
        [[nodiscard]] int
        at(const unsigned int &i, const unsigned int &j) const {
            // If the index is illegal, then throw an exception.
            return data.at(i * 3 + j);
        }

        // Operator overload: at(i, j) for assignment
        int &at(const unsigned int &i, const unsigned int &j) {
            // If the index is illegal, then throw an exception.
            return data.at(i * 3 + j);
        }

        // Set all elements as the same value
        void fill(const int &value) {
            std::fill(data.begin(), data.end(), value);
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Mat3x3i operator*(const Mat3x3i &lhs, const int &scalar) {
        return Mat3x3i(lhs.data[0] * scalar,
                       lhs.data[1] * scalar,
                       lhs.data[2] * scalar,
                       lhs.data[3] * scalar,
                       lhs.data[4] * scalar,
                       lhs.data[5] * scalar,
                       lhs.data[6] * scalar,
                       lhs.data[7] * scalar,
                       lhs.data[8] * scalar);
    }

    inline
    Mat3x3i operator*(const int &scalar, const Mat3x3i &rhs) {
        return rhs * scalar;
    }

    // Operator overload as non-member function: * (Mat3x3i * Vec3i) left-multiplication
    // same as glm::ivec3 rhs * glm::imat3x3 lhs
    inline
    Vec3i operator*(const Mat3x3i &lhs, const Vec3i &rhs) {
        return Vec3i(
                lhs.data[0] * rhs.x + lhs.data[1] * rhs.y + lhs.data[2] * rhs.z,
                lhs.data[3] * rhs.x + lhs.data[4] * rhs.y + lhs.data[5] * rhs.z,
                lhs.data[6] * rhs.x + lhs.data[7] * rhs.y + lhs.data[8] * rhs.z
        );
    }

    // Operator overload as non-member function: * (Mat3x3i * Mat3x3i) right-multiplication
    // same as glm::imat3x3 rhs * glm::imat3x3 lhs
    inline
    Mat3x3i operator*(const Mat3x3i &lhs, const Mat3x3i &rhs) {
        return Mat3x3i(
                lhs.data[0] * rhs.data[0] + lhs.data[1] * rhs.data[3] +
                lhs.data[2] * rhs.data[6],
                lhs.data[0] * rhs.data[1] + lhs.data[1] * rhs.data[4] +
                lhs.data[2] * rhs.data[7],
                lhs.data[0] * rhs.data[2] + lhs.data[1] * rhs.data[5] +
                lhs.data[2] * rhs.data[8],
                lhs.data[3] * rhs.data[0] + lhs.data[4] * rhs.data[3] +
                lhs.data[5] * rhs.data[6],
                lhs.data[3] * rhs.data[1] + lhs.data[4] * rhs.data[4] +
                lhs.data[5] * rhs.data[7],
                lhs.data[3] * rhs.data[2] + lhs.data[4] * rhs.data[5] +
                lhs.data[5] * rhs.data[8],
                lhs.data[6] * rhs.data[0] + lhs.data[7] * rhs.data[3] +
                lhs.data[8] * rhs.data[6],
                lhs.data[6] * rhs.data[1] + lhs.data[7] * rhs.data[4] +
                lhs.data[8] * rhs.data[7],
                lhs.data[6] * rhs.data[2] + lhs.data[7] * rhs.data[5] +
                lhs.data[8] * rhs.data[8]
        );
    }

    inline
    int determinant(Mat3x3i const &obj) {
        return obj.at(0, 0) *
               (obj.at(1, 1) * obj.at(2, 2) - obj.at(2, 1) * obj.at(1, 2)) -
               obj.at(0, 1) *
               (obj.at(1, 0) * obj.at(2, 2) - obj.at(1, 2) * obj.at(2, 0)) +
               obj.at(0, 2) *
               (obj.at(1, 0) * obj.at(2, 1) - obj.at(1, 1) * obj.at(2, 0));
    }

    // transpose
    // | 0 1 2 |  --> | 0 3 6 |
    // | 3 4 5 |  --> | 1 4 7 |
    // | 6 7 8 |  --> | 2 5 8 |
    inline
    Mat3x3i transpose(Mat3x3i obj) {
        std::swap(obj.data[3], obj.data[1]);
        std::swap(obj.data[6], obj.data[2]);
        std::swap(obj.data[7], obj.data[5]);
        return obj;
    }

    // Structure: Mat4x4i
    //
    // Description: A 4x4 matrix where each element is an 'int' type, a std::array is used to store all elements.
    // Diagram: {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} --> |0   1  2  3|
    //                                                      |4   5  6  7|
    //                                                      |8   9 10 11|
    //                                                      |12 13 14 15|
    struct Mat4x4i {
        // Field
        std::array<int, 16> data{};

        // Constructor
        explicit Mat4x4i(const int &e0,
                         const int &e1,
                         const int &e2,
                         const int &e3,
                         const int &e4,
                         const int &e5,
                         const int &e6,
                         const int &e7,
                         const int &e8,
                         const int &e9,
                         const int &e10,
                         const int &e11,
                         const int &e12,
                         const int &e13,
                         const int &e14,
                         const int &e15) {
            data[0] = e0;
            data[1] = e1;
            data[2] = e2;
            data[3] = e3;
            data[4] = e4;
            data[5] = e5;
            data[6] = e6;
            data[7] = e7;
            data[8] = e8;
            data[9] = e9;
            data[10] = e10;
            data[11] = e11;
            data[12] = e12;
            data[13] = e13;
            data[14] = e14;
            data[15] = e15;
        }

        // Default constructor
        Mat4x4i() = default;

        // Constructor takes std::array<int, 16>
        explicit Mat4x4i(const std::array<int, 16> &rhs) : data(rhs) {}

        // Constructor std::initializer_list<int>
        Mat4x4i(const std::initializer_list<int> &rhs) {
            // Check if the length of rhs is not 16
            assert(rhs.size() == 16);
            std::copy(rhs.begin(), rhs.end(), data.begin());
        }

        // Constructor as an identity * scalar
        explicit Mat4x4i(const int &scalar) {
            data[0] = scalar;
            data[1] = 0;
            data[2] = 0;
            data[3] = 0;
            data[4] = 0;
            data[5] = scalar;
            data[6] = 0;
            data[7] = 0;
            data[8] = 0;
            data[9] = 0;
            data[10] = scalar;
            data[11] = 0;
            data[12] = 0;
            data[13] = 0;
            data[14] = 0;
            data[15] = scalar;
        }

        // Operator overload: ==
        bool operator==(const Mat4x4i &other) const {
            for (unsigned int i = 0; i != 4; ++i) {
                for (unsigned int j = 0; j != 4; ++j) {
                    if (this->at(i, j) - other.at(i, j) != 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        // Operator overload: !=
        bool operator!=(const Mat4x4i &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Mat4x4i operator+(const Mat4x4i &rhs) const {
            Mat4x4i result;
            for (size_t i = 0; i != 16; ++i) {
                result.data[i] += rhs.data[i];
            }
            return result;
        }

        // Operator overload: -
        Mat4x4i operator-(const Mat4x4i &rhs) const {
            Mat4x4i result;
            for (size_t i = 0; i != 16; ++i) {
                result.data[i] -= rhs.data[i];
            }
            return result;
        }

        // Operator overload: / (integer division)
        Mat4x4i operator/(const int &scalar) const {
            // Abort if scalar = 0
            assert(scalar != 0);
            return Mat4x4i(data[0] / scalar,
                           data[1] / scalar,
                           data[2] / scalar,
                           data[3] / scalar,
                           data[4] / scalar,
                           data[5] / scalar,
                           data[6] / scalar,
                           data[7] / scalar,
                           data[8] / scalar,
                           data[9] / scalar,
                           data[10] / scalar,
                           data[11] / scalar,
                           data[12] / scalar,
                           data[13] / scalar,
                           data[14] / scalar,
                           data[15] / scalar);
        }

        // Operator overload: +=
        Mat4x4i &operator+=(const Mat4x4i &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] += rhs.data[i];
            }
            return *this;
        }

        // Operator overload: -=
        Mat4x4i &operator-=(const Mat4x4i &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] -= rhs.data[i];
            }
            return *this;
        }

        // Operator overload: *=
        Mat4x4i &operator*=(const int &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] *= rhs;
            }
            return *this;
        }

        // Operator overload: /= (integer division)
        Mat4x4i &operator/=(const int &rhs) {
            // Abort if rhs = 0
            assert(rhs != 0);
            for (size_t i = 0; i != 16; ++i) {
                data[i] /= rhs;
            }
            return *this;
        }

        // Operator overload: -()
        Mat4x4i operator-() const {
            return Mat4x4i(-data[0],
                           -data[1],
                           -data[2],
                           -data[3],
                           -data[4],
                           -data[5],
                           -data[6],
                           -data[7],
                           -data[8],
                           -data[9],
                           -data[10],
                           -data[11],
                           -data[12],
                           -data[13],
                           -data[14],
                           -data[15]);
        }

        // Operator overload: +()
        const Mat4x4i &operator+() const {
            return *this;
        }

        // Operator overload: at(i, j) access only
        [[nodiscard]] int
        at(const unsigned int &i, const unsigned int &j) const {
            // If the index is illegal, then throw an exception.
            return data.at(i * 4 + j);
        }

        // Operator overload: at(i, j) for assignment
        int &at(const unsigned int &i, const unsigned int &j) {
            // If the index is illegal, then throw an exception.
            return data.at(i * 4 + j);
        }

        // Set all elements as the same value
        void fill(const int &value) {
            std::fill(data.begin(), data.end(), value);
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Mat4x4i operator*(const Mat4x4i &lhs, const int &scalar) {
        return Mat4x4i(lhs.data[0] * scalar,
                       lhs.data[1] * scalar,
                       lhs.data[2] * scalar,
                       lhs.data[3] * scalar,
                       lhs.data[4] * scalar,
                       lhs.data[5] * scalar,
                       lhs.data[6] * scalar,
                       lhs.data[7] * scalar,
                       lhs.data[8] * scalar,
                       lhs.data[9] * scalar,
                       lhs.data[10] * scalar,
                       lhs.data[11] * scalar,
                       lhs.data[12] * scalar,
                       lhs.data[13] * scalar,
                       lhs.data[14] * scalar,
                       lhs.data[15] * scalar);
    }

    inline
    Mat4x4i operator*(const int &scalar, const Mat4x4i &rhs) {
        return rhs * scalar;
    }

    // Operator overload as non-member function: * (Mat4x4i * Vec4i) left-multiplication
    // same as glm::ivec4 rhs * glm::imat4x4 lhs
    inline
    Vec4i operator*(const Mat4x4i &lhs, const Vec4i &rhs) {
        return Vec4i(
                lhs.data[0] * rhs.x + lhs.data[1] * rhs.y +
                lhs.data[2] * rhs.z + lhs.data[3] * rhs.w,
                lhs.data[4] * rhs.x + lhs.data[5] * rhs.y +
                lhs.data[6] * rhs.z + lhs.data[7] * rhs.w,
                lhs.data[8] * rhs.x + lhs.data[9] * rhs.y +
                lhs.data[10] * rhs.z + lhs.data[11] * rhs.w,
                lhs.data[12] * rhs.x + lhs.data[13] * rhs.y +
                lhs.data[14] * rhs.z + lhs.data[15] * rhs.w
        );
    }

    // Operator overload as non-member function: * (Mat4x4i * Mat4x4i) right-multiplication
    // same as glm::imat4x4 rhs * glm::imat4x4 lhs
    inline
    Mat4x4i operator*(const Mat4x4i &lhs, const Mat4x4i &rhs) {
        return Mat4x4i(
                lhs.data[0] * rhs.data[0] + lhs.data[1] * rhs.data[4] +
                lhs.data[2] * rhs.data[8] +
                lhs.data[3] * rhs.data[12],
                lhs.data[0] * rhs.data[1] + lhs.data[1] * rhs.data[5] +
                lhs.data[2] * rhs.data[9] +
                lhs.data[3] * rhs.data[13],
                lhs.data[0] * rhs.data[2] + lhs.data[1] * rhs.data[6] +
                lhs.data[2] * rhs.data[10] +
                lhs.data[3] * rhs.data[14],
                lhs.data[0] * rhs.data[3] + lhs.data[1] * rhs.data[7] +
                lhs.data[2] * rhs.data[11] +
                lhs.data[3] * rhs.data[15], //

                lhs.data[4] * rhs.data[0] + lhs.data[5] * rhs.data[4] +
                lhs.data[6] * rhs.data[8] +
                lhs.data[7] * rhs.data[12],
                lhs.data[4] * rhs.data[1] + lhs.data[5] * rhs.data[5] +
                lhs.data[6] * rhs.data[9] +
                lhs.data[7] * rhs.data[13],
                lhs.data[4] * rhs.data[2] + lhs.data[5] * rhs.data[6] +
                lhs.data[6] * rhs.data[10] +
                lhs.data[7] * rhs.data[14],
                lhs.data[4] * rhs.data[3] + lhs.data[5] * rhs.data[7] +
                lhs.data[6] * rhs.data[11] +
                lhs.data[7] * rhs.data[15], //

                lhs.data[8] * rhs.data[0] + lhs.data[9] * rhs.data[4] +
                lhs.data[10] * rhs.data[8] +
                lhs.data[11] * rhs.data[12],
                lhs.data[8] * rhs.data[1] + lhs.data[9] * rhs.data[5] +
                lhs.data[10] * rhs.data[9] +
                lhs.data[11] * rhs.data[13],
                lhs.data[8] * rhs.data[2] + lhs.data[9] * rhs.data[6] +
                lhs.data[10] * rhs.data[10] +
                lhs.data[11] * rhs.data[14],
                lhs.data[8] * rhs.data[3] + lhs.data[9] * rhs.data[7] +
                lhs.data[10] * rhs.data[11] +
                lhs.data[11] * rhs.data[15], //

                lhs.data[12] * rhs.data[0] + lhs.data[13] * rhs.data[4] +
                lhs.data[14] * rhs.data[8] +
                lhs.data[15] * rhs.data[12],
                lhs.data[12] * rhs.data[1] + lhs.data[13] * rhs.data[5] +
                lhs.data[14] * rhs.data[9] +
                lhs.data[15] * rhs.data[13],
                lhs.data[12] * rhs.data[2] + lhs.data[13] * rhs.data[6] +
                lhs.data[14] * rhs.data[10] +
                lhs.data[15] * rhs.data[14],
                lhs.data[12] * rhs.data[3] + lhs.data[13] * rhs.data[7] +
                lhs.data[14] * rhs.data[11] +
                lhs.data[15] * rhs.data[15] //
        );
    }

    // | 0  1  2  3 |
    // | 4  5  6  7 |
    // | 8  9 10 11 |
    // |12 13 14 15 |
    inline
    int determinant(Mat4x4i const &obj) {
        return obj.data[0] *
               determinant(Mat3x3i(obj.data[5], obj.data[6], obj.data[7],
                                   obj.data[9], obj.data[10], obj.data[11],
                                   obj.data[13], obj.data[14], obj.data[15])) -
               obj.data[1] *
               determinant(Mat3x3i(obj.data[4], obj.data[6], obj.data[7],
                                   obj.data[8], obj.data[10], obj.data[11],
                                   obj.data[12], obj.data[14], obj.data[15])) +
               obj.data[2] *
               determinant(Mat3x3i(obj.data[4], obj.data[5], obj.data[7],
                                   obj.data[8], obj.data[9], obj.data[11],
                                   obj.data[12], obj.data[13], obj.data[15])) -
               obj.data[3] *
               determinant(Mat3x3i(obj.data[4], obj.data[5], obj.data[6],
                                   obj.data[8], obj.data[9], obj.data[10],
                                   obj.data[12], obj.data[13], obj.data[14]));
    }

    // transpose
    // | 0  1  2  3 |  --> | 0  4  8 12 |
    // | 4  5  6  7 |  --> | 1  5  9 13 |
    // | 8  9 10 11 |  --> | 2  6 10 14 |
    // |12 13 14 15 |  --> | 3  7 11 15 |
    inline
    Mat4x4i transpose(Mat4x4i obj) {
        std::swap(obj.data[1], obj.data[4]);
        std::swap(obj.data[2], obj.data[8]);
        std::swap(obj.data[3], obj.data[12]);
        std::swap(obj.data[6], obj.data[9]);
        std::swap(obj.data[7], obj.data[13]);
        std::swap(obj.data[11], obj.data[14]);
        return obj;
    }

    // Structure: Vec2
    //
    // Description: A 2D Vector that holds positional data using 2 doubles
    struct Vec2 {
        // Fields
        double x;
        double y;

        // Alternative getters for UV Coords (s, t)
        [[nodiscard]] double s() const {
            return x;
        }

        [[nodiscard]] double t() const {
            return y;
        }

        // Constructor
        explicit Vec2(double x, double y) : x(x), y(y) {}

        // Default Constructor
        Vec2() : Vec2(0.0, 0.0) {}

        // Operator overload: [] access only
        double operator[](int index) const {
            // Check if index is valid
            assert(index >= 0 && index <= 1);
            if (index == 0) {
                return x;
            }
            return y;
        }

        // Operator overload: [] for assignment
        double &operator[](int index) {
            // Check if index is valid
            assert(index >= 0 && index <= 1);
            if (index == 0) {
                return x;
            }
            return y;
        }

        // Operator overload: ==
        bool operator==(const Vec2 &other) const {
            return (Math::threeWayComparator(x - other.x) == 0 &&
                    Math::threeWayComparator(y - other.y) == 0);
        }

        // Operator overload: !=
        bool operator!=(const Vec2 &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Vec2 operator+(const Vec2 &rhs) const {
            return Vec2(x + rhs.x, y + rhs.y);
        }

        // Operator overload: -
        Vec2 operator-(const Vec2 &rhs) const {
            return Vec2(x - rhs.x, y - rhs.y);
        }

        // Operator overload: /
        Vec2 operator/(const double &scalar) const {
            return Vec2(x / scalar, y / scalar);
        }

        // Operator overload: +=
        Vec2 &operator+=(const Vec2 &rhs) {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        // Operator overload: -=
        Vec2 &operator-=(const Vec2 &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        // Operator overload: *=
        Vec2 &operator*=(const double &rhs) {
            x *= rhs;
            y *= rhs;
            return *this;
        }

        // Operator overload: /=
        Vec2 &operator/=(const double &rhs) {
            x /= rhs;
            y /= rhs;
            return *this;
        }

        // Operator /= overload of two Vec2, it works component-wise like GLSL.
        Vec2 &operator/=(const Vec2 &rhs) {
            x /= rhs.x;
            y /= rhs.y;
            return *this;
        }

        // Operator overload: -()
        Vec2 operator-() const {
            return Vec2(-x, -y);
        }

        // Operator overload: +()
        const Vec2 &operator+() const {
            return *this;
        }

        // Set all elements as the same value
        void fill(const double &value) {
            x = value;
            y = value;
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Vec2 operator*(const Vec2 &lhs, const double &scalar) {
        return Vec2(lhs.x * scalar, lhs.y * scalar);
    }

    inline
    Vec2 operator*(const double &scalar, const Vec2 &rhs) {
        return rhs * scalar;
    }

    // Operator * overload of two Vec2, it works component-wise like GLSL.
    inline
    Vec2 operator*(const Vec2 &lhs, const Vec2 &rhs) {
        return Vec2(
                lhs.x * rhs.x,
                lhs.y * rhs.y
        );
    }

    // Operator / overload of two Vec2, it works component-wise like GLSL.
    inline
    Vec2 operator/(const Vec2 &lhs, const Vec2 &rhs) {
        return Vec2(
                lhs.x / rhs.x,
                lhs.y / rhs.y
        );
    }

    // dot product
    inline
    double dot(const Vec2 &lhs, const Vec2 &rhs) {
        return (lhs.x * rhs.x + lhs.y * rhs.y);
    }

    // cross product
    inline
    double cross(const Vec2 &lhs, const Vec2 &rhs) {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    // norm(length)
    inline
    double norm(const Vec2 &obj) {
        return sqrt(dot(obj, obj));
    }

    // squareLength: return length * length
    inline
    double squareLength(const Vec2 &obj) {
        return dot(obj, obj);
    }

    // distance of two vectors
    inline
    double distance(const Vec2 &lhs, const Vec2 &rhs) {
        return sqrt(
                (lhs.x - rhs.x) * (lhs.x - rhs.x) +
                (lhs.y - rhs.y) * (lhs.y - rhs.y)
        );
    }

    // normalize
    inline
    Vec2 normalize(const Vec2 &obj) {
        double objLength = norm(obj);
        return obj / objLength;
    }

    // linear interpolation
    inline
    Vec2 lerp(const Vec2 &a, const Vec2 &b, double t) {
        return (1.0 - t) * a + t * b;
    }

    // Structure: Vec3
    //
    // Description: A 3D Vector that holds positional data using 3 doubles.
    struct Vec3 {
        // Fields
        double x;
        double y;
        double z;

        // Alternative getters for RGB
        [[nodiscard]] double r() const {
            return x;
        }

        [[nodiscard]] double g() const {
            return y;
        }

        [[nodiscard]] double b() const {
            return z;
        }

        // Constructor
        explicit Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

        // Default Constructor
        Vec3() : Vec3(0.0, 0.0, 0.0) {}

        // Constructor with a Vec2
        explicit Vec3(const double &x, const Vec2 &vec2) : Vec3(x, vec2.x,
                                                                vec2.y) {}

        explicit Vec3(const Vec2 &vec2, const double &z) : Vec3(vec2.x,
                                                                vec2.y,
                                                                z) {}

        // Operator overload: [] access only
        double operator[](int index) const {
            // Check if index is valid
            assert(index >= 0 && index <= 2);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                default:
                    return z;
            }
        }

        // Operator overload: [] for assignment
        double &operator[](int index) {
            // Check if index is valid
            assert(index >= 0 && index <= 2);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                default:
                    return z;
            }
        }

        // Operator overload: ==
        bool operator==(const Vec3 &other) const {
            return (Math::threeWayComparator(x - other.x) == 0 &&
                    Math::threeWayComparator(y - other.y) == 0 &&
                    Math::threeWayComparator(z - other.z) == 0);
        }

        // Operator overload: !=
        bool operator!=(const Vec3 &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Vec3 operator+(const Vec3 &rhs) const {
            return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
        }

        // Operator overload: -
        Vec3 operator-(const Vec3 &rhs) const {
            return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        // Operator overload: /
        Vec3 operator/(const double &scalar) const {
            return Vec3(x / scalar, y / scalar, z / scalar);
        }

        // Operator overload: +=
        Vec3 &operator+=(const Vec3 &rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            return *this;
        }

        // Operator overload: -=
        Vec3 &operator-=(const Vec3 &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            return *this;
        }

        // Operator overload: *=
        Vec3 &operator*=(const double &rhs) {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            return *this;
        }

        // Operator overload: /=
        Vec3 &operator/=(const double &rhs) {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            return *this;
        }

        // Operator /= overload of two Vec3, it works component-wise like GLSL.
        Vec3 &operator/=(const Vec3 &rhs) {
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            return *this;
        }

        // Operator overload: -()
        Vec3 operator-() const {
            return Vec3(-x, -y, -z);
        }

        // Operator overload: +()
        const Vec3 &operator+() const {
            return *this;
        }

        // Set all elements as the same value
        void fill(const double &value) {
            x = value;
            y = value;
            z = value;
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Vec3 operator*(const Vec3 &lhs, const double &scalar) {
        return Vec3(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
    }

    inline
    Vec3 operator*(const double &scalar, const Vec3 &rhs) {
        return rhs * scalar;
    }

    // Operator * overload of two Vec3, it works component-wise like GLSL.
    inline
    Vec3 operator*(const Vec3 &lhs, const Vec3 &rhs) {
        return Vec3(
                lhs.x * rhs.x,
                lhs.y * rhs.y,
                lhs.z * rhs.z
        );
    }

    // Operator / overload of two Vec3, it works component-wise like GLSL.
    inline
    Vec3 operator/(const Vec3 &lhs, const Vec3 &rhs) {
        return Vec3(
                lhs.x / rhs.x,
                lhs.y / rhs.y,
                lhs.z / rhs.z
        );
    }

    // dot product
    inline
    double dot(const Vec3 &lhs, const Vec3 &rhs) {
        return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
    }

    // cross product
    inline
    Vec3 cross(const Vec3 &lhs, const Vec3 &rhs) {
        return Vec3(
                lhs.y * rhs.z - rhs.y * lhs.z,
                lhs.z * rhs.x - rhs.z * lhs.x,
                lhs.x * rhs.y - rhs.x * lhs.y
        );
    }

    // norm(length)
    inline
    double norm(const Vec3 &obj) {
        return sqrt(dot(obj, obj));
    }

    // squareLength: return length * length
    inline
    double squareLength(const Vec3 &obj) {
        return dot(obj, obj);
    }

    // distance of two vectors
    inline
    double distance(const Vec3 &lhs, const Vec3 &rhs) {
        return sqrt(
                (lhs.x - rhs.x) * (lhs.x - rhs.x) +
                (lhs.y - rhs.y) * (lhs.y - rhs.y) +
                (lhs.z - rhs.z) * (lhs.z - rhs.z)
        );
    }

    // normalize
    inline
    Vec3 normalize(const Vec3 &obj) {
        double objLength = norm(obj);
        return obj / objLength;
    }

    // linear interpolation
    inline
    Vec3 lerp(const Vec3 &a, const Vec3 &b, double t) {
        return (1.0 - t) * a + t * b;
    }

    // obtain the vector by the vector in and a normal unit vector after reflection
    Vec3 reflect(const Vec3 &in, const Vec3 &n) {
        return in - 2.0 * dot(in, n) * n;
    }

    // Structure: Vec4
    //
    // Description: A 3D Vector that holds positional data using 4 doubles in a homogeneous coordinate system.
    struct Vec4 {
        // Fields
        double x;
        double y;
        double z;
        double w;

        // Alternative getters for RGBA
        [[nodiscard]] double r() const {
            return x;
        }

        [[nodiscard]] double g() const {
            return y;
        }

        [[nodiscard]] double b() const {
            return z;
        }

        [[nodiscard]] double a() const {
            return w;
        }

        // Constructor
        explicit Vec4(double x, double y, double z, double w) : x(x), y(y),
                                                                z(z),
                                                                w(w) {}

        // Default Constructor
        Vec4() : Vec4(0.0, 0.0, 0.0, 0.0) {}

        // Constructor with 2 'Vec2's
        explicit Vec4(const Vec2 &a, const Vec2 &b) : Vec4(a.x, a.y, b.x,
                                                           b.y) {}

        // Constructor with 1 'Vec2'
        explicit Vec4(const Vec2 &vec2, const double &z, const double &w)
                : Vec4(vec2.x, vec2.y, z, w) {}

        explicit Vec4(const double &x, const Vec2 &vec2, const double &w)
                : Vec4(x, vec2.x, vec2.y, w) {}

        explicit Vec4(const double &x, const double &y, const Vec2 &vec2)
                : Vec4(x, y, vec2.x, vec2.y) {}

        // Constructor with 1 'Vec3'
        explicit Vec4(const Vec3 &vec3, const double &w) : Vec4(vec3.x,
                                                                vec3.y,
                                                                vec3.z,
                                                                w) {}

        explicit Vec4(const double &x, const Vec3 &vec3) : Vec4(x, vec3.x,
                                                                vec3.y,
                                                                vec3.z) {}

        // Operator overload: [] access only
        double operator[](int index) const {
            // Check if index is valid
            assert(index >= 0 && index <= 3);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                default:
                    return w;
            }
        }

        // Operator overload: [] for assignment
        double &operator[](int index) {
            // Check if index is valid
            assert(index >= 0 && index <= 3);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                default:
                    return w;
            }
        }

        // Operator overload: ==
        bool operator==(const Vec4 &other) const {
            return (Math::threeWayComparator(x - other.x) == 0 &&
                    Math::threeWayComparator(y - other.y) == 0 &&
                    Math::threeWayComparator(z - other.z) == 0 &&
                    Math::threeWayComparator(w - other.w) == 0);
        }

        // Operator overload: !=
        bool operator!=(const Vec4 &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Vec4 operator+(const Vec4 &rhs) const {
            return Vec4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
        }

        // Operator overload: -
        Vec4 operator-(const Vec4 &rhs) const {
            return Vec4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
        }

        // Operator overload: /
        Vec4 operator/(const double &scalar) const {
            return Vec4(x / scalar, y / scalar, z / scalar, w / scalar);
        }

        // Operator overload: +=
        Vec4 &operator+=(const Vec4 &rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            w += rhs.w;
            return *this;
        }

        // Operator overload: -=
        Vec4 &operator-=(const Vec4 &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            w -= rhs.w;
            return *this;
        }

        // Operator overload: *=
        Vec4 &operator*=(const double &rhs) {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            w *= rhs;
            return *this;
        }

        // Operator overload: /=
        Vec4 &operator/=(const double &rhs) {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            w /= rhs;
            return *this;
        }

        // Operator /= overload of two Vec4, it works component-wise like GLSL.
        Vec4 &operator/=(const Vec4 &rhs) {
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            w /= rhs.w;
            return *this;
        }

        // Operator overload: -()
        Vec4 operator-() const {
            return Vec4(-x, -y, -z, -w);
        }

        // Operator overload: +()
        const Vec4 &operator+() const {
            return *this;
        }

        // Set all elements as the same value
        void fill(const double &value) {
            x = value;
            y = value;
            z = value;
            w = value;
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Vec4 operator*(const Vec4 &lhs, const double &scalar) {
        return Vec4(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar,
                    lhs.w * scalar);
    }

    inline
    Vec4 operator*(const double &scalar, const Vec4 &rhs) {
        return rhs * scalar;
    }

    // Operator * overload of two Vec4, it works component-wise like GLSL.
    inline
    Vec4 operator*(const Vec4 &lhs, const Vec4 &rhs) {
        return Vec4(
                lhs.x * rhs.x,
                lhs.y * rhs.y,
                lhs.z * rhs.z,
                lhs.w * rhs.w
        );
    }

    // Operator / overload of two Vec4, it works component-wise like GLSL.
    inline
    Vec4 operator/(const Vec4 &lhs, const Vec4 &rhs) {
        return Vec4(
                lhs.x / rhs.x,
                lhs.y / rhs.y,
                lhs.z / rhs.z,
                lhs.w / rhs.w
        );
    }

    // dot product
    inline
    double dot(const Vec4 &lhs, const Vec4 &rhs) {
        return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w);
    }

    // norm(length)
    inline
    double norm(const Vec4 &obj) {
        return sqrt(dot(obj, obj));
    }

    // squareLength: return length * length
    inline
    double squareLength(const Vec4 &obj) {
        return dot(obj, obj);
    }

    // distance of two vectors
    inline
    double distance(const Vec4 &lhs, const Vec4 &rhs) {
        return sqrt(
                (lhs.x - rhs.x) * (lhs.x - rhs.x) +
                (lhs.y - rhs.y) * (lhs.y - rhs.y) +
                (lhs.z - rhs.z) * (lhs.z - rhs.z) +
                (lhs.w - rhs.w) * (lhs.w - rhs.w)
        );
    }

    // normalize
    inline
    Vec4 normalize(const Vec4 &obj) {
        double objLength = norm(obj);
        return obj / objLength;
    }

    // linear interpolation
    inline
    Vec4 lerp(const Vec4 &a, const Vec4 &b, double t) {
        return (1.0 - t) * a + t * b;
    }

    // Structure: Mat2x2
    //
    // Description: A 2x2 matrix where each element is a 'double' type, a std::array is used to store all elements.
    // Diagram: {0,1,2,3} --> |0 1|
    //                        |2 3|
    struct Mat2x2 {
        // Field
        std::array<double, 4> data{};

        // Constructor
        explicit Mat2x2(const double &e0, const double &e1, const double &e2,
                        const double &e3) {
            data[0] = e0;
            data[1] = e1;
            data[2] = e2;
            data[3] = e3;
        }

        // Default constructor
        Mat2x2() = default;

        // Constructor takes std::array<double, 4>
        explicit Mat2x2(const std::array<double, 4> &rhs) : data(rhs) {}

        // Constructor std::initializer_list<double>
        Mat2x2(const std::initializer_list<double> &rhs) {
            // Check if the length of rhs is not 4
            assert(rhs.size() == 4);
            std::copy(rhs.begin(), rhs.end(), data.begin());
        }

        // Constructor as an identity * scalar
        explicit Mat2x2(const double &scalar) {
            data[0] = scalar;
            data[1] = 0.0;
            data[2] = 0.0;
            data[3] = scalar;
        }

        // Operator overload: ==
        bool operator==(const Mat2x2 &other) const {
            for (unsigned int i = 0; i != 2; ++i) {
                for (unsigned int j = 0; j != 2; ++j) {
                    if (Math::threeWayComparator(
                            this->at(i, j) - other.at(i, j)) != 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        // Operator overload: !=
        bool operator!=(const Mat2x2 &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Mat2x2 operator+(const Mat2x2 &rhs) const {
            return Mat2x2(data[0] + rhs.data[0],
                          data[1] + rhs.data[1],
                          data[2] + rhs.data[2],
                          data[3] + rhs.data[3]);
        }

        // Operator overload: -
        Mat2x2 operator-(const Mat2x2 &rhs) const {
            return Mat2x2(data[0] - rhs.data[0],
                          data[1] - rhs.data[1],
                          data[2] - rhs.data[2],
                          data[3] - rhs.data[3]);
        }

        // Operator overload: /
        Mat2x2 operator/(const double &scalar) const {
            return Mat2x2(data[0] / scalar,
                          data[1] / scalar,
                          data[2] / scalar,
                          data[3] / scalar);
        }

        // Operator overload: +=
        Mat2x2 &operator+=(const Mat2x2 &rhs) {
            data[0] += rhs.data[0];
            data[1] += rhs.data[1];
            data[2] += rhs.data[2];
            data[3] += rhs.data[3];
            return *this;
        }

        // Operator overload: -=
        Mat2x2 &operator-=(const Mat2x2 &rhs) {
            data[0] -= rhs.data[0];
            data[1] -= rhs.data[1];
            data[2] -= rhs.data[2];
            data[3] -= rhs.data[3];
            return *this;
        }

        // Operator overload: *=
        Mat2x2 &operator*=(const double &rhs) {
            data[0] *= rhs;
            data[1] *= rhs;
            data[2] *= rhs;
            data[3] *= rhs;
            return *this;
        }

        // Operator overload: /=
        Mat2x2 &operator/=(const double &rhs) {
            data[0] /= rhs;
            data[1] /= rhs;
            data[2] /= rhs;
            data[3] /= rhs;
            return *this;
        }

        // Operator overload: -()
        Mat2x2 operator-() const {
            return Mat2x2(-data[0],
                          -data[1],
                          -data[2],
                          -data[3]);
        }

        // Operator overload: +()
        const Mat2x2 &operator+() const {
            return *this;
        }

        // Operator overload: at(i, j) access only
        [[nodiscard]] double
        at(const unsigned int &i, const unsigned int &j) const {
            // If the index is illegal, then throw an exception.
            return data.at(i * 2 + j);
        }

        // Operator overload: at(i, j) for assignment
        double &at(const unsigned int &i, const unsigned int &j) {
            // If the index is illegal, then throw an exception.
            return data.at(i * 2 + j);
        }

        // Set all elements as the same value
        void fill(const double &value) {
            std::fill(data.begin(), data.end(), value);
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Mat2x2 operator*(const Mat2x2 &lhs, const double &scalar) {
        return Mat2x2(lhs.data[0] * scalar,
                      lhs.data[1] * scalar,
                      lhs.data[2] * scalar,
                      lhs.data[3] * scalar);
    }

    inline
    Mat2x2 operator*(const double &scalar, const Mat2x2 &rhs) {
        return rhs * scalar;
    }

    // Operator overload as non-member function: * (Mat2x2 * Vec2) right-multiplication
    // same as glm::dvec2 rhs * glm::dmat2x2 lhs
    inline
    Vec2 operator*(const Mat2x2 &lhs, const Vec2 &rhs) {
        return Vec2(
                lhs.data[0] * rhs.x + lhs.data[1] * rhs.y,
                lhs.data[2] * rhs.x + lhs.data[3] * rhs.y
        );
    }

    // Operator overload as non-member function: * (Mat2x2 * Mat2x2) right-multiplication
    // same as glm::dmat2x2 rhs * glm::dmat2x2 lhs
    inline
    Mat2x2 operator*(const Mat2x2 &lhs, const Mat2x2 &rhs) {
        return Mat2x2(
                lhs.data[0] * rhs.data[0] + lhs.data[1] * rhs.data[2],
                lhs.data[0] * rhs.data[1] + lhs.data[1] * rhs.data[3],
                lhs.data[2] * rhs.data[0] + lhs.data[3] * rhs.data[2],
                lhs.data[2] * rhs.data[1] + lhs.data[3] * rhs.data[3]
        );
    }

    inline
    double determinant(Mat2x2 const &obj) {
        return obj.data[0] * obj.data[3] - obj.data[1] * obj.data[2];
    }

    inline
    Mat2x2 inverse(Mat2x2 const &obj) {
        double temp = determinant(obj);
        temp = 1.0 / temp;
        Mat2x2 result(
                obj.data[3] * temp,
                -obj.data[1] * temp,
                -obj.data[2] * temp,
                obj.data[0] * temp
        );
        return result;
    }

    // transpose
    // | 0 1 |  --> | 0 2 |
    // | 2 3 |  --> | 1 3 |
    inline
    Mat2x2 transpose(Mat2x2 obj) {
        std::swap(obj.at(0, 1), obj.at(1, 0));
        return obj;
    }

    // Structure: Mat3x3
    //
    // Description: A 3x3 matrix where each element is a 'double' type, a std::array is used to store all elements.
    // Diagram: {0,1,2,3,4,5,6,7,8} --> |0 1 2|
    //                                  |3 4 5|
    //                                  |6 7 8|
    struct Mat3x3 {
        // Field
        std::array<double, 9> data{};

        // Constructor
        explicit Mat3x3(const double &e0,
                        const double &e1,
                        const double &e2,
                        const double &e3,
                        const double &e4,
                        const double &e5,
                        const double &e6,
                        const double &e7,
                        const double &e8) {
            data[0] = e0;
            data[1] = e1;
            data[2] = e2;
            data[3] = e3;
            data[4] = e4;
            data[5] = e5;
            data[6] = e6;
            data[7] = e7;
            data[8] = e8;
        }

        // Default constructor
        Mat3x3() = default;

        // Constructor takes std::array<double, 9>
        explicit Mat3x3(const std::array<double, 9> &rhs) : data(rhs) {}

        // Constructor std::initializer_list<double>
        Mat3x3(const std::initializer_list<double> &rhs) {
            // Check if the length of rhs is not 9
            assert(rhs.size() == 9);
            std::copy(rhs.begin(), rhs.end(), data.begin());
        }

        // Constructor as an identity * scalar
        explicit Mat3x3(const double &scalar) {
            data[0] = scalar;
            data[1] = 0.0;
            data[2] = 0.0;
            data[3] = 0.0;
            data[4] = scalar;
            data[5] = 0.0;
            data[6] = 0.0;
            data[7] = 0.0;
            data[8] = scalar;
        }

        // Operator overload: ==
        bool operator==(const Mat3x3 &other) const {
            for (unsigned int i = 0; i != 3; ++i) {
                for (unsigned int j = 0; j != 3; ++j) {
                    if (Math::threeWayComparator(
                            this->at(i, j) - other.at(i, j)) != 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        // Operator overload: !=
        bool operator!=(const Mat3x3 &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Mat3x3 operator+(const Mat3x3 &rhs) const {
            Mat3x3 result;
            for (size_t i = 0; i != 9; ++i) {
                result.data[i] += rhs.data[i];
            }
            return result;
        }

        // Operator overload: -
        Mat3x3 operator-(const Mat3x3 &rhs) const {
            Mat3x3 result;
            for (size_t i = 0; i != 9; ++i) {
                result.data[i] -= rhs.data[i];
            }
            return result;
        }

        // Operator overload: /
        Mat3x3 operator/(const double &scalar) const {
            return Mat3x3(data[0] / scalar,
                          data[1] / scalar,
                          data[2] / scalar,
                          data[3] / scalar,
                          data[4] / scalar,
                          data[5] / scalar,
                          data[6] / scalar,
                          data[7] / scalar,
                          data[8] / scalar);
        }

        // Operator overload: +=
        Mat3x3 &operator+=(const Mat3x3 &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] += rhs.data[i];
            }
            return *this;
        }

        // Operator overload: -=
        Mat3x3 &operator-=(const Mat3x3 &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] -= rhs.data[i];
            }
            return *this;
        }

        // Operator overload: *=
        Mat3x3 &operator*=(const double &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] *= rhs;
            }
            return *this;
        }

        // Operator overload: /=
        Mat3x3 &operator/=(const double &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] /= rhs;
            }
            return *this;
        }

        // Operator overload: -()
        Mat3x3 operator-() const {
            return Mat3x3(-data[0],
                          -data[1],
                          -data[2],
                          -data[3],
                          -data[4],
                          -data[5],
                          -data[6],
                          -data[7],
                          -data[8]);
        }

        // Operator overload: +()
        const Mat3x3 &operator+() const {
            return *this;
        }

        // Operator overload: at(i, j) access only
        [[nodiscard]] double
        at(const unsigned int &i, const unsigned int &j) const {
            // If the index is illegal, then throw an exception.
            return data.at(i * 3 + j);
        }

        // Operator overload: at(i, j) for assignment
        double &at(const unsigned int &i, const unsigned int &j) {
            // If the index is illegal, then throw an exception.
            return data.at(i * 3 + j);
        }

        // Set all elements as the same value
        void fill(const double &value) {
            std::fill(data.begin(), data.end(), value);
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Mat3x3 operator*(const Mat3x3 &lhs, const double &scalar) {
        return Mat3x3(lhs.data[0] * scalar,
                      lhs.data[1] * scalar,
                      lhs.data[2] * scalar,
                      lhs.data[3] * scalar,
                      lhs.data[4] * scalar,
                      lhs.data[5] * scalar,
                      lhs.data[6] * scalar,
                      lhs.data[7] * scalar,
                      lhs.data[8] * scalar);
    }

    inline
    Mat3x3 operator*(const double &scalar, const Mat3x3 &rhs) {
        return rhs * scalar;
    }

    // Operator overload as non-member function: * (Mat3x3 * Vec3) left-multiplication
    // same as glm::dvec3 rhs * glm::dmat3x3 lhs
    inline
    Vec3 operator*(const Mat3x3 &lhs, const Vec3 &rhs) {
        return Vec3(
                lhs.data[0] * rhs.x + lhs.data[1] * rhs.y + lhs.data[2] * rhs.z,
                lhs.data[3] * rhs.x + lhs.data[4] * rhs.y + lhs.data[5] * rhs.z,
                lhs.data[6] * rhs.x + lhs.data[7] * rhs.y + lhs.data[8] * rhs.z
        );
    }

    // Operator overload as non-member function: * (Mat3x3 * Mat3x3) right-multiplication
    // same as glm::mat3x3 rhs * glm::mat3x3 lhs
    inline
    Mat3x3 operator*(const Mat3x3 &lhs, const Mat3x3 &rhs) {
        return Mat3x3(
                lhs.data[0] * rhs.data[0] + lhs.data[1] * rhs.data[3] +
                lhs.data[2] * rhs.data[6],
                lhs.data[0] * rhs.data[1] + lhs.data[1] * rhs.data[4] +
                lhs.data[2] * rhs.data[7],
                lhs.data[0] * rhs.data[2] + lhs.data[1] * rhs.data[5] +
                lhs.data[2] * rhs.data[8],
                lhs.data[3] * rhs.data[0] + lhs.data[4] * rhs.data[3] +
                lhs.data[5] * rhs.data[6],
                lhs.data[3] * rhs.data[1] + lhs.data[4] * rhs.data[4] +
                lhs.data[5] * rhs.data[7],
                lhs.data[3] * rhs.data[2] + lhs.data[4] * rhs.data[5] +
                lhs.data[5] * rhs.data[8],
                lhs.data[6] * rhs.data[0] + lhs.data[7] * rhs.data[3] +
                lhs.data[8] * rhs.data[6],
                lhs.data[6] * rhs.data[1] + lhs.data[7] * rhs.data[4] +
                lhs.data[8] * rhs.data[7],
                lhs.data[6] * rhs.data[2] + lhs.data[7] * rhs.data[5] +
                lhs.data[8] * rhs.data[8]
        );
    }

    inline
    double determinant(Mat3x3 const &obj) {
        return obj.at(0, 0) *
               (obj.at(1, 1) * obj.at(2, 2) - obj.at(2, 1) * obj.at(1, 2)) -
               obj.at(0, 1) *
               (obj.at(1, 0) * obj.at(2, 2) - obj.at(1, 2) * obj.at(2, 0)) +
               obj.at(0, 2) *
               (obj.at(1, 0) * obj.at(2, 1) - obj.at(1, 1) * obj.at(2, 0));
    }

    inline
    Mat3x3 inverse(Mat3x3 const &obj) {
        double temp = determinant(obj);
        temp = 1.0 / temp;
        Mat3x3 result(
                (obj.at(1, 1) * obj.at(2, 2) - obj.at(2, 1) * obj.at(1, 2)) *
                temp,
                (obj.at(0, 2) * obj.at(2, 1) - obj.at(0, 1) * obj.at(2, 2)) *
                temp,
                (obj.at(0, 1) * obj.at(1, 2) - obj.at(0, 2) * obj.at(1, 1)) *
                temp,
                (obj.at(1, 2) * obj.at(2, 0) - obj.at(1, 0) * obj.at(2, 2)) *
                temp,
                (obj.at(0, 0) * obj.at(2, 2) - obj.at(0, 2) * obj.at(2, 0)) *
                temp,
                (obj.at(1, 0) * obj.at(0, 2) - obj.at(0, 0) * obj.at(1, 2)) *
                temp,
                (obj.at(1, 0) * obj.at(2, 1) - obj.at(2, 0) * obj.at(1, 1)) *
                temp,
                (obj.at(2, 0) * obj.at(0, 1) - obj.at(0, 0) * obj.at(2, 1)) *
                temp,
                (obj.at(0, 0) * obj.at(1, 1) - obj.at(1, 0) * obj.at(0, 1)) *
                temp
        );
        return result;
    }

    // transpose
    // | 0 1 2 |  --> | 0 3 6 |
    // | 3 4 5 |  --> | 1 4 7 |
    // | 6 7 8 |  --> | 2 5 8 |
    inline
    Mat3x3 transpose(Mat3x3 obj) {
        std::swap(obj.data[3], obj.data[1]);
        std::swap(obj.data[6], obj.data[2]);
        std::swap(obj.data[7], obj.data[5]);
        return obj;
    }

    // Structure: Mat4x4
    //
    // Description: A 4x4 matrix where each element is a 'double' type, a std::array is used to store all elements.
    // Diagram: {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} --> |0   1  2  3|
    //                                                      |4   5  6  7|
    //                                                      |8   9 10 11|
    //                                                      |12 13 14 15|
    struct Mat4x4 {
        // Field
        std::array<double, 16> data{};

        // Constructor
        explicit Mat4x4(const double &e0,
                        const double &e1,
                        const double &e2,
                        const double &e3,
                        const double &e4,
                        const double &e5,
                        const double &e6,
                        const double &e7,
                        const double &e8,
                        const double &e9,
                        const double &e10,
                        const double &e11,
                        const double &e12,
                        const double &e13,
                        const double &e14,
                        const double &e15) {
            data[0] = e0;
            data[1] = e1;
            data[2] = e2;
            data[3] = e3;
            data[4] = e4;
            data[5] = e5;
            data[6] = e6;
            data[7] = e7;
            data[8] = e8;
            data[9] = e9;
            data[10] = e10;
            data[11] = e11;
            data[12] = e12;
            data[13] = e13;
            data[14] = e14;
            data[15] = e15;
        }

        // Default constructor
        Mat4x4() = default;

        // Constructor takes std::array<double, 16>
        explicit Mat4x4(const std::array<double, 16> &rhs) : data(rhs) {}

        // Constructor std::initializer_list<double>
        Mat4x4(const std::initializer_list<double> &rhs) {
            // Check if the length of rhs is not 16
            assert(rhs.size() == 16);
            std::copy(rhs.begin(), rhs.end(), data.begin());
        }

        // Constructor as an identity * scalar
        explicit Mat4x4(const double &scalar) {
            data[0] = scalar;
            data[1] = 0.0;
            data[2] = 0.0;
            data[3] = 0.0;
            data[4] = 0.0;
            data[5] = scalar;
            data[6] = 0.0;
            data[7] = 0.0;
            data[8] = 0.0;
            data[9] = 0.0;
            data[10] = scalar;
            data[11] = 0.0;
            data[12] = 0.0;
            data[13] = 0.0;
            data[14] = 0.0;
            data[15] = scalar;
        }

        // Operator overload: ==
        bool operator==(const Mat4x4 &other) const {
            for (unsigned int i = 0; i != 4; ++i) {
                for (unsigned int j = 0; j != 4; ++j) {
                    if (Math::threeWayComparator(
                            this->at(i, j) - other.at(i, j)) != 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        // Operator overload: !=
        bool operator!=(const Mat4x4 &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Mat4x4 operator+(const Mat4x4 &rhs) const {
            Mat4x4 result;
            for (size_t i = 0; i != 16; ++i) {
                result.data[i] += rhs.data[i];
            }
            return result;
        }

        // Operator overload: -
        Mat4x4 operator-(const Mat4x4 &rhs) const {
            Mat4x4 result;
            for (size_t i = 0; i != 16; ++i) {
                result.data[i] -= rhs.data[i];
            }
            return result;
        }

        // Operator overload: /
        Mat4x4 operator/(const double &scalar) const {
            return Mat4x4(data[0] / scalar,
                          data[1] / scalar,
                          data[2] / scalar,
                          data[3] / scalar,
                          data[4] / scalar,
                          data[5] / scalar,
                          data[6] / scalar,
                          data[7] / scalar,
                          data[8] / scalar,
                          data[9] / scalar,
                          data[10] / scalar,
                          data[11] / scalar,
                          data[12] / scalar,
                          data[13] / scalar,
                          data[14] / scalar,
                          data[15] / scalar);
        }

        // Operator overload: +=
        Mat4x4 &operator+=(const Mat4x4 &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] += rhs.data[i];
            }
            return *this;
        }

        // Operator overload: -=
        Mat4x4 &operator-=(const Mat4x4 &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] -= rhs.data[i];
            }
            return *this;
        }

        // Operator overload: *=
        Mat4x4 &operator*=(const double &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] *= rhs;
            }
            return *this;
        }

        // Operator overload: /=
        Mat4x4 &operator/=(const double &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] /= rhs;
            }
            return *this;
        }

        // Operator overload: -()
        Mat4x4 operator-() const {
            return Mat4x4(-data[0],
                          -data[1],
                          -data[2],
                          -data[3],
                          -data[4],
                          -data[5],
                          -data[6],
                          -data[7],
                          -data[8],
                          -data[9],
                          -data[10],
                          -data[11],
                          -data[12],
                          -data[13],
                          -data[14],
                          -data[15]);
        }

        // Operator overload: +()
        const Mat4x4 &operator+() const {
            return *this;
        }

        // Operator overload: at(i, j) access only
        [[nodiscard]] double
        at(const unsigned int &i, const unsigned int &j) const {
            // If the index is illegal, then throw an exception.
            return data.at(i * 4 + j);
        }

        // Operator overload: at(i, j) for assignment
        double &at(const unsigned int &i, const unsigned int &j) {
            // If the index is illegal, then throw an exception.
            return data.at(i * 4 + j);
        }

        // Set all elements as the same value
        void fill(const double &value) {
            std::fill(data.begin(), data.end(), value);
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Mat4x4 operator*(const Mat4x4 &lhs, const double &scalar) {
        return Mat4x4(lhs.data[0] * scalar,
                      lhs.data[1] * scalar,
                      lhs.data[2] * scalar,
                      lhs.data[3] * scalar,
                      lhs.data[4] * scalar,
                      lhs.data[5] * scalar,
                      lhs.data[6] * scalar,
                      lhs.data[7] * scalar,
                      lhs.data[8] * scalar,
                      lhs.data[9] * scalar,
                      lhs.data[10] * scalar,
                      lhs.data[11] * scalar,
                      lhs.data[12] * scalar,
                      lhs.data[13] * scalar,
                      lhs.data[14] * scalar,
                      lhs.data[15] * scalar);
    }

    inline
    Mat4x4 operator*(const double &scalar, const Mat4x4 &rhs) {
        return rhs * scalar;
    }

    // Operator overload as non-member function: * (Mat4x4 * Vec4) left-multiplication
    // same as glm::dvec4 rhs * glm:dmat4x4 lhs
    inline
    Vec4 operator*(const Mat4x4 &lhs, const Vec4 &rhs) {
        return Vec4(
                lhs.data[0] * rhs.x + lhs.data[1] * rhs.y +
                lhs.data[2] * rhs.z + lhs.data[3] * rhs.w,
                lhs.data[4] * rhs.x + lhs.data[5] * rhs.y +
                lhs.data[6] * rhs.z + lhs.data[7] * rhs.w,
                lhs.data[8] * rhs.x + lhs.data[9] * rhs.y +
                lhs.data[10] * rhs.z + lhs.data[11] * rhs.w,
                lhs.data[12] * rhs.x + lhs.data[13] * rhs.y +
                lhs.data[14] * rhs.z + lhs.data[15] * rhs.w
        );
    }

    // Operator overload as non-member function: * (Mat4x4 * Mat4x4) right-multiplication
    // same as glm::dmat4x4 rhs * glm::dmat4x4 lhs
    inline
    Mat4x4 operator*(const Mat4x4 &lhs, const Mat4x4 &rhs) {
        return Mat4x4(
                lhs.data[0] * rhs.data[0] + lhs.data[1] * rhs.data[4] +
                lhs.data[2] * rhs.data[8] +
                lhs.data[3] * rhs.data[12],
                lhs.data[0] * rhs.data[1] + lhs.data[1] * rhs.data[5] +
                lhs.data[2] * rhs.data[9] +
                lhs.data[3] * rhs.data[13],
                lhs.data[0] * rhs.data[2] + lhs.data[1] * rhs.data[6] +
                lhs.data[2] * rhs.data[10] +
                lhs.data[3] * rhs.data[14],
                lhs.data[0] * rhs.data[3] + lhs.data[1] * rhs.data[7] +
                lhs.data[2] * rhs.data[11] +
                lhs.data[3] * rhs.data[15], // 1st row

                lhs.data[4] * rhs.data[0] + lhs.data[5] * rhs.data[4] +
                lhs.data[6] * rhs.data[8] +
                lhs.data[7] * rhs.data[12],
                lhs.data[4] * rhs.data[1] + lhs.data[5] * rhs.data[5] +
                lhs.data[6] * rhs.data[9] +
                lhs.data[7] * rhs.data[13],
                lhs.data[4] * rhs.data[2] + lhs.data[5] * rhs.data[6] +
                lhs.data[6] * rhs.data[10] +
                lhs.data[7] * rhs.data[14],
                lhs.data[4] * rhs.data[3] + lhs.data[5] * rhs.data[7] +
                lhs.data[6] * rhs.data[11] +
                lhs.data[7] * rhs.data[15], // 2nd row

                lhs.data[8] * rhs.data[0] + lhs.data[9] * rhs.data[4] +
                lhs.data[10] * rhs.data[8] +
                lhs.data[11] * rhs.data[12],
                lhs.data[8] * rhs.data[1] + lhs.data[9] * rhs.data[5] +
                lhs.data[10] * rhs.data[9] +
                lhs.data[11] * rhs.data[13],
                lhs.data[8] * rhs.data[2] + lhs.data[9] * rhs.data[6] +
                lhs.data[10] * rhs.data[10] +
                lhs.data[11] * rhs.data[14],
                lhs.data[8] * rhs.data[3] + lhs.data[9] * rhs.data[7] +
                lhs.data[10] * rhs.data[11] +
                lhs.data[11] * rhs.data[15], // 3rd row

                lhs.data[12] * rhs.data[0] + lhs.data[13] * rhs.data[4] +
                lhs.data[14] * rhs.data[8] +
                lhs.data[15] * rhs.data[12],
                lhs.data[12] * rhs.data[1] + lhs.data[13] * rhs.data[5] +
                lhs.data[14] * rhs.data[9] +
                lhs.data[15] * rhs.data[13],
                lhs.data[12] * rhs.data[2] + lhs.data[13] * rhs.data[6] +
                lhs.data[14] * rhs.data[10] +
                lhs.data[15] * rhs.data[14],
                lhs.data[12] * rhs.data[3] + lhs.data[13] * rhs.data[7] +
                lhs.data[14] * rhs.data[11] +
                lhs.data[15] * rhs.data[15] // 4th row
        );
    }

    // | 0  1  2  3 |
    // | 4  5  6  7 |
    // | 8  9 10 11 |
    // |12 13 14 15 |
    inline
    double determinant(Mat4x4 const &obj) {
        return obj.data[0] *
               determinant(Mat3x3(obj.data[5], obj.data[6], obj.data[7],
                                  obj.data[9], obj.data[10], obj.data[11],
                                  obj.data[13], obj.data[14], obj.data[15])) -
               obj.data[1] *
               determinant(Mat3x3(obj.data[4], obj.data[6], obj.data[7],
                                  obj.data[8], obj.data[10], obj.data[11],
                                  obj.data[12], obj.data[14], obj.data[15])) +
               obj.data[2] *
               determinant(Mat3x3(obj.data[4], obj.data[5], obj.data[7],
                                  obj.data[8], obj.data[9], obj.data[11],
                                  obj.data[12], obj.data[13], obj.data[15])) -
               obj.data[3] *
               determinant(Mat3x3(obj.data[4], obj.data[5], obj.data[6],
                                  obj.data[8], obj.data[9], obj.data[10],
                                  obj.data[12], obj.data[13], obj.data[14]));
    }

    // transpose
    // | 0  1  2  3 |  --> | 0  4  8 12 |
    // | 4  5  6  7 |  --> | 1  5  9 13 |
    // | 8  9 10 11 |  --> | 2  6 10 14 |
    // |12 13 14 15 |  --> | 3  7 11 15 |
    inline
    Mat4x4 transpose(Mat4x4 obj) {
        std::swap(obj.data[1], obj.data[4]);
        std::swap(obj.data[2], obj.data[8]);
        std::swap(obj.data[3], obj.data[12]);
        std::swap(obj.data[6], obj.data[9]);
        std::swap(obj.data[7], obj.data[13]);
        std::swap(obj.data[11], obj.data[14]);
        return obj;
    }

    // Structure: Vec2f
    //
    // Description: A 2D Vector that holds positional data using 2 floats
    struct Vec2f {
        // Fields
        float x;
        float y;

        // Alternative getters for UV Coords (s, t)
        [[nodiscard]] float s() const {
            return x;
        }

        [[nodiscard]] float t() const {
            return y;
        }

        // Constructor
        explicit Vec2f(float x, float y) : x(x), y(y) {}

        // Default Constructor
        Vec2f() : Vec2f(0.0f, 0.0f) {}

        // Operator overload: [] access only
        float operator[](int index) const {
            // Check if index is valid
            assert(index >= 0 && index <= 1);
            if (index == 0) {
                return x;
            }
            return y;
        }

        // Operator overload: [] for assignment
        float &operator[](int index) {
            // Check if index is valid
            assert(index >= 0 && index <= 1);
            if (index == 0) {
                return x;
            }
            return y;
        }

        // Operator overload: ==
        bool operator==(const Vec2f &other) const {
            return (Math::threeWayComparator(x - other.x) == 0 &&
                    Math::threeWayComparator(y - other.y) == 0);
        }

        // Operator overload: !=
        bool operator!=(const Vec2f &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Vec2f operator+(const Vec2f &rhs) const {
            return Vec2f(x + rhs.x, y + rhs.y);
        }

        // Operator overload: -
        Vec2f operator-(const Vec2f &rhs) const {
            return Vec2f(x - rhs.x, y - rhs.y);
        }

        // Operator overload: /
        Vec2f operator/(const float &scalar) const {
            return Vec2f(x / scalar, y / scalar);
        }

        // Operator overload: +=
        Vec2f &operator+=(const Vec2f &rhs) {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        // Operator overload: -=
        Vec2f &operator-=(const Vec2f &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        // Operator overload: *=
        Vec2f &operator*=(const float &rhs) {
            x *= rhs;
            y *= rhs;
            return *this;
        }

        // Operator overload: /=
        Vec2f &operator/=(const float &rhs) {
            x /= rhs;
            y /= rhs;
            return *this;
        }

        // Operator /= overload of two Vec2f, it works component-wise like GLSL.
        Vec2f &operator/=(const Vec2f &rhs) {
            x /= rhs.x;
            y /= rhs.y;
            return *this;
        }

        // Operator overload: -()
        Vec2f operator-() const {
            return Vec2f(-x, -y);
        }

        // Operator overload: +()
        const Vec2f &operator+() const {
            return *this;
        }

        // Set all elements as the same value
        void fill(const float &value) {
            x = value;
            y = value;
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Vec2f operator*(const Vec2f &lhs, const float &scalar) {
        return Vec2f(lhs.x * scalar, lhs.y * scalar);
    }

    inline
    Vec2f operator*(const float &scalar, const Vec2f &rhs) {
        return rhs * scalar;
    }

    // Operator * overload of two Vec2f, it works component-wise like GLSL.
    inline
    Vec2f operator*(const Vec2f &lhs, const Vec2f &rhs) {
        return Vec2f(
                lhs.x * rhs.x,
                lhs.y * rhs.y
        );
    }

    // Operator / overload of two Vec2f, it works component-wise like GLSL.
    inline
    Vec2f operator/(const Vec2f &lhs, const Vec2f &rhs) {
        return Vec2f(
                lhs.x / rhs.x,
                lhs.y / rhs.y
        );
    }

    // dot product
    inline
    float dot(const Vec2f &lhs, const Vec2f &rhs) {
        return (lhs.x * rhs.x + lhs.y * rhs.y);
    }

    // cross product of two 2D vector will result a float
    inline
    float cross(const Vec2f &lhs, const Vec2f &rhs) {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    // norm(length)
    inline
    float norm(const Vec2f &obj) {
        return sqrtf(dot(obj, obj));
    }

    // squareLength: return length * length
    inline
    float squareLength(const Vec2f &obj) {
        return dot(obj, obj);
    }

    // distance of two vectors
    inline
    float distance(const Vec2f &lhs, const Vec2f &rhs) {
        return sqrtf(
                (lhs.x - rhs.x) * (lhs.x - rhs.x) +
                (lhs.y - rhs.y) * (lhs.y - rhs.y)
        );
    }

    // normalize
    inline
    Vec2f normalize(const Vec2f &obj) {
        float objLength = norm(obj);
        return obj / objLength;
    }

    // linear interpolation
    inline
    Vec2f lerp(const Vec2f &a, const Vec2f &b, float t) {
        return (1.0f - t) * a + t * b;
    }

    // Structure: Vec3f
    //
    // Description: A 3D Vector that holds positional data using 3 floats.
    struct Vec3f {
        // Fields
        float x;
        float y;
        float z;

        // Alternative getters for RGB
        [[nodiscard]] float r() const {
            return x;
        }

        [[nodiscard]] float g() const {
            return y;
        }

        [[nodiscard]] float b() const {
            return z;
        }

        // Constructor
        explicit Vec3f(float x, float y, float z) : x(x), y(y), z(z) {}

        // Default Constructor
        Vec3f() : Vec3f(0.0f, 0.0f, 0.0f) {}

        // Constructor with a Vec2f
        explicit Vec3f(const float &x, const Vec2f &vec2f) : Vec3f(x, vec2f.x,
                                                                   vec2f.y) {}

        explicit Vec3f(const Vec2f &vec2f, const float &z) : Vec3f(vec2f.x,
                                                                   vec2f.y,
                                                                   z) {}

        // Operator overload: [] access only
        float operator[](int index) const {
            // Check if index is valid
            assert(index >= 0 && index <= 2);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                default:
                    return z;
            }
        }

        // Operator overload: [] for assignment
        float &operator[](int index) {
            // Check if index is valid
            assert(index >= 0 && index <= 2);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                default:
                    return z;
            }
        }

        // Operator overload: ==
        bool operator==(const Vec3f &other) const {
            return (Math::threeWayComparator(x - other.x) == 0 &&
                    Math::threeWayComparator(y - other.y) == 0 &&
                    Math::threeWayComparator(z - other.z) == 0);
        }

        // Operator overload: !=
        bool operator!=(const Vec3f &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Vec3f operator+(const Vec3f &rhs) const {
            return Vec3f(x + rhs.x, y + rhs.y, z + rhs.z);
        }

        // Operator overload: -
        Vec3f operator-(const Vec3f &rhs) const {
            return Vec3f(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        // Operator overload: /
        Vec3f operator/(const float &scalar) const {
            return Vec3f(x / scalar, y / scalar, z / scalar);
        }

        // Operator overload: +=
        Vec3f &operator+=(const Vec3f &rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            return *this;
        }

        // Operator overload: -=
        Vec3f &operator-=(const Vec3f &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            return *this;
        }

        // Operator overload: *=
        Vec3f &operator*=(const float &rhs) {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            return *this;
        }

        // Operator overload: /=
        Vec3f &operator/=(const float &rhs) {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            return *this;
        }

        // Operator /= overload of two Vec3f, it works component-wise like GLSL.
        Vec3f &operator/=(const Vec3f &rhs) {
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            return *this;
        }

        // Operator overload: -()
        Vec3f operator-() const {
            return Vec3f(-x, -y, -z);
        }

        // Operator overload: +()
        const Vec3f &operator+() const {
            return *this;
        }

        // Set all elements as the same value
        void fill(const float &value) {
            x = value;
            y = value;
            z = value;
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Vec3f operator*(const Vec3f &lhs, const float &scalar) {
        return Vec3f(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
    }

    inline
    Vec3f operator*(const float &scalar, const Vec3f &rhs) {
        return rhs * scalar;
    }

    // Operator * overload of two Vec3f, it works component-wise like GLSL.
    inline
    Vec3f operator*(const Vec3f &lhs, const Vec3f &rhs) {
        return Vec3f(
                lhs.x * rhs.x,
                lhs.y * rhs.y,
                lhs.z * rhs.z
        );
    }

    // Operator / overload of two Vec3f, it works component-wise like GLSL.
    inline
    Vec3f operator/(const Vec3f &lhs, const Vec3f &rhs) {
        return Vec3f(
                lhs.x / rhs.x,
                lhs.y / rhs.y,
                lhs.z / rhs.z
        );
    }

    // dot product
    inline
    float dot(const Vec3f &lhs, const Vec3f &rhs) {
        return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
    }

    // cross product
    inline
    Vec3f cross(const Vec3f &lhs, const Vec3f &rhs) {
        return Vec3f(
                lhs.y * rhs.z - rhs.y * lhs.z,
                lhs.z * rhs.x - rhs.z * lhs.x,
                lhs.x * rhs.y - rhs.x * lhs.y
        );
    }

    // norm(length)
    inline
    float norm(const Vec3f &obj) {
        return sqrtf(dot(obj, obj));
    }

    // squareLength: return length * length
    inline
    float squareLength(const Vec3f &obj) {
        return dot(obj, obj);
    }

    // distance of two vectors
    inline
    float distance(const Vec3f &lhs, const Vec3f &rhs) {
        return sqrtf(
                (lhs.x - rhs.x) * (lhs.x - rhs.x) +
                (lhs.y - rhs.y) * (lhs.y - rhs.y) +
                (lhs.z - rhs.z) * (lhs.z - rhs.z)
        );
    }

    // normalize
    inline
    Vec3f normalize(const Vec3f &obj) {
        float objLength = norm(obj);
        return obj / objLength;
    }

    // linear interpolation
    inline
    Vec3f lerp(const Vec3f &a, const Vec3f &b, float t) {
        return (1.0f - t) * a + t * b;
    }

    // obtain the vector by the vector in and a normal unit vector after reflection
    Vec3f reflect(const Vec3f &in, const Vec3f &n) {
        return in - 2.0f * dot(in, n) * n;
    }

    // Check if the ray described by the vector in refracts on the surface by Snell's Law
    // and the normal unit vector is given,
    // obtain the refracted vector 't' if it is true
    // otherwise return false (cos_t2 <= 0, which means the total internal reflection occurs)
    // Reference: Page747, https://developer.download.nvidia.com/cg/Cg_3.1/Cg-3.1_April2012_ReferenceManual.pdf
    bool ifRefract(const Vec3f &l, const Vec3f &N, float nI_to_nT, Vec3f &t) {
        Vec3f L = normalize(l);
        float cosi = dot(L, N);
        float cos_t2 = 1.0f - nI_to_nT * nI_to_nT * (1.0f - cosi * cosi);
        if (cos_t2 > 0) {
            t = nI_to_nT * (L - N * cosi) - N * sqrtf(cos_t2);
            return true;
        }
        return false;
    }

    // Structure: Vec4f
    //
    // Description: A 3D Vector that holds positional data using 4 floats in a homogeneous coordinate system.
    struct Vec4f {
        // Fields
        float x;
        float y;
        float z;
        float w;

        // Alternative getters for RGBA
        [[nodiscard]] float r() const {
            return x;
        }

        [[nodiscard]] float g() const {
            return y;
        }

        [[nodiscard]] float b() const {
            return z;
        }

        [[nodiscard]] float a() const {
            return w;
        }

        // Constructor
        explicit Vec4f(float x, float y, float z, float w) : x(x), y(y), z(z),
                                                             w(w) {}

        // Default Constructor
        Vec4f() : Vec4f(0.0f, 0.0f, 0.0f, 0.0f) {}

        // Constructor with 2 'Vec2f's
        explicit Vec4f(const Vec2f &a, const Vec2f &b) : Vec4f(a.x, a.y, b.x,
                                                               b.y) {}

        // Constructor with 1 'Vec2f'
        explicit Vec4f(const Vec2f &vec2f, const float &z, const float &w)
                : Vec4f(vec2f.x, vec2f.y, z, w) {}

        explicit Vec4f(const float &x, const Vec2f &vec2f, const float &w)
                : Vec4f(x, vec2f.x, vec2f.y, w) {}

        explicit Vec4f(const float &x, const float &y, const Vec2f &vec2f)
                : Vec4f(x, y, vec2f.x, vec2f.y) {}

        // Constructor with 1 'Vec3f'
        explicit Vec4f(const Vec3f &vec3f, const float &w) : Vec4f(vec3f.x,
                                                                   vec3f.y,
                                                                   vec3f.z,
                                                                   w) {}

        explicit Vec4f(const float &x, const Vec3f &vec3f) : Vec4f(x, vec3f.x,
                                                                   vec3f.y,
                                                                   vec3f.z) {}

        // Operator overload: [] access only
        float operator[](int index) const {
            // Check if index is valid
            assert(index >= 0 && index <= 3);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                default:
                    return w;
            }
        }

        // Operator overload: [] for assignment
        float &operator[](int index) {
            // Check if index is valid
            assert(index >= 0 && index <= 3);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                default:
                    return w;
            }
        }

        // Operator overload: ==
        bool operator==(const Vec4f &other) const {
            return (Math::threeWayComparator(x - other.x) == 0 &&
                    Math::threeWayComparator(y - other.y) == 0 &&
                    Math::threeWayComparator(z - other.z) == 0 &&
                    Math::threeWayComparator(w - other.w) == 0);
        }

        // Operator overload: !=
        bool operator!=(const Vec4f &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Vec4f operator+(const Vec4f &rhs) const {
            return Vec4f(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
        }

        // Operator overload: -
        Vec4f operator-(const Vec4f &rhs) const {
            return Vec4f(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
        }

        // Operator overload: /
        Vec4f operator/(const float &scalar) const {
            return Vec4f(x / scalar, y / scalar, z / scalar, w / scalar);
        }

        // Operator overload: +=
        Vec4f &operator+=(const Vec4f &rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            w += rhs.w;
            return *this;
        }

        // Operator overload: -=
        Vec4f &operator-=(const Vec4f &rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            w -= rhs.w;
            return *this;
        }

        // Operator overload: *=
        Vec4f &operator*=(const float &rhs) {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            w *= rhs;
            return *this;
        }

        // Operator overload: /=
        Vec4f &operator/=(const float &rhs) {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            w /= rhs;
            return *this;
        }

        // Operator /= overload of two Vec4f, it works component-wise like GLSL.
        Vec4f &operator/=(const Vec4f &rhs) {
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            w /= rhs.w;
            return *this;
        }

        // Operator overload: -()
        Vec4f operator-() const {
            return Vec4f(-x, -y, -z, -w);
        }

        // Operator overload: +()
        const Vec4f &operator+() const {
            return *this;
        }

        // Set all elements as the same value
        void fill(const float &value) {
            x = value;
            y = value;
            z = value;
            w = value;
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Vec4f operator*(const Vec4f &lhs, const float &scalar) {
        return Vec4f(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar,
                     lhs.w * scalar);
    }

    inline
    Vec4f operator*(const float &scalar, const Vec4f &rhs) {
        return rhs * scalar;
    }

    // Operator * overload of two Vec4f, it works component-wise like GLSL.
    inline
    Vec4f operator*(const Vec4f &lhs, const Vec4f &rhs) {
        return Vec4f(
                lhs.x * rhs.x,
                lhs.y * rhs.y,
                lhs.z * rhs.z,
                lhs.w * rhs.w
        );
    }

    // Operator / overload of two Vec4f, it works component-wise like GLSL.
    inline
    Vec4f operator/(const Vec4f &lhs, const Vec4f &rhs) {
        return Vec4f(
                lhs.x / rhs.x,
                lhs.y / rhs.y,
                lhs.z / rhs.z,
                lhs.w / rhs.w
        );
    }

    // dot product
    inline
    float dot(const Vec4f &lhs, const Vec4f &rhs) {
        return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w);
    }

    // norm(length)
    inline
    float norm(const Vec4f &obj) {
        return sqrtf(dot(obj, obj));
    }

    // squareLength: return length * length
    inline
    float squareLength(const Vec4f &obj) {
        return dot(obj, obj);
    }

    // distance of two vectors
    inline
    float distance(const Vec4f &lhs, const Vec4f &rhs) {
        return sqrtf(
                (lhs.x - rhs.x) * (lhs.x - rhs.x) +
                (lhs.y - rhs.y) * (lhs.y - rhs.y) +
                (lhs.z - rhs.z) * (lhs.z - rhs.z) +
                (lhs.w - rhs.w) * (lhs.w - rhs.w)
        );
    }

    // normalize
    inline
    Vec4f normalize(const Vec4f &obj) {
        float objLength = norm(obj);
        return obj / objLength;
    }

    // linear interpolation
    inline
    Vec4f lerp(const Vec4f &a, const Vec4f &b, float t) {
        return (1.0f - t) * a + t * b;
    }

    // Structure: Mat2x2f
    //
    // Description: A 2x2 matrix where each element is a 'float' type, a std::array is used to store all elements.
    // Diagram: {0,1,2,3} --> |0 1|
    //                        |2 3|
    struct Mat2x2f {
        // Field
        std::array<float, 4> data{};

        // Constructor
        explicit Mat2x2f(const float &e0, const float &e1, const float &e2,
                         const float &e3) {
            data[0] = e0;
            data[1] = e1;
            data[2] = e2;
            data[3] = e3;
        }

        // Default constructor
        Mat2x2f() = default;

        // Constructor takes std::array<float, 4>
        explicit Mat2x2f(const std::array<float, 4> &rhs) : data(rhs) {}

        // Constructor std::initializer_list<float>
        Mat2x2f(const std::initializer_list<float> &rhs) {
            // Check if the length of rhs is not 4
            assert(rhs.size() == 4);
            std::copy(rhs.begin(), rhs.end(), data.begin());
        }

        // Constructor as an identity * scalar
        explicit Mat2x2f(const float &scalar) {
            data[0] = scalar;
            data[1] = 0.0f;
            data[2] = 0.0f;
            data[3] = scalar;
        }

        // Operator overload: ==
        bool operator==(const Mat2x2f &other) const {
            for (unsigned int i = 0; i != 2; ++i) {
                for (unsigned int j = 0; j != 2; ++j) {
                    if (Math::threeWayComparator(
                            this->at(i, j) - other.at(i, j)) != 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        // Operator overload: !=
        bool operator!=(const Mat2x2f &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Mat2x2f operator+(const Mat2x2f &rhs) const {
            return Mat2x2f(data[0] + rhs.data[0],
                           data[1] + rhs.data[1],
                           data[2] + rhs.data[2],
                           data[3] + rhs.data[3]);
        }

        // Operator overload: -
        Mat2x2f operator-(const Mat2x2f &rhs) const {
            return Mat2x2f(data[0] - rhs.data[0],
                           data[1] - rhs.data[1],
                           data[2] - rhs.data[2],
                           data[3] - rhs.data[3]);
        }

        // Operator overload: /
        Mat2x2f operator/(const float &scalar) const {
            return Mat2x2f(data[0] / scalar,
                           data[1] / scalar,
                           data[2] / scalar,
                           data[3] / scalar);
        }

        // Operator overload: +=
        Mat2x2f &operator+=(const Mat2x2f &rhs) {
            data[0] += rhs.data[0];
            data[1] += rhs.data[1];
            data[2] += rhs.data[2];
            data[3] += rhs.data[3];
            return *this;
        }

        // Operator overload: -=
        Mat2x2f &operator-=(const Mat2x2f &rhs) {
            data[0] -= rhs.data[0];
            data[1] -= rhs.data[1];
            data[2] -= rhs.data[2];
            data[3] -= rhs.data[3];
            return *this;
        }

        // Operator overload: *=
        Mat2x2f &operator*=(const float &rhs) {
            data[0] *= rhs;
            data[1] *= rhs;
            data[2] *= rhs;
            data[3] *= rhs;
            return *this;
        }

        // Operator overload: /=
        Mat2x2f &operator/=(const float &rhs) {
            data[0] /= rhs;
            data[1] /= rhs;
            data[2] /= rhs;
            data[3] /= rhs;
            return *this;
        }

        // Operator overload: -()
        Mat2x2f operator-() const {
            return Mat2x2f(-data[0],
                           -data[1],
                           -data[2],
                           -data[3]);
        }

        // Operator overload: +()
        const Mat2x2f &operator+() const {
            return *this;
        }

        // Operator overload: at(i, j) access only
        [[nodiscard]] float
        at(const unsigned int &i, const unsigned int &j) const {
            // If the index is illegal, then throw an exception.
            return data.at(i * 2 + j);
        }

        // Operator overload: at(i, j) for assignment
        float &at(const unsigned int &i, const unsigned int &j) {
            // If the index is illegal, then throw an exception.
            return data.at(i * 2 + j);
        }

        // Set all elements as the same value
        void fill(const float &value) {
            std::fill(data.begin(), data.end(), value);
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Mat2x2f operator*(const Mat2x2f &lhs, const float &scalar) {
        return Mat2x2f(lhs.data[0] * scalar,
                       lhs.data[1] * scalar,
                       lhs.data[2] * scalar,
                       lhs.data[3] * scalar);
    }

    inline
    Mat2x2f operator*(const float &scalar, const Mat2x2f &rhs) {
        return rhs * scalar;
    }

    // Operator overload as non-member function: * (Mat2x2f * Vec2f) right-multiplication
    // same as glm::vec2 rhs * glm::mat2x2 lhs
    inline
    Vec2f operator*(const Mat2x2f &lhs, const Vec2f &rhs) {
        return Vec2f(
                lhs.data[0] * rhs.x + lhs.data[1] * rhs.y,
                lhs.data[2] * rhs.x + lhs.data[3] * rhs.y
        );
    }

    // Operator overload as non-member function: * (Mat2x2f * Mat2x2f) right-multiplication
    // same as glm::mat2x2 rhs * glm::mat2x2 lhs
    inline
    Mat2x2f operator*(const Mat2x2f &lhs, const Mat2x2f &rhs) {
        return Mat2x2f(
                lhs.data[0] * rhs.data[0] + lhs.data[1] * rhs.data[2],
                lhs.data[0] * rhs.data[1] + lhs.data[1] * rhs.data[3],
                lhs.data[2] * rhs.data[0] + lhs.data[3] * rhs.data[2],
                lhs.data[2] * rhs.data[1] + lhs.data[3] * rhs.data[3]
        );
    }

    inline
    float determinant(Mat2x2f const &obj) {
        return obj.data[0] * obj.data[3] - obj.data[1] * obj.data[2];
    }

    inline
    Mat2x2f inverse(Mat2x2f const &obj) {
        float temp = determinant(obj);
        temp = 1.0f / temp;
        Mat2x2f result(
                obj.data[3] * temp,
                -obj.data[1] * temp,
                -obj.data[2] * temp,
                obj.data[0] * temp
        );
        return result;
    }

    // transpose
    // | 0 1 |  --> | 0 2 |
    // | 2 3 |  --> | 1 3 |
    inline
    Mat2x2f transpose(Mat2x2f obj) {
        std::swap(obj.at(0, 1), obj.at(1, 0));
        return obj;
    }

    // Structure: Mat3x3f
    //
    // Description: A 3x3 matrix where each element is a 'float' type, a std::array is used to store all elements.
    // Diagram: {0,1,2,3,4,5,6,7,8} --> |0 1 2|
    //                                  |3 4 5|
    //                                  |6 7 8|
    struct Mat3x3f {
        // Field
        std::array<float, 9> data{};

        // Constructor
        explicit Mat3x3f(const float &e0,
                         const float &e1,
                         const float &e2,
                         const float &e3,
                         const float &e4,
                         const float &e5,
                         const float &e6,
                         const float &e7,
                         const float &e8) {
            data[0] = e0;
            data[1] = e1;
            data[2] = e2;
            data[3] = e3;
            data[4] = e4;
            data[5] = e5;
            data[6] = e6;
            data[7] = e7;
            data[8] = e8;
        }

        // Default constructor
        Mat3x3f() = default;

        // Constructor takes std::array<float, 9>
        explicit Mat3x3f(const std::array<float, 9> &rhs) : data(rhs) {}

        // Constructor std::initializer_list<float>
        Mat3x3f(const std::initializer_list<float> &rhs) {
            // Check if the length of rhs is not 9
            assert(rhs.size() == 9);
            std::copy(rhs.begin(), rhs.end(), data.begin());
        }

        // Constructor as an identity * scalar
        explicit Mat3x3f(const float &scalar) {
            data[0] = scalar;
            data[1] = 0.0f;
            data[2] = 0.0f;
            data[3] = 0.0f;
            data[4] = scalar;
            data[5] = 0.0f;
            data[6] = 0.0f;
            data[7] = 0.0f;
            data[8] = scalar;
        }

        // Operator overload: ==
        bool operator==(const Mat3x3f &other) const {
            for (unsigned int i = 0; i != 3; ++i) {
                for (unsigned int j = 0; j != 3; ++j) {
                    if (Math::threeWayComparator(
                            this->at(i, j) - other.at(i, j)) != 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        // Operator overload: !=
        bool operator!=(const Mat3x3f &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Mat3x3f operator+(const Mat3x3f &rhs) const {
            Mat3x3f result;
            for (size_t i = 0; i != 9; ++i) {
                result.data[i] += rhs.data[i];
            }
            return result;
        }

        // Operator overload: -
        Mat3x3f operator-(const Mat3x3f &rhs) const {
            Mat3x3f result;
            for (size_t i = 0; i != 9; ++i) {
                result.data[i] -= rhs.data[i];
            }
            return result;
        }

        // Operator overload: /
        Mat3x3f operator/(const float &scalar) const {
            return Mat3x3f(data[0] / scalar,
                           data[1] / scalar,
                           data[2] / scalar,
                           data[3] / scalar,
                           data[4] / scalar,
                           data[5] / scalar,
                           data[6] / scalar,
                           data[7] / scalar,
                           data[8] / scalar);
        }

        // Operator overload: +=
        Mat3x3f &operator+=(const Mat3x3f &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] += rhs.data[i];
            }
            return *this;
        }

        // Operator overload: -=
        Mat3x3f &operator-=(const Mat3x3f &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] -= rhs.data[i];
            }
            return *this;
        }

        // Operator overload: *=
        Mat3x3f &operator*=(const float &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] *= rhs;
            }
            return *this;
        }

        // Operator overload: /=
        Mat3x3f &operator/=(const float &rhs) {
            for (size_t i = 0; i != 9; ++i) {
                data[i] /= rhs;
            }
            return *this;
        }

        // Operator overload: -()
        Mat3x3f operator-() const {
            return Mat3x3f(-data[0],
                           -data[1],
                           -data[2],
                           -data[3],
                           -data[4],
                           -data[5],
                           -data[6],
                           -data[7],
                           -data[8]);
        }

        // Operator overload: +()
        const Mat3x3f &operator+() const {
            return *this;
        }

        // Operator overload: at(i, j) access only
        [[nodiscard]] float
        at(const unsigned int &i, const unsigned int &j) const {
            // If the index is illegal, then throw an exception.
            return data.at(i * 3 + j);
        }

        // Operator overload: at(i, j) for assignment
        float &at(const unsigned int &i, const unsigned int &j) {
            // If the index is illegal, then throw an exception.
            return data.at(i * 3 + j);
        }

        // Set all elements as the same value
        void fill(const float &value) {
            std::fill(data.begin(), data.end(), value);
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Mat3x3f operator*(const Mat3x3f &lhs, const float &scalar) {
        return Mat3x3f(lhs.data[0] * scalar,
                       lhs.data[1] * scalar,
                       lhs.data[2] * scalar,
                       lhs.data[3] * scalar,
                       lhs.data[4] * scalar,
                       lhs.data[5] * scalar,
                       lhs.data[6] * scalar,
                       lhs.data[7] * scalar,
                       lhs.data[8] * scalar);
    }

    inline
    Mat3x3f operator*(const float &scalar, const Mat3x3f &rhs) {
        return rhs * scalar;
    }

    // Operator overload as non-member function: * (Mat3x3f * Vec3f) left-multiplication
    // same as glm::vec3 rhs * glm::mat3x3 lhs
    inline
    Vec3f operator*(const Mat3x3f &lhs, const Vec3f &rhs) {
        return Vec3f(
                lhs.data[0] * rhs.x + lhs.data[1] * rhs.y + lhs.data[2] * rhs.z,
                lhs.data[3] * rhs.x + lhs.data[4] * rhs.y + lhs.data[5] * rhs.z,
                lhs.data[6] * rhs.x + lhs.data[7] * rhs.y + lhs.data[8] * rhs.z
        );
    }

    // Operator overload as non-member function: * (Mat3x3f * Mat3x3f) right-multiplication
    // same as glm::mat3x3 rhs * glm::mat3x3 lhs
    inline
    Mat3x3f operator*(const Mat3x3f &lhs, const Mat3x3f &rhs) {
        return Mat3x3f(
                lhs.data[0] * rhs.data[0] + lhs.data[1] * rhs.data[3] +
                lhs.data[2] * rhs.data[6],
                lhs.data[0] * rhs.data[1] + lhs.data[1] * rhs.data[4] +
                lhs.data[2] * rhs.data[7],
                lhs.data[0] * rhs.data[2] + lhs.data[1] * rhs.data[5] +
                lhs.data[2] * rhs.data[8],
                lhs.data[3] * rhs.data[0] + lhs.data[4] * rhs.data[3] +
                lhs.data[5] * rhs.data[6],
                lhs.data[3] * rhs.data[1] + lhs.data[4] * rhs.data[4] +
                lhs.data[5] * rhs.data[7],
                lhs.data[3] * rhs.data[2] + lhs.data[4] * rhs.data[5] +
                lhs.data[5] * rhs.data[8],
                lhs.data[6] * rhs.data[0] + lhs.data[7] * rhs.data[3] +
                lhs.data[8] * rhs.data[6],
                lhs.data[6] * rhs.data[1] + lhs.data[7] * rhs.data[4] +
                lhs.data[8] * rhs.data[7],
                lhs.data[6] * rhs.data[2] + lhs.data[7] * rhs.data[5] +
                lhs.data[8] * rhs.data[8]
        );
    }

    inline
    float determinant(Mat3x3f const &obj) {
        return obj.at(0, 0) *
               (obj.at(1, 1) * obj.at(2, 2) - obj.at(2, 1) * obj.at(1, 2)) -
               obj.at(0, 1) *
               (obj.at(1, 0) * obj.at(2, 2) - obj.at(1, 2) * obj.at(2, 0)) +
               obj.at(0, 2) *
               (obj.at(1, 0) * obj.at(2, 1) - obj.at(1, 1) * obj.at(2, 0));
    }

    inline
    Mat3x3f inverse(Mat3x3f const &obj) {
        float temp = determinant(obj);
        temp = 1.0f / temp;
        Mat3x3f result(
                (obj.at(1, 1) * obj.at(2, 2) - obj.at(2, 1) * obj.at(1, 2)) *
                temp,
                (obj.at(0, 2) * obj.at(2, 1) - obj.at(0, 1) * obj.at(2, 2)) *
                temp,
                (obj.at(0, 1) * obj.at(1, 2) - obj.at(0, 2) * obj.at(1, 1)) *
                temp,
                (obj.at(1, 2) * obj.at(2, 0) - obj.at(1, 0) * obj.at(2, 2)) *
                temp,
                (obj.at(0, 0) * obj.at(2, 2) - obj.at(0, 2) * obj.at(2, 0)) *
                temp,
                (obj.at(1, 0) * obj.at(0, 2) - obj.at(0, 0) * obj.at(1, 2)) *
                temp,
                (obj.at(1, 0) * obj.at(2, 1) - obj.at(2, 0) * obj.at(1, 1)) *
                temp,
                (obj.at(2, 0) * obj.at(0, 1) - obj.at(0, 0) * obj.at(2, 1)) *
                temp,
                (obj.at(0, 0) * obj.at(1, 1) - obj.at(1, 0) * obj.at(0, 1)) *
                temp
        );
        return result;
    }

    // transpose
    // | 0 1 2 |  --> | 0 3 6 |
    // | 3 4 5 |  --> | 1 4 7 |
    // | 6 7 8 |  --> | 2 5 8 |
    inline
    Mat3x3f transpose(Mat3x3f obj) {
        std::swap(obj.data[3], obj.data[1]);
        std::swap(obj.data[6], obj.data[2]);
        std::swap(obj.data[7], obj.data[5]);
        return obj;
    }

    // Structure: Mat4x4f
    //
    // Description: A 4x4 matrix where each element is a 'float' type, a std::array is used to store all elements.
    // Diagram: {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} --> |0   1  2  3|
    //                                                      |4   5  6  7|
    //                                                      |8   9 10 11|
    //                                                      |12 13 14 15|
    struct Mat4x4f {
        // Field
        std::array<float, 16> data{};

        // Constructor
        explicit Mat4x4f(const float &e0,
                         const float &e1,
                         const float &e2,
                         const float &e3,
                         const float &e4,
                         const float &e5,
                         const float &e6,
                         const float &e7,
                         const float &e8,
                         const float &e9,
                         const float &e10,
                         const float &e11,
                         const float &e12,
                         const float &e13,
                         const float &e14,
                         const float &e15) {
            data[0] = e0;
            data[1] = e1;
            data[2] = e2;
            data[3] = e3;
            data[4] = e4;
            data[5] = e5;
            data[6] = e6;
            data[7] = e7;
            data[8] = e8;
            data[9] = e9;
            data[10] = e10;
            data[11] = e11;
            data[12] = e12;
            data[13] = e13;
            data[14] = e14;
            data[15] = e15;
        }

        // Default constructor
        Mat4x4f() = default;

        // Constructor takes std::array<float, 16>
        explicit Mat4x4f(const std::array<float, 16> &rhs) : data(rhs) {}

        // Constructor std::initializer_list<float>
        Mat4x4f(const std::initializer_list<float> &rhs) {
            // Check if the length of rhs is not 16
            assert(rhs.size() == 16);
            std::copy(rhs.begin(), rhs.end(), data.begin());
        }

        // Constructor as an identity * scalar
        explicit Mat4x4f(const float &scalar) {
            data[0] = scalar;
            data[1] = 0.0f;
            data[2] = 0.0f;
            data[3] = 0.0f;
            data[4] = 0.0f;
            data[5] = scalar;
            data[6] = 0.0f;
            data[7] = 0.0f;
            data[8] = 0.0f;
            data[9] = 0.0f;
            data[10] = scalar;
            data[11] = 0.0f;
            data[12] = 0.0f;
            data[13] = 0.0f;
            data[14] = 0.0f;
            data[15] = scalar;
        }

        // Operator overload: ==
        bool operator==(const Mat4x4f &other) const {
            for (unsigned int i = 0; i != 4; ++i) {
                for (unsigned int j = 0; j != 4; ++j) {
                    if (Math::threeWayComparator(
                            this->at(i, j) - other.at(i, j)) != 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        // Operator overload: !=
        bool operator!=(const Mat4x4f &other) const {
            return !(*this == other);
        }

        // Operator overload: +
        Mat4x4f operator+(const Mat4x4f &rhs) const {
            Mat4x4f result;
            for (size_t i = 0; i != 16; ++i) {
                result.data[i] += rhs.data[i];
            }
            return result;
        }

        // Operator overload: -
        Mat4x4f operator-(const Mat4x4f &rhs) const {
            Mat4x4f result;
            for (size_t i = 0; i != 16; ++i) {
                result.data[i] -= rhs.data[i];
            }
            return result;
        }

        // Operator overload: /
        Mat4x4f operator/(const float &scalar) const {
            return Mat4x4f(data[0] / scalar,
                           data[1] / scalar,
                           data[2] / scalar,
                           data[3] / scalar,
                           data[4] / scalar,
                           data[5] / scalar,
                           data[6] / scalar,
                           data[7] / scalar,
                           data[8] / scalar,
                           data[9] / scalar,
                           data[10] / scalar,
                           data[11] / scalar,
                           data[12] / scalar,
                           data[13] / scalar,
                           data[14] / scalar,
                           data[15] / scalar);
        }

        // Operator overload: +=
        Mat4x4f &operator+=(const Mat4x4f &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] += rhs.data[i];
            }
            return *this;
        }

        // Operator overload: -=
        Mat4x4f &operator-=(const Mat4x4f &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] -= rhs.data[i];
            }
            return *this;
        }

        // Operator overload: *=
        Mat4x4f &operator*=(const float &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] *= rhs;
            }
            return *this;
        }

        // Operator overload: /=
        Mat4x4f &operator/=(const float &rhs) {
            for (size_t i = 0; i != 16; ++i) {
                data[i] /= rhs;
            }
            return *this;
        }

        // Operator overload: -()
        Mat4x4f operator-() const {
            return Mat4x4f(-data[0],
                           -data[1],
                           -data[2],
                           -data[3],
                           -data[4],
                           -data[5],
                           -data[6],
                           -data[7],
                           -data[8],
                           -data[9],
                           -data[10],
                           -data[11],
                           -data[12],
                           -data[13],
                           -data[14],
                           -data[15]);
        }

        // Operator overload: +()
        const Mat4x4f &operator+() const {
            return *this;
        }

        // Operator overload: at(i, j) access only
        [[nodiscard]] float
        at(const unsigned int &i, const unsigned int &j) const {
            // If the index is illegal, then throw an exception.
            return data.at(i * 4 + j);
        }

        // Operator overload: at(i, j) for assignment
        float &at(const unsigned int &i, const unsigned int &j) {
            // If the index is illegal, then throw an exception.
            return data.at(i * 4 + j);
        }

        // Set all elements as the same value
        void fill(const float &value) {
            std::fill(data.begin(), data.end(), value);
        }
    };

    // Operator overload as non-member function: * (scalar)
    inline
    Mat4x4f operator*(const Mat4x4f &lhs, const float &scalar) {
        return Mat4x4f(lhs.data[0] * scalar,
                       lhs.data[1] * scalar,
                       lhs.data[2] * scalar,
                       lhs.data[3] * scalar,
                       lhs.data[4] * scalar,
                       lhs.data[5] * scalar,
                       lhs.data[6] * scalar,
                       lhs.data[7] * scalar,
                       lhs.data[8] * scalar,
                       lhs.data[9] * scalar,
                       lhs.data[10] * scalar,
                       lhs.data[11] * scalar,
                       lhs.data[12] * scalar,
                       lhs.data[13] * scalar,
                       lhs.data[14] * scalar,
                       lhs.data[15] * scalar);
    }

    inline
    Mat4x4f operator*(const float &scalar, const Mat4x4f &rhs) {
        return rhs * scalar;
    }

    // Operator overload as non-member function: * (Mat4x4f * Vec4f) left-multiplication
    // same as glm::vec4 rhs * glm::mat4x4 lhs
    inline
    Vec4f operator*(const Mat4x4f &lhs, const Vec4f &rhs) {
        return Vec4f(
                lhs.data[0] * rhs.x + lhs.data[1] * rhs.y +
                lhs.data[2] * rhs.z + lhs.data[3] * rhs.w,
                lhs.data[4] * rhs.x + lhs.data[5] * rhs.y +
                lhs.data[6] * rhs.z + lhs.data[7] * rhs.w,
                lhs.data[8] * rhs.x + lhs.data[9] * rhs.y +
                lhs.data[10] * rhs.z + lhs.data[11] * rhs.w,
                lhs.data[12] * rhs.x + lhs.data[13] * rhs.y +
                lhs.data[14] * rhs.z + lhs.data[15] * rhs.w
        );
    }

    // Operator overload as non-member function: * (Mat4x4f * Mat4x4f) right-multiplication
    // same as glm::mat4x4 rhs * glm::mat4x4 lhs
    inline
    Mat4x4f operator*(const Mat4x4f &lhs, const Mat4x4f &rhs) {
        return Mat4x4f(
                lhs.data[0] * rhs.data[0] + lhs.data[1] * rhs.data[4] +
                lhs.data[2] * rhs.data[8] +
                lhs.data[3] * rhs.data[12],
                lhs.data[0] * rhs.data[1] + lhs.data[1] * rhs.data[5] +
                lhs.data[2] * rhs.data[9] +
                lhs.data[3] * rhs.data[13],
                lhs.data[0] * rhs.data[2] + lhs.data[1] * rhs.data[6] +
                lhs.data[2] * rhs.data[10] +
                lhs.data[3] * rhs.data[14],
                lhs.data[0] * rhs.data[3] + lhs.data[1] * rhs.data[7] +
                lhs.data[2] * rhs.data[11] +
                lhs.data[3] * rhs.data[15], //

                lhs.data[4] * rhs.data[0] + lhs.data[5] * rhs.data[4] +
                lhs.data[6] * rhs.data[8] +
                lhs.data[7] * rhs.data[12],
                lhs.data[4] * rhs.data[1] + lhs.data[5] * rhs.data[5] +
                lhs.data[6] * rhs.data[9] +
                lhs.data[7] * rhs.data[13],
                lhs.data[4] * rhs.data[2] + lhs.data[5] * rhs.data[6] +
                lhs.data[6] * rhs.data[10] +
                lhs.data[7] * rhs.data[14],
                lhs.data[4] * rhs.data[3] + lhs.data[5] * rhs.data[7] +
                lhs.data[6] * rhs.data[11] +
                lhs.data[7] * rhs.data[15], //

                lhs.data[8] * rhs.data[0] + lhs.data[9] * rhs.data[4] +
                lhs.data[10] * rhs.data[8] +
                lhs.data[11] * rhs.data[12],
                lhs.data[8] * rhs.data[1] + lhs.data[9] * rhs.data[5] +
                lhs.data[10] * rhs.data[9] +
                lhs.data[11] * rhs.data[13],
                lhs.data[8] * rhs.data[2] + lhs.data[9] * rhs.data[6] +
                lhs.data[10] * rhs.data[10] +
                lhs.data[11] * rhs.data[14],
                lhs.data[8] * rhs.data[3] + lhs.data[9] * rhs.data[7] +
                lhs.data[10] * rhs.data[11] +
                lhs.data[11] * rhs.data[15], //

                lhs.data[12] * rhs.data[0] + lhs.data[13] * rhs.data[4] +
                lhs.data[14] * rhs.data[8] +
                lhs.data[15] * rhs.data[12],
                lhs.data[12] * rhs.data[1] + lhs.data[13] * rhs.data[5] +
                lhs.data[14] * rhs.data[9] +
                lhs.data[15] * rhs.data[13],
                lhs.data[12] * rhs.data[2] + lhs.data[13] * rhs.data[6] +
                lhs.data[14] * rhs.data[10] +
                lhs.data[15] * rhs.data[14],
                lhs.data[12] * rhs.data[3] + lhs.data[13] * rhs.data[7] +
                lhs.data[14] * rhs.data[11] +
                lhs.data[15] * rhs.data[15] //
        );
    }

    // | 0  1  2  3 |
    // | 4  5  6  7 |
    // | 8  9 10 11 |
    // |12 13 14 15 |
    inline
    float determinant(Mat4x4f const &obj) {
        return obj.data[0] *
               determinant(Mat3x3f(obj.data[5], obj.data[6], obj.data[7],
                                   obj.data[9], obj.data[10], obj.data[11],
                                   obj.data[13], obj.data[14], obj.data[15])) -
               obj.data[1] *
               determinant(Mat3x3f(obj.data[4], obj.data[6], obj.data[7],
                                   obj.data[8], obj.data[10], obj.data[11],
                                   obj.data[12], obj.data[14], obj.data[15])) +
               obj.data[2] *
               determinant(Mat3x3f(obj.data[4], obj.data[5], obj.data[7],
                                   obj.data[8], obj.data[9], obj.data[11],
                                   obj.data[12], obj.data[13], obj.data[15])) -
               obj.data[3] *
               determinant(Mat3x3f(obj.data[4], obj.data[5], obj.data[6],
                                   obj.data[8], obj.data[9], obj.data[10],
                                   obj.data[12], obj.data[13], obj.data[14]));
    }

    // transpose
    // | 0  1  2  3 |  --> | 0  4  8 12 |
    // | 4  5  6  7 |  --> | 1  5  9 13 |
    // | 8  9 10 11 |  --> | 2  6 10 14 |
    // |12 13 14 15 |  --> | 3  7 11 15 |
    inline
    Mat4x4f transpose(Mat4x4f obj) {
        std::swap(obj.data[1], obj.data[4]);
        std::swap(obj.data[2], obj.data[8]);
        std::swap(obj.data[3], obj.data[12]);
        std::swap(obj.data[6], obj.data[9]);
        std::swap(obj.data[7], obj.data[13]);
        std::swap(obj.data[11], obj.data[14]);
        return obj;
    }

    /** Float Matrix Transformation **/
    // Obtain the scale matrix with three components
    inline
    Mat4x4f scale(const float &x, const float &y, const float &z) {
        Mat4x4f result = {
                x, 0.f, 0.f, 0.f,    //
                0.f, y, 0.f, 0.f,    //
                0.f, 0.f, z, 0.f,    //
                0.f, 0.f, 0.f, 1.0f  //
        };
        return result;
    }

    // Obtain the scale matrix with one scalar
    inline
    Mat4x4f scale(const float &scalar) {
        Mat4x4f result = {
                scalar, 0.f, 0.f, 0.f,   //
                0.f, scalar, 0.f, 0.f,   //
                0.f, 0.f, scalar, 0.f,   //
                0.f, 0.f, 0.f, 1.0f      //
        };
        return result;
    }

    // Obtain the scale matrix with one 'Vec3f' instance
    inline
    Mat4x4f scale(const Vec3f &obj) {
        Mat4x4f result = {
                obj.x, 0.f, 0.f, 0.f,   //
                0.f, obj.y, 0.f, 0.f,   //
                0.f, 0.f, obj.z, 0.f,   //
                0.f, 0.f, 0.f, 1.0f     //
        };
        return result;
    }

    // Obtain the scale matrix with one std::array<float, 3> instance
    inline
    Mat4x4f scale(const std::array<float, 3> &obj) {
        Mat4x4f result = {
                obj[0], 0.f, 0.f, 0.f,   //
                0.f, obj[1], 0.f, 0.f,   //
                0.f, 0.f, obj[2], 0.f,   //
                0.f, 0.f, 0.f, 1.0f      //
        };
        return result;
    }

    // Obtain the translate matrix with three components
    inline
    Mat4x4f translate(const float &x, const float &y, const float &z) {
        Mat4x4f result = {
                1.f, 0.f, 0.f, x,  //
                0.f, 1.f, 0.f, y,  //
                0.f, 0.f, 1.f, z,  //
                0.f, 0.f, 0.f, 1.f //
        };
        return result;
    }

    // Obtain the translate matrix with one 'Vec3f' instance
    inline
    Mat4x4f translate(const Vec3f &obj) {
        Mat4x4f result = {
                1.f, 0.f, 0.f, obj.x,  //
                0.f, 1.f, 0.f, obj.y,  //
                0.f, 0.f, 1.f, obj.z,  //
                0.f, 0.f, 0.f, 1.f     //
        };
        return result;
    }

    // Obtain the translate matrix with one std::array<float, 3> instance
    inline
    Mat4x4f translate(const std::array<float, 3> &obj) {
        Mat4x4f result = {
                1.f, 0.f, 0.f, obj[0],  //
                0.f, 1.f, 0.f, obj[1],  //
                0.f, 0.f, 1.f, obj[2],  //
                0.f, 0.f, 0.f, 1.f      //
        };
        return result;
    }

    // Obtain the rotate matrix about x-axis (radians only)
    inline
    Mat4x4f rotateAboutXAxis(const float &radians) {
        float cos_theta = std::cos(radians);
        float sin_theta = std::sin(radians);
        Mat4x4f result = {
                1.f, 0.f, 0.f, 0.f, //
                0.f, cos_theta, -sin_theta, 0.f, //
                0.f, sin_theta, cos_theta, 0.f, //
                0.f, 0.f, 0.f, 1.f  //
        };
        return result;
    }

    // Obtain the rotate matrix about y-axis (radians only)
    inline
    Mat4x4f rotateAboutYAxis(const float &radians) {
        float cos_theta = std::cos(radians);
        float sin_theta = std::sin(radians);
        Mat4x4f result = {
                cos_theta, 0.f, sin_theta, 0.f, //
                0.f, 1.f, 0.f, 0.f, //
                -sin_theta, 0.f, cos_theta, 0.f, //
                0.f, 0.f, 0.f, 1.f  //
        };
        return result;
    }

    // Obtain the rotate matrix about z-axis (radians only)
    inline
    Mat4x4f rotateAboutZAxis(const float &radians) {
        float cos_theta = std::cos(radians);
        float sin_theta = std::sin(radians);
        Mat4x4f result = {
                cos_theta, -sin_theta, 0.f, 0.f, //
                sin_theta, cos_theta, 0.f, 0.f, //
                0.f, 0.f, 1.f, 0.f, //
                0.f, 0.f, 0.f, 1.f  //
        };
        return result;
    }

    // Obtain the rotate matrix about an arbitrary axis (radians only)
    // same as glm::rotate(glm::mat4(1.0f), glm::radians(-radians), glm::vec3(axis));
    inline
    Mat4x4f rotate(const float &radians, const Vec3f &axis) {
        Vec3f n = normalize(axis);
        float cos_theta = std::cos(radians);
        float sin_theta = std::sin(radians);
        // Rodrigues' formula
        Mat4x4f result = {
                n.x * n.x + (1.0f - n.x * n.x) * cos_theta,
                n.x * n.y * (1.0f - cos_theta) - n.z * sin_theta,
                n.x * n.z * (1.0f - cos_theta) + n.y * sin_theta, 0.0f, //
                n.x * n.y * (1.0f - cos_theta) + n.z * sin_theta,
                n.y * n.y + (1.0f - n.y * n.y) * cos_theta,
                n.y * n.z * (1.0f - cos_theta) - n.x * sin_theta, 0.0f, //
                n.x * n.z * (1.0f - cos_theta) - n.y * sin_theta,
                n.y * n.z * (1.0f - cos_theta) + n.x * sin_theta,
                n.z * n.z + (1 - n.z * n.z) * cos_theta, 0.0f, //
                0.0f, 0.0f, 0.0f, 1.0f //
        };
        return result;
    }

    // Obtain the transformation that produces a parallel projection
    // its transpose is the same as glm::ortho(left, right, bottom, top, zNear, zFar);
    inline
    Mat4x4f
    ortho(const float &left, const float &right, const float &bottom,
          const float &top, const float &zNear,
          const float &zFar) {
        float t_x = -(right + left) / (right - left);
        float t_y = -(top + bottom) / (top - bottom);
        float t_z = -(zFar + zNear) / (zFar - zNear);
        Mat4x4f result = {
                2.0f / (right - left), 0.0f, 0.0f, t_x,
                0.0f, 2.0f / (top - bottom), 0.0f, t_y,
                0.0f, 0.0f, -2.0f / (zFar - zNear), t_z,
                0.0f, 0.0f, 0.0f, 1.0f
        };
        return result;
    }

    // Obtain the matrix that specifies a viewing frustum into the world coordinate system
    // fovy should be in double radians to reduce precision loss
    // its transpose is the same as glm::perspective(fovy, aspect, zNear, zFar)
    inline
    Mat4x4f
    perspective(const double &fovy, const float &aspect, const float &zNear,
                const float &zFar) {
        auto f = static_cast<float>(std::tan(
                M_PI_2 - fovy / 2.0));   // cot(x) = tan(M_PI_2 - x)
        Mat4x4f result = {
                f / aspect, 0.0f, 0.0f, 0.0f,
                0.0f, f, 0.0f, 0.0f,
                0.0f, 0.0f, (zFar + zNear) / (zNear - zFar),
                2.0f * zFar * zNear / (zNear - zFar),
                0.0f, 0.0f, -1.0f, 0.0f
        };
        return result;
    }

    // Obtain a viewing matrix derived from an eye point, a reference
    // point indicating the center of the scene to observe, and an UP vector
    // its transpose is the same as glm::lookAt(eye, target, upVector)
    inline
    Mat4x4f lookAt(const float &eyeX, const float &eyeY, const float &eyeZ,
                   const float &targetX, const float &targetY,
                   const float &targetZ, const float &upX, const float &upY,
                   const float &upZ) {
        // eyeX, eyeY, eyeZ: Specifies the position of the eye point
        // targetX, targetY, targetZ: Specifies the position of the reference point
        // upX, upY, upZ: Specifies the direction of the up vector
        Vec3f f = normalize(
                Vec3f(targetX - eyeX, targetY - eyeY, targetZ - eyeZ));
        Vec3f up = normalize(Vec3f(upX, upY, upZ));
        Vec3f s = normalize(cross(f, up));
        Vec3f u = cross(s, f);
        Vec3f eye(eyeX, eyeY, eyeZ);
        Mat4x4f result = {
                s[0], s[1], s[2], -dot(s, eye),
                u[0], u[1], u[2], -dot(u, eye),
                -f[0], -f[1], -f[2], dot(f, eye),
                0.0f, 0.0f, 0.0f, 1.0f
        };
        return result;
    }

    inline
    Mat4x4f lookAt(const Vec3f &eye, const Vec3f &target, const Vec3f &up) {
        Vec3f f = normalize(target - eye);
        Vec3f normalizeUp = normalize(up);
        Vec3f s = normalize(cross(f, normalizeUp));
        Vec3f u = cross(s, f);
        Mat4x4f result = {
                s[0], s[1], s[2], -dot(s, eye),
                u[0], u[1], u[2], -dot(u, eye),
                -f[0], -f[1], -f[2], dot(f, eye),
                0.0f, 0.0f, 0.0f, 1.0f
        };
        return result;
    }

    // Degree to radians
    inline
    float radians(const float &degree) {
        return static_cast<float>(M_PI * degree / 180.0);
    }

    // Radians to degree
    inline
    float degree(const float &radians) {
        return static_cast<float>(180.0 * radians / M_PI);
    }

    // Degree to radians (double)
    inline
    double radians(const double &degree) {
        return M_PI * degree / 180.0;
    }

    // Radians to degree (double)
    inline
    double degree(const double &radians) {
        return 180.0 * radians / M_PI;
    }

    /** representation **/
    // to_string
    inline
    std::string to_string(const Vec2f &obj) {
        std::string result = "Vec2f";
        result += "(";
        result += std::to_string(obj.x);
        result += ", ";
        result += std::to_string(obj.y);
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Vec2i &obj) {
        std::string result = "Vec2i";
        result += "(";
        result += std::to_string(obj.x);
        result += ", ";
        result += std::to_string(obj.y);
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Vec3f &obj) {
        std::string result = "Vec3f";
        result += "(";
        result += std::to_string(obj.x);
        result += ", ";
        result += std::to_string(obj.y);
        result += ", ";
        result += std::to_string(obj.z);
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Vec3i &obj) {
        std::string result = "Vec3i";
        result += "(";
        result += std::to_string(obj.x);
        result += ", ";
        result += std::to_string(obj.y);
        result += ", ";
        result += std::to_string(obj.z);
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Vec4f &obj) {
        std::string result = "Vec4f";
        result += "(";
        result += std::to_string(obj.x);
        result += ", ";
        result += std::to_string(obj.y);
        result += ", ";
        result += std::to_string(obj.z);
        result += ", ";
        result += std::to_string(obj.w);
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Vec4i &obj) {
        std::string result = "Vec4i";
        result += "(";
        result += std::to_string(obj.x);
        result += ", ";
        result += std::to_string(obj.y);
        result += ", ";
        result += std::to_string(obj.z);
        result += ", ";
        result += std::to_string(obj.w);
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Mat2x2i &obj) {
        std::string result = "Mat2x2i";
        result += "(";
        result += "(" + std::to_string(obj.at(0, 0)) + ", " +
                  std::to_string(obj.at(0, 1)) + ")";
        result += ", ";
        result += "(" + std::to_string(obj.at(1, 0)) + ", " +
                  std::to_string(obj.at(1, 1)) + ")";
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Mat2x2f &obj) {
        std::string result = "Mat2x2f";
        result += "(";
        result += "(" + std::to_string(obj.at(0, 0)) + ", " +
                  std::to_string(obj.at(0, 1)) + ")";
        result += ", ";
        result += "(" + std::to_string(obj.at(1, 0)) + ", " +
                  std::to_string(obj.at(1, 1)) + ")";
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Mat3x3i &obj) {
        std::string result = "Mat3x3i";
        result += "(";
        for (unsigned int i = 0; i != 3; ++i) {
            if (i != 0) {
                result += ", ";
            }
            result += "(";
            for (unsigned int j = 0; j != 3; ++j) {
                if (j != 0) {
                    result += ", ";
                }
                result += std::to_string(obj.at(i, j));
            }
            result += ")";
        }
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Mat3x3f &obj) {
        std::string result = "Mat3x3f";
        result += "(";
        for (unsigned int i = 0; i != 3; ++i) {
            if (i != 0) {
                result += ", ";
            }
            result += "(";
            for (unsigned int j = 0; j != 3; ++j) {
                if (j != 0) {
                    result += ", ";
                }
                result += std::to_string(obj.at(i, j));
            }
            result += ")";
        }
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Mat4x4i &obj) {
        std::string result = "Mat4x4i";
        result += "(";
        for (unsigned int i = 0; i != 4; ++i) {
            if (i != 0) {
                result += ", ";
            }
            result += "(";
            for (unsigned int j = 0; j != 4; ++j) {
                if (j != 0) {
                    result += ", ";
                }
                result += std::to_string(obj.at(i, j));
            }
            result += ")";
        }
        result += ")";
        return result;
    }

    // to_string
    inline
    std::string to_string(const Mat4x4f &obj) {
        std::string result = "Mat4x4f";
        result += "(";
        for (unsigned int i = 0; i != 4; ++i) {
            if (i != 0) {
                result += ", ";
            }
            result += "(";
            for (unsigned int j = 0; j != 4; ++j) {
                if (j != 0) {
                    result += ", ";
                }
                result += std::to_string(obj.at(i, j));
            }
            result += ")";
        }
        result += ")";
        return result;
    }

    // Overload operator: std::ostream::operator<<
    inline
    std::ostream &operator<<(std::ostream &out, const Vec2i &v) {
        return out << to_string(v);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Vec3i &v) {
        return out << to_string(v);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Vec4i &v) {
        return out << to_string(v);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Vec2f &v) {
        return out << to_string(v);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Vec3f &v) {
        return out << to_string(v);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Vec4f &v) {
        return out << to_string(v);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Mat2x2i &m) {
        return out << to_string(m);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Mat3x3i &m) {
        return out << to_string(m);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Mat4x4i &m) {
        return out << to_string(m);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Mat2x2f &m) {
        return out << to_string(m);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Mat3x3f &m) {
        return out << to_string(m);
    }

    inline
    std::ostream &operator<<(std::ostream &out, const Mat4x4f &m) {
        return out << to_string(m);
    }
}

// Namespace: Utility
// Description: The namespace includes all miscellaneous methods
namespace Utility {

    // Check if 'filename' is a regular file instead of a directory
    inline
    bool isRegularFile(const std::string &filename) {
        return std::experimental::filesystem::is_regular_file(filename);
    }

    // Check if 'filename' has .glsl as its suffix
    inline
    bool isGlslFile(const std::string &filename) {
        return std::experimental::filesystem::path(filename).extension() ==
               ".glsl";
    }

    // Check if 'filename' has .obj as its suffix
    inline
    bool isObjFile(const std::string &filename) {
        return std::experimental::filesystem::path(filename).extension() ==
               ".obj";
    }

    // Check if 'filename' has .tga as its suffix
    inline
    bool isTgaFile(const std::string &filename) {
        return std::experimental::filesystem::path(filename).extension() ==
               ".tga";
    }

    // Check if the user has the permission to read 'filename'.
    inline
    bool
    hasReadPermission(const std::experimental::filesystem::path &filename) {
        auto perm = std::experimental::filesystem::status(
                filename).permissions();
        return (perm & std::experimental::filesystem::perms::owner_read) !=
               std::experimental::filesystem::perms::none;
    }

    // Return min(max(n, lowerBound), upperBound) for n using the lowerBound and the upperBound
    inline
    void
    clamp(double &n, const double &lowerBound, const double &upperBound) {
        n = std::min(std::max(n, lowerBound), upperBound);
    }

    inline
    void
    clamp(int &n, const int &lowerBound, const int &upperBound) {
        n = std::min(std::max(n, lowerBound), upperBound);
    }

    // Convert RGB unsigned integers to the corresponding float between 0.0f-1.0f
    inline
    std::tuple<float, float, float>
    rgb2float(const unsigned int &r, const unsigned int &g,
              const unsigned int &b) {
        return std::make_tuple<float, float, float>(
                static_cast<float>(r) / 255.0f,
                static_cast<float>(g) / 255.0f,
                static_cast<float>(b) / 255.0f);
    }

    // Convert RGB doubles to the corresponding integers between 0-255
    inline
    std::tuple<int, int, int>
    rgb2Int(const Math::Vec3 &color, double div = 1.0) {

        std::tuple<int, int, int> result;
        std::get<0>(result) = static_cast<int>(color.r() * 255.99 / div);
        std::get<1>(result) = static_cast<int>(color.g() * 255.99 / div);
        std::get<2>(result) = static_cast<int>(color.b() * 255.99 / div);

        // Clamp RGB to make sure they are integers between 0-255
        clamp(std::get<0>(result), 0, 255);
        clamp(std::get<1>(result), 0, 255);
        clamp(std::get<2>(result), 0, 255);
        return result;
    }

    // Return the integer part of a double
    inline
    double getIntegerPart(const double &n) {
        return n - floor(n);
    }

    // Check if a string can be converted to a valid integer between 0-255(inclusive) by using regular expression
    inline
    bool isValidRGBValue(const std::string &s) {
        for (int i = 0; i <= 255; ++i) {
            if (std::to_string(i) == s) {
                return true;
            }
        }
        return false;
    }

    // A helper function to split a string by using whitespaces with unknown length as delimiter
    inline
    std::vector<std::string> splitByWhitespaces(const std::string &s) {
        std::istringstream iss(s);
        return std::vector<std::string>{std::istream_iterator<std::string>(iss),
                                        std::istream_iterator<std::string>()};
    }

    // A helper function to split a string by using a character delimiter
    inline
    std::vector<std::string> splitByChar(std::string s, const char &delimiter) {
        std::vector<std::string> res;
        std::istringstream f(s);
        std::string temp;
        while (std::getline(f, s, delimiter)) {
            res.emplace_back(s);
        }
        return res;
    }

    // A function that returns a random double such that -1.0 <= x < 1.0
    static std::random_device dev;
    static std::mt19937 random_generator(dev());
    static std::uniform_real_distribution<double> distribution(-1.0f, 1.0f);

    inline
    double getRandomDouble() {
        return distribution(random_generator);
    }

    // A function that returns a pair of random doubles (x0, y0) such that
    // -1.0 <= x0 < 1.0
    // -1.0 <= y0 < 1.0
    // x0^2 + y0^2 < 1 (inside the unit circle)
    inline std::pair<double, double> getRandomDoublePair() {
        double x0, y0;
        do {
            x0 = Utility::getRandomDouble();
            y0 = Utility::getRandomDouble();
        } while (x0 * x0 + y0 * y0 >= 1.0);
        return {x0, y0};
    }

    // A function that returns a Vec3 'result' from an array of Vec3
    // where each component in 'result' is minimum
    template<std::size_t SIZE>
    Math::Vec3 getMinimalComponent(std::array<Math::Vec3, SIZE> a) {
        Math::Vec3 result;
        result.x = std::min_element(a.cbegin(), a.cend(),
                                    [](const Math::Vec3 &lhs,
                                       const Math::Vec3 &rhs) {
                                        return (lhs.x < rhs.x);
                                    })->x;
        result.y = std::min_element(a.cbegin(), a.cend(),
                                    [](const Math::Vec3 &lhs,
                                       const Math::Vec3 &rhs) {
                                        return (lhs.y < rhs.y);
                                    })->y;
        result.z = std::min_element(a.cbegin(), a.cend(),
                                    [](const Math::Vec3 &lhs,
                                       const Math::Vec3 &rhs) {
                                        return (lhs.z < rhs.z);
                                    })->z;
        return result;
    }

    // A function that returns a Vec3 'result' from an array of Vec3
    // where each component in 'result' is maximal
    template<std::size_t SIZE>
    Math::Vec3 getMaximalComponent(std::array<Math::Vec3, SIZE> a) {
        Math::Vec3 result;
        result.x = std::max_element(a.cbegin(), a.cend(),
                                    [](const Math::Vec3 &lhs,
                                       const Math::Vec3 &rhs) {
                                        return (lhs.x < rhs.x);
                                    })->x;
        result.y = std::max_element(a.cbegin(), a.cend(),
                                    [](const Math::Vec3 &lhs,
                                       const Math::Vec3 &rhs) {
                                        return (lhs.y < rhs.y);
                                    })->y;
        result.z = std::max_element(a.cbegin(), a.cend(),
                                    [](const Math::Vec3 &lhs,
                                       const Math::Vec3 &rhs) {
                                        return (lhs.z < rhs.z);
                                    })->z;
        return result;
    }
}