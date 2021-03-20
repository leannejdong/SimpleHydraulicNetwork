/*!
 * Created by leanne on 3/20/21.
 */
#include "HydraulicLib/ConvEigen.h"
#include <Eigen/QR>
#include <fstream>
#include <iostream>
#include <sstream> // std::stringstream
#include <stdexcept> // std::runtime_error
#include <utility> // std::pair
#include <string>
#include <vector>
//#include "include/read_write.h"
//#include "include/conv.h"
using Eigen::VectorXd;
using std::cerr;
using std::cout;

void NetworkSolve() {
//    // Read three_cols.csv and ones.csv
//    std::vector<std::pair<std::string, std::vector<double>>> mul_cols = read_csv("Heating_Cooling_data.csv");
//
//    // Write to another file to check that this was successful
//    write_csv("Heating_Cooling_data_copy.csv", mul_cols);
    // matrix to be loaded from a file
    MatrixXd data;

    // load the matrix from the file
   // data = openData("/home/leanne/CLionProjects/SimpleHydraulicNetwork/inputs/matrix.csv");
    data = openData("inputs/matrix.csv");
    VectorXd Demand_A = data.col(0);
    VectorXd Demand_B = data.col(1);
    VectorXd Demand_C = data.col(2);
    VectorXd Demand_D = data.col(3);
    VectorXd Demand_E = data.col(4);
    VectorXd Demand_F = data.col(5);
    VectorXd Demand_z0(8760);
    Demand_z0.setZero();
    VectorXd Demand_z4(8760);
    Demand_z4.setZero();

    Demand_A = Demand_A/4.2/15;
    Demand_B = Demand_B/4.2/15;
    Demand_C = Demand_C/4.2/15;
    Demand_D = Demand_D/4.2/15;
    Demand_E = Demand_E/4.2/15;
    Demand_F = Demand_F/4.2/15;

    //   cerr << Demand_C.size() << "\n";
    MatrixXd B(8760, 8);
    B << Demand_z0, Demand_C, Demand_B, Demand_D, Demand_z4, Demand_A, Demand_E, Demand_F;
    //   cerr << B << "\n";

    MatrixXd Q = MatrixXd::Zero(8760, 8);
    Q.col(1) = Demand_C;
    Q.col(2) = Demand_B;
    Q.col( 3) = Demand_D;
    Q.col(4) = Demand_A + Demand_E + Demand_F;
    Q.col(5) = Demand_A;
    Q.col(6) = Demand_E;
    Q.col(7) = Demand_F;
    Q.col(0) = Demand_C + Demand_B + Demand_D + Demand_A + Demand_E + Demand_F;
    cerr << "The first set of solutions is \n" << Q.row(0) << "\n";
    saveData("outputs/flowQ.csv", Q);
    cerr << Q.rows() << " rows and " << Q.cols() << " columns.";
//    MatrixXd A(8, 8);
//    A << 1, -1, -1, -1, -1, 0, 0, 0,
//            0, 1, 0, 0, 0, 0, 0, 0,
//            0, 0, 1, 0, 0, 0, 0, 0,
//            0, 0, 0, 1, 0, 0, 0, 0,
//            0, 0, 0, 0, 1, -1, -1, 1,
//            0, 0, 0, 0, 0, 1, 0, 0,
//            0, 0, 0, 0, 0, 0, 1, 0,
//            0, 0, 0, 0, 0, 0, 0, 1;

    //MatrixXd X = A.colPivHouseholderQr().solve(B.transpose());
//    MatrixXd X = A.lu().solve(B.transpose());
//    cerr << "The condition number is " << A.lu().rcond() << "\n";
//    cerr << "The first set of solutions is \n" << X.col(0) << "\n";
//    double relative_err = (A*X - B.transpose()).norm()/B.transpose().norm();
//    cerr << "The relative error is:\n" << relative_err << "\n";
//    saveData("outputs/flow.csv", X.transpose());
////    Eigen::IOFormat csv(-1, 0, ", ", "\n");
////    std::cout << X.format(csv) << std::endl;
//    cerr << X.rows() << " rows and " << X.cols() << " columns.";

//    for (int i = 0; i < data.rows(); ++i){
//        Demand_A(i) = Demand_A(i)/4.2/15;
//        Demand_B(i) = Demand_B(i)/4.2/15;
//        Demand_C(i) = Demand_C(i)/4.2/15;
//        Demand_D(i) = Demand_D(i)/4.2/15;
//        Demand_E(i) = Demand_E(i)/4.2/15;
//        Demand_F(i) = Demand_F(i)/4.2/15;
//;    }
    // MatrixXd Q = MatrixXd::Zero(8760, 8);

//    for (int i = 0; i < data.rows(); ++i){
//        b << 0.0, Demand_C(i), Demand_B(i), Demand_D(i), 0.0, Demand_A(i), Demand_E(i), Demand_F(i);
//        VectorXd x = A.colPivHouseholderQr().solve(b);
//        cout << "The solution is:\n" << x << "\n";
//    }
}

/*
 * Our accuracy are good but we are getting some systematic error as the solutions from Matlab and C++ deviate.
 * This might due to the non-empty nullspace. If our matrix is rank deficient the solution may have an arbitrary large component added in the null space.
 * In other words if Ax = b then the computed solution might be x' = x* + x0, where A*x0 = 0, so r = A*x'-b = 0.
 * So, we could have perfect accuracy but still produce different solutions due to the non-empty nullspace.
 * If my system is well-conditioned, I will not need to worry about that.  If it isn't, it might help explain the systematic error I'm getting.
 *
 */

/*
 * Precision could be lost when reading/writing CSV file
 * Residual error (or existence of solutions)
 * Rank deficiency
 * Well conditionness
 */

