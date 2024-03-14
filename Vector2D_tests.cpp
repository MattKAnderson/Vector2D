#include "Vector2D.hpp"
#include <gtest/gtest.h>
#include <array>

namespace {
    namespace IntegralSpecializationTests {

        class sixIntParametrization : public testing::TestWithParam<std::tuple<int, int, int, int, int, int>> {};    
        class fiveIntParametrization : public testing::TestWithParam<std::tuple<int, int, int, int, int>> {};
        class fourIntParametrization : public testing::TestWithParam<std::tuple<int, int, int, int>> {};

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

        class ParametrizedVectorIntDotProduct : public fiveIntParametrization {};
        TEST_P(ParametrizedVectorIntDotProduct, dotProduct) {
            auto [x1, y1, x2, y2, expected] = GetParam();
            int result = Vector2D<int>(x1, y1) * Vector2D<int>(x2, y2);
            EXPECT_EQ(result, expected);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorIntDotProduct,
            ParametrizedVectorIntDotProduct,
            testing::Values(
                std::make_tuple(4, 2, 8, 5, 42),
                std::make_tuple(0, 16, 12, 29, 464),
                std::make_tuple(7, 0, 13, 19, 91),
                std::make_tuple(1, 0, 23, 12, 23),
                std::make_tuple(0, 1, 23, 17, 17),
                std::make_tuple(-12, 5, 8, 12, -36)
            )
        );

        class ParametrizedVectorIntScalarProduct : public fiveIntParametrization {};
        TEST_P(ParametrizedVectorIntScalarProduct, scalarTimesVectorX) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<int> result = s * Vector2D<int>(x, y);
            EXPECT_EQ(result.x, ex);
        }
        TEST_P(ParametrizedVectorIntScalarProduct, scalarTimesVectorY) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<int> result = s * Vector2D<int>(x, y);
            EXPECT_EQ(result.y, ey);
        }
        TEST_P(ParametrizedVectorIntScalarProduct, VectorTimesScalarX) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<int> result = Vector2D<int>(x, y) * s;
            EXPECT_EQ(result.x, ex);
        }
        TEST_P(ParametrizedVectorIntScalarProduct, VectorTimesScalarY) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<int> result = Vector2D<int>(x, y) * s;
            EXPECT_EQ(result.y, ey);
        }
        TEST_P(ParametrizedVectorIntScalarProduct, ScalarTimesEqualsX) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<int> result(x, y);
            result *= s;
            EXPECT_EQ(result.x, ex);
        }
        TEST_P(ParametrizedVectorIntScalarProduct, ScalarTimesEqualsY) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<int> result(x, y);
            result *= s;
            EXPECT_EQ(result.y, ey);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorIntScalarProduct, 
            ParametrizedVectorIntScalarProduct,
            testing::Values(
                std::make_tuple(0, 7, 12, 0, 84),
                std::make_tuple(9, 0, 4, 36, 0),
                std::make_tuple(17, -5, 0, 0, 0),
                std::make_tuple(-2, 5, 1, -2, 5),
                std::make_tuple(3, 14, -3, -9, -42),
                std::make_tuple(-6, 6, -6, 36, -36)
            )
        );

        class ParametrizedVectorIntDivision : public fiveIntParametrization {};
        TEST_P(ParametrizedVectorIntDivision, divisionX) {
            auto [x1, y1, s, ex, ey] = GetParam();
            Vector2D<int> result = Vector2D<int>(x1, y1) / s;
            EXPECT_EQ(result.x, ex);
        }
        TEST_P(ParametrizedVectorIntDivision, divisionY) {
            auto [x1, y1, s, ex, ey] = GetParam();
            Vector2D<int> result = Vector2D<int>(x1, y1) / s;
            EXPECT_EQ(result.y, ey);
        }
        TEST_P(ParametrizedVectorIntDivision, divsionEqX) {
            auto [x1, y1, s, ex, ey] = GetParam();
            Vector2D<int> result(x1, y1);
            result /= s;
            EXPECT_EQ(result.x, ex);
        }
        TEST_P(ParametrizedVectorIntDivision, divisionEqY) {
            auto [x1, y1, s, ex, ey] = GetParam();
            Vector2D<int> result(x1, y1);
            result /= s;
            EXPECT_EQ(result.y, ey);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorIntDivision,
            ParametrizedVectorIntDivision,
            testing::Values(
                std::make_tuple(16, 8, 2, 8, 4),
                std::make_tuple(7, 4, 2, 3, 2),
                std::make_tuple(21, -17, 3, 7, -5),
                std::make_tuple(0, 13, 5, 0, 2),
                std::make_tuple(-28, 7, -12, 2, 0),
                std::make_tuple(62, 0, -8, -7, 0)
            )
        );

        class ParametrizedVectorIntEquality : public testing::TestWithParam<std::tuple<int, int, int, int, bool>> {};
        TEST_P(ParametrizedVectorIntEquality, equality) {
            auto [x1, y1, x2, y2, expected] = GetParam();
            bool result = Vector2D<int>(x1, y1) == Vector2D<int>(x2, y2);
            EXPECT_EQ(result, expected);
        }
        TEST_P(ParametrizedVectorIntEquality, inequality) {
            auto [x1, y1, x2, y2, expected] = GetParam();
            bool result = Vector2D<int>(x1, y1) != Vector2D<int>(x2, y2);
            EXPECT_EQ(result, !expected);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorIntEquality,
            ParametrizedVectorIntEquality,
            testing::Values(
                std::make_tuple(13, 9, 13, 8, false),
                std::make_tuple(12, 8, 12, 8, true),
                std::make_tuple(7, 19, 7, 3, false),
                std::make_tuple(-7, 13, 7, 13, false),
                std::make_tuple(-29, 2, 29, -2, false),
                std::make_tuple(3, -27, 3, -27, true)
            )
        );
    }
    namespace FloatingPointTests {
        class sixDoubleParametrization : public testing::TestWithParam<std::tuple<double, double, double, double, double, double>> {};
        class fiveDoubleParametrization : public testing::TestWithParam<std::tuple<double, double, double, double, double>> {};

        class ParametrizedVectorAddition : public sixDoubleParametrization {};
        TEST_P(ParametrizedVectorAddition, additionX) {
            auto [x1, y1, x2, y2, ex, ey] = GetParam();
            Vector2D<double> result = Vector2D<double>(x1, y1) + Vector2D<double>(x2, y2);
            EXPECT_NEAR(result.x, ex, 1e-8);
        }
        TEST_P(ParametrizedVectorAddition, additionY) {
            auto [x1, y1, x2, y2, ex, ey] = GetParam();
            Vector2D<double> result = Vector2D<double>(x1, y1) + Vector2D<double>(x2, y2);
            EXPECT_NEAR(result.y, ey, 1e-8);        
        }
        TEST_P(ParametrizedVectorAddition, plusEqX) {
            auto [x1, y1, x2, y2, ex, ey] = GetParam();
            Vector2D<double> result(x1, y1);
            result += Vector2D<double>(x2, y2);
            EXPECT_NEAR(result.x, ex, 1e-8);
        }
        TEST_P(ParametrizedVectorAddition, plusEqY) {
            auto [x1, y1, x2, y2, ex, ey] = GetParam();
            Vector2D<double> result(x1, y1);
            result += Vector2D<double>(x2, y2);
            EXPECT_NEAR(result.y, ey, 1e-8);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorAddition, 
            ParametrizedVectorAddition,
            testing::Values(
                std::make_tuple(84.561, 9.0345, 0, 0, 84.561, 9.0345),
                std::make_tuple(0, 0, 52.7562, 103.56, 52.7562, 103.56),
                std::make_tuple(4.76234, -1.3789, -3.456, 22.4857, 1.30634, 21.1068),
                std::make_tuple(-6.667, -0.9612, -12.387, -0.01128, -19.054, -0.97248),
                std::make_tuple(1722841.21451, -7197591213.12, 234002341.09, 10008314.821, 235725182.30451, -7187582898.299)
            )    
        );

        class ParametrizedVectorSubtraction : public sixDoubleParametrization {};
        TEST_P(ParametrizedVectorSubtraction, subtractionX) {
            auto [x1, y1, x2, y2, ex, ey] = GetParam();
            Vector2D<double> result = Vector2D<double>(x1, y1) - Vector2D<double>(x2, y2);
            EXPECT_NEAR(result.x, ex, 1e-8);
        }
        TEST_P(ParametrizedVectorSubtraction, subtractionY) {
            auto [x1, y1, x2, y2, ex, ey] = GetParam();
            Vector2D<double> result = Vector2D<double>(x1, y1) - Vector2D<double>(x2, y2);
            EXPECT_NEAR(result.y, ey, 1e-8);        
        }
        TEST_P(ParametrizedVectorSubtraction, subtractionEqX) {
            auto [x1, y1, x2, y2, ex, ey] = GetParam();
            Vector2D<double> result(x1, y1);
            result -= Vector2D<double>(x2, y2);
            EXPECT_NEAR(result.x, ex, 1e-8);
        }
        TEST_P(ParametrizedVectorSubtraction, subtractionEqY) {
            auto [x1, y1, x2, y2, ex, ey] = GetParam();
            Vector2D<double> result(x1, y1);
            result -= Vector2D<double>(x2, y2);
            EXPECT_NEAR(result.y, ey, 1e-8);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorSubtraction,
            ParametrizedVectorSubtraction,
            testing::Values(
                std::make_tuple(0.56875, 0.238781, 0.0, 0.230111, 0.56875, 0.00867),
                std::make_tuple(0.74312, 0.449134, 0.573213, 0.0, 0.169907, 0.449134),
                std::make_tuple(0.91231, 0.881231, 0.0, 0.0, 0.91231, 0.881231),
                std::make_tuple(-81.93113, 5.42812, 4.678912, 2.34501, -86.610042, 3.08311),
                std::make_tuple(-4.76192, -0.71621, -3.48791, 0.333321, -1.27401, -1.049531),
                std::make_tuple(7.199213, 5912.41412, -7.192310, -439.2812, 14.391523, 6351.69532)
            )
        );
        class ParametrizedVectorDotProduct : public fiveDoubleParametrization {};
        TEST_P(ParametrizedVectorDotProduct, dotProduct) {
            auto [x1, y1, x2, y2, expected] = GetParam();
            double result = Vector2D<double>(x1, y1) * Vector2D<double>(x2, y2);
            EXPECT_NEAR(result, expected, 1e-8);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorDotProduct,
            ParametrizedVectorDotProduct,
            testing::Values(
                std::make_tuple(57.8231, 0.7612, 0.991, 32.812, 82.2791865),
                std::make_tuple(0.0, 7.181231, 9.7612, 12.87131, 92.43185038),
                std::make_tuple(823.19841, 0.0, 1.8173, 1.857182, 1495.99847049),
                std::make_tuple(1.0, 0.0, 8.187831, 91.18763, 8.187831),
                std::make_tuple(0.0, 9.8749, 9071.2, 73.99, 730.643851),
                std::make_tuple(-45.8371, 4.9812, 104.89, 0.9721, -4803.01119448)
            )
        );

        class ParametrizedVectorScalarProduct : public fiveDoubleParametrization {};
        TEST_P(ParametrizedVectorScalarProduct, scalarTimesVectorX) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<double> result = s * Vector2D<double>(x, y);
            EXPECT_NEAR(result.x, ex, 1e-8);
        }
        TEST_P(ParametrizedVectorScalarProduct, scalarTimesVectorY) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<double> result = s * Vector2D<double>(x, y);
            EXPECT_NEAR(result.y, ey, 1e-8);
        }
        TEST_P(ParametrizedVectorScalarProduct, VectorTimesScalarX) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<double> result = Vector2D<double>(x, y) * s;
            EXPECT_NEAR(result.x, ex, 1e-8);
        }
        TEST_P(ParametrizedVectorScalarProduct, VectorTimesScalarY) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<double> result = Vector2D<double>(x, y) * s;
            EXPECT_NEAR(result.y, ey, 1e-8);
        }
        TEST_P(ParametrizedVectorScalarProduct, ScalarTimesEqualsX) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<double> result(x, y);
            result *= s;
            EXPECT_NEAR(result.x, ex, 1e-8);
        }
        TEST_P(ParametrizedVectorScalarProduct, ScalarTimesEqualsY) {
            auto [x, y, s, ex, ey] = GetParam();
            Vector2D<double> result(x, y);
            result *= s;
            EXPECT_NEAR(result.y, ey, 1e-8);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorScalarProduct, 
            ParametrizedVectorScalarProduct,
            testing::Values(
                std::make_tuple(0.0, 6.78129, 10.762, 0.0, 72.98024298),
                std::make_tuple(0.91731, 0.0, 4.56, 4.1829336, 0.0),
                std::make_tuple(9120.12431, -5.08712, 0.0, 0.0, 0.0),
                std::make_tuple(-0.8126741, 0.9666132, 1.0, -0.8126741, 0.9666132),
                std::make_tuple(0.771231, 0.332986, -1.0, -0.771231, -0.332986),
                std::make_tuple(-89.2341, 56.8134, -1.04, 92.803464, -59.085936)
            )
        );

        class ParametrizedVectorDivision : public fiveDoubleParametrization {};
        TEST_P(ParametrizedVectorDivision, divisionX) {
            auto [x1, y1, s, ex, ey] = GetParam();
            Vector2D<double> result = Vector2D<double>(x1, y1) / s;
            EXPECT_NEAR(result.x, ex, 1e-8);
        }
        TEST_P(ParametrizedVectorDivision, divisionY) {
            auto [x1, y1, s, ex, ey] = GetParam();
            Vector2D<double> result = Vector2D<double>(x1, y1) / s;
            EXPECT_NEAR(result.y, ey, 1e-8);
        }
        TEST_P(ParametrizedVectorDivision, divsionEqX) {
            auto [x1, y1, s, ex, ey] = GetParam();
            Vector2D<double> result(x1, y1);
            result /= s;
            EXPECT_NEAR(result.x, ex, 1e-8);
        }
        TEST_P(ParametrizedVectorDivision, divisionEqY) {
            auto [x1, y1, s, ex, ey] = GetParam();
            Vector2D<double> result(x1, y1);
            result /= s;
            EXPECT_NEAR(result.y, ey, 1e-8);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorDivision,
            ParametrizedVectorDivision,
            testing::Values(
                std::make_tuple(7.62, 4.8839, 1.056, 7.215909091, 4.624905303),
                std::make_tuple(0.6884, 0.73241, 2.0, 0.3442, 0.366205),
                std::make_tuple(52413.8712, -107.5891, 1.26, 41598.31047619, -85.3881746),
                std::make_tuple(0.0, 7.991241, 0.506, 0.0, 15.7929664),
                std::make_tuple(-1.03862, 1.07621, -12.9123, 0.080436483, -0.08334766),
                std::make_tuple(0.62978, 0.0, -1.08, -0.583129629, 0.0)
            )
        );

        class ParametrizedVectorEquality : public testing::TestWithParam<std::tuple<double, double, double, double, bool>> {};
        TEST_P(ParametrizedVectorEquality, equality) {
            auto [x1, y1, x2, y2, expected] = GetParam();
            bool result = Vector2D<double>(x1, y1) == Vector2D<double>(x2, y2);
            EXPECT_EQ(result, expected);
        }
        TEST_P(ParametrizedVectorEquality, inequality) {
            auto [x1, y1, x2, y2, expected] = GetParam();
            bool result = Vector2D<double>(x1, y1) != Vector2D<double>(x2, y2);
            EXPECT_EQ(result, !expected);
        }
        INSTANTIATE_TEST_SUITE_P(
            VectorEquality,
            ParametrizedVectorEquality,
            testing::Values(
                std::make_tuple(12.98671, 0.97123, 12.98671, 0.98123, false),
                std::make_tuple(12.812821, 8.09009, 12.812821, 8.09009, true),
                std::make_tuple(0.7819, 7.8181, 0.7820, 7.8181, false),
                std::make_tuple(-7.917813, 0.016721, 7.917813, 0.016721, false),
                std::make_tuple(-9071.998, 0.675, -9071.998, -0.675, false),
                std::make_tuple(18563.9093, -2086.7821, 18563.9093, -2086.7821, true)
            )
        );

        // need to test len, lensq, length_along, rotate, rotated, normalize still


    }
    namespace ConstructionConversionUtilityTests {
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
        TEST(Conversion, IntegralToFloatingX) {
            Vector2D<double> result = Vector2D<int>(33, 9);
            EXPECT_DOUBLE_EQ(result.x, 33.0);
        }
        TEST(Conversion, IntegralToFloatingY) {
            Vector2D<double> result = Vector2D<int>(28, 17);
            EXPECT_DOUBLE_EQ(result.y, 17);
        }
        TEST(Conversion, FloatingToIntegralX) {
            Vector2D<int> result = Vector2D<double>(7.98, -6.32);
            EXPECT_EQ(result.x, 7);
        }
        TEST(Conversion, FloatingToIntegralY) {
            Vector2D<int> result = Vector2D<double>(7.98, -6.32);
            EXPECT_EQ(result.y, -6);
        }
        TEST(ToString, FloatingToString) {
            std::string result = to_string(Vector2D<double>(7.8, -3.33));
            std::string expected("(7.800000, -3.330000)");
            EXPECT_EQ(result, expected);
        }
        TEST(ToString, IntegralToString) {
            std::string result = to_string(Vector2D<int>(-9, 8));
            std::string expected("(-9, 8)");
            EXPECT_EQ(result, expected);
        }
        TEST(ToString, CharToString) {
            std::string result = to_string(Vector2D<char>(13, -2));
            std::string expected("(13, -2)");
            EXPECT_EQ(result, expected);
        }
    }
}