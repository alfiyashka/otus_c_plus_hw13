#include "accuracyHelper.hpp"
#include <fstream>
#include <iostream>

#include "mlp_classifier.h"
#include "utils.hpp"

#include "eigen3/Eigen/Dense"

double AccuracyHelper::calculateAccuracy(const std::string &m1File,  // first layer filename
                                       const std::string &m2File,  // second layer filename
                                       const std::string testFile) // test filename
{
    std::ifstream testFileSt(testFile, std::ifstream::in);
    if (!testFileSt.is_open())
    {
        throw std::runtime_error("Test file does not exist");
    }
    else
    {
        const size_t input_dim = 784;
        const size_t hidden_dim = 128;
        const size_t output_dim = 10;

        auto w1 = read_mat_from_file(input_dim, hidden_dim, m1File);
        auto w2 = read_mat_from_file(hidden_dim, output_dim, m2File);

        auto clf = mnist::MlpClassifier{w1.transpose(), w2.transpose()};

        auto features = mnist::MlpClassifier::features_t{};

        double pred = 0;
        int counter = 0;
        float failpredict = 0;
        size_t classNumber;
        for (;;)
        {
            testFileSt >> classNumber;
            char delimitor;
            testFileSt >> delimitor;
            if (!read_features(testFileSt, features, ','))
            {
                break;
            }
            auto [predictedClass, accuracy] = clf.predict(features);
            if (predictedClass == classNumber)
            {
                pred += accuracy;
            }
            else
            {
                failpredict++;
            }
            counter++;
        }
        const auto accuracy = pred / counter;
        const float failureDetection = failpredict / counter;
        std::cout << "Accuracy is " << accuracy << ". Failure detection: " << failureDetection << " \n";
        return accuracy;
    }
    return 0;
}