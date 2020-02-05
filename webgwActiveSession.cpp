/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

template <typename _T>
class Singleton
{
public:
    static _T& instance()
    {
        static _T gInst; 
        return gInst;
    }

    virtual ~Singleton()
    {
    }
};

template <class T>
class WebGwActiveSessions : public Singleton< WebGwActiveSessions<T> >
{
    public:
        int i;
        int type;    
    WebGwActiveSessions() 
    {
        type = 0;
        cout << "WebGwActiveSessions constructor type" << type << endl;
    }
    
	static WebGwActiveSessions<T>& getInstance(int type = 0)
	{
            type = type;
          //  cout << "type set at here is" << type;
			WebGwActiveSessions<T> &activeSession = (WebGwActiveSessions<T> &)Singleton< WebGwActiveSessions<T> >::instance();
            //cout << "session type before set is" << activeSession.type << endl;
            activeSession.type = type;
            return activeSession;
	}
		
    virtual ~WebGwActiveSessions() {}
    int getSessionId()
	{
	    return i;
	}
	
	void setSessionId()
	{
	    i =1;
	}
		    
};

class WebGwActiveChatSessions : public WebGwActiveSessions<WebGwActiveChatSessions>
{
protected:
	WebGwActiveChatSessions() { type = 1; }
	~WebGwActiveChatSessions();
	WebGwActiveChatSessions(WebGwActiveChatSessions const& copy);
	WebGwActiveChatSessions& operator=(WebGwActiveChatSessions const& copy);
};

class WebGwActiveGrpChatSessions : public WebGwActiveSessions<WebGwActiveGrpChatSessions>
{
protected:
	WebGwActiveGrpChatSessions() 
	{ 
	    type = 2; 
	    cout << " Calling WebGwActiveGrpChatSessions" << endl;
	}
	~WebGwActiveGrpChatSessions();
	WebGwActiveGrpChatSessions(WebGwActiveGrpChatSessions const& copy);
	WebGwActiveGrpChatSessions& operator=(WebGwActiveGrpChatSessions const& copy);
};

int main()
{
    WebGwActiveGrpChatSessions::getInstance().setSessionId(); 
    cout << WebGwActiveGrpChatSessions::getInstance().getSessionId() << endl;
    cout << WebGwActiveChatSessions::getInstance().getSessionId() << endl;
    return 0;
}

