#ifndef CONVERTTASKTHREAD_H
#define CONVERTTASKTHREAD_H

#include <wx/thread.h>
#include "../ncmdump_GUIMain.h"
#define ID_CONVERT_TASK_FINISHED 999

class ncmdump_GUIFrame;

class ConvertTaskThread : public wxThread
{
    public:
        ConvertTaskThread( ncmdump_GUIFrame& frame_ref );
        virtual ~ConvertTaskThread();
        virtual ExitCode Entry() override;

    protected:
        ncmdump_GUIFrame& frame;
};

#endif // CONVERTTASKTHREAD_H
