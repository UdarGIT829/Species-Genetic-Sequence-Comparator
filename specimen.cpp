#include "specimen.h"

Specimen::Specimen()
{
}
void Specimen::setID(std::string newName)
{
	idName = newName;
}
void Specimen::setNativity(int input, int indexPosition)
{
	belongs[indexPosition].first += input;
}
std::string Specimen::getID()
{
	return idName;
}
int Specimen::getNativity()
{
    char tempBucket;
    int informativeSize = belongs.size();
	for (size_t i = 0; i < belongs.size(); i++)
    {
        tempBucket = belongs[i].second;
        switch (tempBucket)
        {
        case 'N':
            /* code */
            break;
        case 'I':

            break;
        case 'H':
            
            break;
        case 'U':
            informativeSize--;
            break;
        default:
            break;
        }

        /* code */
    }
    
}
char Specimen::belonging(int indexPosition)
{
    
    switch (belongs[indexPosition].first)
    {
    case 2:
        belongs[indexPosition].second = 'N';
        break;
    case -2:
        belongs[indexPosition].second = 'I';
        break;
    case 0:
        belongs[indexPosition].second = 'H';
        break;
    case 1:
        belongs[indexPosition].second = 'U';
        break;
    case -1: 
        belongs[indexPosition].second = 'U';
        break;
    default:
        break;
    }
    return belongs[indexPosition].second;
}

int Specimen::setSpecimenData(std::vector< std::pair< int, int > > mList, std::string identifier)
{
    for (size_t i = 0; i < mList.size(); i++)
    {
        markerList.push_back(mList[i]);
    }
    
    return 0;
}