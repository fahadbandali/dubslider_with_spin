#include "main.h"
#include "burning.h"
#include "play.h"
#include "myDoubleSlider.h"
#include "thumb_up.xpm"
#include "thumb_down.xpm"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

	//Burning *burning = new Burning(wxT("The media Widget"));
	play *bb = new play(wxT("BitmapButton"));
	//burning->Show(true);
	bb->Show(true);



	return true;
}