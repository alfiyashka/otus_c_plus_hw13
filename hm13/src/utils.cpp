#include "utils.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

Eigen::MatrixXf read_mat_from_stream(size_t rows, size_t cols, std::istream& stream) {
    Eigen::MatrixXf res(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            float val;
            stream >> val;
            res(i, j) = val;
        }
    }
    return res;
}

Eigen::MatrixXf read_mat_from_file(size_t rows, size_t cols, const std::string& filepath) {
    std::ifstream stream{filepath};
    if (!stream.is_open())
    {
        throw std::runtime_error(
            (std::string("Data file with name ") + filepath + " does not exist").c_str());
    }
    return read_mat_from_stream(rows, cols, stream);
}


bool read_features(std::istream& stream, mnist::Classifier::features_t& features, const char delimiter /*= ' '*/) {
    std::string line;
    std::getline(stream, line);

    features.clear();
    std::istringstream linestream{line};
    std::string valueStr;
    int value;
    while (std::getline(linestream, valueStr, delimiter)) {
        value = std::atoi(valueStr.c_str());
        features.push_back(value);
    }
    return stream.good();
}

std::vector<float> read_vector(std::istream& stream) {
    std::vector<float> result;

    std::copy(std::istream_iterator<float>(stream),
              std::istream_iterator<float>(),
              std::back_inserter(result));
    return result;
}