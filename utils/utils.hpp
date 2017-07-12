#ifndef __BUSH_UTILS_HPP__
#define __BUSH_UTILS_HPP__

#include "Eigen/Dense"

class Distance {
public:
    /* Euclidean Distance
     * d = ((x1-x2)^2 + (y1-y2)^2 + ...)^(1/2)
     * */
    static double euclideanDistance(const Eigen::VectorXd &a,
                const Eigen::VectorXd &b) {
        Eigen::VectorXd x = a - b;
        Eigen::VectorXd c;
        for (int i = 0; i < x.size(); ++i) {
            c << power(x[i], 2);
        }

        return c.sum();
    }

    /* Manhattan Distance
     * d = |x1-x2| + |y1-y2| + ...
     * */
    static double manhattanDistance(const Eigen::VectorXd &a,
                const Eigen::VectorXd &b) {
        Eigen::VectorXd x = a - b;
        Eigen::VectorXd c;

        for (int i = 0; i < x.size(); ++i) {
            c << abs(x[i]);
        }

        return c.sum();
    }

    /* Chebyshev Distance
     * d = max(|x1-x2|, |y1-y2|, ...)
     * */
    static double chebyshevDistance(const Eigen::VectorXd &a,
                const Eigen::VecotrXd &b) {
        Eigen::VectorXd x = a - b;
        Eigen::VectorXd c;

        for (int i = 0; i < x.size(); ++i) {
            c << abs(x[i]);
        }
        return (double)x.maxCoeff();
    }

};

#endif
