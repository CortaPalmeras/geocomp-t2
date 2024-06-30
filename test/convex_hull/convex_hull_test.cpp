
#include <cstdlib>
#include <gtest/gtest.h>
#include <iostream>
#include <random>

std::mt19937 test_rng;

class TestEnv : public ::testing::Environment {
    std::random_device seedgen;

public:
    void SetUp() override {
        int seed = seedgen();
        std::cout << "\nSeed para tests: " << seed << '\n' << std::endl;
        test_rng.seed(seed);
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    testing::AddGlobalTestEnvironment(new TestEnv);
    return RUN_ALL_TESTS();
}
