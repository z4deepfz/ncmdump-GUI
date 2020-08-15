#include "ConvertTaskThread.h"

ConvertTaskThread::ConvertTaskThread(ncmdump_GUIFrame& frame_ref):
    wxThread(wxTHREAD_DETACHED), frame(frame_ref)
{
    //ctor
}

ConvertTaskThread::~ConvertTaskThread()
{
    //dtor
}

void* ConvertTaskThread::Entry()
{
    frame.ConvertAllNcmFiles();
    return nullptr;
}

