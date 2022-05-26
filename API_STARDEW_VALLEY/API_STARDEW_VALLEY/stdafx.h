// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
#include <list>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>// 플레이어 좌표검사용.

extern float g_fSound;
extern HWND g_hWnd;
extern int g_iDay;
extern int g_iMoney;

using namespace std;

// 라이브러리 : 바이너리로 번역(컴파일)된 함수들을 모아놓은 파일, 코드 재사용을 위한 초창기 방법 중 하나이며, 다른 프로그램에서 사용할 수 있도록 운영체제나 소프트웨어 개발자의 의해 제공
// 라이브러리의 대다수 함수들은 함수의 정의 및 선언들을 필요로 하기 때문에 링크 되기 전 전처리기에 의해 해당 헤더파일을 원스 프로그램에 포함시켜야 한다.
// 라이브러리들은 사용자의 프로그램과 링크되어 실행이 가능한 완전한 프로그램을 이루게 된다.

#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")

#include <io.h>

#include "fmod.h" //어디 있음 이거
#include "fmod.hpp"
#pragma comment(lib, "fmodex_vc.lib")

//선생님 파일 가져옴?무슨 파일 가져와야되는지 모름
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif