#pragma once
#ifndef SPECIMEN_H
#define SPECIMEN_H
#include <string>
#include <list>
#include <vector>
#include <utility>

class Specimen
{
private:
	std::string idName;
	std::vector < std::pair< int, int > > markerList;
    //int score; //DONE:put in list called BELONGS
	float percentChance; 
    std::vector < std::pair< int ,char > > belongs; //  DONE:change to list of *Pairs* of < int score, char markerBelongsTo>
    
public:
	Specimen(){
		
	};
	void setID(std::string newName);
	std::string getID();
	void setNativity(int input, int indexPosition); /*
                                1 = Parent is Native
                                0 = Parent is Hybrid
                               -1 = Parent is Invasive
                            */
	int getNativity();
    char belonging(int indexPosition);
	int setSpecimenData(std::vector< std::pair< int, int > > mList, std::string identifier);
	//void writeData(Lexeme lexVect[]);
};
#endif