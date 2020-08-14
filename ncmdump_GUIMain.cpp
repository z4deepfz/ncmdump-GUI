/***************************************************************
 * Name:      ncmdump_GUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    z4deepfz ()
 * Created:   2020-08-03
 * Copyright: z4deepfz ()
 * License:
 **************************************************************/

#include "ncmdump_GUIMain.h"
#include "GUIExtra.hpp"
#include <wx/msgdlg.h>

//(*InternalHeaders(ncmdump_GUIFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ncmdump_GUIFrame)
const long ncmdump_GUIFrame::ID_LISTCTRL1 = wxNewId();
const long ncmdump_GUIFrame::ID_BUTTON1 = wxNewId();
const long ncmdump_GUIFrame::ID_BUTTON2 = wxNewId();
const long ncmdump_GUIFrame::ID_BUTTON4 = wxNewId();
const long ncmdump_GUIFrame::ID_BUTTON5 = wxNewId();
const long ncmdump_GUIFrame::ID_BUTTON3 = wxNewId();
const long ncmdump_GUIFrame::ID_GAUGE1 = wxNewId();
const long ncmdump_GUIFrame::ID_PANEL1 = wxNewId();
const long ncmdump_GUIFrame::idMenuQuit = wxNewId();
const long ncmdump_GUIFrame::ID_MENUITEM1 = wxNewId();
const long ncmdump_GUIFrame::idMenuAbout = wxNewId();
const long ncmdump_GUIFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ncmdump_GUIFrame,wxFrame)
    //(*EventTable(ncmdump_GUIFrame)
    //*)
END_EVENT_TABLE()

ncmdump_GUIFrame::ncmdump_GUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ncmdump_GUIFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, _("ncmdump GUI"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(800,600));
    SetIcon(wxIcon(wxT("aaaa")));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(368,328), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Items"));
    itembox = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTCTRL1"));
    addListCtrlCol(*itembox);
    StaticBoxSizer1->Add(itembox, 1, wxALL|wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    btnAdd = new wxButton(Panel1, ID_BUTTON1, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnAdd->SetMinSize(wxSize(-1,36));
    BoxSizer2->Add(btnAdd, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    btnDel = new wxButton(Panel1, ID_BUTTON2, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    btnDel->SetMinSize(wxSize(-1,36));
    BoxSizer2->Add(btnDel, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    btnClear = new wxButton(Panel1, ID_BUTTON4, _("Clear"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    btnClear->SetMinSize(wxSize(-1,36));
    BoxSizer2->Add(btnClear, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    BoxSizer2->Add(-1,-1,6, wxLEFT|wxRIGHT|wxEXPAND, 5);
    btnOption = new wxButton(Panel1, ID_BUTTON5, _("Options"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    btnOption->SetMinSize(wxSize(-1,36));
    BoxSizer2->Add(btnOption, 1, wxLEFT|wxRIGHT|wxEXPAND, 5);
    StaticBoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(StaticBoxSizer1, 5, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON3, _("Convert"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button1->SetMinSize(wxSize(-1,30));
    BoxSizer4->Add(Button1, 0, wxALL|wxEXPAND, 4);
    gauge = new wxGauge(Panel1, ID_GAUGE1, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_GAUGE1"));
    BoxSizer4->Add(gauge, 5, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer4, 0, wxALL|wxEXPAND, 0);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 10);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("Sound Quality Upgrade"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuBar1->Append(Menu3, _("&Tools"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("&Help"));
    SetMenuBar(MenuBar1);
    stb = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    stb->SetFieldsCount(1,__wxStatusBarWidths_1);
    stb->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(stb);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncmdump_GUIFrame::OnAddFile);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncmdump_GUIFrame::OnDeleteItem);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncmdump_GUIFrame::OnClear);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncmdump_GUIFrame::OnOptions);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ncmdump_GUIFrame::OnStartConvert);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ncmdump_GUIFrame::OnQuit);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ncmdump_GUIFrame::OnToolDelPoorFiles);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ncmdump_GUIFrame::OnAbout);
    //*)

    d_option = new ncmdumpGUI_OptionsDialog(this);
    d_merge  = new MergeFileDialog(this);

    SetDropTarget(new DnDTarget(this));
    flagEdiable = true;
    stb->SetStatusText(_(" Idle"), 0);
}

ncmdump_GUIFrame::~ncmdump_GUIFrame()
{
    //(*Destroy(ncmdump_GUIFrame)
    //*)
}

void ncmdump_GUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ncmdump_GUIFrame::OnAbout(wxCommandEvent& event)
{
    const wxString aboutinfo =
        wxString("Author: z4deepfz\n")
        + "Github Page: https://github.com/z4deepfz\n\n"
        + "----------------Special thanks to----------------\n"
        + "ncmdump repo: https://github.com/anonymous5l/ncmdump\n"
        + "Library Author: anonymous5l\n"
        + "Github Page: https://github.com/anonymous5l\n\n"
        + "Build info: " + wxbuildinfo(long_f);

    wxMessageBox(aboutinfo, _("About ncmdump Graphical User Interface"));
}

void ncmdump_GUIFrame::AddItems(const wxArrayString& a)
{
    if(flagEdiable == false){
        return;
    }
    for(auto i: a){
        if( isNCMFile(i) ){ /// avoid another files added
            sFile.insert( static_cast<std::string>(i) );
        }
    }
    reFillList();
    return;
}


/** 自定义事件处理函数 **/

void ncmdump_GUIFrame::OnAddFile(wxCommandEvent& event)
{
    if(flagEdiable == false){
        return;
    }
    /// function: add file to the item box. the path will be send to ncmdump to convert later
    /// 1. show a file dialog to request a file path
    wxFileDialog cfile( this, wxFileSelectorPromptStr, wxEmptyString, wxEmptyString,
                        _("*.ncm"), wxFD_OPEN|wxFD_MULTIPLE );


    /// 2. add the path to a container(map, vector, queue, etc...)
    if(cfile.ShowModal() == wxID_OK){
        wxArrayString tmp;
        cfile.GetPaths(tmp);
        AddItems(tmp);
    }

    /// 3. add filename to the item box
    reFillList();

    /// return
    return;
}

void ncmdump_GUIFrame::OnDeleteItem(wxCommandEvent& event)
{
    if(flagEdiable == false){
        return;
    }
    /// functin: delete the chosen item in the item box
    auto p = itembox->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    while(p != -1){
        //wxMessageBox(wxString::Format("Item: %d", p));
        /// 1. get name of item from item box
        auto t = itembox->GetItemText(p);

        /// 2. find string in the container
        auto it = sFile.find( static_cast<std::string>(t) );
        if(it == sFile.end()){
            wxMessageBox( _("Unexpect Error: Cannot find Item \"") + t + "\"" );
        }
        else{
            /// 3. delete this item in container
            sFile.erase(it);
        }

        p = itembox->GetNextItem(p, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    }

    /// 4. delete this item in the item box
    reFillList();

    /// return
    return;
}

void ncmdump_GUIFrame::OnStartConvert(wxCommandEvent& event)
{
    /// const value
    const auto red = wxColor(237, 38, 36);
    const auto green = wxColor(0, 201, 87);

    /// flags
    flagEdiable = false;
    const auto flagDelNCM  = d_option->isDeleteNCMFile();
    const auto flagFixMeta = d_option->isFixMetaData();

    /// function: convert all of the files
    /// 1. pop up a file dialog to require the output path
    wxDirDialog d(this);

    if(d.ShowModal() == wxID_OK){
        /// 2. loop send each file to the ncmdump core
        const auto opath = static_cast<const std::string>( d.GetPath() );
        const auto tot = sFile.size();
        auto cnt = 0;
        gauge->SetValue(0);
        stb->SetStatusText(wxString::Format(" (0/%d) Processing...", tot));
        for(auto i: sFile){
            if( DumpNcm(i, opath, flagFixMeta) ){
                setItemColor(static_cast<wxString>(i), green);
                if( flagDelNCM ){
                    if( wxRemoveFile( static_cast<wxString>(i) ) == false ){
                        // delete failed
                        wxMessageBox(_("Delete Failed!"), _("Warning"), wxICON_INFORMATION|wxCENTER);
                    }
                }
            }
            else{
                /// 3. when error occured, pop up a dialog asking if continue
                setItemColor(static_cast<wxString>(i), red);
                wxMessageDialog e(this, _("Error occured when converting \"") + i + _("\"\nWould you like to continue?"),
                                  _("Error"), wxYES_NO|wxICON_HAND|wxCENTER);
                if( e.ShowModal() == wxID_NO ){
                    wxMessageBox(_("Task Abort!"), _("Warning"), wxICON_INFORMATION|wxCENTER);
                    goto endfunc;
                }
            }
            /// update gauge when pass a task
            ++cnt;
            gauge->SetValue(cnt*100 / tot);
            stb->SetStatusText(genProcessText(cnt, tot, i));
        }
        wxMessageBox(_("All tasks finished!"));
    }

endfunc:
    gauge->SetValue(0);
    flagEdiable = true;
    //stb->SetStatusText("Idle");
    return;
}

void ncmdump_GUIFrame::OnClear(wxCommandEvent& event)
{
    if(flagEdiable){
        sFile.clear();
        itembox->DeleteAllItems();
    }
}

void ncmdump_GUIFrame::OnOptions(wxCommandEvent& event)
{
    d_option->Show();
}

void ncmdump_GUIFrame::OnToolDelPoorFiles(wxCommandEvent& event)
{
    d_merge->Show();
    return;
}
