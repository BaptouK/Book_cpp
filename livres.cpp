#include <iostream>
#include <string>

class Livre {
public:
    Livre(int id, std::string name, std::string auteur, int annee, bool avaible)
        : id(id), titre(std::move(name)), auteur(std::move(auteur)), annee(annee), available(avaible) {}

    Livre(std::string name, std::string auteur, int annee, bool avaible)
        : id(++last_id), titre(std::move(name)), auteur(std::move(auteur)), annee(annee), available(avaible) {}

    ~Livre() = default;

    static int getLastId() noexcept {
        return last_id;
    }

    int getId() const noexcept {
        return id;
    }
    void setId(int id) {
        this->id = id;
    }

    std::string getTitre() const noexcept {
        return titre;
    }
    void setTitre(const std::string& titre) {
        this->titre = titre;
    }

    std::string getAuteur() const noexcept {
        return auteur;
    }
    void setAuteur(const std::string& auteur) {
        this->auteur = auteur;
    }

    int getAnnee() const noexcept {
        return annee;
    }
    void setAnnee(int annee) {
        this->annee = annee;
    }

    bool getAvailable() const noexcept {
        return available;
    }
    void setAvailable(bool available) {
        this->available = available;
    }

private:
    inline static int last_id = 0;
    int id;
    std::string titre;
    std::string auteur;
    int annee;
    bool available;
};
