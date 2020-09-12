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
	int m1num,m2num, ingrnum;
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
	
	srand(time(0));



	int ingredients=rand()%MAX_INGREDIENTS;
	//std::cerr<<ingredients;

	int streams=0;
	bool ok=1;

	while((ingredients>0 || streams>1) || ok){
		//std::cerr<<'.';
		ok=true;
		switch(rand()%5){
			case 0:
				//std::cerr<<0;
				if(ingredients>0){
					std::cout<<"i"<<rand()%ingrnum<<" ";
					ingredients--;
					streams++;
					break;
				}
			case 1:
				//std::cerr<<1;
			case 2:
				//std::cerr<<2;
				if(streams>0){
					std::cout<<"m"<<rand()%m1num<<' ';
					break;
				}
			case 3:
				//std::cerr<<3;
				if(streams>1){
					std::cout<<"M"<<rand()%m2num<<' ';
					streams--;
					break;
				}
			default:
				ok=false;
		}
	}
	return 0;
}
