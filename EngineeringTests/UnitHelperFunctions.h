#pragma once

#include "CppUnitTest.h"

#include "EngineeringLibrary\Engineering.h" 

#include "UnitStrings.h"

namespace Microsoft {
  namespace VisualStudio {
    namespace CppUnitTestFramework {

      /** Unspecialized eng::UnitBase conversion to std::wstring */
      template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
        int MD, int LD, int TD, int CD, int TeD, int AD, int LuD> 
        static std::wstring
        ToString(const eng::UnitBase<MN, LN, TN, CN, TeN, AN, LuN,
                                     MD, LD, TD, CD, TeD, AD, LuD>& t) {
        return ToString(t.value()) + L" " 
          + unitStr<MN, LN, TN, CN, TeN, AN, LuN,
          MD, LD, TD, CD, TeD, AD, LuD>();
      }

      template<size_t N,
        int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
        int MD = 1, int LD = 1, int TD = 1, int CD = 1, int TeD = 1, int AD = 1, int LuD = 1>
        static std::wstring
        ToString(const eng::Vector<N, MN, LN, TN, CN, TeN, AN, LuN,
                 MD, LD, TD, CD, TeD, AD, LuD>& vec) {
        std::wstring ret = L"[";
        for (size_t i = 0; i < N; ++i) {
          ret += (i == 0 ? L"" : L", ") + ToString(vec[i].value());
        }
        ret += L"] " + unitStr<MN, LN, TN, CN, TeN, AN, LuN,
          MD, LD, TD, CD, TeD, AD, LuD>();
        
        return ret;
      }

    };  // namespace CppUnitTestFramework
  };  // namespace VisualStudio
};  // namespace Microsoft
