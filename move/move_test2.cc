//C++11 引入了右值引用的概念，以表示一个本应没有名称的临时对象。右值引用的声明与左值引用类似，但是它使用的是 2 个 & 符号（&&).




#include<iostream>
#include<fstream>
#include<string>
#include<vector>

namespace list {
    class FileList {
        std::vector<std::string> string_list;
    public:
        FileList(std::string name);
        FileList(FileList &&f);
        void output_list();
    };
    
    
    // fill file list
    FileList::FileList(std::string name) {
        
        std::fstream file;
        file.open(name, std::ios::in);
        if(!file.is_open()) return;
        
        while(!file.eof()) {
            std::string str;
            std::getline(file, str);
            if(file)
                string_list.push_back(str);
        }
        file.close();
    }
    
    FileList::FileList(FileList &&f) : string_list{std::move(f.string_list)} {
        
    }
    
    void FileList::output_list() {
        for(auto &i : string_list) std::cout << i << "\n";
    }

    FileList fillList(std::string name) {
        FileList f(name);
        return f;
    }
    
}


int main(int argc, char **argv) {
    list::FileList f = list::fillList("move_test2.cc");
    f.output_list();
    return 0;
}
