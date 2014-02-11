#include "kxTxtFile.h"

bool kxTxtFile::Open(const char* path)
{
	ftxt_Std.open (path, std::ifstream::in);
    return ftxt_Std.good();
}

bool kxTxtFile::Save(const char* path)
{
    ftxt_Std.open (path, std::ofstream::out | std::ofstream::trunc);
    return ftxt_Std.good();
}


bool kxTxtFile::Open(const char* path, std::vector<std::string>& data)
{
    ftxt_Std.open (path, std::ifstream::in);
    oTxtData(data);
    return ftxt_Std.good();
}

bool kxTxtFile::Save(const char* path, std::vector<std::string>& data)
{
    ftxt_Std.open (path, std::ofstream::out | std::ofstream::trunc);
    iTxtData(data);
    return ftxt_Std.good();
}


void kxTxtFile::file2mem()
{
    dtxt_Txt.clear();
    std::string str;

    while (getline(ftxt_Std , str))
        dtxt_Txt.push_back(str);
}

void kxTxtFile::mem2file()
{
    if (!dtxt_Txt.empty())
    {
	    for (std::vector<std::string>::iterator it = dtxt_Txt.begin(); it != dtxt_Txt.end(); ++it)
	    {   
	        *it += '\n';
	        ftxt_Std.write(it->c_str(), it->length());
	    }
    }
}