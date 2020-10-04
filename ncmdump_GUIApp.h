/***************************************************************
 * Name:      ncmdump_GUIApp.h
 * Purpose:   Defines Application Class
 * Author:    z4deepfz ()
 * Created:   2020-08-03
 * Copyright: z4deepfz ()
 * License:
 **************************************************************/

#ifndef NCMDUMP_GUIAPP_H
#define NCMDUMP_GUIAPP_H

#include <wx/app.h>
#include <wx/cmdline.h>

class ncmdump_GUIApp : public wxApp
{
    public:
        virtual bool OnInit();
    private:
        wxLocale m_locale;
};

#endif // NCMDUMP_GUIAPP_H
