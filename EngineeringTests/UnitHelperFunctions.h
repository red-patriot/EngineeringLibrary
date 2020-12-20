#pragma once

#include "CppUnitTest.h"

#include "EngineeringLibrary\Engineering.h" 

namespace Microsoft {
  namespace VisualStudio {
    namespace CppUnitTestFramework {
      template<> static std::wstring
        ToString<eng::Acceleration>(const  eng::Acceleration& t) {
        return ToString(t.value()) + L" m/s^2";
      }

      template<> static std::wstring
        ToString<eng::Angle>(const  eng::Angle& t) {
        return ToString(t.value()) + L" rad";
      }

      template<> static std::wstring
        ToString<eng::Area>(const  eng::Area& t) {
        return ToString(t.value()) + L" m^2";
      }

      template<> static std::wstring
        ToString<eng::Damping>(const  eng::Damping& t) {
        return ToString(t.value()) + L" Ns/m";
      }

      template<> static std::wstring
        ToString<eng::Energy>(const  eng::Energy& t) {
        return ToString(t.value()) + L" J";
      }

      template<> static std::wstring
        ToString<eng::Force>(const  eng::Force& t) {
        return ToString(t.value()) + L" N";
      }

      template<> static std::wstring
        ToString<eng::Frequency>(const  eng::Frequency& t) {
        return ToString(t.value()) + L" Hz";
      }

      template<> static std::wstring
        ToString<eng::Length>(const  eng::Length& t) {
        return ToString(t.value()) + L" m";
      }

      template<> static std::wstring
        ToString<eng::Mass>(const  eng::Mass& t) {
        return ToString(t.value()) + L" kg";
      }

      template<> static std::wstring
        ToString<eng::SecondMomentOfArea>(const  eng::SecondMomentOfArea& t) {
        return ToString(t.value()) + L" m^4";
      }

      template<> static std::wstring
        ToString<eng::Pressure>(const  eng::Pressure& t) {
        return ToString(t.value()) + L" Pa";
      }

      template<> static std::wstring
        ToString<eng::Stiffness>(const  eng::Stiffness& t) {
        return ToString(t.value()) + L" N/m";
      }

      template<> static std::wstring
        ToString<eng::Time>(const  eng::Time& t) {
        return ToString(t.value()) + L" sec";
      }

      template<> static std::wstring
        ToString<eng::Velocity>(const  eng::Velocity& t) {
        return ToString(t.value()) + L" m/s";
      }

      template<> static std::wstring
        ToString<eng::Volume>(const  eng::Volume& t) {
        return ToString(t.value()) + L" m^3";
      }

      template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
        int MD=1, int LD=1, int TD=1, int CD=1, int TeD=1, int AD=1, int LuD=1> 
        static std::wstring
        ToString(const eng::UnitBase<MN, LN, TN, CN, TeN, AN, LuN,
                                     MD, LD, TD, CD, TeD, AD, LuD>& t) {
        return ToString(t.value()) + L" <"
          + ToString(MN) + L"/" + ToString(MD) + L" "
          + ToString(LN) + L"/" + ToString(LD) + L" "
          + ToString(TN) + L"/" + ToString(TD) + L" "
          + ToString(CN) + L"/" + ToString(CD) + L" "
          + ToString(TeN) + L"/" + ToString(TeD) + L" "
          + ToString(AN) + L"/" + ToString(AD) + L" "
          + ToString(LuN) + L"/" + ToString(LuD)
          + L">";
      }
    };
  };
};
