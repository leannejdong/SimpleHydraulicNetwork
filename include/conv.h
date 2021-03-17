/*!
 * Created by leanne on 3/15/21.
 */

#ifndef SIMPLEHYDRAULICNETWORK_CONV_H
#define SIMPLEHYDRAULICNETWORK_CONV_H

using Eigen::VectorXd;

inline MatrixXd makeEigenMatrixFromVectors(const vector<vector<double>> &matvalues)
{
    size_t n_rows = matvalues.size();
    size_t n_cols = matvalues[0].size();
    MatrixXd A(n_rows,n_cols);

    for (size_t i=0; i!=n_rows; ++i) {
        assert(matvalues[i].size() == n_cols);

        for (size_t j=0; j!=n_cols; ++j) {
            A(i,j) = matvalues[i][j];
        }
    }

    return A;
}

inline VectorXd makeEigenVectorFromVectors(const vector<double> &vecvalues)
{
    size_t n = vecvalues.size();
    VectorXd b(n);

    for (size_t i = 0; i < n; ++i)
    {
        b(i) = vecvalues[i];
    }

    return b;

}

inline vector<float> makeVectorsFromEigen(const VectorXd &vecvalues)
{
    using std::vector;
    size_t n = vecvalues.size();
    vector<float> b(n);
    for (size_t i = 0; i < n; ++i)
    {
        b[i] = vecvalues(i);
    }
    return b;
}

inline vector<vector<float>> makeMariceFromEigen(const MatrixXd &matvalues)
{
    size_t n_rows = matvalues.rows();
    size_t n_cols = matvalues.cols();
    vector<vector<float>> A(n_rows, vector<float> (n_cols, 0));

    for (size_t i = 0; i!= n_rows; ++i)
    {
        assert(matvalues.col(i).size() == n_cols);

        for (size_t j = 0; j!= n_cols; ++j)
        {
            A[i][j] = matvalues(i, j);

        }
    }
    return A;
}

#endif //SIMPLEHYDRAULICNETWORK_CONV_H
