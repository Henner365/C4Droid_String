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
        char* temp = new char[length+1];//+1 er til '\0'
        pstrA=temp;
        for(int i=0;i<length;i++)
        {
                *temp=*cchp; // problem omr�de farlig pointer c kode.

        std::cout<<" i: "<<i<<" "<<*temp<<".";temp++;cchp++;
        }
        *temp='\0'; // slut på streng;

};

string::string( string& tocopy){
        std::cout<<"\n cc jeg er kaldt\n";

        char *lcp=tocopy.get();
        std::cout<<lcp;

        if(lcp!=NULL)
        {
        std::cout<<std::endl<<"cc : tocopy er rigtigt ikke NULL men:  "<<lcp<<"\n";
        str_int si;
        si=get_length(lcp);
        std::cout<<"\n cc:  tocopy length: "<<si<<"\n";


                this->pstrA = new char[si+1];
                for(int i=0;i<si;i++){*(this->pstrA)=*(lcp);this->pstrA++;lcp++;}*this->pstrA='\0'; //strcpy
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


int main()
{
        if(1){string mystr("abc");std::cout<<" -> "<<mystr;  }

        //      string a(b);std::cout<<"\n a:"<<a<<"\n";}

        std::cout<<"hello man"<<std::endl;
        return 0;
}