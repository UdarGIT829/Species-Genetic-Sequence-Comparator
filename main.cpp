#include "specimen.h"
#include <iostream>         // For testing 
#include <fstream>          // For I/O
#include <string.h>         // Guarantees strings work as expected
#include <vector>             // Each specimen is a vector
#include <utility>          // Provides 'Pair' DataStructure to populate each specimen's vector
#include <unordered_map>    // Known genotypes will be categorized as Native, Hybrid, or Invasive,
                            //  or combinations, or none
    /*
    Create table describing occurence patterns of the subject allele
                                                        A: Native only
                                                        B: Native & Hybrid
                                                        C: Hybrid only
                                                        D: Hybrid & Invasive
                                                        E: Native, Hybrid, & Invasive
                                                        F: Invasive only
                                                        G: Native & Invasive

    In the following table, occurence patterns of pairs of alleles indicate part of the heritage of the specimen. 
        Each specimen has a certain number of markers from which alleles are analyzed
        The following characters denote heritage at the marker location of the genome of the specimen
                                                        N: Native
                                                        H: Hybrid
                                                        I: Invasive
                                                        U: Uninformative (Cannot be used to determine heritage)
    */
    const char CHILDRENTABLE[8][8] =    {
                                    //AA    AB    AC    AD    AE    AF    AG    AJ  
                                    {   'N',  'N',  'U',  'H',  'U',  'H',  'U',  'U'},
                                    //BA    BB    BC    BD    BE    BF    BG    BJ
                                    {   'N',  'N',  'U',  'H',  'U',  'H',  'U',  'U'},
                                    //CA    CB    CC    CD    CE    CF    CG    CJ
                                    {   'U',  'U',  'H',  'U',  'U',  'H',  'U',  'U'},
                                    //DA    DB    DC    DD    DE    DF    DG    DJ
                                    {   'H',  'H',  'U',  'I',  'U',  'I',  'U',  'U'},
                                    //EA    EB    EC    ED    EE    EF    EG    EJ
                                    {   'U',  'U',  'U',  'U',  'U',  'U',  'U',  'U'},
                                    //FA    FB    FC    FD    FE    FF    FG    FJ
                                    {   'H',  'H',  'U',  'I',  'U',  'I',  'U',  'U'},
                                    //GA    GB    GC    GD    GE    GF    GG    GJ
                                    {   'U',  'U',  'U',  'U',  'U',  'U',  'U',  'U'},
                                    //JA    JB    JC    JD    JE    JF    JG    JJ
                                    {   'U',  'U',  'U',  'U',  'U',  'U',  'U',  'U'},
                                         };

void inputData  (
                std::vector< std::unordered_map< int, char > > &gtCat,    std::vector< std::string > &mvector, 
                std::vector< Specimen > svector,            std::unordered_map< std::string, float > sScores
                )
{
    
    // Before return:
    //  Iterating through the vector of umaps of gtCat's
    //  Populate umap of genotype's categoriescharCast
        //Pretent fstream input of csv
        //Delimit each string where temp contains one cell at a time
        std::string temp;
        std::pair<int, int> tPair;

        bool afterTabLogic = 0;

        std::string pairDelim = ",";
        size_t pairingPosition = 0;
        char tempChar;
        std::fstream dataFile;
        int Rowsize = 0, Columnsize = 0;


        Specimen emptySpec;

        dataFile.open ("SYC03-P1-P2-P3 Genotypes Table.txt");
        while(getline(dataFile, temp))
        {
            Rowsize++;
            std::cout << Rowsize << ": " << temp << std::endl;
            //svector.push_back(emptySpec);

        }
            svector.resize(Rowsize);
        std::cout << std::endl;
        dataFile.close();

        Rowsize = 0;
        dataFile.open ("SYC03-P1-P2-P3 Genotypes Table.txt");
        int genoHelper = 0;
        std::string genoSHelper = "";

        while(getline(dataFile, temp))
        {


            // Need to put integers from the Columnsize 6 & 9 into pair for the svector[Rowsize].setSpecimenData(vector<pairs>, nameOfSpecimen)


            for (size_t i = 0; i < temp.length(); i++)
            {
                tempChar = temp[i];

                if(tempChar == '\t')
                {
                    Columnsize++;
                    afterTabLogic = 1;
                }
                 if(Columnsize == 6 )// if Columnsize == 10)
                {
                    
                    std::cout << tempChar;
                    genoSHelper[genoHelper] = tempChar;
                    genoHelper++;
                }
                else if(Columnsize == 7)
                {
                    std::cout << '/t';
                    tPair.first = std::atoi(genoSHelper.c_str());
                    //std::cout << tPair.first;

                    genoHelper = 0;
                    //genoSHelper = "";
                }
                else if(Columnsize == 9)
                {
                    std::cout << tempChar;
                    genoSHelper[genoHelper] = tempChar;
                    genoHelper++;
                }
            }
            tPair.second = std::atoi(genoSHelper.c_str());
            //std::cout << tPair.second << std::endl;
            Columnsize = 0;
            std::cout << "~~~~~~~~~" << tPair.first << ',' << tPair.second << std::endl;

        }
        
        dataFile.close();                                   
                                                
                                                std::cout << "The number of specimens is: " << Rowsize-1;
                                                std::cout << "The number of Markers is: " << Columnsize-1;
    //  Create vector of marker names
    //  Create vector of unknown-specimens
    //  Create umap of unknown-specimen ID's for scores (eg: SYC456 - 80% Native)

    return;
}

void belong     (
                Specimen subject, std::unordered_map<int,char> gtCat, 
                std::unordered_map< std::string, float > sScores
                )
{

    
    return;
}

int main()
{
    std::vector< std::unordered_map< int, char > > genotypeCategories;
    //  Each marker will be organized into categories for each numerical genotype based on comparisons 
    //  of known specimens with eachother


    std::vector< std::string > markervector;
    std::vector< Specimen > uSpecvector;
    std::unordered_map< std::string, float > uSpecScores;
    inputData(genotypeCategories, markervector, uSpecvector, uSpecScores);




    return 0;
}
