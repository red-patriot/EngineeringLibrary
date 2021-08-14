#pragma once

#include "CppUnitTest.h"

#include "EngineeringLibrary\Engineering.h" 

namespace Microsoft {
  namespace VisualStudio {
    namespace CppUnitTestFramework {

      /** Unspecialized eng::UnitBase conversion to std::wstring */
      template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
        int MD, int LD, int TD, int CD, int TeD, int AD, int LuD, class ...> 
        static std::wstring
        ToString(const eng::SIUnit<MN, LN, TN, CN, TeN, AN, LuN,
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

      /** Convert eng::UnitBase to std::wstring if all denominators are 1 */
      template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN>
      static std::wstring
        ToString(const eng::SIUnit<MN, LN, TN, CN, TeN, AN, LuN, 1, 1, 1, 1, 1, 1, 1>& t) {
        return ToString(t.value()) + L" <"
          + ToString(MN)  + L" "
          + ToString(LN) + L" "
          + ToString(TN) + L" "
          + ToString(CN) + L" "
          + ToString(TeN) + L" "
          + ToString(AN) + L" "
          + ToString(LuN) 
          + L">";
      }

      /** Convert eng::Acceleration to std::wstring */
      template<>
      static std::wstring
        ToString(const eng::Acceleration& t) {
        return ToString(t.value()) + L" m/s^2";
      }

      /** Convert eng::Area to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Area& t) {
        return ToString(t.value()) + L" m^2";
      }

      /** Convert eng::Damping to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Damping& t) {
        return ToString(t.value()) + L" Ns/m";
      }

      /** Convert eng::DViscosity to std::wstring */
      template<> static std::wstring
        ToString(const  eng::DViscosity& t) {
        return ToString(t.value()) + L" Ns/m2";
      }

      /** Convert eng::Energy to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Energy& t) {
        return ToString(t.value()) + L" J";
      }

      /** Convert eng::Force to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Force& t) {
        return ToString(t.value()) + L" N";
      }

      /** Convert eng::Frequency to std::wstring */
      template<> static std::wstring
        ToString(const  eng::SIUnit<0, 0, -1, 0, 0, 0, 0>& t) {
        return ToString(t.value()) + L" Hz";
      }

      /** Convert eng::KViscosity to std::wstring */
      template<> 
      static std::wstring
        ToString(const  eng::KViscosity& t) {
        return ToString(t.value()) + L" m2/s";
      }

      /** Convert eng::Length to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Length& t) {
        return ToString(t.value()) + L" m";
      }
      
      /** Convert eng::Mass to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Mass& t) {
        return ToString(t.value()) + L" kg";
      }

      /** Convert eng::Pressure to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Pressure& t) {
        return ToString(t.value()) + L" Pa";
      }

      /** Convert eng::SecondMomentOfArea to std::wstring */
      template<> static std::wstring
        ToString(const  eng::SecondMomentOfArea& t) {
        return ToString(t.value()) + L" m^4";
      }

      /** Convert eng::Stiffness to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Stiffness& t) {
        return ToString(t.value()) + L" N/m";
      }

      /** Convert eng::Temperature to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Temperature& t) {
        return ToString(t.value()) + L" K";
      }

      /** Convert eng::Time to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Time& t) {
        return ToString(t.value()) + L" sec";
      }

      /** Convert eng::Velocity to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Velocity& t) {
        return ToString(t.value()) + L" m/s";
      }

      /** Convert eng::Volume to std::wstring */
      template<> static std::wstring
        ToString(const  eng::Volume& t) {
        return ToString(t.value()) + L" m^3";
      }
    };  // namespace CppUnitTestFramework
  };  // namespace VisualStudio
};  // namespace Microsoft
