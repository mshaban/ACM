
#include <cstring>

using namespace std;
bool WriteComPort(CString PortSpecifier, CString data)
{
    DCB dcb;
    DWORD byteswritten;
    HANDLE hPort = CreateFile(
                       PortSpecifier,
                       GENERIC_WRITE,
                       0,
                       NULL,
                       OPEN_EXISTING,
                       0,
                       NULL );
    if (!GetCommState(hPort, &dcb))
        return false;
    dcb.BaudRate = CBR_9600;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    if (!SetCommState(hPort, &dcb))
        return false;
    //9600 Baud
    //8 data bits
    //no parity
    //1 stop
    bool retVal = WriteFile(hPort, data, 1, &byteswritten, NULL);
    CloseHandle(hPort); //close the handle
    return retVal;
}

int main(int argc, char const *argv[])
{
    bool retVal = WriteFile(hPort, data, 1, &byteswritten, NULL); CloseHandle(hPort);
    return 0;
}