
// MixinExampleDlg.h : header file
//

#pragma once

#include "colored_control.h"
#include "lowercase_combobox.h"


// CMixinExampleDlg dialog
class CMixinExampleDlg : public CDialogEx
{
// Construction
public:
	CMixinExampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MIXINEXAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	colored_control<CComboBox> m_colored_combobox;
	lowercase_combobox<CComboBox> m_lowercase_combobox;
	lowercase_combobox<colored_control<CComboBox>> m_colored_lowercase_combobox;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
