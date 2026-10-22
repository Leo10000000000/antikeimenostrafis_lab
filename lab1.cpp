#include <iostream>
#include <string>

using namespace std;

class Protein {
    private:
        string id;
        string name;
        string sequence;

    public:
        void setID(string newID){id = newID;}
        void setNAME(string newNAME){name = newNAME;}
        void setSEQUENCE(string newSEQ){sequence = newSEQ;}
        
        string getID(){return id;}
        string getNAME(){return name;}
        string getSEQUENCE(){return sequence;}
        
        string describe(){return "protein " + name + " " + sequence;}

        int length(){return sequence.length();};
};

class Gene {
    private:
        string id;
        string name;
        string chrom;
        int start;
        int end;
        char strand;

    public:
        void setID(string newID){id = newID;}
        void setNAME(string newNAME){name = newNAME;}
        void setChrom(string newChrom){chrom = newChrom;}
        void setStart(int newStart){start = newStart;}
        void setEnd(int newEnd){end = newEnd;}
        void setStrand(char newStrand){strand = newStrand;}

        string getID(){return id;}
        string getNAME(){return name;}
        string getChrom(){return chrom;}
        int getStart(){return start;}
        int getEnd(){return end;}
        char getStrand(){return strand;}

        string describe(){return "Gene " + name + " (" + chrom + ":" + to_string(start) + "-" + to_string(end) + ", " + to_string(strand) + ").";}
};



int main(){
    
    Protein P1;
    P1.setID("ENSP1234");
    P1.setNAME("PTEN");
    P1.setSEQUENCE("MTAIIKEIVSRNKBRRYQEDGFDLDLTYIYPNIIAMGFPA");

    Protein P2;
    P2.setID("ENSP5678");
    P2.setNAME("BRCA1_prot");
    P2.setSEQUENCE("MSLQRET");


    Gene G1;
    G1.setID("ENSG1234");
    G1.setNAME("BRCA1");
    G1.setChrom("chr17");
    G1.setStart(43044295);
    G1.setEnd(43170245);
    G1.setStrand('+');

    Gene G2;
    G2.setID("ENSG5678");
    G2.setNAME("PTEN_gene");
    G2.setChrom("chr10");
    G2.setStart(87863115);
    G2.setEnd(87958325);
    G2.setStrand('-');


    cout << P1.describe() << endl;
    cout << P1.length() << endl;
    cout << P2.describe() << endl;
    cout << G1.describe() << endl;
    cout << G2.describe() << endl;

    
    return 0;
}