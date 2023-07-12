# CH12 动态内存
## 12.1 动态内存和智能指针
memory头文件
shared_ptr允许多个指针指向同一个对象，unique_ptr则“独占"所指向的对象。标准库还定义了weak_ptr的伴随类，它是一个弱引用，指向shared_ptr所管理的对象。
### 12.1.1 shared_ptr类
shared_ptr类是一个模板类。除此之外，它的用法类似于普通指针
- make_shared函数
  用来初始化一个智能指针shared_ptr;
- shared_ptr的拷贝和赋值
  每拷贝一次，引用计数加一。
- shared_ptr自动销毁所管理的对象
- shared_ptr还会自动释放相关联的内存
- 使用动态生存期的资源的类
    程序使用动态内存出于以下三种原因：
  1. 程序不知道自己需要使用多少对象   （容器类）
  2. 程序不知道所需对象的准确类型    （第15章有例子）
  3. 程序需要在多个对象间共享数据  （本章例子）
目前为止，我们使用的类，分配的资源和对应对象生存期一致。对象存在则资源存在，对象销毁这资源销毁。
所有对象共享同一资源。对象销毁，资源仍然存在。

- 定义strBlob类

- StrBlob的拷贝、赋值和销毁

### 12.1.2 直接管理内存
使用new和delete直接管理内存容易出错。
- 使用new动态分配和初始化对象
  值初始化的内置类型对象有着良好定义的值。而默认初始化的对象的值这是未定义的。
- 动态分配的const对象
- 内存耗尽
  throw一个bad_alloc的异常。 nothrow都定义在头文件new中
- 释放动态内存
  delete p
- 指针值和delete
  只能释放指向动态内存的指针和空指针，const动态对象也可以被释放。
- 动态对象的生存期知道被释放时为止
- delete之后重置指针值，这只是提供了有限的保护
  课后练习：在动态指针赋值或者是强制类型的过程中容易发生内存泄漏。

### 12.1.3 shared_ptr和new结合使用
我们可以是使用new出来的指针来给智能指针初始化。
但是用New出来的指针必须使用直接初始化的方式。因为只能智能指针构造函数是explicit的。
同理不能在返回语句中隐式转换一个普通指针。
必须将shared_ptr显式的绑定在一个想要返回的指针上。
  
注意如果不是指向动态内存的指针来初始化智能指针，则需要提供自己的释放机制，不能使用delete。
```c++
shared_ptr<T> p(q,d)   //d是可调用对象，而不是delete
```
- 不要混合使用普通指针和智能指针
  当将一个shared_ptr绑定到一个普通指针时，我们就将内存的管理责任交给了这个shared_ptr。一旦这样做了，我们就不应该再使用内置指针来访问shared_ptr所指向的内存了。
- 不能使用get 来初始化另一个智能指针或为智能指针赋值
  get的设定是为了让在不能使用智能指针的情况下，返回一个内置指针。
- 其他shared_ptr操作
  
课后题：注意避免使用get()产生double free的情况，或者是函数参数传递一个普通指针时，也会出现double free的错误。

### 12.1.4 智能指针和异常
在发生异常的时候可能会有内存没有被释放。
- 智能指针和哑类
- 使用我们自己的释放操作
  删除器（deleter）

### 12.1.5 unique_ptr
unique_ptr不支持拷贝和赋值，独占所指向的对象。


### 12.1.6 weak_ptr
weak_ptr指向shared_ptr所指向的对象，但是它不影响shared_ptr所指向对象的销毁和释放。不会改变引用计数。
- 核查指针类

- 指针操作
- 

## 12.2 动态数组
C++ 分配一个对象数组的两种方法：
- new方法
- allocator类：允许分配和初始化分离。可以提供更好的性能和更灵活的内存管理能力。

### 12.2.1 new和数组
- 分配一个数组会得到一个元素类型的指针
  我们得到的是一个指针，而且还不能调用begin和end函数。
- 初始化动态分配对象的数组
  初始化的话就是在后面加上一对空括号。
  还可以加上一个元素初始化器的花括号列表
- 动态分配一个空数组是合法的。
  可以用指针遍历动态数组。
- 释放动态数组
  必须加上一个空方括号，不加可能没有警告出现异常
- 智能指针和动态数组
  ```c++
  unique_ptr<int []> ptr=new int [42];
  unique_ptr<int []> ptr(new int [42]);
  ptr.release();
  ptr[1]
  ```
  可以用unique_ptr下标直接访问元素
shared_ptr不支持管理动态数组，需要提供自己的删除器

### 12.2.2 allocator类
标准库allocator类定义在头文件memory中
new的局限：
1. new将内存分配和对象构造组合在一起，delete将对象析构和内存释放组合在一起
2. 将对象构造和内存分配组合在一起，可能会导致不必要的浪费。
```c++
string *const p= new string[n];
string s;
string *q=p;
while(cin>>s&&q!=p+n)
  *q++=s;
const size_t size = p-q;
delete [] p;
```

- allocator类
allocator类是个模板。
```c++
allocator<string> alloc;
auto const p=alloc.allocate(n);
```
- allocator分配未构造的内存
  construct成员函数接收一个指针或者多个额外参数。
```c++
auto q=p;
alloc.construct(q++);      //*q为空字符串
alloc.construct(q++,10,'c')；   //*q为“cccccccccc”
alloc.construct(q++,"hi");     //*q为"hi"
```
当我们用完对象的时候，就可以用destroy函数来销毁它们。destroy接收一个指针，对指向的对象执行析构函数。
```c++
while(q!=p)
  alloc.destroy(--p);
```
一旦元素被销毁后，就可以重新使用这部分内存重新保存其他的string，也可以将其归还系统。释放内存通过deallocate来实现：
```c++
alloc.deallocate(p,n);
```
- 拷贝和填充未初始化内存的算法
  两个伴随算法，可以在未初始化内存中创建对象。定义在memory中。
```c++
uninitialized_copy(b,e,b2)
uninitialized_copy_n(b,n,b2)
uninitialized_fill(b,e,t)
uninitialized_fill_n(b,n,t)

//申请2倍的动态内存
auto p=alloc.allocate(vi.size()*2);
//将一倍的动态内存按原来的vi中元素拷贝
auto q=uninitialized_copy(vi.begin(),vi.end(),p);
//将剩下的动态内存中的元素全部初始化为42
uninitialized_fill_n(q,vi.size(),42);
```
注意uninitialized_copy返回(递增后的)目的位置迭代器。

## 12.3 使用标准库： 文本查询程序
### 12.3.1 文本查询程序设计
- 读取输入文件，记录单词出现的每一行，将每一行单词分解
- 当程序输出时，
  1. 每个单词关联的行号
  2. 行号必须升序且无重复
  3. 必须打印给定行号的文本

实现：
- 使用vector<string>记录行号和行文本
- 使用istringstream来将每行分解为单词
- 使用set来保存每个单词在输入文本出现的行号
- map 每个单词和对应set
---------------------------
- 数据结构：
保存输入文件的类，令文件查询更为容易。查询文件：TextQuery类 返回内容类：QueryResult类

- 在类之间共享数据
  通过返回指向TextQuery对象内部的迭代器(或指针)，我们可以避免拷贝操作。但是如果TextQuery对象在对应的QueryResult对象之前被销毁，就会引用一个不再存在对象的数据。因此我们可以用共享指针shared_ptr来反映数据结构中这种共享关系。
- 使用TextQuery类
  
