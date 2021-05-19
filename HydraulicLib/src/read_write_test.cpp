/*!
 * Created by leanne on 3/20/21.
 */
#include "HydraulicLib/read_write.h"
#include "HydraulicLib/ConvEigen.h"
#include "doctest.h"

// not in use
//TEST_CASE("testing read_csv") {
//   // auto f = read_csv("/home/leanne/CLionProjects/SimpleHydraulicNetwork/inputs/matrix.csv");
//    auto f = read_csv("inputs/matrix.csv");
//}

TEST_CASE("testing openData") {
    MatrixXd expect_row0(7, 1);
    expect_row0 << 1601.712489,280.7502345,727.4294176,844.6040675,171.1146591,253.7172345,3879.328102;
    MatrixXd actual_data(8760, 7);
    actual_data << openData("inputs/matrix.csv");
    CHECK((actual_data.row(0) - expect_row0.transpose()).norm() < 1e-4);
    std::cerr << "pass openData.csv\n";
}

TEST_CASE(" testing saveData") {
    MatrixXd A(3,3);
    A << 1, 0, 1, 1, 2, 3, 4, 5, 6;
    saveData("outputs/saveData.csv", A);
    MatrixXd result_data = openData("outputs/saveData.csv");
   // std::cerr << "The result_data.row(0) is " << result_data.row(0) << "\n";

    MatrixXd expect_data(3,1) ;
    expect_data << 1, 0, 1;
   // std::cerr << "The expect_data.transpose is " << expect_data.transpose() << "\n";
    CHECK(result_data.row(0) == expect_data.transpose());
    std::cerr << "pass saveData.csv\n";
}

