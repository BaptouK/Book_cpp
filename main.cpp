#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "livres.cpp"
#include "membres.cpp"
#include "emprunts.cpp"

void test_import_affichage(std::vector<Livre> livres,std::vector<Membre> membres,std::vector<Emprunt> emprunts) {
    Livre livre1("titre1","auteur1",2023,true);
    Membre membre1("name1","prenom1","mail1");
    Emprunt emprunt1(1,1,"2023-10-01","2023-10-15");

    std::cout << "nombres de livres " << livres.size() << std::endl;
    for (int i = 0; i < livres.size(); i++) {
        std::cout << livres[i].getTitre() << std::endl;
    }

    std::cout << "nombres de Membres " << membres.size() << std::endl;
    for (int i = 0; i < membres.size(); i++) {
        std::cout << membres[i].getName() << " " << membres[i].getPrenom() << std::endl;
    }

    std::cout << "nombres d'emprunts " << emprunts.size() << std::endl;
    for (int i = 0; i < emprunts.size(); i++) {
        std::cout << emprunts[i].getId() << std::endl;
    }
};

int load_livre(std::string const &folder, std::vector<Livre>& livres, std::string& Header_livre) {

    std::ifstream file(folder);

    if (file.is_open()) {
        std::string line;
        std::getline(file,Header_livre);

        while (std::getline(file,line)) {
            //std::cout << line << std::endl;
            std::istringstream stream(line);

            std::string id;
            std::getline(stream, id, ',');

            std::string titre;
            std::getline(stream, titre, ',');

            std::string auteur;
            std::getline(stream, auteur, ',');

            std::string annee;
            std::getline(stream, annee, ',');

            std::string available;
            std::getline(stream, available, ',');

            bool bool_avaible;
            if (available=="oui") {
                bool_avaible =true;
            } else {
                bool_avaible = false;
            }


            //std::cout << "annee : "<< annee << std::endl;
            //std::cout << "dispo : "<< bool_avaible << std::endl;

            int int_id {std::stoi(id)};
            int int_annee {std::stoi(annee)};

            Livre livre(int_id,titre,auteur,int_annee,bool_avaible);
            livres.push_back(livre);
        }
        return 0;
    }  else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }
};
int load_membres(std::string const &folder, std::vector<Membre>& membres, std::string& Header_membre) {

    std::ifstream file(folder);

    if (file.is_open()) {
        std::string line;
        std::getline(file,Header_membre);

        while (std::getline(file,line)) {
            //std::cout << line << std::endl;

            std::string id;
            std::istringstream stream(line);
            std::getline(stream, id, ',');

            std::string name;
            std::getline(stream, name, ',');

            std::string prenom;
            std::getline(stream, prenom, ',');

            std::string mail;
            std::getline(stream, mail, ',');

            int int_id {std::stoi(id)};

            Membre membre(int_id,name,prenom,mail);
            membres.push_back(membre);
        }
        return 0;
    }  else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }
};
int load_emprunts(std::string const &folder, std::vector<Emprunt>& emprunts,std::string& Header_emprunt) {

    std::ifstream file(folder);

    if (file.is_open()) {
        std::string line;
        std::getline(file,Header_emprunt);

        while (std::getline(file,line)) {
            //std::cout << line << std::endl;
            std::istringstream stream(line);

            std::string id;
            std::getline(stream, id, ',');

            std::string id_livre;
            std::getline(stream, id_livre, ',');

            std::string id_membre;
            std::getline(stream, id_membre, ',');

            std::string date_emprunt;
            std::getline(stream, date_emprunt, ',');

            std::string date_retour;
            std::getline(stream, date_retour, ',');

            int int_id {std::stoi(id)};
            int int_id_livre {std::stoi(id_livre)};
            int int_id_membre{std::stoi(id_membre)};

            if (date_retour=="") {
                date_retour = "0000-00-00";
            }

            Emprunt emprunt(int_id,int_id_livre,int_id_livre,date_emprunt,date_retour);
            emprunts.push_back(emprunt);
        }
        std::getline(file,line);

        return 0;
    }  else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }
};

void affichage_livre(std::vector<Livre>& livres,std::string& Header_livre) {
    std::cout << Header_livre << std::endl;
    std::cout << "--------------------------" << std::endl;
    for ( auto livre : livres) {
    std:: cout << "ID : " << livre.getId();
    std:: cout << " " << livre.getTitre();
    std:: cout << " " << livre.getAuteur();
    std:: cout << " " << livre.getAnnee();
    std::string dispo {livre.getAvailable() ? "disponible" : "non disponible"};
    std:: cout << " " << dispo << std::endl;
    std::cout << "--------------------------" << std::endl;
    };
};
void affichage_membre(std::vector<Membre>& membres,std::string& Header_membre) {
    std::cout << Header_membre << std::endl;
    std::cout << "--------------------------" << std::endl;
    for ( auto membre : membres) {
    std:: cout << "ID : " << membre.getId();
    std:: cout << " " << membre.getName();
    std:: cout << " " << membre.getPrenom();
    std:: cout << " " << membre.getMail();
    std::cout << "\n--------------------------" << std::endl;
    };
};

void add_livre(std::vector<Livre>& livres) {
    std::cout << "Entrez le titre du livre : "<< std::endl;
    std::string name;
    std::getline(std::cin,name);

    std::cout << "Entrez le nom de l'auteur du livre : "<< std::endl;
    std::string auteur;
    std::getline(std::cin,auteur);

    std::cout << "Entrez l'année de sortie: "<< std::endl;

    std::string annee;
    std::getline(std::cin,annee);

    int int_annee{std::stoi(annee)};

    std::cout << "Voulez vous ajoutez " << name << " a la bibliotheque ? (oui/non) : "<< std::endl;
    std::string reponse;
    std::getline(std::cin,reponse);
    if (reponse != "oui") {
        std::cout << "Livre non ajouté" << std::endl;
    }else {
        Livre livre(name,auteur,int_annee,true);
        livres.push_back(livre);
        std::cout << "Livre ajouté : " << livre.getTitre() << std::endl;
    }

}
void add_membre(std::vector<Membre>& membres) {

    std::cout << "Entrez le prenom du membre : "<< std::endl;
    std::string prenom;
    std::getline(std::cin,prenom);

    std::cout << "Entrez le nom du membre : "<< std::endl;
    std::string name;
    std::getline(std::cin,name);

    std::cout << "Entrez l'email du membre : "<< std::endl;
    std::string mail;
    std::getline(std::cin,mail);

    std::cout << "Voulez vous ajoutez " << prenom << " "<< name << " aux membres ? (oui/non) : "<< std::endl;
    std::string reponse;
    std::getline(std::cin,reponse);
    if (reponse != "oui") {
        std::cout << "Membre non ajouté" << std::endl;
    }else {
        Membre membre(name,prenom,mail);
        membres.push_back(membre);
        std::cout << "Membre ajouté : " << membre.getName() << std::endl;
    }
}
void emprunter(std::vector<Emprunt>& emprunts,std::vector<Membre>& membres,std::vector<Livre>& livres,std::string Header_livre,std::string  Header_membre,std::string  Header_emprunt) {

    affichage_membre(membres,Header_membre);

    std::string id_membre;
    std::cout << "Entrez votre ID de membre : "<< std::endl;
    std::getline(std::cin,id_membre);
    int int_id_membre{std::stoi(id_membre)};

    if (int_id_membre > Membre::getLastId()) {
        std::cout << "ID de membre non valide" << std::endl;
        return;
    }

    affichage_livre(livres,Header_livre);

    std::string id_livre;
    std::cout << "Entrez L'id du livre que vous souhaitez emprunter : "<< std::endl;
    std::getline(std::cin,id_livre);
    int int_id_livre{std::stoi(id_livre)};

    if (int_id_livre > Livre::getLastId()) {
        std::cout << "ID de membre non valide" << std::endl;
        return;
    }

    for (auto& livre : livres) {
        if (livre.getId()==int_id_livre) {

            if (livre.getAvailable()) {
                std::cout << "Livre emprunté : " << livre.getTitre() << std::endl;
                std::cout << "Entrez la date d'emprunt format (AAAA-MM-DD) : "<< std::endl;
                std::string date;
                std::getline(std::cin,date);

                std::cout << "Voulez vous empruntez " << livre.getTitre() << " ? (oui/non) : "<< std::endl;
                std::string reponse;
                std::getline(std::cin,reponse);

                if (reponse != "oui") {
                    std::cout << "Livre non emprunte" << std::endl;
                }else {
                    livre.setAvailable(false);

                    Emprunt emprunt(int_id_livre,int_id_membre,date);
                    emprunts.push_back(emprunt);
                    std::cout << "Vous avez correctement emprunte : " << livre.getTitre() << std::endl;
                }
                break;
            } else {
                std::cout << "Le livre "<< livre.getTitre() << " est non disponible" << std::endl;
                return;
            }
        }
    }




}

void save_livre(std::vector<Livre>& livres,std::string& file_name,std::string& Header_livre) {
    std::ofstream file("../data/"+file_name+".csv");
    if (file.is_open()) {
        file << Header_livre << std::endl;
        for (int i = 0; i < livres.size(); i++) {
            file << livres[i].getId() << "," << livres[i].getTitre() << "," << livres[i].getAuteur() << "," << livres[i].getAnnee() << "," << livres[i].getAvailable() << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}
void save_membre(std::vector<Membre>& membres,std::string& file_name,std::string& Header_membre) {
    std::ofstream file("../data/"+file_name+".csv");
    if (file.is_open()) {
        file << Header_membre << std::endl;
        for (int i = 0; i < membres.size(); i++) {
            file << membres[i].getId() << "," << membres[i].getName() << ","<< membres[i].getPrenom() << "," << membres[i].getMail() << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}
void save_emprunt(std::vector<Emprunt>& emprunts,std::string& file_name,std::string& Header_emprunt) {
    std::ofstream file("../data/"+file_name+".csv");
    if (file.is_open()) {
        file << Header_emprunt << std::endl;
        for (int i = 0; i < emprunts.size(); i++) {
            file << emprunts[i].getId() << "," <<emprunts[i].getIdLivre() << ","<< emprunts[i].getIdMembre() << ","<<emprunts[i].getDateEmprunt() <<"," << emprunts[i].getDateRetour() << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

void rendre_livre(std::vector<Livre>& livres,std::vector<Emprunt>& emprunts) {

    for (auto& livre :livres) {
        if (!livre.getAvailable()) {
            std:: cout << "ID : " << livre.getId();
            std:: cout << " " << livre.getTitre();
            std:: cout << " " << livre.getAuteur();
            std:: cout << " " << livre.getAnnee();
            std::string dispo {livre.getAvailable() ? "disponible" : "non disponible"};
            std:: cout << " " << dispo << std::endl;
            std::cout << "--------------------------" << std::endl;
        }
    }

    std::string id_livre;
    std::cout << "Entrez L'id du livre que vous souhaitez rendre : "<< std::endl;
    std::getline(std::cin,id_livre);

    int int_id_livre {std::stoi(id_livre)};

    for (auto& livre : livres) {
        if (livre.getId()==int_id_livre) {
            livre.setAvailable(true);
            std::cout << "Livre rendu : " << livre.getTitre() << std::endl;
            std::string date_retour;
            std::cout << "Entrez la date de retour format (AAAA-MM-DD) : "<< std::endl;
            std::getline(std::cin,date_retour);
            for (auto& emprunt : emprunts) {
                if (emprunt.getIdLivre()==int_id_livre) {
                    emprunt.setDateRetour(date_retour);
                    std::cout << "Livre rendu : " << livre.getTitre() << std::endl;
                    break;
                }
            }
        }
    }
}

inline static std::string Header_livre;
inline static std::string Header_membre;
inline static std::string Header_emprunt;

int main() {

    std::vector<Livre> livres;
    std::vector<Membre> membres;
    std::vector<Emprunt> emprunts;

    load_livre("../livre.csv",livres,Header_livre);
    load_membres("../membre.csv",membres,Header_membre);
    load_emprunts("../emprunt.csv",emprunts,Header_emprunt);

    while (true) {
        std::cout << "Commandes disponibles : \n";
        std::cout << "Voir les livres : lib\n";
        std::cout << "Voir les membres : mem\n";
        std::cout << "Ajouter un livre : add_lib\n";
        std::cout << "Ajouter un membre : add_mem\n";
        std::cout << "Emprunter un livre: emprunter\n";
        std::cout << "Rendre un livre: rendre\n";
        std::cout << "Pour sauvegarder les donnees : save\n";
        std::cout << "Pour quitter le programme : exit ou x " << std::endl;

        std::string command;
        std::getline(std::cin,command);


        if (command == "lib") {
            affichage_livre(livres,Header_livre);
        }
        else if (command == "mem") {
            affichage_membre(membres, Header_membre);
        }
        else if (command == "add_lib") {
            add_livre(livres);
        }
        else if (command == "add_mem") {
            add_membre(membres);
        }
        else if (command == "emprunter") {
            emprunter(emprunts,membres,livres,Header_livre,Header_membre,Header_emprunt);
        }
        else if (command=="exit" or command=="x") {
            std::cout << "See you next time!" << std::endl;
            break;
        }else if (command=="rendre") {
            rendre_livre(livres,emprunts);
        }
        else if (command=="save") {
            std::cout << "Entrez le nom de sauvegarde des livres : "<< std::endl;
            std::string name_livre;
            std::getline(std::cin,name_livre);
            save_livre(livres,name_livre,Header_livre);

            std::cout << "Entrez le nom de sauvegarde des membres : " << std::endl;
            std::string name_membre;
            std::getline(std::cin,name_membre);
            save_membre(membres,name_membre,Header_membre);

            std::cout << "Entrez le nom de sauvegarde des emprunts : "<< std::endl;
            std::string name_emprunt;
            std::getline(std::cin,name_emprunt);
            save_emprunt(emprunts,name_emprunt,Header_livre);

        }
        else {
            std::cout << "Commande non reconu : "<< command << std::endl;
        }
        _sleep(3000);

    }

    return 0;
}
