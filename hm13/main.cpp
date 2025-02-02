#include <iostream>
#include <string>
#include "src/accuracyHelper.hpp"

using namespace std;

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    throw std::runtime_error("Incorrect input parameters");
  }
  const std::string testFile = argv[1];
  const std::string m1File = argv[2];
  const std::string m2File = argv[3];

  AccuracyHelper::calculateAccuracy(m1File, m2File, testFile);

  return 0;
}
