//Clock_config
//$Id: Clock_config.cpp,v 1.6 2012/04/25 01:07:49 p334-70d Exp p334-70d $
//
//$Log: Clock_config.cpp,v $
//Revision 1.6  2012/04/25 01:07:49  p334-70d
//Added step numbers
//
//Revision 1.5  2012/04/25 01:03:43  p334-70d
//Added const notations
//
//Revision 1.4  2012/04/25 00:51:25  p334-70d
//Executing normally
//
//Revision 1.3  2012/04/25 00:50:00  p334-70d
//Fixed indentation
//
//Revision 1.2  2012/04/25 00:50:00  p334-70d
//Added comments
//
//Revision 1.1  2012/04/25 00:48:40  p334-70d
//Initial revision
//
//@author: Ramnath Anantharaman
//@contributor: Aditya Jagtiani

#include"Clock_config.h"

using namespace std;

//Constructor
Clock_config::Clock_config(int hours,int start,int end): total_hours(hours), initial_config(start), final_config(end){}

//Destructor
Clock_config :: ~Clock_config(){}

int Clock_config::getinitial_config () const{
	return initial_config;
}

int Clock_config::getfinal_config () const{
	return final_config;
}

//This method generates the moves possible for the clock puzzle
vector<int> Clock_config::get_moves(int cfg){
	int move_left;
   	int move_right;
   	vector<int> moves;
	
	if(cfg==total_hours){
		move_left=cfg-1;
	   	move_right=1;		
   		moves.push_back(move_left);
   		moves.push_back(move_right);
	}
	else if(cfg==1){
		move_left=total_hours;
		move_right=cfg+1;		
		moves.push_back(move_left);
   		moves.push_back(move_right);
	}
	else{
		move_left=cfg-1;
		move_right=cfg+1;		
		moves.push_back(move_left);
		moves.push_back(move_right);
	}
	return moves;
}
//this method displays the shortest path to reach the goal state

void Clock_config::display(int cfg, int initial_config , map<int,int> trackpath){
	
	deque<int> path;
	path.push_back(cfg);
	map<int,int> :: iterator it=trackpath.find(cfg);
		
	while(it->second != initial_config){
		it = trackpath.find(cfg);
		path.push_front(it->second);
		cfg = it->second;	
	}
	
	if(path.size()==1){
		cout<<"Step 0: "<<initial_config<<endl;
		cout<<"Step 1: "<<cfg<<endl;             
	}
	
	else{
		for(unsigned int i=0; i<path.size(); i++){
			cout<<"Step "<<i<<": "<<path.at(i)<<endl;                                 
		}
	}
}

bool Clock_config::isGoal_config(int config) const{
	
	if(config==final_config){
		return true;
	}
	return false;
}
