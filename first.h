
#ifndef  first_h
#define  first_h

#include <iostream>
#include <stdio.h>

typedef unsigned int str_int;


// string can get easyly bigger than. > 16 chars.- then choose heap else stack
// ************************************************************
// paa heapen. 

class string{
	//protected:
	friend std::ostream& operator<<(std::ostream& os, string& prnt);
	private:
	//char stackstore[16];	
	char*   pstrA;
	str_int length;
	//int& ir;
	public:
	char* get();
	~string ();
	string();
	string(const char * cchp);
	string( string& tocopy);//copyconstructor
	string& operator=( string& astr);//assignment operator
	str_int get_length(const char* ccp);

};


#endif 
