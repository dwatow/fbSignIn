#include "comparisionStr.h"
#include <iostream>

using namespace std;

void messageRightParameterIs()
{
    cout << endl << "right format command is:" << endl << "    main <input file> <input file> <output file>" << endl;
}

int main(int argc, char const *argv[])
{
    comparisionStr realMain;
    switch(argc)
    {
    case 1:
        cout << "fbSignIn: no path for input file" << endl;
        messageRightParameterIs();
        break;
    case 2:
        cout << "fbSignIn: no path for input file are not yet enough" << endl;
    case 3:
        cout << "fbSignIn: no path for output file" << endl;
        messageRightParameterIs();
        break;
    case 4:
        //cout << "parameter is right" << endl << endl;
        realMain.SetMember(argv[1]);
        realMain.SetfbSignIn(argv[2]);
        //realMain.GetSignInMember();
        
        realMain.GetSignInMember();
        //realMain.ShowFbSignIn();
        //realMain.ShowMember();
        realMain.ShowResult();
        realMain.GetResult(argv[3]);
        break;
    default:
        cout << "fbSignIn: parameter is to much" << endl;
        messageRightParameterIs();
    }
    

    return 0;
}