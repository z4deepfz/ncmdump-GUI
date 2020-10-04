/***************************************************************
 * Name:      ncmdump_GUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    z4deepfz ()
 * Created:   2020-08-03
 * Copyright: z4deepfz ()
 * License:
 **************************************************************/

#include "ncmdump_GUIApp.h"

static const wxCmdLineEntryDesc g_cmdLineDesc[] =
{
    { wxCMD_LINE_PARAM, NULL, NULL, wxT_2("Open Files"), wxCMD_LINE_VAL_STRING,
        wxCMD_LINE_PARAM_OPTIONAL|wxCMD_LINE_PARAM_MULTIPLE  },
    { wxCMD_LINE_NONE }
};

//(*AppHeaders
#include "ncmdump_GUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ncmdump_GUIApp);

bool ncmdump_GUIApp::OnInit()
{
    /* Locale options */
    m_locale.AddCatalogLookupPathPrefix(wxT("."));
    m_locale.AddCatalogLookupPathPrefix(wxT("locale"));
    m_locale.AddCatalog(wxT("zh_CN"));

    /* cmdline parser */
    wxArrayString arr;
    wxCmdLineParser cmdParser(g_cmdLineDesc, argc, argv);
    cmdParser.Parse();

    for(size_t i=0; i<cmdParser.GetParamCount(); i++){
        const auto s = cmdParser.GetParam(i);
        wxFileName fName(s);
        const auto slong = fName.GetFullName();
        arr.Add(s);
    }

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ncmdump_GUIFrame* Frame = new ncmdump_GUIFrame(0, arr);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
}
