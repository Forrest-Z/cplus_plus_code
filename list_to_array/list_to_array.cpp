#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string addQuotes(const std::string &text) {
    std::string temp;
    
    for(unsigned int i = 0; i < text.length(); ++i) {
        if(text[i] == '\"') {
            temp += '\\';
            temp += text[i];
        } else if(text[i] == '\\') {
            temp += "\\\\";
        } else {
            temp += text[i];
        }
    }
    return temp;
}


void output_file(std::vector<std::string> &v, std::ostream &out_file) {
    out_file << "const char *array[] = { ";
    for(unsigned int i = 0; i < v.size(); ++i) {
        out_file << "\"" << addQuotes(v[i]) << "\",\n ";
    }
    out_file << " 0 }; \n\n";
}



int main(int argc, char **argv) {
    
    if(argc < 2) {
        std::cerr << "Error requires at least one arguments\n" << argv[0] << " source outfile\n" << "if outfile is not provided will print to stardard output\n";
        return 0;
    }
    
    std::fstream file;
    file.open(argv[1], std::ios::in);
    if(!file.is_open()) {
        std::cerr << "Error could not open input file\n";
        return 0;
    }
    
    std::vector<std::string> v;
    
    while(!file.eof()) {
        std::string n;
        std::getline(file, n);
        
        if(file && n.length() > 0) v.push_back(n);
    }
    
    file.close();
    
    if(argc == 2) {
        output_file(v, std::cout);
    } else {
        std::fstream out_file;
        out_file.open(argv[2], std::ios::out);
        if(!out_file.is_open()) {
            std::cerr << "Error could not open output file.\n";
            return 0;
        }
        output_file(v, out_file);
        out_file.close();
        std::cout << "Succuessfully wrote: " << argv[2] << "\n";
    }
    return 0;
}