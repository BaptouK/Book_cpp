#include <string>

class Membre {
public:
    Membre(int id, std::string name, std::string prenom, std::string mail)
        : id(id), name(name), prenom(prenom), mail(mail) {};

    Membre( std::string name, std::string prenom, std::string mail)
        :id(++last_id), name(name), prenom(prenom), mail(mail) {};

    ~Membre(){};

    static int getLastId() noexcept {
        return last_id;
    }

    int getId() const noexcept {
        return id;
    }
    void setId(int id) {
        this->id = id;
    }

    std::string getName() const noexcept {
        return name;
    }
    void setName(std::string name) {
        this->name = name;
    }

    std::string getPrenom() const noexcept {
        return prenom;
    }
    void setPrenom(std::string prenom) {
        this->prenom = prenom;
    }

    std::string getMail() const noexcept {
        return mail;
    }
    void setMail(std::string mail) {
        this->mail = mail;
    }

private:
    inline static int last_id = 0;
    int id;
    std::string name;
    std::string prenom;
    std::string mail;
};
