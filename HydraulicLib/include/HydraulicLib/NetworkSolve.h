/*!
 * Created by leanne on 3/20/21.
 */

#ifndef SIMPLEHYDRAULICNETWORK_NetworkSolve_H
#define SIMPLEHYDRAULICNETWORK_NetworkSolve_H
#include <Eigen/QR>
using Eigen::MatrixXd;

MatrixXd calculateSoln();
void NetworkSolve();

#endif //SIMPLEHYDRAULICNETWORK_NetworkSolve_H
