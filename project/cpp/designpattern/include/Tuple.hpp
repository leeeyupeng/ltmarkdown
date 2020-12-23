template<int... T> struct Indices{};
template<int offset,int size,int... T>
struct BuildIndices
{
    using result = typename BuildIndices<offset,size-1,size+offset,T...>::result;
};
template<int offset,int... T>
struct BuildIndices<offset,0,T...>
{
    using result=Indices<T...>;
};



template<typename... Types>struct  Tuple;
template<> struct Tuple<>{};
template<typename Head,typename... Tail>
struct Tuple<Head,Tail...>:Tuple<Tail...>
{
    Head value;
    Tuple(){}
    Tuple(Head head,Tail... tail):Tuple<Tail...>(tail...),value(head){}
};

template<typename... Types>
auto makeTuple(Types... types){
    return Tuple<Types...>(types...);
}

template<typename F,typename Tuple>
void apply(F& f,Tuple& tuple){

}
