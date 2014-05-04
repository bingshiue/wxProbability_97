/**
 * @file DRunTimeSettingPanel.h
 * @brief Double game run time setting panel.
 *
 */

#ifndef DRUNTIMESETTINGPANEL_H_
#define DRUNTIMESETTINGPANEL_H_

#include <wx/wx.h>
#include <wx/combobox.h>

enum {
	CID_CHECKBOX_RUNDOUBLEGAME    = 701,
	CID_CHECKBOX_RUNTODEAD        = 702,
};

/**
 * @brief Double game run time setting panel.
 */
class DRunTimeSettingPanel : public wxPanel{
public:
	wxPanel* m_parent;/**< Parent Panel */
	wxStaticBox* m_sb;/**< Static Box */
	wxStaticBoxSizer* m_sz;/**< Static Box Sizer */
	wxGridSizer* m_gridSz;

	wxCheckBox* m_runDoubleGameChkBox;/**< Run double game check box */
	wxCheckBox* m_runToDeadChkBox;/**< Run to dead check box */

	/**
	 * @brief Constructor.
	 * @param parent Parent Panel
	 */
	DRunTimeSettingPanel(wxPanel* parent);

};


#endif /* DRUNTIMESETTINGPANEL_H_ */
