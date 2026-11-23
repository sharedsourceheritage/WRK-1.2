// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"

#ifdef _WIN32_WCE

BEGIN_MESSAGE_MAP(CSaveModifiedDlg, CDialog)
	ON_COMMAND(IDYES, OnYes)
	ON_COMMAND(IDNO, OnNo)
	ON_COMMAND(IDCANCEL, OnCancel)
	ON_COMMAND(ID_FILE_SAVE_AS, OnSaveAs)
END_MESSAGE_MAP()

BOOL CSaveModifiedDlg::OnInitDialog()
{
	SetDlgItemText(AFX_IDP_ASK_TO_SAVE, m_strPrompt);
	return CDialog::OnInitDialog();
}

void CSaveModifiedDlg::OnYes()
{
	EndDialog(IDYES); 
}

void CSaveModifiedDlg::OnNo()
{
	EndDialog(IDNO);
}

void CSaveModifiedDlg::OnCancel()
{
	EndDialog(IDCANCEL);
}

void CSaveModifiedDlg::OnSaveAs()
{
	EndDialog(ID_FILE_SAVE_AS);
}
#endif // _WIN32_WCE

