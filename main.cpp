/**
 * main.cpp
 *
 */

#include "main.h"
#include "mainFrame.h"

IMPLEMENT_APP(wxProbability_97)

bool wxProbability_97::OnInit(){
	MainFrame* mainFrame = new MainFrame(wxT("Probability 97"));
	mainFrame->Show(true);

	return true;
}

