#include "first.h"





// string kan blive så sto-. > 16 tegn.- den ern�dt til at være å
// paa heapen. 
/*
class string{
	private:
	char stackstore[16];	
	char*   pstrA;
	str_int lengtt;
	
	public:
	~string ();
	string(const char * cchp);
	str_int get_length(const char* ccp);
	void copy_const_str(char* pStrArr,const char* cchp );
};
*/


char* string::get(){return pstrA;}


string::string():pstrA(NULL),length(80){};

string::string(const char * cchp)
{
	std::cout<<"\n constructor:  jeg er kaldt\n";
	std::cout<<cchp<<std::endl;
	length = get_length(cchp);
	std::cout<<" length : "<<length<<"\n";
	length++;
	char* temp = new char[length];//+1 er til '\0'
	pstrA=temp;
	for(int i=0;i<length;i++)
	{
		*temp=*cchp; // danger area!!! farlig pointer c kode.
	
	std::cout<<" i: "<<i<<" "<<*temp<<".";temp++;cchp++;
	}

	//*temp='\0'   end of string.
	*temp=*cchp;

};

string::string( string& tocopy){
	std::cout<<"\n cc jeg er kaldt\n";
	
	char *lcp=tocopy.get();	
	std::cout<<"lcp :"<<lcp;	

		
	 
	if(lcp!=NULL)
	{
	std::cout<<std::endl<<"cc : tocopy er rigtigt ikke NULL men:  "<<lcp<<"\n";
	str_int si;
	si=get_length(lcp);
	std::cout<<"\n cc:  tocopy length: "<<si<<"\n";
	
		char* tempCc=new char[si+1];		
		this->pstrA = tempCc;
		for(int i=0;i<si;i++){*(tempCc)=*(lcp);tempCc++;lcp++;}*tempCc='\0'; //strcpy
		std::cout<<"\n cc: this->pstrA"<<this->pstrA<<"\n";
	}
	else
	  {	
		  
		this->pstrA=NULL;
	  }
	
};

string& string::operator=( string& astr){
	std::cout<<"\nassignmentoperator jeg er kaldt\n";	
	if(this->pstrA==astr.pstrA)return *this;
	else
	{
		if(this->pstrA!=NULL){
		char* tmp= this->pstrA;


	string& temp(astr);
		
		this->pstrA=temp.pstrA;
		this->length=temp.length;

	return *this;
	}
};

string::~string(){
	if(pstrA!=NULL){	
	delete [] pstrA ;
	std::cout<<"\ndestructor er kaldt\n";
	}


};



str_int string::get_length(const char* ccp) 
{
	int foreverguard=0;
	str_int sint =0;
	const char* traverse_p=ccp;
	while(*traverse_p !='\0' && foreverguard<100)
	{
	std::cout<<*traverse_p<<" trav p ";
	traverse_p++;sint++;foreverguard++; 
	}
	std::cout<<std::endl;
	return sint; 

};


std::ostream& operator<<(std::ostream& os,string& prnt)
{
	os<<prnt.get()<<" hilsen fra friend ";
	return os;
};


void f();


int main()
{
	if(1){string mystr("abc");/*std::cout<<" -> "<<mystr;*/  }
	f();		
	if(1){ string x("xy");string y=x;
	std::cout<<"hello man"<<std::endl;
	return 0;
}
void f(){
	if(1){string b("cdef");	string a(b);std::cout<<"\n a:"<<a<<"\n";}
}
