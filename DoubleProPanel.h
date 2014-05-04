/**
 * @file DoubleProPanel.h
 * @brief Double up Probability Setting Panel.
 *
 */

#ifndef DOUBLEPROPANEL_H_
#define DOUBLEPROPANEL_H_

#include <wx/wx.h>
#include "probability/probabilityDefine.h"

enum {
	CID_ITEM_VALUE_X0 = 1001,
	CID_ITEM_VALUE_X2,
	CID_ITEM_VALUE_X4,
	CID_ITEM_VALUE_X6,
};

class DoubleProPanel : public wxPanel {
public:
	wxPanel* m_parent;/**< Parent Panel */
	wxStaticBox* m_sb;/**< Static Box */
	wxStaticBoxSizer* m_sz;/**< Static Box Sizer */
	wxGridSizer* m_gridSz;

	wxStaticText* m_doubleOddsText[5];/**< Double up game odds setting text */
	wxTextCtrl* m_doubleOddsTc[5];/**< Double up game odds setting text control */

	/**
	 * @brief Constructor.
	 * @param parent Parent Panel
	 */
	DoubleProPanel(wxPanel* parent);
	/**
	 *
	 */
	void AfterEdit(wxCommandEvent& event);
};

#endif /* DOUBLEPROPANEL_H_ */
