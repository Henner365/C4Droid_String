#include "first.h"

// hand compile g++ -g -std=c++11 first.cpp -o first.exe



// string can get easyly bigger than. > 16 chars.- then choose heap else stack
// ************************************************************
//
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


void f();


const char* string::get(){return pstrA;} // do not remove! used by friends!


string::string():pstrA(NULL),length(80){};


string::string(const char * cchp)
{
	std::cout<<"\n constructor:  i'm called   \n";
	std::cout<<cchp<<std::endl;
	length = get_length(cchp);
	std::cout<<" length : "<<length<<"\n";

	char* temp = new char[length+1];//+1 is for '\0'
	pstrA=temp; // alert! Do not move this line.
     
	for(str_int i=0;i<length;i++)
	{
		*temp=*cchp; // danger area!!! dangerous pointer c kode.
	
	std::cout<<" i: "<<i<<" "<<*temp<<".\n";temp++;cchp++;
	}

	//*temp='\0'   end of string.
	*temp=*cchp;
   
};


string::string(const string& tocopy){
	std::cout<<"\n copy constructor i'm called \n";
	
	const char *lcp=tocopy.pstrA;//.get();	
	std::cout<<"lcp :"<<lcp;	

		
	 
	if(lcp!=NULL)
	{
	std::cout<<std::endl<<"cc : tocopy is really not   NULL but:  "<<lcp<<"\n";
	str_int si;
	si=get_length(lcp);
	std::cout<<"\n cc:  tocopy length: "<<si<<"\n";
	
		char* tempCc=new char[si+1];		
		this->pstrA = tempCc;
		for(str_int i=0;i<si;i++){*(tempCc)=*(lcp);tempCc++;lcp++;}*tempCc='\0'; //strcpy
		std::cout<<"\n cc: this->pstrA = "<<this->pstrA<<"\n";
	}
	else
	  {	
		  
		this->pstrA=NULL;
	  }
	
};


string& string::operator=(const string& astr)
{
	std::cout<<"\n assignment operator i'm called   \n";	
	if(this->pstrA==astr.pstrA)return *this;
	else
	{
		if(this->pstrA!=NULL){
            if(this->length!=astr.length)
            {
            const char* lacp = astr.pstrA;    
            char * tmp;
            tmp = this->pstrA;
            delete [] tmp;
            tmp = new char[astr.length+1];
            this->pstrA=tmp;
            str_int si;
            si=get_length(lacp);
            for(str_int i=0;i<si;i++){*(tmp)=*(lacp);tmp++;lacp++;}*tmp='\0'; //strcpy
            }
         }
        else{ // if copyconstructor is not called automatic or this->pstrA is NULL.
            const string& temp(astr);
		
            this->pstrA=temp.pstrA;
            this->length=temp.length;
            }
        
     }
	return *this;
	
};

string::~string(){
	if(pstrA!=NULL){	
	delete [] pstrA ;
	std::cout<<"\ndestructor is called\n";
	}


};


str_int string::get_length(const char* ccp) 
{
	int foreverguard=0;
	str_int sint =0;
	const char* traverse_p=ccp;
	while(*traverse_p !='\0' && foreverguard<100)
	{
	std::cout<<" traverse the pointer "<<*traverse_p<<"\n";
	traverse_p++;sint++;foreverguard++; 
	}
	std::cout<<std::endl;
	return sint; 

};


std::ostream& operator<<(std::ostream& os,string& prnt)
{
	os<<prnt.get()<<".  [greetings from a friend to string] ";
	return os;
};


void f()
{
	if(1){
    string b("cdef");	
    string a(b);
    std::cout<<"\n a:"<<a<<"\n";}
}


int main()
{
	if(0){string mystr("abc");std::cout<<"\nmystr -> "<<mystr<<"\n";  }
	if(0){f();}		
	if(0){ 
        string x("xyzvx");
        string y=x;
        std::cout<<"\n x and y: "<<y<<"\n";
        string z("something else");
        x=z;
        std::cout<<"\n new x: "<<x<<"\n";
    }
    if(1){
        string ny;
        string gammel("new value");
        ny=gammel;
        std::cout<<"\n"<<ny;
    }
	std::cout<<"\nprogram ended witout obvious errors ..."<<std::endl;
	return 0;
}
