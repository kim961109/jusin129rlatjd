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
#include <iostream>// �÷��̾� ��ǥ�˻��.

extern float g_fSound;
extern HWND g_hWnd;
extern int g_iDay;
extern int g_iMoney;

using namespace std;

// ���̺귯�� : ���̳ʸ��� ����(������)�� �Լ����� ��Ƴ��� ����, �ڵ� ������ ���� ��â�� ��� �� �ϳ��̸�, �ٸ� ���α׷����� ����� �� �ֵ��� �ü���� ����Ʈ���� �������� ���� ����
// ���̺귯���� ��ټ� �Լ����� �Լ��� ���� �� ������� �ʿ�� �ϱ� ������ ��ũ �Ǳ� �� ��ó���⿡ ���� �ش� ��������� ���� ���α׷��� ���Խ��Ѿ� �Ѵ�.
// ���̺귯������ ������� ���α׷��� ��ũ�Ǿ� ������ ������ ������ ���α׷��� �̷�� �ȴ�.

#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")

#include <io.h>

#include "fmod.h" //��� ���� �̰�
#include "fmod.hpp"
#pragma comment(lib, "fmodex_vc.lib")

//������ ���� ������?���� ���� �����;ߵǴ��� ��
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif