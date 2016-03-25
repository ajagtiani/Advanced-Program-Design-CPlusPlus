//$Id: clock.cpp,v 1.3 2012/04/25 00:04:48 p334-70d Exp p334-70d $
//$Log: clock.cpp,v $
//Revision 1.3  2012/04/25 00:04:48  p334-70d
//Implemented string streams
//
//Revision 1.2  2012/04/25 00:04:06  p334-70d
//Added error conditions
//
//Revision 1.1  2012/04/25 00:02:56  p334-70d
//Initial revision
//

//Author: Ramnath Ananthraman
//Contributor: Aditya Jagtiani

#include<iostream>
#include<stdlib.h>
#include"Solver.h"
#include<string>
#include<sstream>

using namespace std;

int main(int argc, char * argv[]){
	
	int total_state, initial_state, final_state;
	
	if(argc!=4){
		cerr<<"Invalid number of inputs. Enter 3 values only."<<endl;
		exit(1);
	} 
	
	istringstream iss1(argv[1]);
	iss1>>total_state;
	if(!iss1.eof() || iss1.fail()){
		cerr<<"Invalid input"<<endl;
		exit(1);
	}
	
	istringstream iss2(argv[2]);
	iss2>>initial_state;
	if(!iss2.eof() || iss2.fail()){
		cerr<<"Invalid input"<<endl;
		exit(1);
	}
	
	istringstream iss3(argv[3]);
	iss3>>final_state;
	if(!iss3.eof() || iss3.fail()){
		cerr<<"Invalid input"<<endl;
		exit(1);
	}
	
	if((total_state <= 0)||(initial_state <= 0)||(final_state <= 0)) {
		cerr<<"Invalid input"<<endl;
		exit(1);
	}
	
	if((initial_state > total_state) || (final_state > total_state)) {
		cerr<<"Configuration not possible."<<endl;
		exit(1);
	}
	
	if(initial_state == final_state){
		cout<<"You have reached your destination."<<endl;
		exit(1);
	}
	  	
    Solver<int,Clock_config> clockpuzzle;
	Clock_config clock_obj(total_state,initial_state,final_state);
	clockpuzzle.solve(clock_obj);
	return 0;
}


