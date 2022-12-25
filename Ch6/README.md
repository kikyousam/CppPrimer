## 6.7函数指针
函数指针指向某种特定类型。函数的类型有它的返回值和形参类型共同决定，与函数名无关。
```C++
bool lengthCompare(const string &, const string &);
```
该函数类型是```bool (const string & const string &) ```。要想声明一个可以指向该函数的指针，只需要用指针替换函数名即可：
```C++
bool (*pf) (const string& ,const string &); //未初始化
```

### 使用函数指针
```C++
pf = lengthCompare;
pf = &lengthCompare;

bool b1 = pf("hello","goodbye");
bool b2 = (*pf)("hello","goodbye");
bool b3 = lengthCompare("hello","goodbye");
```

### 重载函数的指针

```C++
void ff(int *);
void ff(unsigned int);

void (*pf1)(unsigned int)=ff;
```

指针类型一定要与函数的返回值还有参数精确匹配

**当我们将decltype作用于某个函数时，它返回函数类型而非指针类型。因此，我们显式地加上*以表明我们需要返回指针，而非函数本身**

