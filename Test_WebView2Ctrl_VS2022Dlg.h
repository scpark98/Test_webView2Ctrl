﻿
// Test_WebView2Ctrl_VS2022Dlg.h: 헤더 파일
//

#pragma once

#include "../../Common/webView2Ctrl/WebView2Ctrl.h"

// CTestwebView2CtrlVS2022Dlg 대화 상자
class CTestwebView2CtrlVS2022Dlg : public CDialogEx
{
// 생성입니다.
public:
	CTestwebView2CtrlVS2022Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_WEBVIEW2CTRL_VS2022_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CWebView2Ctrl m_web;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnDropFiles(HDROP hDropInfo);
};
