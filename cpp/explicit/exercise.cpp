#include <iostream>

class Connection {

private:
    bool connected{false};

public:
    //Explicit constructor that accepts the boolean state
    explicit Connection(bool initialState): connected{initialState} {}

    //Explicit conversion to bool
    explicit operator bool() const { return connected; }

    void connect() {
        connected = true;
    }

    void disconnect() {
        connected = false;
    }

};

int main() {
    Connection connection{false};

    if (!connection)
    {
        std::cout << "Disconnected\n";
    }

    connection.connect();

    if (connection)
    {
        std::cout << "Connected\n";
    }
}