#include "play.h"
#include "widget.h"
#include "burning.h"
#include <wx/wx.h>
#include "myDoubleSlider.h"
#include "thumb_up.xpm"
#include "thumb_down.xpm"
#include <wx/splitter.h>

int D_SLIDER = 1;

play::play(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1500, 400))
{

	step = 1;
	
	wxImage::AddHandler(new wxPNGHandler);
	wxPanel *panel = new wxPanel(this);

	playbutton = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("newplay.png"),
		wxBITMAP_TYPE_PNG)); 
	pausebutton = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("newpause.png"),
		wxBITMAP_TYPE_PNG));
	forwardbutton = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("newforward.png"),
		wxBITMAP_TYPE_PNG)); 
	rewindbutton = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("newrewind.png"),
		wxBITMAP_TYPE_PNG)); 
	
	wxBoxSizer *mainSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer *timeSizer = new wxBoxSizer(wxVERTICAL);
	wxTextCtrl *TextCtrl1 = new wxTextCtrl(panel, wxID_ANY, _("Text"));
	timeSizer->Add(TextCtrl1, 1, wxLEFT | wxRIGHT, 20);
	mainSizer->Add(timeSizer, 0, wxALIGN_CENTER_VERTICAL);


	wxBoxSizer *mediaSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *playerSizer = new wxBoxSizer(wxHORIZONTAL);
	myDoubleSlider *slide = new myDoubleSlider(panel, D_SLIDER, 150, 1000, 0, 1000, wxDefaultPosition, wxSize(-1, 85), wxSL_HORIZONTAL | wxSL_SELRANGE);
	playerSizer->Add(slide, 1, wxEXPAND);
	mediaSizer->Add(playerSizer, 0, wxEXPAND);

	wxBoxSizer *controlsSizer = new wxBoxSizer(wxHORIZONTAL);
	controlsSizer->Add(rewindbutton, 1, wxRIGHT, 40);
	controlsSizer->Add(pausebutton, 1, wxRIGHT | wxLEFT, 10);
	controlsSizer->Add(playbutton, 1, wxRIGHT | wxLEFT, 10);
	controlsSizer->Add(forwardbutton, 1, wxLEFT, 40);
	mediaSizer->Add(controlsSizer, 0, wxTOP | wxALIGN_TOP | wxALIGN_CENTER_HORIZONTAL, 20);
	mainSizer->Add(mediaSizer, 1, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);

	wxBoxSizer *stepSizer = new wxBoxSizer(wxVERTICAL);
	Spin = new wxSpinCtrl(panel, wxID_ANY, _("1"));
	stepSizer->Add(Spin, 1, wxLEFT, 20);
	mainSizer->Add(stepSizer, 0, wxALIGN_CENTER_VERTICAL);

	panel->SetSizer(mainSizer);

	Connect(wxID_ANY, wxEVT_COMMAND_SPINCTRL_UPDATED, (wxObjectEventFunction)&play::OnSpinCtrl1Change);

}


void play::OnSpinCtrl1Change(wxSpinEvent& event)
{
	step = Spin->GetValue();
	Refresh();

}

int play::Getstep()
{
	return step;
}