#include "Vector2D.hpp"
#include <gtest/gtest.h>
#include <array>

namespace {
    class sixIntParametrization : public testing::TestWithParam<std::tuple<int, int, int, int, int, int>> {};    

    class ParametrizedVectorIntAddition : public sixIntParametrization {};
    TEST_P(ParametrizedVectorIntAddition, additionX) {
        auto [x1, y1, x2, y2, ex, ey] = GetParam();
        Vector2D<int> result = Vector2D<int>(x1, y1) + Vector2D<int>(x2, y2);
        EXPECT_EQ(result.x, ex);
    }
    TEST_P(ParametrizedVectorIntAddition, additionY) {
        auto [x1, y1, x2, y2, ex, ey] = GetParam();
        Vector2D<int> result = Vector2D<int>(x1, y1) + Vector2D<int>(x2, y2);
        EXPECT_EQ(result.y, ey);        
    }
    TEST_P(ParametrizedVectorIntAddition, plusEqX) {
        auto [x1, y1, x2, y2, ex, ey] = GetParam();
        Vector2D<int> result(x1, y1);
        result += Vector2D<int>(x2, y2);
        EXPECT_EQ(result.x, ex);
    }
    TEST_P(ParametrizedVectorIntAddition, plusEqY) {
        auto [x1, y1, x2, y2, ex, ey] = GetParam();
        Vector2D<int> result(x1, y1);
        result += Vector2D<int>(x2, y2);
        EXPECT_EQ(result.y, ey);
    }
    INSTANTIATE_TEST_SUITE_P(
        VectorIntAddition, 
        ParametrizedVectorIntAddition,
        testing::Values(
            std::make_tuple(137, 342, 0, 0, 137, 342),
            std::make_tuple(18, 2, 71, -17, 89, -15)
        )    
    );

    class ParametrizedVectorIntSubtraction : public sixIntParametrization {};
    TEST_P(ParametrizedVectorIntSubtraction, subtractionX) {
        auto [x1, y1, x2, y2, ex, ey] = GetParam();
        Vector2D<int> result = Vector2D<int>(x1, y1) - Vector2D<int>(x2, y2);
        EXPECT_EQ(result.x, ex);
    }
    TEST_P(ParametrizedVectorIntSubtraction, subtractionY) {
        auto [x1, y1, x2, y2, ex, ey] = GetParam();
        Vector2D<int> result = Vector2D<int>(x1, y1) - Vector2D<int>(x2, y2);
        EXPECT_EQ(result.y, ey);        
    }
    TEST_P(ParametrizedVectorIntSubtraction, subtractionEqX) {
        auto [x1, y1, x2, y2, ex, ey] = GetParam();
        Vector2D<int> result(x1, y1);
        result -= Vector2D<int>(x2, y2);
        EXPECT_EQ(result.x, ex);
    }
    TEST_P(ParametrizedVectorIntSubtraction, subtractionEqY) {
        auto [x1, y1, x2, y2, ex, ey] = GetParam();
        Vector2D<int> result(x1, y1);
        result -= Vector2D<int>(x2, y2);
        EXPECT_EQ(result.y, ey);
    }
    INSTANTIATE_TEST_SUITE_P(
        VectorIntSubtraction,
        ParametrizedVectorIntSubtraction,
        testing::Values(
            std::make_tuple(18, 7, 13, 12, 5, -5),
            std::make_tuple(9, 14, 16, 5, -7, 9)
        )
    );

    class ParametrizedVectorIntDotProduct : public sixIntParametrization {};

    TEST(Construction, intX) {
        Vector2D<int> result(2, 4);
        EXPECT_EQ(result.x, 2);
    }
    TEST(Construction, intY) {
        Vector2D<int> result(5, 9);
        EXPECT_EQ(result.y, 9);
    }
    TEST(Construction, floatX) {
        Vector2D<float> result(43.5221, 49.3993);
        EXPECT_FLOAT_EQ(result.x, 43.5221);
    }
    TEST(Construction, floatY) {
        Vector2D<float> result(8.23561, 9.72673);
        EXPECT_FLOAT_EQ(result.y, 9.72673);
    }
    TEST(Construction, doubleX) {
        Vector2D<double> result(9.4781, -3.421);
        EXPECT_DOUBLE_EQ(result.x, 9.4781);
    }
    TEST(Construction, doubleY) {
        Vector2D<double> result(22.41, 4.9782);
        EXPECT_DOUBLE_EQ(result.y, 4.9782);
    }

    /*
    TEST(IntAddition, x_both_positive) {
        Vector2D<int> result = Vector2D<int>(4, 9) + Vector2D<int>(16, 2);
        EXPECT_EQ(result.x, 20);
    }
    TEST(IntAddition, x_both_negative) {
        Vector2D<int> result = Vector2D<int>(-6, 21) + Vector2D<int>(-15, 20);
        EXPECT_EQ(result.x, -21);
    }
    TEST(IntAddition, x_mixed) {
        Vector2D<int> result = Vector2D<int>(7, 11) + Vector2D<int>(-11, 16);
        EXPECT_EQ(result.x, -4);
    }
    TEST(IntAddition, x_add_zero) {
        Vector2D<int> result = Vector2D<int>(18, 19) + Vector2D<int>(0, -16);
        EXPECT_EQ(result.x, 18);
    }
    TEST(IntAddition, y_both_positive) {
        Vector2D<int> result = Vector2D<int>(-7, 9) + Vector2D<int>(4, 42);
        EXPECT_EQ(result.y, 51);
    }
    TEST(IntAddition, y_both_negative) {
        Vector2D<int> result = Vector2D<int>(-4, -18) + Vector2D<int>(-3, -7);
        EXPECT_EQ(result.y, -25);
    }
    TEST(IntAddition, y_mixed) {
        Vector2D<int> result = Vector2D<int>(-178, -42) + Vector2D<int>(-26, 82);
        EXPECT_EQ(result.y, 40);
    }
    TEST(IntAddition, y_add_zero) {
        Vector2D<int> result = Vector2D<int>(-688, -498) + Vector<int>(51, 0);
        EXPECT_EQ(result.y, -498);
    }
    TEST(IntSubtraction, x_both_positive) {
        Vector2D<int> result = Vector2D<int>(98, 29) - Vector2D<int>(108, 12);
        EXPECT_EQ(result.x, 10);
    }
    TEST(IntSubtraction, x_both_negative) {
        Vector
    }
    TEST(FloatAddition, all_positive) {
        Vector2D<float> result = Vector2D<float>(3.6, 2.1) + Vector2D<float>(1.8, 3.2);
        EXPECT_FLOAT_EQ(result.x, 5.4);
        EXPECT_FLOAT_EQ(result.y, 5.3);
    }
    */
}