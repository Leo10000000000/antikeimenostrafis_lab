#include <iostream>
#include <string>
#include <vector>

using namespace std;

int protein_count;

class Protein {
    private:
        string id;
        string name;
        string sequence;

    public:
        Protein(string id_0, string name_0, string sequence_0)
            : id(id_0), name(name_0), sequence(sequence_0){
                protein_count += 1;
                cout << "Protein: " << name << " is initialized" << endl;
            }

        ~Protein(){
            protein_count -=1;
            cout << "Protein: " << name << " was destroyed" << endl;
        }

        void setID(string newID){id = newID;}
        void setNAME(string newNAME){name = newNAME;}
        void setSEQUENCE(string newSEQ){sequence = newSEQ;}
        
        string getID() const {return id;}
        string getNAME() const {return name;}
        string getSEQUENCE() const {return sequence;}
        
        string describe() const {return "protein " + name + " " + sequence;}

        int length(){return sequence.length();};
};

int gene_count;

class Gene {
    private:
        string id;
        string name;
        string chrom;
        int start;
        int end;
        char strand;

    public:
        Gene(string id_0, string name_0, string chrom_0, int start_0, int end_0, char strand_0)
            : id(id_0), name(name_0), chrom(chrom_0), start(start_0), end(end_0), strand(strand_0){
                gene_count += 1;
                cout << "Gene: " << name << " is initialized" << endl;
            }

        ~Gene(){
            gene_count -= 1;
            cout << "Gene: " << name << " was destroyed" << endl;
        }

        void setID(string newID){id = newID;}
        void setNAME(string newNAME){name = newNAME;}
        void setChrom(string newChrom){chrom = newChrom;}
        void setStart(int newStart){start = newStart;}
        void setEnd(int newEnd){end = newEnd;}
        void setStrand(char newStrand){strand = newStrand;}

        string describe() const {return "Gene " + name + " (" + chrom + ":" + to_string(start) + "-" + to_string(end) + ", " + string(1, strand) + ").";}
};



int main(){

    vector <Protein> prot_vec;
    vector <Gene> gene_vec;

    prot_vec.reserve(2);
    gene_vec.reserve(2);

    prot_vec.emplace_back("ENSP1234", "PTEN", "MTAIIKEIVSRNKBRRYQEDGFDLDLTYIYPNIIAMGFPA");

    prot_vec.emplace_back("ENSP5678", "BRCA1_prot", "MSLQRET");


    gene_vec.emplace_back("ENSG1234", "BRCA1", "chr17", 43044295, 43170245, '+');

    gene_vec.emplace_back("ENSG5678", "PTEN_gene", "chr10", 87863115, 87958325, '-');


    for(size_t i = 0; i < prot_vec.size(); i++){
        cout << prot_vec[i].describe() << endl;
        cout << "length: " << prot_vec[i].length() << endl;
    }
    
    for(size_t i = 0; i < gene_vec.size(); i++)
        cout << gene_vec[i].describe() << endl;


    
    //cout << "protein_count: " << protein_count << endl;
    //cout << "gene_count: " << gene_count << endl;

    return 0;
}