#include <fstream>

#include <gtest/gtest.h>
#include <eigen3/Eigen/Dense>
#include "../src/utils.hpp"

#include "../src/mlp_classifier.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace mnist;

const size_t input_dim = 784;
const size_t hidden_dim = 128;
const size_t output_dim = 10;

TEST(MlpClassifier, predict_class) {
    auto w1 = read_mat_from_file(input_dim, hidden_dim, "../../train_data/w1.txt");
    auto w2 = read_mat_from_file(hidden_dim, output_dim, "../../train_data/w2.txt");

    auto clf = MlpClassifier{w1.transpose(), w2.transpose()};

    auto features = MlpClassifier::features_t{};


    std::ifstream test_data{"../../train_data/test_data_mlp.txt"};
    ASSERT_TRUE(test_data.is_open());
    for (;;) {
        size_t y_true;
        test_data >> y_true;
        char delimitor[1];
        test_data.read(&delimitor[0], 1);
        if (!read_features(test_data, features)) {
            break;
        }
        auto [y_pred, accuracy]  = clf.predict(features);
        ASSERT_EQ(y_true, y_pred);
    }
}

