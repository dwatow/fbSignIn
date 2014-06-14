#ifndef COMPARISIONSTR_H
#define COMPARISIONSTR_H
#include "kxTxtFile.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

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
		vector<string>::iterator prev_it = data.begin();
        for (vector<string>::iterator it = data.begin(); it != data.end(); ++it)
        {
            if(it->length() == 0)
            {
				prev_it = it;
                continue;
            }

			if (prev_it->length() == 0)
				strv.push_back(*it);

			prev_it = it;
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
        findSignInMember();
        removeRepeatMember();
    }

    void findSignInMember()
    {
        for (std::vector<string>::iterator iMember = member.begin(); iMember != member.end(); ++iMember)
            for (std::vector<string>::iterator iSignIn = fbSignIn.begin(); iSignIn != fbSignIn.end(); ++iSignIn)
                if (isMemberInLineHead(iSignIn, iMember))
                    result.push_back(*iMember);
    }

    void removeRepeatMember()
    {
        std::sort(result.begin(), result.end());
        result.erase(std::unique(result.begin(), result.end()), result.end());
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