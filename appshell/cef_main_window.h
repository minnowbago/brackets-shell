#pragma once
/*
 * Copyright (c) 2013 Adobe Systems Incorporated. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#include "cef_window.h"

class cef_main_window : public cef_window
{
public:
    cef_main_window(void);
    virtual ~cef_main_window(void);

	static HWND SafeGetCefBrowserHwnd();
    static HWND FindFirstTopLevelInstance();

	BOOL Create();
	
	void ShowHelp();
	void ShowAbout();

    static LPCWSTR GetBracketsWindowTitleText();

    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

protected:
	void SaveWindowRect();
	void RestoreWindowRect(int& left, int& top, int& width, int& height, int& showCmd);
	void RestoreWindowPlacement(int showCmd);

	BOOL HandleEraseBackground();
	BOOL HandleCreate();
	BOOL HandleSetFocus(HWND hLosingFocus);
	BOOL HandleDestroy();
	BOOL HandleClose();
	BOOL HandleSize(BOOL bMinimize);
	BOOL HandleInitMenuPopup(HMENU hMenuPopup);
	BOOL HandleCommand(UINT commandId);
	BOOL HandleExitCommand();
    BOOL HandlePaint();
    BOOL HandleGetMinMaxInfo(LPMINMAXINFO mmi);
    BOOL HandleCopyData(HWND, PCOPYDATASTRUCT lpCopyData);


	virtual void PostNcDestory();
    virtual void GetCefBrowserRect(RECT& rect);

    static BOOL CALLBACK FindSuitableBracketsInstanceHelper(HWND hwnd, LPARAM lParam);

private:
	static ATOM RegisterWndClass();
};

#define ID_WM_COPYDATA_SENDOPENFILECOMMAND	(WM_USER+1001)
