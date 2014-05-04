/**
 * @file DoubleContinuePanel.h
 * @brief .
 *
 */

#ifndef DOUBLECONTINUEPANEL_H_
#define DOUBLECONTINUEPANEL_H_

#include <wx/wx.h>

enum {
	CID_CONTINUE_TC_1 = 2001,
	CID_CONTINUE_TC_2,
	CID_CONTINUE_TC_3,
	CID_CONTINUE_TC_4,
	CID_CONTINUE_TC_5,
	CID_CONTINUE_TC_6,
	CID_CONTINUE_TC_7,
	CID_CONTINUE_TC_8,
	CID_CONTINUE_TC_9,
	CID_CONTINUE_TC_10,
	CID_CONTINUE_TC_11,
	CID_CONTINUE_TC_12,
	CID_CONTINUE_TC_13,
	CID_CONTINUE_TC_14,
	CID_CONTINUE_TC_15,
};

class DoubleContinuePanel :  public wxPanel{
public:
	wxPanel* m_parent;/**< Parent Panel */
	wxStaticBox* m_sb;/**< Static Box */
	wxStaticBoxSizer* m_sz;/**< Static Box Sizer */
	wxGridSizer* m_gridSz;

	wxStaticText* m_doubleContinueText[15];/**< Double up game continue setting text */
	wxTextCtrl* m_doubleContinueTc[15];/**< Double up game continue setting text control */

	/**
	 * @brief Constructor.
	 * @param parent Parent Panel.
	 */
	DoubleContinuePanel(wxPanel* parent);
};


#endif /* DOUBLECONTINUEPANEL_H_ */
