#ifndef lipGlobalsH
#define lipGlobalsH
#include <Types.hpp>
//enum TImageType  {titRGB24 = 0, titGray8, titFloat3};
struct TExportImage
	{
	char *exptype;
	int width;
	int height;
	int channels;
	void *imageBuff;
	int imageStride;
	void *alphaBuff;   // not used for now
	int alphaStride;   // not used for now
	};
struct TExportPoint
	{
	int x;
    int y;
    };
struct TExportContour
	{
	int hierarchy[4];		// for simplified output (contour iteration)
	unsigned int numPts;
	TExportPoint *points;
    };
typedef void (__stdcall *TLuaProgress)(int, int);
typedef void (__stdcall *TLuaString)(const char *);
typedef bool (__stdcall *TLuaDoubleString)(const char *, const char *);
typedef bool (__stdcall *TLuaExportImage)(TExportImage *expImage, bool asIs, bool show);
typedef int  (__stdcall *TLuaHostDialog)(const char *, int type);   // 0 - info, 1 - dialog
typedef bool (__stdcall *TLuaExportRawData)(void *, int );
#endif
