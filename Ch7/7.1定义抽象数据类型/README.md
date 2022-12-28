## 7.1定义抽象数据类型

```C++
struct Sale_data {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
    //...
};
Sales_data total;
if(read(cin,total)){
    Sales_data trans;
    while(read(cin,trans)){
        if(total.isbn()==trans.isbn())
            total.combine(trans);
        else{
            print(cout,total)<<endl;
            total=trans;
        }
    }
    print(cout,total)<<endl;
}else{
    cerr<<"No data?!"<<endl;
}

```

### 引入const成员函数
紧跟在参数列表后面的const表明this是一个指向常量的指针，像这样使用const的成员函数被称作为常量成员函数。常量成员函数不能改变它调用对象的内容。

### 7.1.4 构造函数



### 7.3.2返回*this的成员函数

### 7.3.3 类类型

### 7.3.4 友元再探

#### 类之间的友元关系

#### 令成员函数作为友元

## 7.4 类的作用域

类成员函数返回值类型如果是类成员定义的类型，必须指明。因为返回值类型在类的作用域之外。

### 7.4.1 名字查找和类的作用域

## 7.5 构造函数再探

### 7.5.1 构造函数初始化列表
const 引用类型
成员初始化的顺序是按照类定义的出现顺序一致。
默认构造函数就是参数列表中以默认值进行赋值即可。

### 7.5.2 委托构造函数

### 7.5.3 默认构造函数的作用

### 7.5.4 隐式的类类型转换
为类定义隐式转换规则，转换构造函数
- 只允许一步类类型转换
- 类类型转换不是总有效
- 抑制构造函数定义的隐式转换  使用关键字explicit
- explicit构造函数只能用于直接初始化
- 为转换显式地使用构造函数 static_cast<Sales_data>


### 7.5.5 聚合类

### 7.5.6 字面值常量类

- constexpr构造函数

## 7.6 类的静态成员

静态成员的类内初始化必须是常量表达式
静态成员函数能用于某些场景，普通成员不能

