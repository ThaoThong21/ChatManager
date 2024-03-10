// namespace my_handle
#ifndef MY_HANDLE_H
#define MY_HANDLE_H
namespace my_handle{
    void handle_login(const httplib::Request& req, httplib::Response& res);
    void handle_chatboard(const httplib::Request& req, httplib::Response& res);
    void handle_errorpage(const httplib::Request& req, httplib::Response& res);
} // my_handle
#endif //MY_HANDLE_H