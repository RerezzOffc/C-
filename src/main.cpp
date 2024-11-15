#include <httplib.h>
#include <fstream>
#include <iostream>

std::string read_file(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) return "File not found!";
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

int main() {
    httplib::Server server;

    // Route untuk file HTML
    server.Get("/", [](const httplib::Request&, httplib::Response& res) {
        std::string content = read_file("public/index.html");
        res.set_content(content, "text/html");
    });

    // Jalankan server di localhost:8080
    std::cout << "Server running at http://localhost:8080\n";
    server.listen("0.0.0.0", 8080);

    return 0;
}
