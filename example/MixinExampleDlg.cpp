
// MixinExampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MixinExample.h"
#include "MixinExampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMixinExampleDlg dialog



CMixinExampleDlg::CMixinExampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MIXINEXAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMixinExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO1, m_colored_combobox);
	DDX_Control(pDX, IDC_COMBO2, m_lowercase_combobox);
	DDX_Control(pDX, IDC_COMBO3, m_colored_lowercase_combobox);
}

BEGIN_MESSAGE_MAP(CMixinExampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMixinExampleDlg message handlers

BOOL CMixinExampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_colored_combobox.AddString(_T("Apple"));
	m_colored_combobox.AddString(_T("Banana"));
	m_colored_combobox.AddString(_T("Passion-Fruit"));
	m_colored_combobox.AddString(_T("Strawberry"));
	m_colored_combobox.set_fg_color(RGB(50, 50, 255));
	m_colored_combobox.set_bg_color(RGB(0, 255, 30));
	m_colored_combobox.SetCurSel(0);

	m_lowercase_combobox.AddString(_T("Apple"));
	m_lowercase_combobox.AddString(_T("Banana"));
	m_lowercase_combobox.AddString(_T("Passion-Fruit"));
	m_lowercase_combobox.AddString(_T("Strawberry"));
	m_lowercase_combobox.SetCurSel(0);

	m_colored_lowercase_combobox.AddString(_T("Apple"));
	m_colored_lowercase_combobox.AddString(_T("Banana"));
	m_colored_lowercase_combobox.AddString(_T("Passion-Fruit"));
	m_colored_lowercase_combobox.AddString(_T("Strawberry"));
	m_colored_lowercase_combobox.set_fg_color(RGB(50, 50, 255));
	m_colored_lowercase_combobox.set_bg_color(RGB(0, 255, 30));
	m_colored_lowercase_combobox.SetCurSel(0);


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMixinExampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMixinExampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMixinExampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

