#include <string>
#include <sstream>
#include <iostream>
#include <type_traits>
#include <exception>
#include <algorithm>
#include <cctype>

// base case of recursion, no more arguments
void format_impl(std::stringstream& ss, const char* format) { 
    while (*format) {
        if (*format == '%' && *++format != '%') // %% == % (not a format directive)
            throw std::invalid_argument("not enough arguments !\n");
        ss << *format++;
    }
}

template <typename Arg, typename... Args>
void format_impl(std::stringstream& ss, const char* format, Arg arg, Args... args) {
    while (*format) {
        if (*format == '%' && *++format != '%') {
            auto current_format_qualifier = *format;
            switch(current_format_qualifier) {
                case 'd' : 
                    if (!std::is_integral<Arg>()) throw std::invalid_argument("%d introduces integral argument");
                    break;
                case 'f' : 
                    if (!std::is_floating_point<Arg>()) throw std::invalid_argument("%f introduces floating point argument");
                    break;
                case 'b' :
                    if(arg) ss << "true";
                    else ss << "false";
                    return format_impl(ss, ++format, args...);
                case 's' :
                    break;
                // etc.
                default: 
                    throw std::invalid_argument("Not a standard format");
                    break;
            }
            // it's true you'd have to handle many more format qualifiers, but on a safer basis
            ss << arg; // arg type is deduced
            return format_impl(ss, ++format, args...); // one arg less
        }
        ss << *format++;
        } // the format string is exhausted and we still have args : throw
    throw std::invalid_argument("Too many arguments\n");
}

template <typename... Args>
std::string format(const char* fmt, Args... args) {
    std::stringstream ss;
    format_impl(ss, fmt, args...);
    return ss.str();
}
