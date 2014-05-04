/**
 * mainFrame.h
 *
 */

#ifndef MAINFRAME_H_
#define MAINFRAME_H_

using namespace std;
#include <iostream>
#include <iomanip>
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/progdlg.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/datstrm.h>
#include <wx/textfile.h>
#include <wx/tokenzr.h>
#include "ProbabilityPanel.h"
#include "DoubleProPanel.h"
#include "DoubleContinuePanel.h"
#include "DRunTimeSettingPanel.h"
#include "KeyInOutPanel.h"
#include "SettingValuePanel.h"
#include "ResultPanel.h"
#include "game/gameLogicType.h"
#include "game/gameSettingValueType.h"
#include "icon.xpm"

enum {
	CID_RUN_BUTTON    = 101,
	CID_RESET_BUTTON  = 102,
};

enum {
	CID_SAVE_MENU     = 201,
	CID_LOAD_MENU     = 202,
	CID_ABOUT_MENU    = 203,
};

class MainFrame : public wxFrame {

public:
	wxNotebook* m_noteBook;/**< Note Book */
	wxPanel* m_parent;/**< Parent Panel */
	wxPanel* m_doubleUpPanel;/**< Double Up Game Panel */
	wxSizer* m_topLevelSizer;/**< Top Level Sizer */
	wxSizer* m_DoubleTopLevelSizer;/**< Double Top Level Sizer */
	wxSizer* m_hbox;/**< Horizontal Sizer */
	wxSizer* m_hbox_2;/**< Horizontal Sizer */
	wxSizer* m_hbox_3;/**< Horizontal Sizer */
	wxSizer* m_hbox_4;/**< Horizontal Sizer */
	wxSizer* m_hbox_5;/**< Horizontal Sizer */
	wxSizer* m_vbox_1;/**< Vertical Sizer 1 */
	wxSizer* m_vbox_2;/**< Vertical Sizer 2 */

	wxMenuBar* m_menubar;/**< Menu Bar */
	wxMenu* m_file;/**< Menu */
	wxMenu* m_about;/**< About */
	wxMenuItem* quit;/**< Menu Item */

	ProbabilityPanel* m_probabilityPanel_1;/**< Probability Setting Panel 1 */
	ProbabilityPanel* m_probabilityPanel_2;/**< Probability Setting Panel 2 */
	ProbabilityPanel* m_probabilityPanel_3;/**< Probability Setting Panel 2 */
	ProbabilityPanel* m_probabilityPanel_4;/**< Probability Setting Panel 2 */
	ProbabilityPanel* m_probabilityPanel_5;/**< Probability Setting Panel 2 */
	ProbabilityPanel* m_probabilityPanel_6;/**< Probability Setting Panel 2 */
	ProbabilityPanel* m_probabilityPanel_7;/**< Probability Setting Panel 2 */
	ProbabilityPanel* m_probabilityPanel_8;/**< Probability Setting Panel 2 */
	ProbabilityPanel* m_probabilityPanel_9;/**< Probability Setting Panel 2 */

	DoubleProPanel* m_doubleProPanel;/**< Double Up Odds Setting Panel */
	DoubleContinuePanel* m_doubleContinuePanel;/**< Double Up Continue Setting Panel */

	KeyInOutPanel* m_keyInOutPanel;/**< Key In/Out Setting Panel */
	SettingValuePanel* m_settingValuePanel;/**< Setting Value Panel */
	DRunTimeSettingPanel* m_dRunTimeSettingPanel;/**< Double game run time setting panel */
	ResultPanel* m_resultPanel;/**< Result Panel */

	//wxGauge* m_gauge;/**< Gauge */
	wxButton* m_runButton;/**< Run Button */
	wxButton* m_resetButton;/**< Reset Button */

	//Mersenne Twister
	MTRANDOM mtRandom;

	//System Setting Data
	SystemSettingData* systemSettingData;

	//Probability Setting Data
	ProbabilitySettingData* probabilitySettingData;

	//Bonus Setting Data
	BonusSettingData* bonusSettingData;

	//Connect Setting Data
	CONNECTSETTING* connectSetting;

	//Double game run time setting data
	DoubleGameRunTime* doubleRunTime;

	//Probability
	ProbabilityControl* probabilityControl;

	//Double game probability step setting
	DOUBLEPROSTEP* doubleProStep;

	//Double game continue setting
	DOUBLECONTINUE* doubleContinue;

	//Main game frame
	MainGameFrame* mf;

	//Credits
	GameCredits* gameCredits;

	//Game Recorder
	GameRec* rangeRec;
	GameRec* totalRec;

	//Double game Recorder
	DGAMEAWARDREC* dGameAwardRec;

	//
	bool m_needToReset;
	bool m_runOneTest;

	/**
	 * @brief Constructor.
	 * @param title Title of window.
	 */
	MainFrame(const wxString& title);
	/**
	 * @brief OnQuit.
	 * @param event wxCommandEvent
	 */
	void OnQuit(wxCommandEvent& event);
	/**
	 *
	 */
	void OnAbout(wxCommandEvent& event);
	/**
	 * @brief Save data.
	 * @param event wxCommandEvent
	 */
	void SaveFile(wxCommandEvent& event);
	/**
	 * @brief Save data content to file.
	 * @store wxTextOutputStream&
	 */
	void SaveFileContent(wxTextOutputStream& store);
	/**
	 * @brief Load file.
	 * @param event wxCommandEvent&
	 */
	void LoadFile(wxCommandEvent& event);
	/**
	 * @brief Load data from file.
	 * @param load wxTextInputStream
	 */
	void LoadFileContent(wxTextInputStream& load);
	/**
	 * @brief Load data from file(Alternative).
	 * @param filePath File path
	 */
	void LoadFileContentAlternative(wxString filePath);
	/**
	 *
	 */
	void AfterSelectCoinSet(wxCommandEvent& event);
	/**
	 *
	 */
	void AfterSelectMaxBet(wxCommandEvent& event);
	/**
	 *
	 */
	void AfterSelectMainGameMaxWin(wxCommandEvent& event);
	/**
	 *
	 */
	void AfterSelectDoubleGameMaxWin(wxCommandEvent& event);
	/**
	 *
	 */
	void AfterSelectRunDoubleGame(wxCommandEvent& event);
	/**
	 *
	 */
	void AfterSelectRunToDead(wxCommandEvent& event);
	/**
	 * @brief Run.
	 * @param event wxCommandEvent
	 */
	void Run(wxCommandEvent& event);
	/**
	 * @brief Reset.
	 * @param event wxCommandEvent
	 */
	void Reset(wxCommandEvent& event);
	/**
	 * @brief Deconstructor.
	 */
	virtual ~MainFrame();
	/**
	 *
	 */
	bool BetForMax(unsigned long* _bet,unsigned long* _credit,unsigned char _clearBetFirst);
	/**
	 *
	 */
	unsigned int ComputeWagerForLineAndSide(unsigned int wager);
	/**
	 *
	 */
	void setSlot1DefaultValue(void);
	/**
	 *
	 */
	void setSlot2DefaultValue(void);
	/**
	 *
	 */
	void setSlot3DefaultValue(void);
	/**
	 *
	 */
	void setSlot4DefaultValue(void);
	/**
	 *
	 */
	void setSlot5DefaultValue(void);
	/**
	 *
	 */
	void setSlot6DefaultValue(void);
	/**
	 *
	 */
	void setSlot7DefaultValue(void);
	/**
	 *
	 */
	void setSlot8DefaultValue(void);
	/**
	 *
	 */
	void setSlot9DefaultValue(void);
	/**
	 *
	 */
	int setSlot1ProbabilityStep(void);
	/**
	 *
	 */
	int setSlot2ProbabilityStep(void);
	/**
	 *
	 */
	int setSlot3ProbabilityStep(void);
	/**
	 *
	 */
	int setSlot4ProbabilityStep(void);
	/**
	 *
	 */
	int setSlot5ProbabilityStep(void);
	/**
	 *
	 */
	int setSlot6ProbabilityStep(void);
	/**
	 *
	 */
	int setSlot7ProbabilityStep(void);
	/**
	 *
	 */
	int setSlot8ProbabilityStep(void);
	/**
	 *
	 */
	int setSlot9ProbabilityStep(void);
    /**
     *
     */
	int setAutoKeyInOutDefault(void);
	/**
	 *
	 */
	int setAutoKeyInOutValue(void);
	/**
	 *
	 */
	int setDoubleStepDefault(void);
	/**
	 *
	 */
	int setDoubleContinueDefault(void);
	/**
	 *
	 */
	int setDoubleStepValue(void);
	/**
	 *
	 */
	int setDoubleContinueValue(void);
	/**
	 *
	 */
	bool autoKeyOutCheck(unsigned long _credit);
	/**
	 *
	 */
	void setKeyInMaxDefaultValue(void);
	/**
	 *
	 */
	void setKeyInMaxValue(void);
	/**
	 *
	 */
	void updateResultPanel(void);
	/**
	 *
	 */
	unsigned int getDoubleGameAward(void);
	/**
	 *
	 */
	void printFrameItemRecord(void);
	/**
	 *
	 */
	void printFullAwardRecord(void);
	/**
	 *
	 */
	void printLineAwardRecord(void);
	/**
	 *
	 */
	void printDoubleGameAwardRecord(void);
};


#endif /* MAINFRAME_H_ */
