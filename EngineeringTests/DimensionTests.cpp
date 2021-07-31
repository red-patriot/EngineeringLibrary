#include "pch.h"

#include "CppUnitTest.h"
#include "EngineeringLibrary/Dimensions/SIDimension.h"
#include "UnitHelperFunctions.h"

#include <type_traits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DimensionalTests {
  TEST_CLASS(TestSIDimensions) {
    TEST_METHOD(TestAddition) {
      eng::SIDimension<1, 0, 0, 0, 0, 0, 0> a;
      eng::SIDimension<1, 0, 0, 0, 0, 0, 0> b;
      eng::SIDimension<0, 1, 0, 0, 0, 0, 0> c;
      Assert::IsTrue(std::is_same_v<eng::SIDimension<1, 0, 0, 0, 0, 0, 0>,
                                    eng::addition_t<decltype(a), decltype(b)>>);
      Assert::IsFalse(std::is_same_v<eng::SIDimension<1, 0, 0, 0, 0, 0, 0>,
                                     eng::addition_t<decltype(a), decltype(c)>>);
    }
    TEST_METHOD(TestMultiplication) {
      eng::SIDimension<1, 0, 0, 0, 0, 0, 0> a;
      eng::SIDimension<1, 0, 0, 0, 0, 0, 0> b;
      eng::SIDimension<0, 1, 0, 0, 0, 0, 0> c;
      Assert::IsTrue(std::is_same_v<eng::SIDimension<2, 0, 0, 0, 0, 0, 0>,
                                    eng::multiplication_t<decltype(a), decltype(b)>>);
      Assert::IsTrue(std::is_same_v<eng::SIDimension<1, 1, 0, 0, 0, 0, 0>,
                                    eng::multiplication_t<decltype(a), decltype(c)>>);
    }
    TEST_METHOD(TestDivision) {
      eng::SIDimension<1, 2, 1, 0, 0, 0, 0> a;
      eng::SIDimension<1, 0, 0, 0, 0, 0, 0> b;
      eng::SIDimension<0, 1, 0, 0, 0, 0, 0> c;
      Assert::IsTrue(std::is_same_v<eng::SIDimension<0, 2, 1, 0, 0, 0, 0>,
                                    eng::division_t<decltype(a), decltype(b)>>);
      Assert::IsTrue(std::is_same_v<eng::SIDimension<1, 1, 1, 0, 0, 0, 0>,
                                    eng::division_t<decltype(a), decltype(c)>>);
    }
  };
};  // namespace UnitTests
