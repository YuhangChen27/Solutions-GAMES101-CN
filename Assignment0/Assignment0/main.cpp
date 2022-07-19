#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <cmath>
using namespace std;

void rotate2d(Eigen::Vector3f& point, float angle) {
    float rad = float(angle) / 180.0f * float(EIGEN_PI);
    Eigen::Matrix3f m_rotation;
    m_rotation << float(cos(rad)), float(-sin(rad)), 0.0f, float(sin(rad)), float(cos(rad)), 0.0f, 0.0f, 0.0f, 1.0f;
    point = m_rotation * point;
}

void translate2d(Eigen::Vector3f& point, float tx, float ty) {
    Eigen::Vector3f v_translate(float(tx), float(ty), 0);
    auto rotated_point = point + v_translate;
    point = Eigen::Vector3f(rotated_point(0, 0), rotated_point(1, 0), rotated_point(2, 0));
}

int main()
{
    cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    cout << a << endl;
    cout << a / b << endl;
    cout << sqrt(b) << std::endl;
    cout << acos(-1) << std::endl;
    cout << sin(30.0 / 180.0 * acos(-1)) << endl;

    cout << "Example of vector \n";
    
    Eigen::Vector3f v(1.0f, 2.0f, 3.0f);
    Eigen::Vector3f w(1.0f, 0.0f, 0.0f);

    cout << "Example of output \n";
    cout << v << endl;

    cout << "Example of add \n";
    cout << v + w << endl;

    cout << "Example of scalar multiply \n";
    cout << v * 3.0f << endl;
    cout << 2.0f * v << endl;


    cout << "Example of matrix \n";

    Eigen::Matrix3f i, j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;

    cout << "Example of output \n";
    cout << i << endl;

    cout << "Example of add \n";
    cout << i + j << endl;

    cout << "Example of scalar multiply \n";
    cout << i * 2.0f << endl;

    cout << "Example of matrix multiply \n";
    cout << i * j << endl;

    cout << "Example of vector-matrix multiply \n";
    cout << i * v << endl;


    cout << "Point P = (2, 1), 45 degree CCW rotation with respect to (0, 0), followed with (1, 2) translation." << endl;
    Eigen::Vector3f P(2, 1, 1);
    rotate2d(P, 45);
    translate2d(P, 1, 2);
    cout << P << endl;
    return 0;
}
