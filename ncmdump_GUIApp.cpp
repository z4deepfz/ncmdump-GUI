/***************************************************************
 * Name:      ncmdump_GUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    z4deepfz ()
 * Created:   2020-08-03
 * Copyright: z4deepfz ()
 * License:
 **************************************************************/

#include "ncmdump_GUIApp.h"

//(*AppHeaders
#include "ncmdump_GUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ncmdump_GUIApp);

bool ncmdump_GUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ncmdump_GUIFrame* Frame = new ncmdump_GUIFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
