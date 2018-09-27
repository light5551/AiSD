#include <iostream>
//#include <stack>//for stack))))
#include <string>
#include <cstdio>
#include "list.cpp"
//#define SCRIPT_TEST
#define TEST_ALG
bool check_next_symbol(std::string text,int shift)				//true- ( A )
{																//false- ( )
	for(int i=shift;i<text.size()&&text[i]!=')';i++)			
		{
			if(text[i]!=' ')
			return true;
		}
	return false;
}

std::string input(){
	std::string text;
	getline(std::cin,text);	
	return text;
}

bool textcorrect(std::string text)
{
	int sum=0;
	for(int i=0;i<text.size();i++)
	{
		if(sum<0)									//if situation: ))(( - total sum=0,but
			return false;							// it's wrong ,that why sum is checked 
		if(text[i]=='(')							//in cycle
			sum++;
		if(text[i]==')')
			sum--;
	}
	if(sum==0)
	return true;

return false;
}

int main(){
Mylist stk;
bool first_correct_bracket=false;
#ifndef SCRIPT_TEST
std::cout<<"Hello,I am checker of brackets.Enter..."<<std::endl;
#endif
std::string text=input();
int pad=0;
if(first_correct_bracket=textcorrect(text))
for(int i=0;i<text.size();i++)
{
	#ifdef TEST_ALG
	std::cout<<"size of list:"<<stk.size()<<std::endl
	<<"depth of brackets:"<<pad<<std::endl
	<<"symbol= "<<text[i]<<std::endl;
	#endif
	if(text[i]=='(')
	{
		stk.push('(',check_next_symbol(text,i+1) );

				#ifdef TEST_ALG
					if(check_next_symbol(text,i+1))
						pad++;
				#endif
	}
	if(text[i]==')')
	{
		stk.push(')',false);


	}
}

	if(first_correct_bracket) 				//if stack has something,it's error 
		{												//because otherwise it would mean
			#ifdef SCRIPT_TEST							//number of '(' doesnt equal number of ')'
 			FILE *f;									
    		f = fopen("output_of_lab2.txt","wt");		
    		fprintf(f, "%d",stk.count());						
    		fclose(f);
 			return 0;
 			#else
 			std::cout<<"result="<<stk.count()<<std::endl;
 			return 0;
 			#endif
		}

	#ifdef SCRIPT_TEST
 			FILE *f;
    		f = fopen("output_of_lab2.txt","wt");
    		fprintf(f, "error");
    		fclose(f);
 			return 0;
 			#else
 			std::cout<<"error"<<std::endl;
 			#endif

	return 0;
}