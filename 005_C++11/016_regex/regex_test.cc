
#include <iostream>
#include <regex>


// Custom search without Regex

class SearchString {
public:
    SearchString(std::string ctxt, std::initializer_list<std::string> csearch) : txt(ctxt), search(csearch) {}
    bool procSearch() {
        std::string temp_text=lower(txt);
        for(auto &s : search) {
//            if(temp_text.find(lower(s)) != -1){      //如果-1则会有警告，实际上std::string::npos的最终值和-1表示的最终值是一样的
            if(temp_text.find(lower(s)) != std::string::npos){
                std::cout << "Token found: " << s << "\n";
                return true;
            }
        }
        return false;
    }
    
    std::string lower(std::string text) {
        std::string temp;
        auto l = text.length();
        
        for(unsigned int i = 0; i < l; ++i)
            temp += tolower(text[i]);
        return temp;
    }
    
    bool operator()() {
        return procSearch();
    }
protected:
    std::string txt;
    std::initializer_list<std::string> search;

};

// output match info

void output(std::ostream &out, bool b) {
    if(b) out << "Successful Match\n";
    else out << "No match\n";
}

/*
std::regex_search: 搜素正则表达式参数，但它不要求整个字符序列完全匹配。而且它只进行单次搜索，搜索
到即停止继续搜索，不进行重复多次搜索。
std::regex_replace: 多次搜索整个正则表达式(不考虑捕获组)，然后替换正则表达式匹配到的结果。
std::regex_iterator: 用于多次重复匹配，不分组，只进行多次匹配整个正则表达式，可获取整个正则表达式的结果。
std::regex_token_iterator: 用于多次匹配正则表达式, 它可以获取整个正则表达式的结果，也可以获取正则表达式的前缀，还可以获取正则表达式的分组子匹配。 
*/
int main(int argc, char **argv) {
    
    try {
        // search with Regex (better)
        
        std::regex exp1("<.*>.*</.*>");
        bool isTag = std::regex_match("<tag>value</tag>", exp1);
        output(std::cout, isTag);
        std::string test;
        std::cout << "Enter string to test match (enter any <whatever>test</whatever>: ";
        std::getline(std::cin, test);
        bool isTag2 = std::regex_match(test, exp1);
        output(std::cout, isTag2);
        
        std::cout << "Enter test string to see if it contains any instance of the initalizer list\n";
        std::getline(std::cin, test);
        // search with Custom search
        
        SearchString search(test, {"var", "char", "String", "int", "string", "for", "if", "do", "while", "exit", ">>", "<<", "class", "protected", "public", "{", "}", "(", ")", ";", "-", ":", "&", "|", "!", "[", "]"});
        output(std::cout, search());
        
        
    } catch(std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    } catch(...) {
        std::cerr << "Unknown Exception:  \n";
    }
    return 0;
}
