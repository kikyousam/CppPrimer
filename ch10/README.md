# 第10章 泛型算法


### 10.2.2 写容器元素的算法
- fill
- fill_n
- replace
- replace_copy
- back_inserter
- vec.resize()

### 10.2.3 重排容器元素的算法

### 10.3.2 lambda表达式
lambda表达式可以用来解决有时候需要更多的参数，解决谓词的参数限制的问题

可调用对象：函数和函数指针、lambda表达式

lambda表达式可以理解为一个未命名的内联函数

lambda表达式不能有默认参数，也就是说lambda表达式调用的实参数目和形参数目相同。


### 10.3.3 lambda捕获和返回
当定义一个lambda时，编译器生成了一个与lambda对应的新的（未命名）类类型。

- 值捕获
  前提是变量可以拷贝,被捕获的变量的值是在lambda创建时拷贝，因此随后对其修改不会影响到lambda内对应的值
- 引用捕获
  被捕获的变量的值是在lambda创建时拷贝，因此随后对其修改会影响到lambda内对应的值。注意引用的变量在函数执行的过程中必须是要存在的。
- 隐式捕获
  这个分为两种方式，=表示隐式捕获的值捕获，&表示隐式捕获的引用捕获。引用捕获和值捕获是可以混合使用的，加一个，在捕获列表中即可
- 可变lambda
  如果要修改捕获列表中的参数，如果是值捕获，一般lambda是无法修改这个值，仅仅只是拷贝。但是在参数列表后面加上mutable，便可以修改参数。如果是引用捕获，看引用捕获的对象是常量还是非常量，常量不可以修改，非常量可以修改。

- 指定lambda的返回类型
```C++

transform(vi.begin(),vi.end(),vi.begin(),[](int i){return i<0?-i:i;});
//错误 如果有两个return的话
transform(vi.begin(),vi.end(),vi.begin(),[](int i){if(i<0) return -i;else return i;});
//编译器推断这个版本的lambda返回类型是void，但它返回的是一个Int值。
transform(vi.begin(),vi.end(),vi.begin(),[](int i)->int {if(i<0) return -i;else return i;});
```


### 10.3.4 参数绑定
函数和lambda表达式通常可以替换，但是对于一些泛型算法只支持一元谓词，而我们又想利用之前用到的局部变量，所以就需要两个参数，这样对于函数来说就很难以实现，而lambda表达式可以通过捕获列表来捕获局部变量，所以为了解决函数的参数的问题，引入了参数绑定。

- 标准库bind函数
  一个通用的函数适配器，接受一个可调用对象生成一个新的可调用对象来适应原对象的参数列表。
  ```C++
    auto newCallable = bind(callable ,arg_list);
    //arg_list 形如_n 这些参数表示占位符，说明可调用对象中参数位置。_1 _2
  ```
- 使用placeholders名字
  ```c++
    using namespace std::placeholders;
  ```
- bind参数
  通过改变bind参数的位置，可以改变可调用函数的意义 升序——逆序

- 绑定引用参数
  希望改变参数：如果我们希望传递给bind一个对象而又不拷贝它，就必须使用标准库函数ref函数：
  ```c++
    for_each(words.begin(),words.end(),bind(print,ref(os),_1,' '));
  ```
  标准库还有cref函数，表示const ref

## 10.4 再探迭代器
iterator头文件
- 插入迭代器
  用来插入
- 流迭代器
  用来遍历IO流的
- 反向迭代器
  向后移动
- 移动迭代器 
  不是拷贝容器中的元素，而是移动它们

### 10.4.1 插入迭代器
插入器是一种迭代器适配器。它接收一种容器，生成的是一个迭代器，能实现向指定容器中添加元素。

- back_inserter
- front_inserter
- inserter
  接收两个元素，一个是容器，一个是迭代器。返回一个迭代器，插入在原容器迭代器之后。

### 10.4.2 流迭代器
istream_iterator  读取输入流
ostream_iterator  读取输出流

通过使用流迭代器，我们可以用泛型算法来从刘对象读取数据以及向其写入数据。

- istream_iterator操作
  读取的类型必须定义了>>运算符，比如说cin

- 使用算法操作流迭代器
  
- istream_iterator允许使用懒惰求值
  何时读取的问题

- ostream_iterator操作
  
- 使用流迭代器处理类类型


### 10.4.3 反向迭代器
流迭代器和forward_list不可能构建反向迭代器
- 反向迭代器和其他迭代器之间的关系
  可能会逆序。利用反向迭代器reverse_iterator中的base成员可以完成这样的转换。
  ```C++
    auto rcomma=find(line.crbegin(),line.crend(),',');
    string(rcomma.base(),line.cend());
  ```


## 10.5 泛型算法结构
算法所要求的迭代器操作可以分为5个迭代器类别：
输入迭代器，输出迭代器，前向迭代器，双向迭代器，随机访问迭代器

splice的用法将另一个列表中的元素移动到给定列表。

