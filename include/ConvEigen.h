/*!
 * Created by leanne on 3/15/21.
 */

#ifndef SIMPLEHYDRAULICNETWORK_CONVEIGEN_H
#define SIMPLEHYDRAULICNETWORK_CONVEIGEN_H
#include<Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::IOFormat;
using Eigen::FullPrecision;
using std::vector;
using Eigen::Matrix;
using Eigen::Map;
using Eigen::Dynamic;
using Eigen::RowMajor;

void saveData(std::string fileName, MatrixXd  matrix)
{
    //https://eigen.tuxfamily.org/dox/structEigen_1_1IOFormat.html
    const static IOFormat CSVFormat(FullPrecision, Eigen::DontAlignCols, ", ", "\n");

    std::ofstream file(fileName);
    if (!file) return;
    {
        file << matrix.format(CSVFormat);
        // file.close();
    }
}

MatrixXd openData(std::string fileToOpen)
{

    // the inspiration for creating this function was drawn from here
    // https://stackoverflow.com/questions/34247057/how-to-read-csv-file-and-assign-to-eigen-matrix

    // the input is the file: "fileToOpen.csv":
    // a,b,c
    // d,e,f
    // This function converts input file data into the Eigen matrix format


    // the matrix entries are stored in this variable row-wise. For example if we have the matrix:
    // M=[a b c
    //	  d e f]
    // the entries are stored as matrixEntries=[a,b,c,d,e,f], that is the variable "matrixEntries" is a row vector
    // later on, this vector is mapped into the Eigen matrix format
    vector<double> matrixEntries;

    // in this object we store the data from the matrix
    std::ifstream matrixDataFile(fileToOpen);

    // this variable is used to store the row of the matrix that contains commas
    std::string matrixRowString;

    // this variable is used to store the matrix entry;
    std::string matrixEntry;

    // this variable is used to track the number of rows
    int matrixRowNumber = 0;


    while (getline(matrixDataFile, matrixRowString)) // here we read a row by row of matrixDataFile and store every line into the string variable matrixRowString
    {
        std::stringstream matrixRowStringStream(matrixRowString); //convert matrixRowString that is a string to a stream variable.

        while (getline(matrixRowStringStream, matrixEntry, ',')) // here we read pieces of the stream matrixRowStringStream until every comma, and store the resulting character into the matrixEntry
        {
            matrixEntries.push_back(stod(matrixEntry));   //here we convert the string to double and fill in the row vector storing all the matrix entries
        }
        matrixRowNumber++; //update the column numbers
    }

    // here we convet the vector variable into the matrix and return the resulting object,
    // note that matrixEntries.data() is the pointer to the first memory location at which the entries of the vector matrixEntries are stored;
    return Map<Matrix<double, Dynamic, Dynamic, RowMajor>>(matrixEntries.data(), matrixRowNumber, matrixEntries.size() / matrixRowNumber);

}

#endif //SIMPLEHYDRAULICNETWORK_CONVEIGEN_H
