
#include "eigen3/Eigen/Dense"

#include <istream>
#include <string>

#include "classifier.h"

Eigen::MatrixXf read_mat_from_stream(size_t rows, size_t cols, std::istream& stream);

Eigen::MatrixXf read_mat_from_file(size_t rows, size_t cols, const std::string& filepath);

bool read_features(std::istream& stream, mnist::Classifier::features_t& features, const char delimiter = ' ');

std::vector<float> read_vector(std::istream&);