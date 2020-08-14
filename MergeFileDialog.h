#ifndef MERGEFILEDIALOG_H
#define MERGEFILEDIALOG_H

#include <set>
#include <vector>
#include <wx/wx.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>
#include <wx/dir.h>
#include <wx/filename.h>
//#include "GUIExtra.hpp"

//(*Headers(MergeFileDialog)
#include <wx/frame.h>
class wxBoxSizer;
class wxButton;
class wxPanel;
class wxRadioButton;
class wxStaticBoxSizer;
class wxStaticText;
class wxTextCtrl;
//*)

class MergeFileDialog: public wxFrame
{
	public:

		MergeFileDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MergeFileDialog();

		//(*Declarations(MergeFileDialog)
		wxButton* Button1;
		wxButton* btnRun;
		wxButton* btnSelectPath;
		wxPanel* Panel1;
		wxRadioButton* rad_straDel;
		wxRadioButton* rad_straRename;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* txtPath;
		//*)

    protected:
        std::vector<std::string> GetFilesUnderCurrentDir() const;
        bool AskBeforeDelete();

	protected:

		//(*Identifiers(MergeFileDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(MergeFileDialog)
		void OnClose(wxCloseEvent& event);
		void OnRun(wxCommandEvent& event);
		void OnSelectDir(wxCommandEvent& event);
		void OnDeletePoorFile(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
