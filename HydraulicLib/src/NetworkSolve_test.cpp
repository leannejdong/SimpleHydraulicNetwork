/*!
 * Created by leanne on 3/20/21.
 */
#include "HydraulicLib/NetworkSolve.h"
#include "doctest.h"
#include <Eigen/QR>
#include <cassert>
#include <iostream>
#include <cmath>

using Eigen::VectorXd;
TEST_CASE("testing network solver") {
    MatrixXd expect(8,1);
    expect << 61.5766, 11.5465, 4.45635, 13.4064, 32.1674,  25.424, 2.71611, 4.02726;
    std::cerr << "The expected: " << expect.transpose() << "\n";
    MatrixXd result = NetworkSolve();
    std::cerr << "The result: " << result.row(0) << "\n";
    CHECK((result.row(0) - expect.transpose()).norm()<=1e-4);
    std::cerr << "pass l1 norm" << "\n";

    CHECK((result.row(0) - expect.transpose()).squaredNorm()<=1e-8);
    std::cerr << "pass l2 norm" << "\n";
}
