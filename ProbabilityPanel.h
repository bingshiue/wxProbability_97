/**
 * ProbabilityPanel.h
 *
 */

#ifndef PROBABILITYPANEL_H_
#define PROBABILITYPANEL_H_

#include <wx/wx.h>

enum {
	CID_ITEM_VALUE_1 = 0,
	CID_ITEM_VALUE_2,
	CID_ITEM_VALUE_3,
	CID_ITEM_VALUE_4,
	CID_ITEM_VALUE_5,
	CID_ITEM_VALUE_6,
	CID_ITEM_VALUE_7,
	CID_ITEM_VALUE_8,
	CID_ITEM_VALUE_9,
	CID_ITEM_VALUE_10,
};

class ProbabilityPanel : public wxPanel{
public:
	wxPanel*  m_parent;/**< Parent Panel */
	wxSizer*  m_hbox;/**< Horizontal Sizer Box */
	wxStaticBox* m_sb;/**< Static Box */
    wxStaticBoxSizer* m_sz;/**< Static Box Sizer */

    wxGridSizer* m_gridSz;

    wxBitmap* m_bmap;
    wxStaticBitmap* m_sbmap;

    wxStaticText* m_slotItem_1_label;/**< Slot Item 1 Static Text */
    wxStaticText* m_slotItem_2_label;/**< Slot Item 2 Static Text */
    wxStaticText* m_slotItem_3_label;/**< Slot Item 3 Static Text */
    wxStaticText* m_slotItem_4_label;/**< Slot Item 4 Static Text */
    wxStaticText* m_slotItem_5_label;/**< Slot Item 5 Static Text */
    wxStaticText* m_slotItem_6_label;/**< Slot Item 6 Static Text */
    wxStaticText* m_slotItem_7_label;/**< Slot Item 7 Static Text */
    wxStaticText* m_slotItem_8_label;/**< Slot Item 8 Static Text */
    wxStaticText* m_slotItem_9_label;/**< Slot Item 9 Static Text */
    wxStaticText* m_slotItem_10_label;/**< Slot Item 10 Static Text */

    wxTextCtrl* m_slotItem_1_tc;/**< Slot Item 1 Text Control */
    wxTextCtrl* m_slotItem_2_tc;/**< Slot Item 2 Text Control */
    wxTextCtrl* m_slotItem_3_tc;/**< Slot Item 3 Text Control */
    wxTextCtrl* m_slotItem_4_tc;/**< Slot Item 4 Text Control */
    wxTextCtrl* m_slotItem_5_tc;/**< Slot Item 5 Text Control */
    wxTextCtrl* m_slotItem_6_tc;/**< Slot Item 6 Text Control */
    wxTextCtrl* m_slotItem_7_tc;/**< Slot Item 7 Text Control */
    wxTextCtrl* m_slotItem_8_tc;/**< Slot Item 8 Text Control */
    wxTextCtrl* m_slotItem_9_tc;/**< Slot Item 9 Text Control */
    wxTextCtrl* m_slotItem_10_tc;/**< Slot Item 10 Text Control */

    wxStaticText* m_totalValue_label;/**< Probability Total Value Text */
    wxTextCtrl* m_totalValue_tc;/**< Probability Total Value Control */

	/**
	 * @brief Constructor.
	 * @param parent Parent Panel
	 * @param title Title
	 */
	ProbabilityPanel(wxPanel* parent,wxString title);
	/**
	 *
	 */
	void AfterEdit(wxCommandEvent& event);

};


#endif /* PROBABILITYPANEL_H_ */
