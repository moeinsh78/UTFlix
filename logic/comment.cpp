#include "comment.h"

using namespace std;

Comment::Comment(string _content, int id, int costumer_id)
{
    writer_id = costumer_id;
    content = _content;
    comment_id = id;
}

Comment::~Comment() {}