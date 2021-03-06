
// EditCtrlDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "EditCtrl.h"
#include "EditCtrlDlg.h"
#include "afxdialogex.h"
#include "Resource.h"


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


// CEditCtrlDlg 대화 상자



CEditCtrlDlg::CEditCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDITCTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEditCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_General,m_strEditGeneral); //text 연결
	DDX_Text(pDX, IDC_EDIT_PASS, m_strEditPsw);
	DDX_Text(pDX, IDC_EDIT_READONLY, m_strEditReadonly);

	DDX_Control(pDX, IDC_EDIT_General, m_EditCtrl); // rectangle 값 변경



	//DDX_Text(pDX, IDC_EDIT_General, m_strEditGeneral);

}

BEGIN_MESSAGE_MAP(CEditCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_General, &CEditCtrlDlg::OnEnChangeEditGeneral)
	ON_BN_CLICKED(IDC_BTN_EDITCHEK, &CEditCtrlDlg::OnBnClickedBtnEditchek)
	ON_EN_CHANGE(IDC_EDIT_READONLY, &CEditCtrlDlg::OnEnChangeEditReadonly)
	ON_EN_CHANGE(IDC_EDIT_PASS, &CEditCtrlDlg::OnEnChangeEditPass)
	ON_EN_SETFOCUS(IDC_EDIT_PASS, &CEditCtrlDlg::OnEnSetfocusEditPass)
	ON_EN_UPDATE(IDC_EDIT_PASS, &CEditCtrlDlg::OnEnUpdateEditPass)
	ON_EN_KILLFOCUS(IDC_EDIT_PASS, &CEditCtrlDlg::OnEnKillfocusEditPass)
	ON_BN_CLICKED(IDC_BTN_ON, &CEditCtrlDlg::OnBnClickedBtnOn)
	ON_BN_CLICKED(IDC_BTN_OFF, &CEditCtrlDlg::OnBnClickedBtnOff)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CEditCtrlDlg 메시지 처리기

BOOL CEditCtrlDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CEditCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CEditCtrlDlg::OnPaint()
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
HCURSOR CEditCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEditCtrlDlg::OnEnChangeEditGeneral()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CEditCtrlDlg::OnBnClickedBtnEditchek()
{
	
	UpdateData(true); //값을 동기화 해줌 (버튼에 값을 변수에 넣어주기 위해 , 모든 값들이 동기화 )
		
	m_strEditReadonly = m_strEditPsw;
	


	m_strEditReadonly = m_strEditPsw;

	int nValue = atoi(m_strEditPsw.GetBuffer());



	/*

	AfxMessageBox(m_strEditGeneral);
	m_strEditGeneral = "";

	TRACE("m_strEditGeneral : %s\n",m_strEditGeneral.GetBuffer());
	*/
	UpdateData(false); // 변수 값을 button에 출력해줌


}


void CEditCtrlDlg::OnEnChangeEditReadonly()
{
	UpdateData(true);
	
	AfxMessageBox(m_strEditPsw);
}


void CEditCtrlDlg::OnEnChangeEditPass()
{
	UpdateData(true);
	
	
	
	m_strEditReadonly = m_strEditPsw;
	
	UpdateData(false);




}


void CEditCtrlDlg::OnEnSetfocusEditPass()
{
	TRACE("onEnUpdateEditPass()\n");
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CEditCtrlDlg::OnEnUpdateEditPass()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TRACE("onEnUpdateEditPass()\n");
}


void CEditCtrlDlg::OnEnKillfocusEditPass()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TRACE("onEnUpdateEditPass()\n");
}


void CEditCtrlDlg::OnBnClickedBtnOn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_EditCtrl.ShowWindow(SW_SHOW);
	//m_EditCtrl.EnableWindow(true);
	//m_EditCtrl.SetReadOnly(true);

	SetTimer(0, 1000, NULL); //1000 1초

}


void CEditCtrlDlg::OnBnClickedBtnOff()
{
	
	//m_EditCtrl.ShowWindow(SW_HIDE);
	//m_EditCtrl.EnableWindow(false);
	//m_EditCtrl.SetReadOnly(false);
	
	KillTimer(0);
}


void CEditCtrlDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	TRACE("OnTimer()\n");
	
	CDialogEx::OnTimer(nIDEvent);
}
