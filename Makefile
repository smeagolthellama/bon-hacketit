CCFLAGS= -Weverything -Wall -Wextra
CXX= clang++ $(CCFLAGS)

all: gen recipeQ.txt recipesample.txt
gen: gen.cpp
recipeQ.txt: gen
	for i in $$(seq 1 10); do ./gen >> recipeQ.txt ; echo >>recipeQ.txt ; done

recipesample.txt: recipeQ.txt parse.pl
	head -n 1 recipeQ.txt |perl parse.pl >recipesample.txt
