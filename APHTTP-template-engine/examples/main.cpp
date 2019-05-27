#include "handlers.hpp"
#include "my_server.hpp"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  srand(time(NULL)); // for rand
  try {
    MyServer server(argc > 1 ? atoi(argv[1]) : 5000);
    manager Manager = manager();
    server.set_manager(&Manager);
    server.setNotFoundErrPage("static/404.html");
    server.get("/login", new ShowPage("static/logincss.html"));
    server.post("/login", new LoginHandler(&Manager));
    server.get("/up", new ShowPage("static/signupcss.html"));
    server.post("/up", new SignupHandler());
    server.get("/rand", new RandomNumberHandler());
    server.get("/home.png", new ShowImage("static/home.png"));
    server.get("/", new ShowPage("static/home.html"));
    server.get("/colors", new ColorHandler("static/colors.html"));
    server.run();
  } catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
}
