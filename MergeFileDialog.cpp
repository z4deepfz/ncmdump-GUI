#include "MergeFileDialog.h"

//(*InternalHeaders(MergeFileDialog)
#include <wx/button.h>
#include <wx/intl.h>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
//*)

//(*IdInit(MergeFileDialog)
const long MergeFileDialog::ID_STATICTEXT1 = wxNewId();
const long MergeFileDialog::ID_TEXTCTRL1 = wxNewId();
const long MergeFileDialog::ID_BUTTON1 = wxNewId();
const long MergeFileDialog::ID_RADIOBUTTON1 = wxNewId();
const long MergeFileDialog::ID_RADIOBUTTON2 = wxNewId();
const long MergeFileDialog::ID_STATICTEXT2 = wxNewId();
const long MergeFileDialog::ID_STATICTEXT3 = wxNewId();
const long MergeFileDialog::ID_BUTTON2 = wxNewId();
const long MergeFileDialog::ID_BUTTON3 = wxNewId();
const long MergeFileDialog::ID_PANEL1 = wxNewId();
//*)

void MergeMusicFiles(const std::vector<std::string>& arrfiles, bool isDelete);

BEGIN_EVENT_TABLE(MergeFileDialog,wxFrame)
	//(*EventTable(MergeFileDialog)
	//*)
END_EVENT_TABLE()

MergeFileDialog::MergeFileDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(MergeFileDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;

	Create(parent, wxID_ANY, _("Sound Quality Upgrade"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxCLIP_CHILDREN, _T("wxID_ANY"));
	SetClientSize(wxSize(640,600));
	SetMinSize(wxSize(640,600));
	SetIcon(wxIcon(wxT("options_icon")));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(336,328), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Files"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Path"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtPath = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer2->Add(txtPath, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnSelectPath = new wxButton(Panel1, ID_BUTTON1, _("Select"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	btnSelectPath->SetMinSize(wxSize(55,-1));
	BoxSizer2->Add(btnSelectPath, 0, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Strategy"));
	rad_straRename = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Rename as *.poor"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	rad_straRename->SetValue(true);
	StaticBoxSizer2->Add(rad_straRename, 0, wxALL|wxEXPAND, 5);
	rad_straDel = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Just delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	StaticBoxSizer2->Add(rad_straDel, 0, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("You can delete old files at once. Or you can also choose `rename` instead of `delete`. Then delete them via `Delete *.poor files` after make sure they are exactly unnecessary."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticBoxSizer2->Add(StaticText2, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer2, 2, wxALL|wxEXPAND, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Note"));
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("This is a simple tool to automatically select higher sound quality files. It just simply remark or delete `mp3`files only if there\'s a `flac` file with the same name.\n\nIt cannot be said that the sound quality must be improved. Basiclly, `flac` files have higher sound quality than `mp3` files. In most cases it is, especially the files downloaded and converted from Netease Music.\n\nConsidering that there are still some exceptions, please use this tool only for files downloaded from NetEase Music."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticBoxSizer3->Add(StaticText3, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer3, 3, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	btnRun = new wxButton(Panel1, ID_BUTTON2, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(btnRun, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON3, _("Delete *.poor files"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MergeFileDialog::OnSelectDir);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MergeFileDialog::OnRun);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MergeFileDialog::OnDeletePoorFile);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&MergeFileDialog::OnClose);
	//*)
}

MergeFileDialog::~MergeFileDialog()
{
	//(*Destroy(MergeFileDialog)
	//*)
}


void MergeFileDialog::OnClose(wxCloseEvent& event)
{
    //Show(false);
    Destroy();
}

void MergeFileDialog::OnRun(wxCommandEvent& event)
{
    if(rad_straDel->GetValue()){
        // if user wants to delete old files, ask if sure
        if( AskBeforeDelete() == false ){
            return;
        }
    }
    const auto a = GetFilesUnderCurrentDir();
    MergeMusicFiles(a, rad_straDel->GetValue());
}

void MergeFileDialog::OnSelectDir(wxCommandEvent& event)
{
    wxDirDialog d(this);
    if( d.ShowModal() == wxID_OK ){
        txtPath->ChangeValue(d.GetPath());
    }
}

void MergeMusicFiles(const std::vector<std::string>& arrfiles, bool isDelete)
{
    /* add files to a set */
    std::set<std::string> s;
    for(auto i: arrfiles){
        wxFileName f(i);
        auto fname = static_cast<std::string>(f.GetName());
        if( f.GetExt() == "flac" ){
            // if is flac file, add it into std::set
            s.insert(fname);
        }
        else{
            // if not, check if there's a same file in std::set
            if( s.find(fname) != s.end() ){
                // find same file name, delete it
                if(isDelete){
                    if( !wxRemoveFile(i) ){
                        wxMessageBox(_("Error when delete \"")+i+wxT("\""), _("Error"), wxICON_HAND|wxCENTER);
                    }
                }
                else{
                    if( !wxRenameFile(i, i+".poor") ){
                        wxMessageBox(_("Error when rename \"")+i+wxT("\""), _("Error"), wxICON_HAND|wxCENTER);
                    }
                }
            }
            else{
                // if not, keep it. do nothing here
            }
        }
    }

    /* finished */
    wxMessageBox(_("Task Finished."), _("Note"), wxICON_INFORMATION|wxCENTER);
}

void MergeFileDialog::OnDeletePoorFile(wxCommandEvent& event)
{
    if( AskBeforeDelete() == false ){
        return;
    }
    const auto a = GetFilesUnderCurrentDir();
    for(auto i: a){
        wxFileName f(i);
        if( f.GetExt() == "poor" ){
            if( wxRemoveFile(i) == false ){
                wxMessageBox(_("Error when delete \"")+i+wxT("\""), _("Error"), wxICON_HAND|wxCENTER);
            }
        }
    }
    /* finished */
    wxMessageBox(_("Task Finished."), _("Note"), wxICON_INFORMATION|wxCENTER);
}

std::vector<std::string> MergeFileDialog::GetFilesUnderCurrentDir() const
{
    std::vector<std::string> rt;
    wxArrayString a;
    wxDir::GetAllFiles(txtPath->GetValue(), &a);
    for(auto i: a){
        rt.push_back( static_cast<std::string>(i) );
    }
    return rt;
}

bool MergeFileDialog::AskBeforeDelete()
{
    wxMessageDialog dlg(this, _("Are you sure to continue?"), _("Before Deleting"), wxYES_NO);
    return dlg.ShowModal()==wxID_YES;
}
