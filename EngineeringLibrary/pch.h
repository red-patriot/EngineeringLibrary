// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef EngineeringLibrary_PCH_H
#define EngineeringLibrary_PCH_H

#include "framework.h"

// Add all Unit classes that have been tested

// Time headers
#include "Units/Time.h"
#include "Units/Frequency.h"

// Mass header
#include "Units/Mass.h"

// Geometry headers
#include "Units/Angle.h"
#include "Units/Length.h"
#include "Units/Area.h"

#include "Units/MomentOfArea.h"

// Energy headers
#include "Units/Energy.h"

// Force headers
#include "Units/Force.h"
#include "Units/Torque.h"
#include "Units/Stiffness.h"
#include "Units/Damping.h"
#include "Units/Pressure.h"

// Movement headers
#include "Units/Velocity.h"
#include "Units/Acceleration.h"

// Temperature header
#include "Units/Temperature.h"

#endif //PCH_H
