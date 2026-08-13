class Tab{
public:
    string url;
    Tab* prev;
    Tab* next;

    Tab(string url){
        this->url = url;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class BrowserHistory {
public:
    Tab* current_page;

    BrowserHistory(string homepage) {
        current_page = new Tab(homepage);
    }
    
    void visit(string url) {
        Tab* new_page = new Tab(url);
        new_page->prev = current_page;
        current_page->next = new_page;
        current_page = new_page;
    }
    
    string back(int steps) {
        while( current_page->prev && steps){
            current_page = current_page->prev;
            steps--;
        }
        return current_page->url;
    }
    
    string forward(int steps) {
        while(current_page->next && steps){
            current_page = current_page->next;
            steps--;
        }
        return current_page->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */