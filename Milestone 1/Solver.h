//$Id: Solver.h,v 1.7 2012/04/24 23:36:42 p334-70d Exp p334-70d $
//
//$Log: Solver.h,v $
//Revision 1.7  2012/04/24 23:36:42  p334-70d
//Rectified minor errors
//
//Revision 1.6  2012/04/24 22:17:17  p334-70d
//Added documentation comments
//
//Revision 1.5  2012/04/24 22:05:57  p334-70d
//Added destructor
//
//Revision 1.4  2012/04/24 22:05:24  p334-70d
//Resolved differences b/w signed and unsigned integers
//
//Revision 1.3  2012/04/24 22:03:51  p334-70d
//Fixed syntax errors
//
//Revision 1.2  2012/04/24 22:02:09  p334-70d
//Eliminated the standard namespace declaration
//
//Revision 1.1  2012/04/24 22:01:21  p334-70d
//Initial revision
//
//
//Revisions:
//@author: Aditya Jagtiani
//@author: Ramnath Anantharaman

#ifndef SOLVER_H
#define SOLVER_H
#include"Clock_config.h"
#include"River_config.h"
#include "Jam_config.h"
#include "wordCfg.h"
#include<cstdlib>
#include<map>
#include<deque>
#include<string>

template <typename T,typename CONFIGPUZZLE>
class Solver{
public: //Access
	//Default Constructor
	Solver() ;
	
	//Destructor
	~Solver();

	///This method checks whether the current configuration has already 
	///appeared in the deque
	///
	///@param cfg	a template type object of 'T', holds current configuration
	///@param visited	a deque of template type T of configurations
	///
	///return		true or false
	bool ifvisited(T,std::deque<T>);
	
	///This method invokes the generation of moves and performs BFS on them.
	///
	///@param	object	a template type object of 'CONFIGPUZZLE'
	///
	///return		void
	void solve(CONFIGPUZZLE object);
	
private: //Access 
	//Data Members declaration
	std::deque<T> config;//a double ended queue to store possible moves  
	std::deque<T> visited;//a double ended queue to store iterated configurations
	std::map<T,T> trackpath;//a map for the route taken from start to finish	
}; 

//Implementation 

//Constructor 
template<typename T,typename CONFIGPUZZLE>
Solver<T,CONFIGPUZZLE>::Solver(){}

//Destructor
template<typename T,typename CONFIGPUZZLE>
Solver<T,CONFIGPUZZLE>::~Solver(){}

//Method to check whether current config has appeared in the deque
template <typename T,typename CONFIGPUZZLE>
bool Solver<T,CONFIGPUZZLE>::ifvisited(T cfg ,std::deque < T > visited){
	
	for(unsigned int i=0; i<visited.size(); i++){
		if(visited[i] == cfg) 
			return true;
	}
	return false;
}

//Method to invoke generation of moves
template <typename T,typename CONFIGPUZZLE>
void Solver<T,CONFIGPUZZLE>:: solve(CONFIGPUZZLE object){
	
	T cfg;
	config.push_back(object.getinitial_config());
	
	while((!config.empty()) && !object.isGoal_config( config.front())){
		
		cfg = config.front();
		config.pop_front();
		if(!ifvisited(cfg, visited)){
			std::vector< T > return_moves(object.get_moves(cfg));
	        visited.push_back(cfg);
	        for(unsigned int i=0; i<return_moves.size(); i++){
		        config.push_back(return_moves[i]);
	        }
            
			for(unsigned int i=0; i< return_moves.size(); i++){
				if(!ifvisited(return_moves[i], visited))
					trackpath.insert(std::pair< T , T >(return_moves[i], cfg));
			}
		}
	}
	
	if(config.empty()){
		std::cout<<"There is no solution"<<std::endl;
	}
	
	else {
		object.display(config.front(),object.getinitial_config(),trackpath);
	}
}

#endif

