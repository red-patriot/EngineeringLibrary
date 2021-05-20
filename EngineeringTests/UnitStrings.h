#pragma once

#include "CppUnitTest.h"

#include "EngineeringLibrary\Engineering.h" 

namespace Microsoft {
  namespace VisualStudio {
    namespace CppUnitTestFramework {

      // Generic
      template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
        int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
        static std::wstring
        unitStr() {
        return L"<"
          + ToString(MN) + L"/" + ToString(MD) + L" "
          + ToString(LN) + L"/" + ToString(LD) + L" "
          + ToString(TN) + L"/" + ToString(TD) + L" "
          + ToString(CN) + L"/" + ToString(CD) + L" "
          + ToString(TeN) + L"/" + ToString(TeD) + L" "
          + ToString(AN) + L"/" + ToString(AD) + L" "
          + ToString(LuN) + L"/" + ToString(LuD)
          + L">";
      }

      // Acceleration
      template<>
      static std::wstring unitStr<0, 1, -2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"m/s^2";
      }

      // Area
      template<>
      static std::wstring unitStr<0, 2, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"m^2";
      }

      // Damping
      template<>
      static std::wstring unitStr<1, 0, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"Ns/m";
      }

      // DViscosity
      template<>
      static std::wstring unitStr<1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"Ns/m^2";
      }

      // Energy
      template<>
      static std::wstring unitStr<1, 2, -2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"J";
      }

      // Force
      template<>
      static std::wstring unitStr<1, 1, -2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"N";
      }

      // Frequency
      template<>
      static std::wstring unitStr<0, 0, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"Hz";
      }

      // KViscosity
      template<>
      static std::wstring unitStr<0, 2, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"m2/s";
      }

      // Length
      template<>
      static std::wstring unitStr<0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"m";
      }

      // Mass
      template<>
      static std::wstring unitStr<1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"kg";
      }

      // Pressure
      template<>
      static std::wstring unitStr<1, -1, -2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"Pa";
      }

      // SecondMomentOfArea
      template<>
      static std::wstring unitStr<0, 4, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"m^4";
      }

      // Stiffness
      template<>
      static std::wstring unitStr<1, 0, -2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"N/m";
      }

      // Temperature
      template<>
      static std::wstring unitStr<0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"K";
      }

      // Time
      template<>
      static std::wstring unitStr<0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"s";
      }

      // Velocity
      template<>
      static std::wstring unitStr<0, 1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"m/s";
      }

      // Volume
      template<>
      static std::wstring unitStr<0, 3, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>() {
        return L"m^3";
      }

    };
  };
};
