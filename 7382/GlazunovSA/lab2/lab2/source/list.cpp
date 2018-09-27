#include <iostream>
struct left_bracket{
	bool is_atom;
	struct el_of_list*element;
};
struct right_bracket{
	struct el_of_list*element;
};
struct el_of_list{
struct left_bracket*left;
struct right_bracket*right;
};
class Mylist
{
private:
	struct el_of_list*el;
	struct el_of_list* list;
	int size_;
public:
	Mylist(){
		list = new struct el_of_list;
		list->left=NULL;
		list->right=NULL;
		el = list;
		size_=0;
	}
	int size()
	{
		return size_;
	}
	void push(char symbol,bool next_symbol)
	{
		if(symbol=='(')
		{
			el->left=new struct left_bracket;
			el->right=NULL;
			el->left->element=new struct el_of_list;
			el->left->is_atom=next_symbol;
			el=el->left->element;
			el->left=NULL;
			el->right=NULL;
		}
		if(symbol==')')
		{
			el->right=new struct right_bracket;
			el->left=NULL;
			el->right->element=new struct el_of_list;
			el=el->right->element;
			el->left=NULL;
			el->right=NULL;
		}
	}
	int count()
	{
		if(list->left==NULL&&list->right==NULL)
			return 0;

			if(list->left!=NULL)
			{
				if(list->left->is_atom)
					{
						list=list->left->element;
						return count()+1;
					}
				else
					{
						list=list->left->element;
						return count();
					}
			}

			if(list->right!=NULL)
			{
				list=list->right->element;
				return count();
			}

	}
};