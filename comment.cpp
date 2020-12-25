#include "comment.h"

using namespace std;

Comment::Comment(string _content, int id, int costumer_id)
{
    writer_id = costumer_id;
    content = _content;
    comment_id = id;
    deleted = false;
}

void Comment::delete_comment()
{
    deleted = true;
}

void Comment::add_reply(std::string reply)
{
    replies.push_back(reply);
}

void Comment::print_details()
{
    cout << comment_id << ". " << content << endl;
    for (int i = 0; i < replies.size(); i++) 
        cout << comment_id << "." << i + 1 << ". " << replies[i] << endl;
}