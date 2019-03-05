# Lips
## Lua Image Processing System
Lua Image Processing System is mainly intended to be used with Embarcadero C++/Delphi on Windows platform.
It consists of: 
1. Lips engine - lipsEngine.dll (Embarcadero 10.1. Berlin C++ project).    
2. OpenCV wrapper - ocvWrapper.dll (VS2017 project).
3. Host application - proLips.exe (Embarcadero 10.1. Berlin C++ project).

### Lips engine - lipsEngine.dll
This is the core of the project. It's written in Embarcadero C++, but it can be easily modified for other compilers. It uses LuaJit  engine and ffi to pass images structure to Lua scripts. Also, it calls ocvWrapper.dll to apply a limited set of OpenCV filters from Lua script. To use this DLL from Delphi, DLL entries described in lipsEngineDLL.h must be converted to pas file, as well as structure and typedefs in lipsGlobals.h.

Lips engine currently supports RGB24 images and single channel 8-bit (grayscale) images. It can be TBimtap or any kind of image container with contiguous memory buffer. Only width, height, scanline alignement and pointer to image buffer are passed to Lips engine. Also, Lips engine supports RGB24 images with separated alpha channel, such as TIEBitmap image  (commercial product) available on www.imageen.com. Support for RGBA32 can be added as well, but currently it's not supported.

### OpenCV wrapper - ocvWrapper.dll
This dll is written in VS2017, because bcc compiler is not supported by OpenCV. It contains API calls for setting source/target image, for setting region of interesets and a limited set of OpenCV filters and image processing routines. As this dll is called from lipsEngine, after compiling and linking ocvWrapper.dll, import library must be created:

- implib -a ocvWrapper.lib ocvWrapper.dll (for 32-bit dll)
- mkexp -p ocvWrapper.a ocvWrapper.dll (for 64-bit dll)

Import libraries must be copied in OpenCV folder under lipsEngine directory.

### Host application - projLips.exe
Host (demo) application is written in Embarcadero C++ and it contains some commercial components. The source code can be modified to use standard components. From the source code, you can see how to use lipsEngine APIs and how to parse parameters requested from Lua script.

### Lua scripts
The first line in each Lua script intended for use with Lips engine must begin with `require("_prolog")` statement. The exception of this rule is if you want to debug your Lua script with let's say ZeroBrane Studio. In this case, the first statement must be `require("_debug")`. To call OpenCV APIs (ocvWrapper.dll), you must also include opencv script `require("_opencv")`.

When script is executed, Lua engine creates following global variables:

- SourceImage (shared image from Host application)
- TargetImage (shared image from Host application)
- SourceRoi (source image roi, initially set to complete image)
- TargetImage (target image roi, initially set to complete image)
- ExePath (path to host application directory)
- ExeWin32 (boolean - true = 32 bit dll, false = 64 bit dll)

All required Lua scripts as well as example scripts are also distributed with binary packages. 

