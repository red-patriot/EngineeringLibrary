#ifndef Engineering_Export_h_INCLUDED
#define Engineering_Export_h_INCLUDED

#ifdef ENGINEERINGLIBRARY_EXPORTS
#   define ENGINEERINGLIBRARY_API __declspec(dllexport)
#else
#   define ENGINEERINGLIBRARY_API __declspec(dllimport)
#endif

#endif
