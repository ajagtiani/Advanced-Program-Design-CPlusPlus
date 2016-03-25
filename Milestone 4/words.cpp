//$Id$
//$Log$


//@author: Aditya Jagtiani
//This file contains the main method and error checking mechanisms
#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<string>
#include<map>
#include "Solver.h"

using namespace std;

///This function converts a word into lower case
///
///@param  current  current word under consideration
///@return  void
void lowerCase(string &current){

	string::iterator it;
	for(it = current.begin(); it != current.end(); it++)
		*it = tolower(*it);
	}

int main(int argc, char *argv[]){

	const int STARTING_WORD = 1;
	const int GOAL_WORD = 2;
	const int DICTIONARY_FILE = 3;
	const int NO_OF_ARGS = 4;

	map<char, set<string> >  myMap;
	ifstream infile;
	string traverse;
	string alphabets = "qwertyuiopasdfghjklzxcvbnm";
	
	string begin = argv[STARTING_WORD];
	string end = argv[GOAL_WORD];
	string filename = argv[DICTIONARY_FILE];
	
	if(argc != NO_OF_ARGS) {
		cerr<<"Incorrect number of inputs"<<endl;
		exit(1);
	}	
	
	if(begin.size() != end.size()) {
		cerr<<"Start and end words should have the same size"<<endl;
		exit(1);
	}

	lowerCase(begin);
	lowerCase(end);			

	for(unsigned int i=0; i<alphabets.size(); i++){
		set<string> mySet;
		myMap.insert(pair<char, set<string> >(alphabets.at(i),mySet));	

	}

	infile.open(argv[3]);
	if(!infile){
		cerr<<"File does not exist."<<endl;
		exit(1);
	}

	while(infile>>traverse){

		if(traverse.size() == begin.size()){
            		lowerCase(traverse);
			if(myMap.count(traverse.at(0))==1){
				map<char, set<string> >::iterator it1 = myMap.find(traverse.at(0));
				(*it1).second.insert(traverse);	
			}
		}
	}
	infile.close();
		
	Solver<string,wordCfg> wordSolver;
        
    	wordCfg wordPuzzle(begin, end, myMap);

	wordSolver.solve(wordPuzzle);
	return 0;
    	
}
	
