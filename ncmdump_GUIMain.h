/***************************************************************
 * Name:      ncmdump_GUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    z4deepfz ()
 * Created:   2020-08-03
 * Copyright: z4deepfz ()
 * License:
 **************************************************************/

#ifndef NCMDUMP_GUIMAIN_H
#define NCMDUMP_GUIMAIN_H

/// some macro switches

#ifdef _WIN32
    /// following features lead to `unknown software exception` on Windows XP.
    /// I patched it by these macros temporary. If they work well, you can re-enable them.
    #if WINVER > 0x0501
        /// enable feature `sound_quality_update`
        #define ENABLE_SOUND_QUALITY
        /// enable multi-threads. This can keep GUI running during converting (or GUI will freeze)
        #define ENABLE_MULTI_THREADS
    #endif // WINVER
#else // on other OS, enable them
    #define ENABLE_SOUND_QUALITY
    #define ENABLE_MULTI_THREADS
#endif // _WIN32

/**
 *  macro `USE_STD_MULTITHREADS` use std::thread instead of wxThread.
 *  Official document suggests using std::thread with c++11
 *  it's no much difference between them theoretically
 *  but after my test, there're some compatibility problems when using std::thread on Windows XP SP2 or earlier
 *  I'm not pretty sure if it's my fault or the runtime issue on Windows XP
 *  So if this problem doesn't appear on your system, just enable it¡£
**/
//#define USE_STD_MULTITHREADS


#include <set>
#include <thread>
#include <mutex>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/dnd.h>
#include <wx/utils.h>

#include "MergeFileDialog.h"
#include "ncmdump/ncmcrypt.h"
#include "ncmdumpGUI_OptionsDialog.h"
#include "ConvertTaskThread.h"

//(*Headers(ncmdump_GUIFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class ncmdump_GUIFrame: public wxFrame
{
    friend class ConvertTaskThread;
    private: /// custom data
        std::set<wxString> sFile;   /// array to buf the file path
        void reFillList();
        void setItemColor(const wxString& s, const wxColor& c);
        void ConvertAllNcmFiles();
        bool flagEdiable;

    private:        /* Dialog(s) */
        ncmdumpGUI_OptionsDialog *d_option;

    public:
        ncmdump_GUIFrame(wxWindow* parent, wxWindowID id = -1);
        ncmdump_GUIFrame(wxWindow* parent, const wxArrayString& filename, wxWindowID id=-1);
        virtual ~ncmdump_GUIFrame();

        void AddItems(const wxArrayString& a);

    private:

        //(*Handlers(ncmdump_GUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnAddFile(wxCommandEvent& event);
        void OnDeleteItem(wxCommandEvent& event);
        void OnStartConvert(wxCommandEvent& event);
        void OnClear(wxCommandEvent& event);
        void OnOptions(wxCommandEvent& event);
        void OnToolDelPoorFiles(wxCommandEvent& event);
        //*)

        //(*Identifiers(ncmdump_GUIFrame)
        static const long ID_LISTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_BUTTON3;
        static const long ID_GAUGE1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ncmdump_GUIFrame)
        wxButton* Button1;
        wxButton* btnAdd;
        wxButton* btnClear;
        wxButton* btnDel;
        wxButton* btnOption;
        wxGauge* gauge;
        wxListCtrl* itembox;
        wxMenu* Menu3;
        wxMenuItem* MenuItem3;
        wxPanel* Panel1;
        wxStatusBar* stb;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // NCMDUMP_GUIMAIN_H
