#include "ncmdump_GUIApp.h"
#include "ncmdump_GUIMain.h"
#include "wx/wx.h"
#include <exception>

void addListCtrlCol(wxListCtrl& l)
{
    l.InsertColumn(0, _("File Name"), wxLIST_FORMAT_LEFT, 520);
    l.InsertColumn(1, _("Size"), wxLIST_FORMAT_LEFT);
    //wxMessageBox("aaa");
}

void ncmdump_GUIFrame::reFillList()
{
    itembox->DeleteAllItems();
    int cnt = 0;
    for(auto i: sFile){
        wxListItem fn, fs;
        wxFileName f( static_cast<wxString>(i) );

        fn.SetColumn(0);
        fn.SetId(cnt++);
        fn.SetText(i);
        const auto ind = itembox->InsertItem(fn);

        fs.SetColumn(1);
        fs.SetId(ind);
        fs.SetText( f.GetHumanReadableSize() );
        itembox->SetItem(fs);
    }
    return;
}

void ncmdump_GUIFrame::setItemColor(const wxString& s, const wxColor& c)
{
    auto p = itembox->FindItem(-1, s);
    if( p != wxNOT_FOUND){
        itembox->SetItemBackgroundColour(p, c);
    }
    return;
}

bool DumpNcm(const std::string& s, const std::string& opath="")
{
    try{
        NeteaseCrypt c(s);
        c.Dump(opath);
        c.FixMetadata();
    }
    catch(...){
        return false;
    }
    return true;
}

wxString getFileName(const wxString& s)
{
    wxFileName t(s);
    return t.GetFullName();
}

wxString genProcessText(int finished, int total, const wxString& name)
{
    return wxString::Format(" (%d/%d) Processing... [", finished, total) + getFileName(name) + "]";
}

wxString getFileExt(const wxString& s)
{
    wxFileName t(s);
    return t.GetExt();
}

bool isNCMFile(const wxString& s)
{
    return getFileExt(s) == wxString("ncm");
}

class DnDTarget: public wxFileDropTarget
{
    public:
        DnDTarget(ncmdump_GUIFrame *owner): m_owner(owner) {}
        virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames){
            m_owner->AddItems(filenames);
            return true;
        }

    private:
        ncmdump_GUIFrame* m_owner;
};
