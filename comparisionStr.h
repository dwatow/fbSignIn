#ifndef COMPARISIONSTR_H
#define COMPARISIONSTR_H
#include "kxTxtFile.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class comparisionStr{
    vector<string> member;
    vector<string> fbSignIn;
    vector<string> result;

    void getData(const char* path, vector<string>& data)
    {
        kxTxtFile inFlie;
        inFlie.Open(path, data);
        inFlie.Close();
    }

    void setData(const char* path, vector<string>& data)
    {
        kxTxtFile outFile;
        outFile.Save(path, data);
        outFile.Close();
    }

    void findLineOfMemberName(vector<string>& data)
    {
        vector<string> strv;
        for (vector<string>::iterator it = data.begin(); it != data.end(); ++it)
        {
            if (it->length() == 0)
            {
                ++it;
                strv.push_back(*it);
            }
        }
        data.clear();
        data = strv;
    }

    void show(vector<string>& data)
    {
        for (std::vector<string>::iterator i = data.begin(); i != data.end(); ++i)
            cout << *i << endl;
    }

public:
    void SetMember(const char* iPath1)
    {
        getData(iPath1, member);
        findLineOfMemberName(member);
    }

    void SetfbSignIn(const char* iPath2)
    {
        getData(iPath2, fbSignIn);
        findLineOfMemberName(fbSignIn);
    }

    void GetResult(const char* oPath)
    {
        setData(oPath, result);
    }

    bool isMemberInLineHead(std::vector<string>::iterator iSignIn, std::vector<string>::iterator iMem)
    {
        return iSignIn->find(*iMem) == 0;
    }

    bool isSignInNotAgain(std::vector<string>::iterator iMem)
    {
        if (*result.rbegin() != *iMem)
            return true;
        else
            return false;
    }

    void GetSignInMember()
    {
        result.push_back("result is:");

        for (std::vector<string>::iterator iMember = member.begin(); iMember != member.end(); ++iMember)
            for (std::vector<string>::iterator iSignIn = fbSignIn.begin(); iSignIn != fbSignIn.end(); ++iSignIn)
                if (isMemberInLineHead(iSignIn, iMember) && isSignInNotAgain(iMember))
                    result.push_back(*iMember);
    }

    void ShowFbSignIn()
    {
        show(fbSignIn);
    }

    void ShowMember()
    {
        show(member);
    }

    void ShowResult()
    {
        show(result);
    }
};
#endif