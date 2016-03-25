//$Id: river.cpp,v 1.6 2012/04/25 23:52:26 p334-70d Exp p334-70d $
//$Log: river.cpp,v $
//Revision 1.6  2012/04/25 23:52:26  p334-70d
//Added another error condition
//
//Revision 1.5  2012/04/25 23:36:56  p334-70d
//Final changes
//
//Revision 1.4  2012/04/24 21:45:10  p334-70d
//Fixed syntax errors
//
//Revision 1.3  2012/04/24 21:44:36  p334-70d
//Implemented stringstream logic
//
//Revision 1.2  2012/04/24 21:44:08  p334-70d
//Added error conditions
//
//Revision 1.1  2012/04/24 21:42:15  p334-70d
//Initial revision
//
//Author: Aditya Jagtiani
//Author: Ramnath Ananthraman

#include <iostream>
#include "Solver.h"
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
	
	int num_prof, num_student;
	
	if(argc!=3) {
		cerr<<"Invalid number of inputs. Enter 2 values only."<<endl;
		exit(1);
	}
			
	istringstream iss1(argv[1]);
	iss1>>num_prof;
	if(!iss1.eof() || iss1.fail()){
		cerr<<"Invalid input."<<endl;
		exit(1);
	}
	
	istringstream iss2(argv[2]);
	iss2>>num_student;
	if(!iss2.eof() || iss2.fail()){
		cerr<<"Invalid input."<<endl;
		exit(1);
	}
	
	if((num_prof!=0) && (num_student > num_prof)) {
		cerr<<"Invalid configuration."<<endl;
		exit(1);
	}
	
	if(num_prof<0 || num_student<0) {
		cerr<<"Invalid input. Enter non negative values only."<<endl;
		exit(1);
	}
	
	if(num_prof==0 && num_student==0) {
		cout<<"There is nobody to board the boat."<<endl;
		exit(1);
	}
	vector<int>fconfig;
	fconfig.push_back(0);
	fconfig.push_back(0);
	fconfig.push_back(num_prof);
	fconfig.push_back(num_student);
	fconfig.push_back(1);
	
	Solver<vector<int>,River_config> riverpuzzle;
	River_config river_obj(num_prof,num_student,0,0,fconfig);
	riverpuzzle.solve(river_obj);
	
	return 0;
}
