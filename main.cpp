#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include "include/read_write.h"



int main() {
    // Read three_cols.csv and ones.csv
    std::vector<std::pair<std::string, std::vector<int>>> mul_cols = read_csv("Heating_Cooling_data.csv");

    // Write to another file to check that this was successful
    write_csv("Heating_Cooling_data_copy.csv", mul_cols);
    return 0;
}