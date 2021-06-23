#ifndef DATA_USUARIO_H
#define DATA_USUARIO_H

#include <string>

using namespace std;

class DataUsuario
{
private:
    string email;
    string password;

public:
    DataUsuario();
    DataUsuario(const DataUsuario &data);
    DataUsuario(string email, string password);

    string getEmail() const;
    string getPassword() const;

    friend bool operator<(const DataUsuario &d1, const DataUsuario &d2);
    friend bool operator!=(const DataUsuario &d1, const DataUsuario &d2);

    virtual ~DataUsuario();
};

#endif