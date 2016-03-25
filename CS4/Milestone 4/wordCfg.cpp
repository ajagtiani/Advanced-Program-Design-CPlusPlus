#include <iostream>
#include <deque>
#include "wordCfg.h"
#define MIN_WORD_LENGTH 1
using namespace std;

///This file implements the methods needed to solve the word puzzle
///
///@author : Aditya Jagtiani

//Constructor
wordCfg :: wordCfg(string initial, string final, map<char, set<string> > myMap):_initial(initial), _final(final), _myMap(myMap){}

wordCfg :: ~wordCfg() {}

string wordCfg :: getinitial_config() {
	return _initial;
}

string wordCfg :: getfinal_config() {
	return _final;
}

//This method generates moves
vector<string> wordCfg:: get_moves(string configs){
	
	string alphabets = "qwertyuiopasdfghjklzxcvbnm";
	vector<string> moves;	

	for(unsigned int i=0; i<configs.length(); ++i) {		
		for(unsigned int j=0; j<alphabets.length(); ++j) {
			string temp = configs;
			if(temp.at(i) != alphabets.at(j)){
				temp.at(i) = alphabets.at(j);
				}
			map<char, set<string> > :: iterator it= _myMap.find(temp.at(0));
			if(_myMap.find(temp.at(0)) != _myMap.end()){
				if(it->second.count(temp)!=0) {
					moves.push_back(temp);
				}
			}			
		}
	}
	return moves;
}

//This method returns true if the argument is goal state
bool wordCfg:: isGoal_config(string cfg){
	
	(cfg==_final)?true:false;
}

//Method for displaying path to shortest path to goal
void wordCfg:: display(string cfg, string initial, map<string, string> trackpath){

	deque<string> route;
	route.push_back(cfg);	
	map<string, string> :: const_iterator it1 = trackpath.find(cfg);

	while(it1->second != initial){

            it1 = trackpath.find(cfg);
            route.push_front(it1->second);
    	    cfg = it1->second;
    }


		if(route.size() == MIN_WORD_LENGTH){
		
			cout<<"Step 0: "<<initial<<endl;
			cout<<"Step 1: "<<cfg<<endl;
			}

	else{

		for(unsigned int i=0; i<route.size(); ++i){
			cout<<"Step "<<i<<": "<<route[i]<<endl;

		}cout<<endl;	
	}
}




