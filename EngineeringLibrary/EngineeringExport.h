#ifndef Engineering_Export_h_INCLUDED
#define Engineering_Export_h_INCLUDED

//! For a function to be used outside of this library, it must be declared with ENGINEERINGLIBRARY_API

#ifdef ENGINEERINGLIBRARY_EXPORTS
#   define ENGINEERINGLIBRARY_API __declspec(dllexport)
#else
#   define ENGINEERINGLIBRARY_API __declspec(dllimport)
#endif

#endif
