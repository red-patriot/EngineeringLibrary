#ifndef Engineering_Export_h_INCLUDED
#define Engineering_Export_h_INCLUDED

/*****************************************************************//**
 * \file  EngineeringExport.h
 * \brief Defines the necessary macros for exporting from the engineering library.
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

//! For a function to be used outside of this library, it must be declared with ENGINEERINGLIBRARY_API

#ifdef ENGINEERINGLIBRARY_EXPORTS
#   define ENGINEERINGLIBRARY_API __declspec(dllexport)
#else
#   define ENGINEERINGLIBRARY_API __declspec(dllimport)
#endif

#endif
