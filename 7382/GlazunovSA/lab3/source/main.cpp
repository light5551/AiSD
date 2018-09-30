#include<iostream>
#include"stack.cpp"
//#define TEST
int main(){
	Mystack<char> stack(10);
	std::string text;
	getline(std::cin,text);
	for(int i=0;i<text.size();i++)
	{
		stack.push(text[i]);
	}
	for(int i=0;i<text.size();i++)
	{
				#ifdef TEST
					std::cout<<"POP"<<"   ";
					std::cout<<"TOP:"<<stack.top()<<"  ";
					std::cout<<"SIZE:"<<stack.size()<<std::endl;
					stack.pop();
				#else	
					std::cout<<stack.pop();
				#endif
	}

	std::cout<<std::endl;
return 0;
}
