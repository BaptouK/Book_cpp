#include <string>

class Emprunt {
public:
    Emprunt(int id, int id_livre, int id_membre, std::string date_emprunt, std::string date_retour)
        :id(id), id_livre(id_livre), id_membre(id_membre), date_emprunt(date_emprunt), date_retour(date_retour) {
    };
    Emprunt( int id_livre, int id_membre, std::string date_emprunt, std::string date_retour)
        :id(++last_id), id_livre(id_livre), id_membre(id_membre), date_emprunt(date_emprunt), date_retour(date_retour) {
        this->id = ++last_id;
    };

    ~Emprunt(){};

    static int getLastId() noexcept {
        return last_id;
    }

    //fait les meme chose que les setters
    int getId() const noexcept {
        return id;
    }
    void setId(int id) {
        this->id = id;
    }

    int getIdLivre() const noexcept {
        return id_livre;
    }
    void setIdLivre(int id_livre) {
        this->id_livre = id_livre;
    }
    int getIdMembre() const noexcept {
        return id_membre;
    }
    void setIdMembre(int id_membre) {
        this->id_membre = id_membre;
    }

    std::string getDateEmprunt() const noexcept {
        return date_emprunt;
    }
    void setDateEmprunt(std::string date_emprunt) {
        this->date_emprunt = date_emprunt;
    }
    std::string getDateRetour() const noexcept {
        return date_retour;
    }
    void setDateRetour(std::string date_retour) {
        this->date_retour = date_retour;
    }

private:
    inline static int last_id = 0;
    int id;
    int id_livre;
    int id_membre;
    std::string date_emprunt;
    std::string date_retour;
};
