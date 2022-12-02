
// Test_WebView2Ctrl_VS2022Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Test_webView2Ctrl_vs2022.h"
#include "Test_WebView2Ctrl_VS2022Dlg.h"
#include "afxdialogex.h"

#include "../../Common/Functions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestwebView2CtrlVS2022Dlg 대화 상자



CTestwebView2CtrlVS2022Dlg::CTestwebView2CtrlVS2022Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_WEBVIEW2CTRL_VS2022_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestwebView2CtrlVS2022Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WEB, m_web);
}

BEGIN_MESSAGE_MAP(CTestwebView2CtrlVS2022Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDOK, &CTestwebView2CtrlVS2022Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTestwebView2CtrlVS2022Dlg::OnBnClickedCancel)
	ON_WM_DROPFILES()
	ON_WM_WINDOWPOSCHANGED()
	ON_BN_CLICKED(IDC_BUTTON_SEND_MESSAGE, &CTestwebView2CtrlVS2022Dlg::OnBnClickedButtonSendMessage)
END_MESSAGE_MAP()


// CTestwebView2CtrlVS2022Dlg 메시지 처리기

BOOL CTestwebView2CtrlVS2022Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	RestoreWindowPosition(&theApp, this);

	m_web.set_permission_request_mode(1);
	//m_web.allow_external_drop();
	//AfxMessageBox(m_web.get_webview2_runtime_version());
	m_web.navigate(_T("C:\\scpark\\1.Projects_C++\\NH\\bin\\VCC\\htmls\\UID_MM_CM_01_008.html"));

	//AfxMessageBox(m_web.get_default_download_path());
	CTime t = CTime(1970, 0, 0, 0, 0, 0);
	
	//	CTime::GetCurrentTime();
	if (t == CTime(0, 0, 0, 0, 0, 0))
	{
		;
	}
	//else if (t > CTimeSpan(0,0,0,0))
	{
		;
	}
	DragAcceptFiles();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTestwebView2CtrlVS2022Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTestwebView2CtrlVS2022Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTestwebView2CtrlVS2022Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestwebView2CtrlVS2022Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (!m_hWnd || !m_web || !m_web.m_hWnd)
		return;

	CRect rc;
	GetClientRect(rc);

	rc.top += 40;
	m_web.MoveWindow(rc);
}


void CTestwebView2CtrlVS2022Dlg::OnBnClickedOk()
{
	//AfxMessageBox(m_web.get_default_download_path());
	//m_web.navigate(_T("https://www.learningcontainer.com/wp-content/uploads/2020/05/sample-avi-file.avi"));
}

void CTestwebView2CtrlVS2022Dlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CTestwebView2CtrlVS2022Dlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	TCHAR sfile[MAX_PATH];
	CString file;

	DragQueryFile(hDropInfo, 0, sfile, MAX_PATH);

	m_web.navigate(sfile);

	CDialogEx::OnDropFiles(hDropInfo);
}


void CTestwebView2CtrlVS2022Dlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	SaveWindowPosition(&theApp, this);
}


void CTestwebView2CtrlVS2022Dlg::OnBnClickedButtonSendMessage()
{
	m_web.GetWebView()->ExecuteScript(L"MessageReceived('Ayush sent a message from C++ application')",
		Microsoft::WRL::Callback<ICoreWebView2ExecuteScriptCompletedHandler>(this, &CTestwebView2CtrlVS2022Dlg::ExecuteScriptResponse).Get());
}


HRESULT CTestwebView2CtrlVS2022Dlg::ExecuteScriptResponse(HRESULT errorCode, LPCWSTR result)
{
	AfxMessageBox(_T("C++ Application Popup : Message Sent Successfully"));
	return S_OK;
}

