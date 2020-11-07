#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<string, set<int> > book_title;
unordered_map<string, set<int> > book_author;
unordered_map<string, set<int> > key_words;
unordered_map<string, set<int> > publishers;
unordered_map<int, set<int> > publish_year;

void show(set<int>& v){
    for(auto x: v)
        printf("%07d\n", x);
}

int main()
{
    int N;
    cin >> N;
    while(N--){
        int ID;
        cin >> ID;
        getchar();
        string title, author, keywords, publisher;
        getline(cin, title);
        getline(cin, author);
        book_title[title].insert(ID);
        book_author[author].insert(ID);
        while(cin >> keywords){
            key_words[keywords].insert(ID);
            if(getchar() == '\n')
                break;
        }
        getline(cin, publisher);
        publishers[publisher].insert(ID);
        int year;
        cin >> year;
        getchar();
        publish_year[year].insert(ID);
    }
    int M;
    cin >> M;
    while(M--){
        string q, s;
        cin >> q;
        getchar();
        getline(cin, s);
        cout << q << " " << s << endl;
        switch(q[0]){
            case '1':
                if(book_title.find(s) == book_title.end())
                    cout << "Not Found" << endl;
                else
                    show(book_title[s]);
                break;
            case '2':
                if(book_author.find(s) == book_author.end())
                    cout << "Not Found" << endl;
                else
                    show(book_author[s]);
                break;
            case '3':
                if(key_words.find(s) == key_words.end())
                    cout << "Not Found" << endl;
                else
                    show(key_words[s]);
                break;
            case '4':
                if(publishers.find(s) == publishers.end())
                    cout << "Not Found" << endl;
                else
                    show(publishers[s]);
                break;
            case '5':
                if(publish_year.find(stoi(s)) == publish_year.end())
                    cout << "Not Found" << endl;
                else
                    show(publish_year[stoi(s)]);
                break;
        }
    }
    return 0;
}