#ifndef TXTFILE_H
#define TXTFILE_H
#include <vector>
#include <string>
#include <fstream>

class kxTxtFile
{
	std::fstream ftxt_Std;
	std::vector<std::string> dtxt_Txt;

public:
    bool Open(const char*);
    bool Save(const char*);

	void iTxtData(std::vector<std::string>& data){ dtxt_Txt = data; mem2file(); };
	void oTxtData(std::vector<std::string>& data){ file2mem(); data = dtxt_Txt; };
    
    bool Open(const char*, std::vector<std::string>& data);
    bool Save(const char*, std::vector<std::string>& data);

	void Close(){ ftxt_Std.close(); };

	std::vector<std::string> oTxtData(){ file2mem(); return dtxt_Txt; };
private:
	void file2mem();
	void mem2file();
};


#endif