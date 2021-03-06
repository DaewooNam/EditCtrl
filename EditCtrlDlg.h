
// EditCtrlDlg.h: 헤더 파일
//

#pragma once


// CEditCtrlDlg 대화 상자
class CEditCtrlDlg : public CDialogEx
{
// 생성입니다.
public:
	CEditCtrlDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITCTRL_DIALOG };
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
	afx_msg void OnEnChangeEditGeneral();
	
	CString m_strEditGeneral;
	CString m_strEditPsw;
	CString m_strEditReadonly;
	
	CEdit   m_EditCtrl; // button 속성을 변경 시켜 줄 수 있음




	afx_msg void OnBnClickedBtnEditchek();
	afx_msg void OnEnChangeEditReadonly();
	afx_msg void OnEnChangeEditPass();
	afx_msg void OnEnSetfocusEditPass();
	afx_msg void OnEnUpdateEditPass();
	afx_msg void OnEnKillfocusEditPass();
	afx_msg void OnBnClickedBtnOn();
	afx_msg void OnBnClickedBtnOff();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
