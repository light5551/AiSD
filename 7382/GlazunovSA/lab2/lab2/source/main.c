#include<iostream>
#include<stack>//for stack))))
#include<string>
#include<cstdio>
//#define SCRIPT_TEST
//#define TEST_ALG
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
	int i=0;	
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
	return true;
}

int main(){
std::stack<char>stk;
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
	std::cout<<"size of stack:"<<stk.size()<<std::endl
	<<"depth of brackets:"<<pad<<std::endl
	<<"size of stack:"<<stk.size()<<std::endl
	<<"symbol= "<<text[i]<<std::endl;
	#endif
	if(text[i]=='(')
	{
		 stk.push('(');
		 if(check_next_symbol(text,i+1))//it there continue except ' ' ? 
		 {								//if there isn't,this brackets are atomic
		 	pad++;
		 }
	}
	if(text[i]==')')
	{
			if(!stk.empty())
			stk.pop();
	}
}

	if(stk.empty()&&first_correct_bracket) 				//if stack has something,it's error 
		{												//because otherwise it would mean
			#ifdef SCRIPT_TEST							//number of '(' doesnt equal number of ')'
 			FILE *f;									
    		f = fopen("output_of_lab2.txt","wt");		
    		fprintf(f, "%d",pad);						
    		fclose(f);
 			return 0;
 			#else
 			std::cout<<"result="<<pad<<std::endl;
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