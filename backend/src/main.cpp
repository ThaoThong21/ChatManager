#include <httplib.h>
#include <iostream>

int main() {
    httplib::Server server;
    std::cout<<"HELLO start"<<std::endl;
    server.Get("/hello", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });
    server.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Welcome!", "text/plain");
    });
    
    if (server.listen("localhost", 9163)) {
        std::cout << "Server is running on http://localhost:9163" << std::endl;
    } else {
        std::cerr << "Failed to start server." << std::endl;
        return 1;
    }

    return 0;
}
