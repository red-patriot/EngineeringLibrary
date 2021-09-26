#include "pch.h"
#include "CppUnitTest.h"

#include "UnitHelperFunctions.h"
#include "EngineeringLibrary/Engineering.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
  TEST_CLASS(TestsSIUnit){
  public:
    TEST_METHOD(TestMultiply1){
      eng::SIUnit<1, 1, 1, 1, 1, 1, 1> a(5.0);
      eng::SIUnit<1, 2, 1, 1, 1, 1, 1> b(6.0);
      Assert::AreEqual(eng::SIUnit<2, 3, 2, 2, 2, 2, 2>(30.0).value(), (a * b).value());
    } 
    TEST_METHOD(TestMultiply2) {
      eng::SIUnit<1, 1, 1, 1, 1, 1, 1> a(6.0);
      eng::SIUnit<1, 2, 1, 1, 1, 1, 1> b(5.0);
      Assert::AreEqual(eng::SIUnit<0, -1, 0, 0, 0, 0, 0>(1.20).value(), (a / b).value());
    }
    TEST_METHOD(TestMultiply3) {
      eng::SIUnit<1, 1, 1, 1, 1, 1, 1> a(1.0);
      eng::SIUnit<-1, -1, -1, -1, -1, -1, -1> b(5.0);
      Assert::AreEqual(5.0, a * b);
    }
    TEST_METHOD(TestMultiply4) {
      eng::SIUnit<1, 0, 0, 0, 1, 1, 1> a(1.0);
      eng::SIUnit<-1, 0, 0, 0, -1, -1, -1> b(5.0);
      Assert::AreEqual(5.0, a * b);
    }
    TEST_METHOD(TestDivide1) {
      eng::SIUnit<1, 1, 1, 1, 1, 1, 1> a(2.5);
      eng::SIUnit<1, 1, 1, 1, 1, 1, 1> b(5.0);
      Assert::AreEqual(2.0, b / a);
    }
    TEST_METHOD(TestAbs) {
      eng::SIUnit<0, 1, 2, 3, 4, 5, 6> a(2.42);
      eng::SIUnit<0, 1, 2, 3, 6, 0, 6> b(-6.4673);
      eng::SIUnit<0, 1, 2, 3, 4, 3, 0> c(0.0);

      Assert::AreEqual(a, eng::abs(a));
      Assert::AreEqual(-b, eng::abs(b));
      Assert::AreEqual(c, eng::abs(c));
      Assert::AreEqual(-c, eng::abs(c));
    }
    TEST_METHOD(TestSqrt) {
      eng::SIUnit<4, 8, 2, 4, 1, 0, 5> a(4);
      eng::SIUnit<2, 4, 1, 2, 1, 0, 5, 1, 1, 1, 1, 2, 1, 2> sqrta(2);

      Assert::AreEqual(sqrta, eng::sqrt(a));
    }
    TEST_METHOD(TestAbs2) {
      eng::SIUnit<0, 1, 2, 3, 4, 5, 6> a(2.42);
      eng::SIUnit<0, 1, 2, 3, 6, 0, 6> b(-6.4);
      eng::SIUnit<0, 1, 2, 3, 4, 3, 0> c(0.0);

      eng::SIUnit<0, 2, 4, 6, 8, 10, 12> abs2a(5.8564);
      eng::SIUnit<0, 2, 4, 6, 12, 0, 12> abs2b(40.96);
      eng::SIUnit<0, 2, 4, 6, 8, 6, 0> abs2c(0.0);

      Assert::AreEqual(abs2a, eng::abs2(a));
      Assert::AreEqual(abs2b, eng::abs2(b));
      Assert::AreEqual(abs2c, eng::abs2(c));
    }
    TEST_METHOD(TestConjugate) {
      eng::SIUnit<1, 2, 3, 4, 5, 6, 7> a(3.5);
      
      Assert::AreEqual(decltype(a)(3.5), eng::conj(a));
    }
  };
};  // nsmaspace UnitTests
