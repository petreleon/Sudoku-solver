#pragma once
#include "wx/wx.h"
#include <wx\event.h>


class Main :
	public wxFrame
{
	wxGridSizer* gridSizer;
	wxTextCtrl** inputs;
	wxButton* clear;
	wxButton* compute;
	void Compute(wxCommandEvent& event);
	void Clear(wxCommandEvent& event);
public:
	Main();

};

