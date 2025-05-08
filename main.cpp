#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "livres.cpp"
#include "membres.cpp"
#include "emprunts.cpp"

int load_livre(std::string const &folder, std::vector<Livre>& livres) {

    std::ifstream file(folder);

    if (file.is_open()) {
        std::string line;
        std::string first_line;
        std::getline(file,line);

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

int load_membres(std::string const &folder, std::vector<Membre>& membres) {

    std::ifstream file(folder);

    if (file.is_open()) {
        std::string line;
        std::string first_line;
        std::getline(file,line);

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

int load_emprunts(std::string const &folder, std::vector<Emprunt>& emprunts) {

    std::ifstream file(folder);

    if (file.is_open()) {
        std::string line;
        std::string first_line;
        std::getline(file,line);

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
}

void save_livre(std::vector<Livre> livres,std::vector<Membre> membres,std::vector<Emprunt> emprunts,std::string file_name) {
    std::ofstream file("../data/"+file_name+".csv");
    if (file.is_open()) {
        file << "id_livre,titre,auteur,annee,disponible" << std::endl;
        for (int i = 0; i < livres.size(); i++) {
            file << livres[i].getId() << "," << livres[i].getTitre() << "," << livres[i].getAuteur() << "," << livres[i].getAnnee() << "," << livres[i].getAvailable() << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

int main() {

    std::vector<Livre> livres;
    std::vector<Membre> membres;
    std::vector<Emprunt> emprunts;

    load_livre("../livre.csv",livres);
    load_membres("../membre.csv",membres);
    load_emprunts("../emprunts.csv",emprunts);


    while (true) {
        _sleep(3000);
        std::cout << "Commandes disponibles : \n";
        std::cout << "Voir les livres : lib\n";
        //std::cout << "Voir les membres : member\n";
        //std::cout << "Voir les emprunts : emprunt\n";
        std::cout << "Ajouter un livre : add_lib\n";
        //std::cout << "Ajouter un membre : add_member\n";
        //std::cout << "Ajouter un emprunt : add_emprunt\n";
        std::cout << "Pour sauvegarder les donnees : save\n";
        std::cout << "Pour quitter le programme : exit" << std::endl;

        std::string command;
        std::getline(std::cin,command);


        if (command == "lib") {
            test_import_affichage(livres,membres,emprunts);
        }else if (command == "add_lib") {
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

            Livre livre(name,auteur,int_annee,true);
            livres.push_back(livre);
            std::cout << "Livre ajouté : " << livre.getTitre() << std::endl;
        }
        else if (command=="exit" or command=="x") {
            std::cout << "See you next time!" << std::endl;
            break;
        }else if (command=="save") {
            std::cout << "Entrez le nom du ficher : ";
            std::string name;
            std::getline(std::cin,name);

            save_livre(livres,membres,emprunts,name);
        }
        else {
            std::cout << "Commande non reconu : "<< command << std::endl;
        }


    }

    return 0;
}
