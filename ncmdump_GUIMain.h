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

#include <set>
#include <thread>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/dnd.h>
#include <wx/utils.h>

#include "MergeFileDialog.h"
#include "ncmdump/ncmcrypt.h"
#include "ncmdumpGUI_OptionsDialog.h"

#if WINVER > 0x0501
    /// comment: function `sound_quality_update` has some problems under winXP and earlier
    ///          this macro will block the function under winXP
    #define ENABLE_SOUND_QUALITY
#endif // WINVER

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
    private: /// custom data
        std::set<std::string> sFile;   /// array to buf the file path
        void reFillList();
        void setItemColor(const wxString& s, const wxColor& c);
        void ConvertAllNcmFiles();
        bool flagEdiable;

    private:        /* Dialog(s) */
        ncmdumpGUI_OptionsDialog *d_option;

    public:
        ncmdump_GUIFrame(wxWindow* parent,wxWindowID id = -1);
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
