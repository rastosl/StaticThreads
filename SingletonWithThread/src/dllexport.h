#if defined (WIN32)// && defined (BUILD_SHARED_LIBS)
#if defined (_MSC_VER)
#pragma warning(disable: 4251)
#endif
#if defined(SingletonWithThread_EXPORTS)
#define  DLLEXPORT __declspec(dllexport)
#else
#define  DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT
#endif
