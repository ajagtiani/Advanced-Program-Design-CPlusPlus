
#ifndef WORD_CFG
#define WORD_CFG
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

///This file contains the declaration of methods and data members required 
///to solve the word ladder puzzle
///
///@author: Aditya Jagtiani

class wordCfg {

	public:
		///Constructor
		///
		///@param _initial  beginning word
		///@param _final  destination word
		///@param myMap  map containing key as starting alphabet and values as words
		wordCfg(std::string, std::string, std::map<char, std::set<std::string> >);
		
		~wordCfg();
		
		///Accessor method
		///This accessor method returns a string containing initial configration
		///@return: string containing the initial configuration
		std::string getinitial_config();

		///Accessor method	
		///This method returns a string containing the final configuration
		///@return: string containing the goal configuration
		std::string getfinal_config();


		///This method generates the moves possible from current state
		///
		///@param  configs string containing current configuration 
		///@return a vector of strings 
		std::vector<std::string> get_moves(std::string);

		///This method returns true if current state is the solution
		///
		///@param  cfg a string containing current state
		///@return true or false
		bool isGoal_config(std::string);

		///This method displays the shortest path from start to finish
		///
		///@param  cfg  a string containing the solution state
		///@param  initial  a string containing initial state
		///@param  trackpath a map containing keys as children configs and 
		///	  		value as parent configs
		///@return void
		void  display(std::string, std::string, std::map<std::string, std::string>);

		
	private: //Access

		 ///Represents the initial word
		 std::string _initial;

		 ///Represens the final word
		 std::string _final;

		 ///Map to validate words with the provided dictionary
		 std::map<char, std::set<std::string> > _myMap;

};


#endif

