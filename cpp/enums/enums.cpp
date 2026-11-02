#include <iostream>

//Enum to track the result of beginConnect()
enum class BeginResult {
    Started,
    AlreadyConnecting,
    AlreadyConnected
};

//Enum to track the result of CompleteConnect
enum class CompleteResult {
    Completed,
    NotStarted,
    AlreadyConnected
};

//Enum to track the state of the connection
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
    
    //Function to see the current state of the connection
    ConnectionState currentState() const {
        return state;
    }

    //Making state machine:
    //Start by alowing changing state from disconnected to connecting
    //Begin connect + disconnected = change to connecting + true
    //Begin connect + connected / connecting = false
    //UPDATE:
    //Now we use an enum to say more about the result of the operation
    BeginResult beginConnect(){
        switch (state){
            case ConnectionState::Disconnected:
                state = ConnectionState::Connecting;
                return BeginResult::Started;

            case ConnectionState::Connecting:
                return BeginResult::AlreadyConnecting;

            case ConnectionState::Connected:
                return BeginResult::AlreadyConnected;
        }

        return BeginResult::AlreadyConnected;
    }

    //Allow the change from connecting to connected
    //complete connect + connecting = change to connected + true
    // complete connect + disconnected / connected = false
    //UPDATE
    //Now this gives more information on the result of the operation
    CompleteResult completeConnect(){
        switch (state){
            case ConnectionState::Disconnected:
                return CompleteResult::NotStarted;

            case ConnectionState::Connecting:
                state = ConnectionState::Connected;
                return CompleteResult::Completed;

            case ConnectionState::Connected:
                return CompleteResult::AlreadyConnected;
        }

        return CompleteResult::AlreadyConnected;
    }

};

int main() {
    Connection connection;

    ConnectionState starting = connection.currentState();

    switch (starting) {
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