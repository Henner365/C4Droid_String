
#ifndef  first_h
#define  first_h

#include <iostream>
#include <stdio.h>

typedef unsigned int str_int;


// string can get easyly bigger than. > 16 chars.- then choose heap else stack
// ************************************************************
// 

class string{
	//protected:
	friend std::ostream& operator<<(std::ostream& os, string& prnt);
	private:
	//char stackstore[16];	
	char*   pstrA;
	str_int length;
	//int& ir;
	public:
	const char* get();
	~string ();
	string();
	string(const char * cchp);
	string(const string& tocopy);//copyconstructor
	string& operator=(const string& astr);//assignment operator
	str_int get_length(const char* ccp);

};


#endif 
