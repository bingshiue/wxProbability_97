/**
 * SettingValuePanel.h
 *
 */

#ifndef SETTINGVALUEPANEL_H_
#define SETTINGVALUEPANEL_H_

#include <wx/wx.h>
#include <wx/combobox.h>
#include "game/gameSettingValue.h"

enum {
	CID_COMBOBOX_COINSET          = 901,
	CID_COMBOBOX_MAXBET           = 902,
	CID_COMBOBOX_MAINGAMEMAXWIN   = 903,
	CID_COMBOBOX_DOUBLEGAMEMAXWIN = 904,
	//CID_CHECKBOX_RUNDOUBLEGAME    = 905,
	//CID_CHECKBOX_RUNTODEAD        = 906,

};

class SettingValuePanel : public wxPanel {
public:
	wxPanel* m_parent;/**< Parent Panel */
	wxStaticBox* m_sb;
	wxStaticBoxSizer* m_sbz;
	wxGridSizer* m_gridSz;
	wxSizer* m_hsz1;
	wxSizer* m_hsz2;
	wxStaticText* m_maxKeyIn;
	wxTextCtrl* m_maxKeyIn_tc;
	wxStaticText* m_coinSet;
	wxComboBox* m_coinSetCB;
	wxStaticText* m_maxBet;
	wxComboBox* m_maxBetCB;
	wxStaticText* m_mainGameMaxWin;
	wxComboBox* m_mainGameMaxWinCB;
	wxStaticText* m_doubleGameMaxWin;
	wxComboBox* m_doubleGameMaxWinCB;
	//wxCheckBox* m_runDoubleGameChkBox;
	//wxCheckBox* m_runToDeadChkBox;


	/**
	 * @brief Constructor.
	 * @param parent Parent Panel
	 */
	SettingValuePanel(wxPanel* parent);
};

#endif /* SETTINGVALUEPANEL_H_ */
