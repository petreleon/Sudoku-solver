#include "Main.h"
#include "Sudoku.h"
void Main::Compute(wxCommandEvent& event)
{
	//wxMessageBox(wxT("Hello World!"));
	int sudokuGrid[9][9];
	for (int i = 0; i < 9 * 9; i++) {
		wxString value = inputs[i]->GetValue();
		if (value == "") {
			sudokuGrid[i / 9][i % 9] = 0;
		}
		else {
			sudokuGrid[i / 9][i % 9] = wxAtoi(value);
		}
	}

	if (SolveSudoku(sudokuGrid) == false) {
		wxMessageBox(wxT("I can't solve this. :'("));
		return;
	}

	for (int i = 0; i < 9 * 9; i++) {
		wxString value = wxString::Format(wxT("%i"), sudokuGrid[i / 9][i % 9]);
		inputs[i]->ChangeValue(value);
	}
}
void Main::Clear(wxCommandEvent& event)
{
	for (int i = 0; i < 9 * 9; i++) {
		inputs[i]->ChangeValue("");
	}
}
Main::Main() : wxFrame(NULL, wxID_ANY, "Sudoku Solver", wxPoint(50, 50), wxSize(450, 340)) {
	inputs = new wxTextCtrl * [9 * 9];
	gridSizer = new wxGridSizer(10, 9, 0, 0);
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			inputs[y * 9 + x] = new wxTextCtrl(this, 10000 + y * 9 + x);
			gridSizer->Add(inputs[y * 9 + x], 1, wxEXPAND | wxALL);
		}
	}
	compute = new wxButton(this, 1100, wxT("Solve"));
	gridSizer->Add(compute, 1, wxEXPAND | wxALL);
	clear = new wxButton(this, 1101, wxT("Clear"));
	gridSizer->Add(clear, 1, wxEXPAND | wxALL);
	this->SetSizer(gridSizer);
	compute->Bind(wxEVT_BUTTON, &Main::Compute, this);
	clear->Bind(wxEVT_BUTTON, &Main::Clear, this);
}