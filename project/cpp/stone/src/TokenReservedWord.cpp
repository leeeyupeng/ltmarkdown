#include"TokenReservedWord.hpp"

TokenReservedWord::TokenReservedWord(/* args */)
{
}

TokenReservedWord::~TokenReservedWord()
{
}

TokenReservedWord::TokenReservedWordType TokenReservedWord::GetReservedWordType(string str){
    TokenReservedWordType type = TokenReservedWordType::NONE;
    if(str=="char"){
        type = TokenReservedWordType::CHAR;
    }
    else if(str == "int"){
        type = TokenReservedWordType::INT;
    }
    else if(str == "float"){
        type = TokenReservedWordType::FLOAT;
    }
    else if(str == "if"){
        type = TokenReservedWordType::IF;
    }
    else if(str == "while"){
        type = TokenReservedWordType::WHILE;
    }
    else if(str == "return"){
        type = TokenReservedWordType::RETURN;
    }
    return type;
}