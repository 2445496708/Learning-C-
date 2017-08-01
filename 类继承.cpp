初始化列表语法能减少函数的调用，提高效率

基类：class TableTennisPlayer
      {
      ...
      }
派生类：class RatedPlayer : public TableTennisPlayer
        {
        ...
        }

派生类对象存储了基类的数据成员 （继承基类的实现）
派生类对象可以使用基类的方法  （继承基类的接口）
派生类需要自己的构造函数
派生类可以根据需要添加额外的数据成员和成员函数

派生类不能直接访问基类的私有成员， 而必须通过基类的方法进行访问

派生类构造函数：
  首先创建基类对象（若没有显式指出，会自动调用基类的默认构造函数）
  派生类构造函数应通过成员初始化列表将基类信息传递给基类构造函数
  派生类构造函数应初始化派生类新增的数据成员
释放对象顺序与创建对象顺序相反
RatedPlayer::RatedPlayer(unsigned int t, const string & fn,
    const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
    {
        rating = r;
    }

派生与继承特殊关系：
  派生对象可使用基类的非私有方法
  基类指针可以在不进行显式类型转换的情况下指向派生类对象
  基类引用可以在不进行显式类型转换的情况下引用派生类对象
  e.g.RatedPlayer olaf1(...);
  TableTennisPlayer olaf2(olaf1);
  TableTennisPlayer (const RatedPlayer &)//don't exist
  //implicit copy constructor
  TableTennisPlayer (const TableTennisPlayer &)
  
is-a关系：is-a-kind-of

多态公有继承
  实现机制：
    在派生类中重定义基类的方法
    使用虚方法
  关键字virtual
  方法在基类中被声明为虚后，它在派生类中将自动成为虚方法；然而，在派生类声明中用virtual明确指出也不失为好方法
  在派生类中重新定义基类的方法，通常应将基类方法声明为虚
  这样程序将根据对象类型而不是指针或引用的类型来选择方法的版本
  为基类声明一个虚析构函数也是一种惯例，确保按正确顺序调用析构函数
  而构造函数不能是虚函数
  友元不能是虚函数，因为它不是类成员
  重定义不是重载，重定义会将旧版本隐藏

早期联编（静态）默认，效率高
晚期联编（动态）--虚成员函数
向上强制转换：派生类指针或引用转为基类指针或引用，不需进行显式类型转换
向下强制转换：。。。，必需进行显式类型转换

访问控制：protected
  使派生类能访问公众不能使用的内部函数，若是数据的话会有危险

抽象基类
    包含纯虚函数类只能用作基类，不能创建该类的对象
    pure virtual function 通过=0来指明
    virtual double Area() const = 0;
    纯虚函数可以不提供定义，也可提供定义

继承和动态内存分配：
    派生类不使用new：不需要为派生类定义显式析构函数、复制构造函数和赋值运算符
    派生类使用new：必须为派生类定义显式析构函数、复制构造函数和赋值运算符，且只负责新添加成员，继承的成员调用基类函数完成初始化

友元函数并非类成员，不能继承。若希望派生类能使用基类友元，要通过强制类型转换,将派生类引用或指针转为基类引用或指针，然后使用转换后的指针或引用来
调用基类的友元
    ostream & operator<<(ostream & os, const hasDMA & hs)
    {
    //type cast to match operator<<(ostream &, const baseDMA & )
        os << (const baseDMA &）hs;
        os << "Style: " << hs.style << endl;
        return os;
    }




























































































