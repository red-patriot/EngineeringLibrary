#pragma once

#include "CppUnitTest.h"

#include "EngineeringLibrary\Engineering.h"

#include "UnitHelperFunctions.h"

namespace Microsoft {
  namespace VisualStudio {
    namespace CppUnitTestFramework {
      template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
        int MD = 1, int LD = 1, int TD = 1, int CD = 1, int TeD = 1, int AD = 1, int LuD = 1>
        static std::wstring
        ToString(const eng::Vector<MN, LN, TN, CN, TeN, AN, LuN,
                 MD, LD, TD, CD, TeD, AD, LuD>& t) {
        return L"[" + ToString(t.x().value()) + L", "
          + ToString(t.y().value()) + L", "
          + ToString(t.z().value()) + L"]"
          + L" <" 
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
