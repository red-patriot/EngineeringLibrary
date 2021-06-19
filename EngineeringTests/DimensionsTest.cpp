#include "pch.h"
#include "CppUnitTest.h"

#include "UnitHelperFunctions.h"

#include "EngineeringLibrary\Units\UnitBase.h"
#include "EngineeringLibrary\Units\UnitTraits.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DimensionTests {
  TEST_CLASS(TestBaseFunctions) {
    TEST_METHOD(TestNthArg) {
      eng::UnitBase<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> u(0);

      Assert::AreEqual(1, eng::dimension_mgmt::nth_arg(u, 0));
      Assert::AreEqual(2, eng::dimension_mgmt::nth_arg(u, 1));
      Assert::AreEqual(3, eng::dimension_mgmt::nth_arg(u, 2));
      Assert::AreEqual(4, eng::dimension_mgmt::nth_arg(u, 3));
      Assert::AreEqual(5, eng::dimension_mgmt::nth_arg(u, 4));
      Assert::AreEqual(6, eng::dimension_mgmt::nth_arg(u, 5));
      Assert::AreEqual(7, eng::dimension_mgmt::nth_arg(u, 6));
      Assert::AreEqual(8, eng::dimension_mgmt::nth_arg(u, 7));
      Assert::AreEqual(9, eng::dimension_mgmt::nth_arg(u, 8));
      Assert::AreEqual(10, eng::dimension_mgmt::nth_arg(u, 9));
      Assert::AreEqual(11, eng::dimension_mgmt::nth_arg(u, 10));
      Assert::AreEqual(12, eng::dimension_mgmt::nth_arg(u, 11));
      Assert::AreEqual(13, eng::dimension_mgmt::nth_arg(u, 12));
      Assert::AreEqual(14, eng::dimension_mgmt::nth_arg(u, 13));
    };
    TEST_METHOD(TestSign) {
      Assert::AreEqual(-1, eng::dimension_mgmt::sign(-23));
      Assert::AreEqual(0, eng::dimension_mgmt::sign(0));
      Assert::AreEqual(1, eng::dimension_mgmt::sign(15));
    }
    TEST_METHOD(TestAbs) {
      Assert::AreEqual(12, eng::dimension_mgmt::abs(12));
      Assert::AreEqual(153, eng::dimension_mgmt::abs(-153));
      Assert::AreEqual(0, eng::dimension_mgmt::abs(0));
    }
  };

};  // DimensionTests
