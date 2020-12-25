#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>

const int HASH_KEY1 = 11;
const int HASH_KEY2 = 9;
const int HASH_KEY3 = 5;

const std::string GET_NOTIF_HEADER = "#. Notification Message";
const std::string GET_FOLLOWERS_HEAD1 = "List of Followers";
const std::string GET_FOLLOWERS_HEAD2 = "#. User Id | User Username | User Email";
const std::string GET_SEARCH_HEADER = "#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director";
const std::string RECOMMENDATION_HEADER1 = "Recommendation Film";
const std::string RECOMMENDATION_HEADER2 = "#. Film Id | Film Name | Film Length | Film Director";

const int GOOD_GRADE = 8;
const int BAD_GRADE = 5;

const float GOOD_GRADE_PERCENTAGE = 0.95;
const float AVERAGE_GRADE_PERCENTAGE = 0.9;
const float BAD_GRADE_PERCENTAGE = 0.8;

const std::string ALL_NOTIFS_P2 = " with id ";
const std::string ALL_NOTIFS_P4 = " with id ";

const std::string FILM_NOTIF_P1 = "Publisher ";
const std::string FILM_NOTIF_P3 = " register new film.";

const std::string COMMENT_NOTIF_P1 = "User ";
const std::string COMMENT_NOTIF_P3 = " comment on your film ";

const std::string REPLY_NOTIF_P1 = "Publisher ";
const std::string REPLY_NOTIF_P3 = " reply to your comment.";

const std::string FOLLOW_NOTIF_P1 = "User ";
const std::string FOLLOW_NOTIF_P3 = " follow you.";

const std::string BUY_NOTIF_P1 = "User ";
const std::string BUY_NOTIF_P3 = " buy your film ";

const std::string RATE_NOTIF_P1 = "User ";
const std::string RATE_NOTIF_P3 = " rate your film ";


const std::string GET = "GET";
const std::string PUT = "PUT";
const std::string POST = "POST";
const std::string DELETE = "DELETE";

const std::string QUESTION_MARK = "?";

const std::string OK = "OK";
const char* const BAD_REQUEST = "Bad Request";
const char* const NOT_FOUND = "Not Found";
const char* const PERMISSION_DENIED = "Permission Denied";

const std::string FALSE_P = "false";
const std::string TRUE_P = "true";

const std::string USERNAME = "username";
const std::string PASSWORD = "password";
const std::string AGE = "age";
const std::string EMAIL = "email";
const std::string PUBLISHER = "publisher";

const std::string FILM_ID = "film_id";
const std::string USER_ID = "user_id";
const std::string COMMENT_ID = "comment_id";

const std::string AMOUNT = "amount";

const std::string CONTENT = "content";

const std::string SCORE = "score";

const std::string LIMIT = "limit";

const std::string NAME = "name";
const std::string YEAR = "year";
const std::string LENGTH = "length";
const std::string SUMMARY = "summary";
const std::string PRICE = "price";
const std::string DIRECTOR = "director";
const std::string MAX_YEAR = "max_year";
const std::string MIN_YEAR = "min_year";
const std::string MIN_RATE = "min_rate";

const std::string LOGIN = "login";
const std::string SIGNUP = "signup";
const std::string FILMS = "films";
const std::string FOLLOWERS = "followers";
const std::string RATE = "rate";
const std::string COMMENTS = "comments";
const std::string PURCHASED = "purchased";
const std::string PUBLISHED = "published";
const std::string NOTIFICATIONS = "notifications";
const std::string READ = "read";
const std::string MONEY = "money";
const std::string BUY = "buy";
const std::string REPLIES = "replies";

const char SPACE = ' ';
#endif