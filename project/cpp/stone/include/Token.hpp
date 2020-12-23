
enum TokenType{
    NONE,
    ID,
    NUM,
    REAL,
    STRING,
    RESERVERDWORD,

};

class Token
{
private:
    TokenType tokentype=TokenType::NONE;
public:
    Token(/* args */);
    ~Token();
};