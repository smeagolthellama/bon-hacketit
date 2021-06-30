#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#ifndef MAX_INGREDIENTS
#define MAX_INGREDIENTS 10
#endif

int main(){
	std::ifstream m1("methods1.txt");
	std::ifstream m2("methods2.txt");
	std::ifstream ingr("ingredients.txt");
	unsigned int m1num,m2num, ingrnum;
	m1num=m2num=ingrnum=0;
	std::string unused;
	while(std::getline(m1,unused)){
		m1num++;
	}
	while(std::getline(m2,unused)){
		m2num++;
	}
	while(std::getline(ingr,unused)){
		ingrnum++;
	}
	//std::cerr<<m1num<<' '<<m2num<<' '<<ingrnum<<'\n';
	
	unsigned int *ingredient_map=static_cast<unsigned int*>(calloc(sizeof(int),ingrnum));
	unsigned int last_method1;
	unsigned int last_method2;

	srand(time(nullptr));



	unsigned int ingredients=rand()%MAX_INGREDIENTS;
	unsigned int ingredient;
	//std::cerr<<ingredients;

	unsigned int streams=0;
	bool ok=1;

	while((ingredients>0 || streams>1) || ok){
		//std::cerr<<'.';
		ok=true;
		switch(rand()%5){
			case 0:
				//std::cerr<<0;
				if(ingredients>0){
					do{
						ingredient=(rand()%ingrnum);
					}while(ingredient_map[ingredient]==1);
					ingredient_map[ingredient]=1;
					std::cout<<"i"<<ingredient<<" ";
					ingredients--;
					streams++;
					break;
				}
			case 1:
				//std::cerr<<1;
			case 2:
				//std::cerr<<2;
				if(streams>0){
					unsigned int method=rand()%m1num;
					while(method==last_method1){
						method=rand()%m1num;
					}
					std::cout<<"m"<<method<<' ';
					break;
				}
			case 3:
				//std::cerr<<3;
				if(streams>1){
					unsigned int method=rand()%m2num;
					while(method==last_method2){
						method=rand()%m2num;
					}
					std::cout<<"M"<<method<<' ';
					streams--;
					break;
				}
			default:
				ok=false;
		}
	}
	return 0;
}
