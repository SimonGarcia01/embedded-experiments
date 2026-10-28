#include <iostream>

enum class ConnectionState {
    Disconnected,
    Connecting,
    Connected
};

class Connection {

private:
    //Importance of this state being private for the state machine =
    //With the methods we make sure changes only happens according to our rules = invariants
    ConnectionState state{ConnectionState::Disconnected};

public:

    //Explicit conversion to bool
    explicit operator bool() const {
        return state == ConnectionState::Connected;
    }

    //Making state machine:
    //Start by alowing changing state from disconnected to connecting
    //Begin connect + disconnected = change to connecting + true
    //Begin connect + connected / connecting = false
    bool beginConnect() {
        if (state != ConnectionState::Disconnected)
        {
            return false;
        }

        state = ConnectionState::Connecting;
        return true;
    }

    //Allow the change from connecting to connected
    //complete connect + connecting = change to connected + true
    // complete connect + disconnected / connected = false
    bool completeConnect(){
        if(state != ConnectionState::Connecting) return false;

        state = ConnectionState::Connected;
        return true;
    }

};

int main() {
    Connection connection;

    switch (connection) {
        case ConnectionState::Disconnected:
            std::cout << "Disconnected\n";
            break;

        case ConnectionState::Connecting:
            std::cout << "Connecting\n";
            break;

        case ConnectionState::Connected:
            std::cout << "Connected\n";
            break;
    }
}