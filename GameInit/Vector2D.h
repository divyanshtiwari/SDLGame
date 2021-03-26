 //13   // Vector2D.h

#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <math.h>


class Vector2D
{
    public:
        Vector2D(){}
        Vector2D(float x, float y): m_x(x), m_y(y) {}
        virtual ~Vector2D() {}

        float length() { return sqrt(m_x * m_x + m_y * m_y); }

        float getX() { return m_x; }
        float getY() { return m_y; }
        void setX(float x) { m_x = x; }
        void setY(float y) { m_y = y; }

        // adding two vectors
        Vector2D operator+ (Vector2D &v2) const {
            return Vector2D(m_x + v2.m_x , m_y + v2.m_y);
        }

        friend Vector2D& operator+= (Vector2D& v1, const Vector2D& v2){

        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;

        return v1;
        }

        // multiply by scalar number
        Vector2D operator*(float scalar)
        {
            return Vector2D(m_x * scalar, m_y * scalar);
        }

        Vector2D& operator*=(float scalar)
        {
            m_x *= scalar;
            m_y *= scalar;

            return *this;
        }

        // Subtraction of two vector
        // v3 = v1 - v2
        Vector2D operator- (const Vector2D& v2) const {
            return Vector2D(m_x - v2.m_x , m_y - v2.m_y);
        }

        friend Vector2D& operator-=(Vector2D& v1, const     Vector2D& v2)
        {
            v1.m_x -= v2.m_x;
            v1.m_y -= v2.m_y;
            return v1;
        }

        // Divide by a scalar number
        Vector2D operator/(float scalar)
        {
            return Vector2D(m_x / scalar, m_y / scalar);
        }
        Vector2D& operator/=(float scalar)
        {
            m_x /= scalar;
            m_y /= scalar;
            return *this;
        }

        // Normalizing a vector
        // l = length. vnormalized = v1 *1/l

        void normalize()
        {
            float l = length();
            if ( l > 0) // we never want to attempt to divide by 0
            {
                (*this) *= 1 / l;
            }
        }

    private:
        float m_x;
        float m_y;
};

#endif // VECTOR2D_H
