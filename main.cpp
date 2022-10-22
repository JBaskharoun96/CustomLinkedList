#include <iostream>
#include <ctime>

using namespace std;

template <class T> class List{

    struct Node{
        T data;
        Node * next;
    };

    Node * head;

public:
    List(){
        head = NULL;
    }

    ~List(){
        while(head != NULL){
            Node * n = head->next;
            delete head;
            head = n;
        }
    }

    void add(T value){
        Node * n = new Node;
        n->data = value;
        n->next = head;
        head = n;
    }

    void show(){
        cout << endl << '\t';
        while(head != NULL){
            Node * n = head->next;
            cout << head->data;
            if(head->next != NULL){cout << ", ";}
            head = n;
        }
        cout << endl << endl;
    }
};

int main(){
    time_t t = time(NULL);

    // creating first list with ints
    List<int> MyList;
    MyList.add(5);
    MyList.add(12);
    MyList.add(24);
    MyList.add(32);
    MyList.add(47);
    MyList.add(54);
    MyList.add(65);

    cout << "\n This is the first list (ints)" << endl;
    MyList.show();

    // creating second list with strings
    List<string> MyStringList;
    MyStringList.add("First String");
    MyStringList.add("Second String");
    MyStringList.add("Third String");
    MyStringList.add("Fourth String");
    MyStringList.add("Fifth String");

    cout << " This is the second list (strings)" << endl;
    MyStringList.show();

    cout << " Today is: " << ctime(&t) << endl;

    return 0;
}

