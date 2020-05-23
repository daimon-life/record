## ddraw
#### 包含
* ddraw.dll
* ddrawex.dll
#### 目录
* C:\Windows\System32
* C:\Windows\SysWOW64
#### 脚本
```bash
# vs2013
pushd "%VS120COMNTOOLS%"..\..\VC && call vcvarsall.bat x86_amd64 && popd
dumpbin /exports ddraw.dll
```
#### 接口
##### ddraw.dll
* AcquireDDThreadLock
* CompleteCreateSysmemSurface
* D3DParseUnknownCommand
* DDGetAttachedSurfaceLcl
* DDInternalLock
* DDInternalUnlock
* DSoundHelp
* **DirectDrawCreate**
* DirectDrawCreateClipper
* **DirectDrawCreateEx**
* DirectDrawEnumerateA
* DirectDrawEnumerateExA
* DirectDrawEnumerateExW
* DirectDrawEnumerateW
* DllCanUnloadNow
* DllGetClassObject
* GetDDSurfaceLocal
* GetOLEThunkData
* GetSurfaceFromDC
* RegisterSpecialCase
* ReleaseDDThreadLock
* SetAppCompatData
##### ddrawex.dll
* 00002950 DllCanUnloadNow
* DllGetClassObject
* DllRegisterServer
* DllUnregisterServer

##### IDirectDraw7
（IDirectDraw IDirectDraw2 IDirectDraw4 IDirectDraw7）<br/>
IDirectDraw methods
* Compact
* **CreateClipper**
* CreatePalette
* **CreateSurface**
* DuplicateSurface
* EnumDisplayModes
* EnumSurfaces
* FlipToGDISurface
* **GetCaps**
* GetDisplayMode
* GetFourCCCodes
* GetGDISurface
* GetMonitorFrequency
* GetScanLine
* GetVerticalBlankStatus
* Initialize
* RestoreDisplayMode
* **SetCooperativeLevel
* SetDisplayMode
* WaitForVerticalBlank
<br/>v2 interface
* GetAvailableVidMem
<br/>V4 Interface
* GetSurfaceFromDC
* RestoreAllSurfaces
* TestCooperativeLevel
* GetDeviceIdentifier
* StartModeTest
* EvaluateMode

##### IDirectDrawSurface7
（IDirectDrawSurface IDirectDrawSurface2 IDirectDrawSurface3 IDirectDrawSurface4 IDirectDrawSurface7）

##### IDirectDrawClipper

#### 使用
##### 渲染流程
```cpp
// 
using DirectDrawCreateExFuncType = HRESULT(WINAPI *)(GUID FAR *, LPVOID *, REFIID, IUnknown FAR *);
DirectDrawCreateExFuncType DirectDrawCreateExFunc;
IDirectDraw7* pDDraw = NULL;
DDCAPS ddcaps1,ddcaps2;
IDirectDrawClipper* pCliper = NULL;
// 
MODULE hDDrawDll = LoadLibrary(L"ddraw.dll");
DirectDrawCreateExFunc = (FUN_DirectDrawCreateEx)GetProcAddress(hDrawDll, "DirectDrawCreateEx");
HRESULT hr = DirectDrawCreateExFunc(NULL, (VOID**)&pDDraw, IID_IDirectDraw7, NULL);
hr = pDDraw->GetCaps(&ddcaps1,&ddcaps2);
hr = pDDraw->SetCooperativeLevel(hWnd, DDSCL_NORMAL);
hr = pDDraw->CreateClipper(0, &pCliper, NULL);
pCliper->SetHWnd(0, hWnd);
// 
IDirectDrawSurface7* pDDawSurfaceFore;
DDSURFACEDESC2 ddsd = {sizeof(ddsd)};
  ddsd.dwFlags        = DDSD_CAPS;
  ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
pDDraw->CreateSurface(&ddsd, &pDDawSurfaceFore, NULL) == DD_OK;
pDDawSurfaceFore->SetClipper(pCliper);
/*
  IDirectDrawGammaControl *pDirectDrawGammaCtrl = NULL;
	pDDawSurfaceFore->QueryInterface(IID_IDirectDrawGammaControl,(void **)&pDirectDrawGammaCtrl);
	if (pDirectDrawGammaCtrl)
	{
		DDGAMMARAMP ddgrammaramp = {0};
		pDirectDrawGammaCtrl->GetGammaRamp(NULL,&ddgrammaramp);
  }
*/
/*
if(pDDawSurfaceFore->IsLost() == DDERR_SURFACELOST)
			pDDawSurfaceFore->Restore();
*/
// 1. YUV Surface
IDirectDrawSurface7* pDDawSurfaceBack; 
DDSURFACEDESC2 ddsd = {sizeof(ddsd)};		
  // DDSCAPS_VIDEOMEMORY
  ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_VIDEOMEMORY; 
  // DDSCAPS_SYSTEMMEMORY
  ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY; 
  ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT;
  ddsd.dwWidth = width;
  ddsd.dwHeight = height;
  ddsd.ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
  ddsd.ddpfPixelFormat.dwFlags  = DDPF_FOURCC | DDPF_YUV ;
  ddsd.ddpfPixelFormat.dwFourCC = MAKEFOURCC('Y','V','1','2'); // YUY2 UYVY
  ddsd.ddpfPixelFormat.dwYUVBitCount = 12; // 16 16
pDDraw->CreateSurface(&ddsd, &pDDawSurfaceBack, NULL) == DD_OK;
DDSURFACEDESC2 ddsd = {sizeof(ddsd)};
pDDawSurfaceBack->Lock(NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL) == DD_OK;
	LPBYTE lpSurf = (LPBYTE)ddsd.lpSurface;
	int	npitch = ddsd.lPitch > ddsd.dwWidth ? ddsd.dwWidth : ddsd.lPitch;
	for (int i = 0; i < height; i++)
	{
		memset(lpSurf, 16, npitch);	
		lpSurf += ddsd.lPitch;
	}
	for (int i = 0; i < height / 2; i++)
	{
		memset(lpSurf, 128, npitch / 2);
		lpSurf += ddsd.lPitch / 2;
	}
	for (int i=0; i < height/2; i++)
	{
		memset(lpSurf, 128, npitch / 2);	
		lpSurf += ddsd.lPitch/2;
	}
pDDawSurfaceBack->Unlock(NULL);

// 
pDDawSurfaceFore->Blt(&rcDst, pDDawSurfaceBack, NULL/*&rcSrc*/, DDBLT_WAIT, NULL);
```
##### 能力参考
```cpp
// DDCAPS.dwCaps & DDSCAPS_OVERLAY
DDSCAPS_OVERLAY
DDSCAPS_FLIP
DDSCAPS_OFFSCREENPLAIN
DDSCAPS_VIDEOMEMORY
DDSCAPS_SYSTEMMEMORY
DDCAPS_BLT
DDCAPS_BLTSTRETCH
DDCAPS_ALIGNBOUNDARYDEST
DDCAPS_ALIGNSIZEDEST
DDCAPS_ALIGNBOUNDARYSRC
DDCAPS_ALIGNSIZESRC
// DDSURFACEDESC2.DDPIXELFORMAT
{ MAKEFOURCC('Y','V','1','2'), 12 },
{ MAKEFOURCC('Y','U','Y','2'), 16 },
{ MAKEFOURCC('U','Y','V','Y'), 16 }
```
