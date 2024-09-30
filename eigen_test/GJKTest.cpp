#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#include <Eigen/Eigen>
#include <Eigen/Geometry>

double cross(const Eigen::Vector2d &a, const Eigen::Vector2d &b)
{
    return a.x() * b.y() - a.y() * b.x();
}

/**
 * @brief Determine if a given polygon is convex
 * @param ploy polygon to be determined
 * @return true if the polygon is convex, false otherwise
 *
 * This function works by walking along the edges of the polygon,
 * and checking if the cross product of each pair of adjacent
 * edges have the same sign. If the sign changes, then the
 * polygon is concave.
 */
bool isConvex(const std::vector<Eigen::Vector2d> &ploy)
{
    if (ploy.size() < 4)
        return true;

    double sign = 0;
    sign = cross(ploy[1] - ploy[0], ploy[2] - ploy[1]);

    for (int i = 2; i < ploy.size(); i++)
    {
        double cur_d = 0.0;
        cur_d = i + 1 < ploy.size() ? cross(ploy[i] - ploy[i - 1], ploy[i + 1] - ploy[i])
                                    : cross(ploy[i] - ploy[i - 1], ploy[0] - ploy[i]);
        if (cur_d * sign < 0)
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Find the point in the polygon ploy furthest in the direction dir.
 * @param ploy the polygon
 * @param dir the direction
 * @return the point in ploy furthest in the direction dir
 *
 * This is used in the GJK algorithm to find the point in a polygon
 * that is the furthest in a given direction.
 */
Eigen::Vector2d Support(const std::vector<Eigen::Vector2d> &ploy, const Eigen::Vector2d &dir)
{
    Eigen::Vector2d ret = ploy[0];
    double max_distance = ploy[0].dot(dir);
    for (int i = 0; i < ploy.size(); i++)
    {
        if (ploy[i].dot(dir) > max_distance)
        {
            ret = ploy[i];
            max_distance = ploy[i].dot(dir);
        }
    }

    return ret;
}

/**
 * @brief Get the new vertex in the Minkowski difference of two polygons.
 * @param poly1 the first polygon
 * @param poly2 the second polygon
 * @param dir the direction in which to find the new vertex
 * @return the new vertex
 *
 * This function is used in the GJK algorithm to find the new vertex in
 * the Minkowski difference of two polygons. It first finds the point in
 * each polygon that is the furthest in the given direction. It then
 * subtracts the two points to get the new vertex in the Minkowski difference.
 */
Eigen::Vector2d GetNewVertex(const std::vector<Eigen::Vector2d> &poly1,
                             const std::vector<Eigen::Vector2d> &poly2,
                             const Eigen::Vector2d &dir)
{
    auto a = Support(poly1, dir);
    auto b = Support(poly2, -dir);
    return a - b;
}

/**
 * @brief Calculate the area of a triangle given its three vertices.
 * @param p1 the first vertex
 * @param p2 the second vertex
 * @param p3 the third vertex
 * @return the area of the triangle
 *
 * This function uses Heron's formula to calculate the area of a triangle
 * given its three vertices.
 */
double HeronArea(const Eigen::Vector2d &p1,
                 const Eigen::Vector2d &p2,
                 const Eigen::Vector2d &p3)
{
    double a = (p1 - p2).norm();
    double b = (p2 - p3).norm();
    double c = (p3 - p1).norm();
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

/**
 * @brief Check if the origin is in the triangle of the given 3 points
 * @param simplex the three points of the triangle
 * @return true if the origin is in the triangle
 *
 * This function uses Heron's formula to calculate the area of the triangle
 * given its three vertices.
 *
 * It uses the following algorithm:
 * 1. Calculate the area of the triangle using Heron's formula
 * 2. Calculate the area of the three triangles formed by the origin and
 *    each pair of the three vertices
 * 3. Check if the sum of the three areas is equal to the area of the original
 *    triangle
 *
 */
bool haveOrigin(const std::vector<Eigen::Vector2d> &simplex)
{
    Eigen::Vector2d origin = Eigen::Vector2d(0, 0);
    auto s1 = HeronArea(origin, simplex[0], simplex[1]);
    auto s2 = HeronArea(origin, simplex[1], simplex[2]);
    auto s3 = HeronArea(origin, simplex[0], simplex[2]);
    auto S = HeronArea(simplex[0], simplex[1], simplex[2]);

    if (s1 + s2 + s3 - S < 0.00001)
    {
        cout << "S is:" << S << "s is:" << s1 + s2 + s3 << endl;
        return true;
    }

    return false;
}

bool cmp(Eigen::Vector2d a, Eigen::Vector2d b)
{
    // small to large
    return a.norm() < b.norm();
}

Eigen::Vector2d calculateNormalVector(const Eigen::Vector2d &p1, const Eigen::Vector2d &p2)
{
    Eigen::Vector2d vectorDiff = p2 - p1;
    Eigen::Vector2d unitVector = vectorDiff.normalized();
    Eigen::Vector2d normalVector(unitVector.y(), -unitVector.x());

    return normalVector;
}

/**
 * @brief Check if two convex polygons intersect using the GJK algorithm
 * @param poly1 the first polygon
 * @param poly2 the second polygon
 * @return true if the two polygons intersect
 *
 * This function uses the GJK algorithm to check if two convex
 * polygons intersect. It first calculates the point in each
 * polygon that is the furthest in the direction of the other
 * polygon. It then checks if the line segment between the two
 * points contains the origin. If it does, then the two polygons
 * intersect. If not, then it calculates the point in each
 * polygon that is the furthest in the direction of the line
 * segment between the two points and checks if the origin is in
 * the triangle formed by the two points and the third point.
 * If it is, then the two polygons intersect. If not, then they
 * do not.
 *
 * The time complexity of this algorithm is O(n), where n is the
 * number of vertices of the two polygons.
 */
bool GJK(const std::vector<Eigen::Vector2d> &poly1, const std::vector<Eigen::Vector2d> &poly2)
{
    vector<Eigen::Vector2d> simplex;

    Eigen::Vector2d dir = Eigen::Vector2d(0, 1);
    Eigen::Vector2d vertex = GetNewVertex(poly1, poly2, dir);
    simplex.push_back(vertex);

    dir = -dir;
    cout << "simplex: [" << simplex[0].transpose() << "]" << endl;
    cout << "dirtance: " << dir.transpose() << endl;
    cout << "--------------------------" << endl;

    while (true)
    {
        vertex = GetNewVertex(poly1, poly2, dir);
        std::cout << "vertex.dir: " << vertex.dot(dir) << std::endl;
        if (vertex.dot(dir) <= 0)
        {
            return false;
        }
        // update simplex
        simplex.push_back(vertex);
        cout << "simplex: ";
        for (auto x : simplex)
        {
            cout << "[" << x.transpose() << "] ";
        }
        cout << endl;

        // update dir, and judge if the origin is in the simplex
        if (simplex.size() == 2)
        {
            dir = calculateNormalVector(simplex[0], simplex[1]);
        }
        if (simplex.size() == 3)
        {

            if (haveOrigin(simplex))
            {

                return true;
            }

            sort(simplex.begin(), simplex.end(), cmp);
            simplex.pop_back();

            dir = calculateNormalVector(simplex[0], simplex[1]);
        }

        cout << "dirtance: " << dir.transpose() << endl;
        cout << "--------------------------" << endl;
    }
}

int main()
{
    std::vector<Eigen::Vector2d> poly1, poly2;

    // 创建两个多边形 poly1 和 poly2
    poly1.push_back(Eigen::Vector2d(0, 0));
    poly1.push_back(Eigen::Vector2d(3, 0));
    poly1.push_back(Eigen::Vector2d(3, 3));
    poly1.push_back(Eigen::Vector2d(0, 3));
    // 重叠测试
    // poly2.push_back(Eigen::Vector2d(2, 2));
    // poly2.push_back(Eigen::Vector2d(5, 2));
    // poly2.push_back(Eigen::Vector2d(5, 5));
    // poly2.push_back(Eigen::Vector2d(2, 5));

    // 不重叠测试
    poly2.push_back(Eigen::Vector2d(4, 3));
    poly2.push_back(Eigen::Vector2d(5, 3));
    poly2.push_back(Eigen::Vector2d(4, 5));
    poly2.push_back(Eigen::Vector2d(4, 5));

    if (!isConvex(poly1) || !isConvex(poly2))
    {
        std::cout << "no convex" << std::endl;
        return 0;
    }

    if (GJK(poly1, poly2))
    {
        std::cout << "overlap" << std::endl;
    }
    else
    {
        std::cout << "no overlap" << std::endl;
    }

    return 0;
}