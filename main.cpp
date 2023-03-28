#include <iostream>
#include <stdexcept>

class Coord2D {
public:
    Coord2D(double x, double y) : m_x(x), m_y(y) {}

    double getX() const { return m_x; }
    double getY() const { return m_y; }

    double operator[](int index) const {
        if (index == 0) {
            return m_x;
        }
        else if (index == 1) {
            return m_y;
        }
        else {
            throw std::out_of_range("Invalid index");
        }
    }

    bool operator==(const Coord2D& other) const {
        return (m_x == other.m_x) && (m_y == other.m_y);
    }

protected:
    double m_x;
    double m_y;
};

class Coord3D : public Coord2D {
public:
    Coord3D(double x, double y, double z) : Coord2D(x, y), m_z(z) {}

    double getZ() const { return m_z; }

    double operator[](int index) const {
        if (index == 0) {
            return m_x;
        }
        else if (index == 1) {
            return m_y;
        }
        else if (index == 2) {
            return m_z;
        }
        else {
            throw std::out_of_range("Invalid index");
        }
    }

    bool operator==(const Coord3D& other) const {
        return (m_x == other.m_x) && (m_y == other.m_y) && (m_z == other.m_z);
    }

private:
    double m_z;
};

int main() {
    Coord2D c2d(1.0, 2.0);
    Coord3D c3d(3.0, 4.0, 5.0);

    std::cout << c2d.getX() << std::endl; // 1
    std::cout << c2d[0] << std::endl; // 1
    std::cout << c3d[2] << std::endl; // 5

    Coord2D* arr[] = { &c2d, &c3d };

    std::cout << (*arr[0] == Coord2D(1.0, 2.0)) << std::endl; // true
    std::cout << (*arr[1] == Coord3D(3.0, 4.0, 5.0)) << std::endl; // true

    return 0;
}
